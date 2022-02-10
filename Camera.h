#ifndef CAMERA
#define CAMERA

#include "Ray.h"

class Camera
{
public:
	Camera()
	{
		m_lowerLeftCorner = Vector3(-2.0, -1.0, -1.0);
		m_horizontal = Vector3(4.0, 0.0, 0.0);
		m_vertical = Vector3(0.0, 2.0, 0.0);
		m_origin = Vector3(0.0, 0.0, 0.0);
	}
	
	//依据渲染图的uv来获取每一个像素点的射线
	Ray getRay(float u,float v) {
		return Ray(m_origin, m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_origin);
	}

	Vector3 m_lowerLeftCorner;//The screen left lower corner position
	Vector3 m_horizontal;
	Vector3 m_vertical;
	Vector3 m_origin; //The Camera position
};





#endif
