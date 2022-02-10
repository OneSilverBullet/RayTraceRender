#pragma once
#ifndef RAYH
#define RAYH
#include "MathLib.h"

class Ray
{
public:
	Vector3 m_originPoint;
	Vector3 m_direction;

	Ray() {}
	Ray(const Vector3& originPoint, const Vector3& direction)
	{
		m_originPoint = originPoint;
		m_direction = direction;
	}
	Vector3 originPoint()const { return m_originPoint; }
	Vector3 direction()const { return m_direction; }
	Vector3 parameterPoint(float t)const
	{
		return m_originPoint + m_direction * t;
	}
};



#endif