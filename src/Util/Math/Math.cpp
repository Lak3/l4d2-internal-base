#include "Math.h"

void CUtil_Math::VectorTransform(const Vector input, const matrix3x4_t& matrix, Vector& output)
{
	output[0] = input.Dot({ matrix[0][0], matrix[0][1], matrix[0][2] }) + matrix[0][3];
	output[1] = input.Dot({ matrix[1][0], matrix[1][1], matrix[1][2] }) + matrix[1][3];
	output[2] = input.Dot({ matrix[2][0], matrix[2][1], matrix[2][2] }) + matrix[2][3];
}

void CUtil_Math::BuildTransformedBox(Vector* v2, const Vector bbmin, const Vector bbmax, const matrix3x4_t& m)
{
	Vector v[8];
	PointsFromBox(bbmin, bbmax, v);

	VectorTransform(v[0], m, v2[0]);
	VectorTransform(v[1], m, v2[1]);
	VectorTransform(v[2], m, v2[2]);
	VectorTransform(v[3], m, v2[3]);
	VectorTransform(v[4], m, v2[4]);
	VectorTransform(v[5], m, v2[5]);
	VectorTransform(v[6], m, v2[6]);
	VectorTransform(v[7], m, v2[7]);
}

void CUtil_Math::PointsFromBox(const Vector mins, const Vector maxs, Vector* points)
{
	points[0][0] = mins[0];
	points[0][1] = mins[1];
	points[0][2] = mins[2];

	points[1][0] = mins[0];
	points[1][1] = mins[1];
	points[1][2] = maxs[2];

	points[2][0] = mins[0];
	points[2][1] = maxs[1];
	points[2][2] = mins[2];

	points[3][0] = mins[0];
	points[3][1] = maxs[1];
	points[3][2] = maxs[2];

	points[4][0] = maxs[0];
	points[4][1] = mins[1];
	points[4][2] = mins[2];

	points[5][0] = maxs[0];
	points[5][1] = mins[1];
	points[5][2] = maxs[2];

	points[6][0] = maxs[0];
	points[6][1] = maxs[1];
	points[6][2] = mins[2];

	points[7][0] = maxs[0];
	points[7][1] = maxs[1];
	points[7][2] = maxs[2];
}

void CUtil_Math::VectorAngles(const Vector& forward, Vector& angles)
{
	float yaw, pitch;

	if (forward.y == 0.0f && forward.x == 0.0f)
	{
		yaw = 0.0f;
		pitch = (forward.z > 0.0f) ? 270.0f : 90.0f;
	}
	else
	{
		yaw = RAD2DEGF(::atan2f(forward.y, forward.x));
		yaw += (360.0f * (yaw < 0.0f));

		const float tmp = forward.Lenght2D();

		pitch = RAD2DEGF(::atan2f(-forward.z, tmp));
		pitch += (360.0f * (pitch < 0.0f));
	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0.0f;
}

void CUtil_Math::AngleVectors(const Vector vAngles, Vector* vForward)
{
	float sp, sy, cp, cy;

	const float flX = DEG2RADF(vAngles.x);
	sp = ::sinf(flX);
	cp = ::cosf(flX);

	const float flY = DEG2RADF(vAngles.y);
	sy = ::sinf(flY);
	cy = ::cosf(flY);

	if (vForward)
	{
		vForward->x = (cp * cy);
		vForward->y = (cp * sy);
		vForward->z = -sp;
	}
}

void CUtil_Math::ClampAngles(Vector& v)
{
	v.x = Max(-89.0f, Min(89.0f, NormalizeAngle(v.x)));
	v.y = NormalizeAngle(v.y);
	v.z = 0.0f;
}

void CUtil_Math::RotateTriangle(Vector2D* v, const float flRotation)
{
	const Vector2D vCenter = (v[0] + v[1] + v[2]) / 3.0f;

	for (int n = 0; n < 3; n++)
	{
		v[n] -= vCenter;

		const float flX = v[n].x;
		const float flY = v[n].y;

		const float r = DEG2RADF(flRotation);
		const float c = ::cosf(r);
		const float s = ::sinf(r);

		v[n].x = (flX * c) - (flY * s);
		v[n].y = (flX * s) + (flY * c);

		v[n] += vCenter;
	}
}

float CUtil_Math::GetFovBetween(const Vector vSrc, const Vector vDst)
{
	Vector v_src = { };
	AngleVectors(vSrc, &v_src);

	Vector v_dst = { };
	AngleVectors(vDst, &v_dst);

	float result = RAD2DEG(acos(v_dst.Dot(v_src) / v_dst.LenghtSqr()));

	if (!isfinite(result) || isinf(result) || isnan(result))
		result = FLT_MAX;

	return result;
}

float CUtil_Math::NormalizeAngle(const float ang)
{
	if (!::isfinite(ang))
		return 0.0f;

	return ::remainderf(ang, 360.0f);
}

Vector CUtil_Math::GetAngleToPosition(const Vector vFrom, const Vector vTo)
{
	const Vector vDelta = (vFrom - vTo);
	const float flHyp = ::sqrtf((vDelta.x * vDelta.x) + (vDelta.y * vDelta.y));

	return { (::atanf(vDelta.z / flHyp) * M_RADPI), (::atanf(vDelta.y / vDelta.x) * M_RADPI) + (180.0f * (vDelta.x >= 0.0f)), 0.0f };
}