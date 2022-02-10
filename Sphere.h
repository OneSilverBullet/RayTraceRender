#ifndef SPHERE
#define SPHERE
#include "Hitable.h"

class Sphere : public Hitable
{
public:
	Vector3 m_center;
	float m_radius;
	Sphere() {}
	Sphere(Vector3 cen, float r) :m_center(cen), m_radius(r) {}
	virtual bool Hit(const Ray& r, float t_min, float t_max, HitRecord& rec)const override;

};


#endif
