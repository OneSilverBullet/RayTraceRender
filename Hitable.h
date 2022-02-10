#ifndef HITABLE
#define HITABLE
#include "Ray.h"

//The hit information record
struct HitRecord 
{
	float m_paramT; //hit parameter t
	Vector3 m_hitPoint;//hit point
	Vector3 m_normal;//normal
};

//The basic class of hitable object
class Hitable
{
public:
	//Calculate hit record based on ray and min t and max t
	virtual bool Hit(const Ray& r, float minT, float maxT, HitRecord& rec)const = 0;
};


#endif
