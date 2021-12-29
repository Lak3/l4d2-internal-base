#pragma once

#include "client_class.h"

class Color
{
public:
	Color() {
		*((int*)this) = 0;
	}

	Color(int _r, int _g, int _b) {
		SetColor(_r, _g, _b, 0);
	}

	Color(int _r, int _g, int _b, int _a) {
		SetColor(_r, _g, _b, _a);
	}

	void SetColor(int _r, int _g, int _b, int _a = 0) {
		_color[0] = static_cast<unsigned char>(_r);
		_color[1] = static_cast<unsigned char>(_g);
		_color[2] = static_cast<unsigned char>(_b);
		_color[3] = static_cast<unsigned char>(_a);
	}

	void GetColor(int& _r, int& _g, int& _b, int& _a) const {
		_r = _color[0];
		_g = _color[1];
		_b = _color[2];
		_a = _color[3];
	}

	void SetRawColor(int color32) {
		*((int*)this) = color32;
	}

	int GetRawColor() const {
		return *((int*)this);
	}

	void AsFloat(float* out) {
		out[0] = (static_cast<float>(_color[0]) / 255.0f);
		out[1] = (static_cast<float>(_color[1]) / 255.0f);
		out[2] = (static_cast<float>(_color[2]) / 255.0f);
	}

	inline int r() const { return _color[0]; }
	inline int g() const { return _color[1]; }
	inline int b() const { return _color[2]; }
	inline int a() const { return _color[3]; }

	unsigned char& operator[](int index) {
		return _color[index];
	}

	const unsigned char& operator[](int index) const {
		return _color[index];
	}

	bool operator == (const Color& rhs) const {
		return (*((int*)this) == *((int*)&rhs));
	}

	bool operator != (const Color& rhs) const {
		return !(operator==(rhs));
	}

	Color& operator=(const Color& rhs)
	{
		SetRawColor(rhs.GetRawColor());
		return *this;
	}

private:
	unsigned char _color[4];
};