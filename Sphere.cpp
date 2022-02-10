#include "Sphere.h"

//hit the sphere
//dot(p(t)-c, p(t)-c)=R*R
//t*t*dot(B,B)+2*t*dot(A-C,A-C)+dot(C,C)-R*R=0
//p(t) is the ray, c is the origin of the sphere.
//return the hit point t
bool Sphere::Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const
{
	Vector3 oc = r.originPoint() - m_center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - m_radius * m_radius;
	float discriminant = b * b - a*c;
	if (discriminant > 0)
	{
		//check the closer point
		float temp = (-b - sqrt(b*b - a * c)) / a;
		if (temp<t_max&&temp>t_min)
		{
			rec.m_paramT = temp;
			rec.m_hitPoint = r.parameterPoint(rec.m_paramT);
			rec.m_normal = (rec.m_hitPoint - m_center) / m_radius;
			return true;
		}
		//check the farer point
		temp = (-b + sqrt(b*b - a * c)) / a;
		if (temp<t_max&&temp>t_min)
		{
			rec.m_paramT = temp;
			rec.m_hitPoint = r.parameterPoint(rec.m_paramT);
			rec.m_normal = (rec.m_hitPoint - m_center) / m_radius;
			return true;
		}
	}
	return false;
}
