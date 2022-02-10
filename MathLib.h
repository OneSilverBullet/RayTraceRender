#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <iostream>

/*
* Vector3
*/
class Vector3
{
public:
	float e[3];

	Vector3(){}
	Vector3(float e0, float e1, float e2)
	{
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}

	inline float x() const { return  e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const Vector3& operator+()const { return *this; }
	inline const Vector3& operator-()const { return Vector3(-e[0], -e[1], e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	//location operation
	inline Vector3& operator+=(const Vector3& v2)
	{
		e[0] += v2.e[0];
		e[1] += v2.e[1];
		e[2] += v2.e[2];
		return *this;
	}
	inline Vector3& operator-=(const Vector3& v2)
	{
		e[0] -= v2.e[0];
		e[1] -= v2.e[1];
		e[2] -= v2.e[2];
		return *this;
	}
	inline Vector3& operator*=(const Vector3& v2)
	{
		e[0] *= v2.e[0];
		e[1] *= v2.e[1];
		e[2] *= v2.e[2];
		return *this;
	}
	inline Vector3& operator/=(const Vector3& v2)
	{
		e[0] /= v2.e[0];
		e[1] /= v2.e[1];
		e[2] /= v2.e[2];
		return *this;
	}
	inline Vector3& operator*=(const float t)
	{
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}
	inline Vector3& operator/=(const float t)
	{
		e[0] /= t;
		e[1] /= t;
		e[2] /= t;
		return *this;
	}

	inline float length()const
	{
		return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	inline float length2()const
	{
		return (e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
	}

	inline Vector3 normalize()
	{
		return Vector3(e[0] / length(), e[1] / length(), e[2] / length());
	}
};

//Color operation
inline Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}
inline Vector3 operator*(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vector3 operator*(const Vector3& v1, const float v)
{
	return Vector3(v1.e[0] * v, v1.e[1] * v, v1.e[2] * v);
}

inline Vector3 operator/(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vector3 operator/(const Vector3& v1, const float v)
{
	return Vector3(v1.e[0] / v, v1.e[1] / v, v1.e[2] / v);
}

inline Vector3 normalize(Vector3 v)
{
	return v/v.length();
}

inline float dot(const Vector3& v1, const Vector3& v2)
{
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}

inline Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}




#endif