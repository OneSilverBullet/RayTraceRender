#include "pch.h"
#include "sphere.h"

//hit the sphere
//dot(p(t)-c, p(t)-c)=R*R
//t*t*dot(B,B)+2*t*dot(A-C,A-C)+dot(C,C)-R*R=0
//p(t) is the ray, c is the origin of the sphere.
//return the hit point t
bool sphere::hit(const ray & r, float t_min, float t_max, hit_record & rec) const
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - a*c;
	if (discriminant > 0)
	{
		//check the closer point
		float temp = (-b - sqrt(b*b - a * c)) / a;
		if (temp<t_max&&temp>t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		//check the farer point
		temp = (-b + sqrt(b*b - a * c)) / a;
		if (temp<t_max&&temp>t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}

	return false;
}
