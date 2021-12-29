#pragma once

#include "Vector/Vector.h"

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

using matrix3x4_t = float[3][4];
using VMatrix = float[4][4];

class CUtil_Math
{
public:
	void VectorTransform(const Vector input, const matrix3x4_t& matrix, Vector& output);
	void BuildTransformedBox(Vector* v2, const Vector bbmin, const Vector bbmax, const matrix3x4_t& m);
	void PointsFromBox(const Vector mins, const Vector maxs, Vector* points);
	void VectorAngles(const Vector& forward, Vector& angles);
	void AngleVectors(const Vector vAngles, Vector* vForward);
	void ClampAngles(Vector& v);
	void RotateTriangle(Vector2D* v, const float flRotation);

	float GetFovBetween(const Vector vSrc, const Vector vDst);
	float NormalizeAngle(const float ang);

	Vector GetAngleToPosition(const Vector vFrom, const Vector vTo);

public:
	template<typename T>
	inline T Clamp(const T val, const T min, const T max) {
		const T t = (val < min) ? min : val;
		return (t > max) ? max : t;
	}

	template<typename T>
	inline T Min(const T a, const T b) {
		return ((a > b) * b) + ((a <= b) * a);
	}

	template<typename T>
	inline T Max(const T a, const T b) {
		return ((a > b) * a) + ((a <= b) * b);
	}

	//Not really math related at all.
	template<typename F, typename ... T>
	inline bool CompareGroup(F&& first, T&& ... t) {
		return ((first == t) || ...);
	}
};

namespace U { inline CUtil_Math Math; }