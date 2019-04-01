#ifndef CAMERA
#define CAMERA

#include "ray.h"

class camera
{
public:
	camera()
	{
		lower_left_corner = vec3(-2.0, -1.0, -1.0);
		horizontal = vec3(4.0, 0.0, 0.0);
		vertical = vec3(0.0, 2.0, 0.0);
		origin = vec3(0.0, 0.0, 0.0);
	}
	
	ray getRay(float u,float v) {
		return ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
	}

	vec3 lower_left_corner;//The screen left lower corner position
	vec3 horizontal;
	vec3 vertical;
	vec3 origin; //The Camera position
};





#endif
