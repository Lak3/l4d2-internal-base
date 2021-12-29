#pragma once

#include <math.h>
#include "../../NetVarManager/NetVarManager.h"

typedef float vec_t;

class Vector2D
{
public:
	Vector2D(void)
	{
		x = y = 0.0f;
	}

	Vector2D(float X, float Y)
	{
		x = X; y = Y;
	}

	Vector2D(float* v)
	{
		x = v[0]; y = v[1];
	}

	Vector2D(const float* v)
	{
		x = v[0]; y = v[1];
	}

	Vector2D(const Vector2D& v)
	{
		x = v.x; y = v.y;
	}

	Vector2D& operator=(const Vector2D& v)
	{
		x = v.x; y = v.y; return *this;
	}

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector2D& operator+=(const Vector2D& v)
	{
		x += v.x; y += v.y; return *this;
	}

	Vector2D& operator-=(const Vector2D& v)
	{
		x -= v.x; y -= v.y; return *this;
	}

	Vector2D& operator*=(const Vector2D& v)
	{
		x *= v.x; y *= v.y; return *this;
	}

	Vector2D& operator/=(const Vector2D& v)
	{
		x /= v.x; y /= v.y; return *this;
	}

	Vector2D& operator+=(float v)
	{
		x += v; y += v; return *this;
	}

	Vector2D& operator-=(float v)
	{
		x -= v; y -= v; return *this;
	}

	Vector2D& operator*=(float v)
	{
		x *= v; y *= v; return *this;
	}

	Vector2D& operator/=(float v)
	{
		x /= v; y /= v; return *this;
	}

	Vector2D operator+(const Vector2D& v) const
	{
		return Vector2D(x + v.x, y + v.y);
	}

	Vector2D operator-(const Vector2D& v) const
	{
		return Vector2D(x - v.x, y - v.y);
	}

	Vector2D operator*(const Vector2D& v) const
	{
		return Vector2D(x * v.x, y * v.y);
	}

	Vector2D operator/(const Vector2D& v) const
	{
		return Vector2D(x / v.x, y / v.y);
	}

	Vector2D operator+(float v) const
	{
		return Vector2D(x + v, y + v);
	}

	Vector2D operator-(float v) const
	{
		return Vector2D(x - v, y - v);
	}

	Vector2D operator*(float v) const
	{
		return Vector2D(x * v, y * v);
	}

	Vector2D operator/(float v) const
	{
		return Vector2D(x / v, y / v);
	}

	void Set(float X = 0.0f, float Y = 0.0f)
	{
		x = X; y = Y;
	}

	float Lenght(void) const
	{
		return ::sqrtf(x * x + y * y);
	}

	float LenghtSqr(void) const
	{
		return (x * x + y * y);
	}

	float DistTo(const Vector2D& v) const
	{
		return (*this - v).Lenght();
	}

	float DistToSqr(const Vector2D& v) const
	{
		return (*this - v).LenghtSqr();
	}

	float Dot(const Vector2D& v) const
	{
		return (x * v.x + y * v.y);
	}

	bool IsZero(void) const
	{
		return (x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f);
	}

public:
	vec_t x, y;
};

struct Vertex_t
{
	Vertex_t() { }
	Vertex_t(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}
	void Init(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}

	Vector2D m_Position;
	Vector2D m_TexCoord;
};