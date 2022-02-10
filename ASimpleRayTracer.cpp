// ASimpleRayTracer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <random>
#include "HitableList.h"
#include "Sphere.h"
#include "float.h"
#include "Camera.h"
using namespace std;

#define MAX_FLOAT 9999.0


std::mt19937 mt;
std::uniform_real_distribution<float> rand0_1;


Vector3 random_in_unit_sphere()
{
	Vector3 p;
	do 
	{
		p = (Vector3(rand0_1(mt), rand0_1(mt), rand0_1(mt)) - Vector3(1, 1, 1))*2.0;
	} while (dot(p, p) >= 1.0);
	return p;
}


Vector3 Sampler(const Ray& r, Hitable* world)
{
	static int runTimes = 0;
	HitRecord rec;
	if (world->Hit(r, 0.0, MAX_FLOAT, rec) && runTimes < 10) //当前RunTimes不大于10次
	{
		runTimes++;
		Vector3 target = rec.m_hitPoint + rec.m_normal + random_in_unit_sphere();
		return Sampler(Ray(rec.m_hitPoint, target - rec.m_hitPoint), world)*0.5f;
		//return vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1)*0.5;
	}
	//Get the unit vector of the direction
	runTimes = 0;
	Vector3 unit_direction = normalize(r.direction()); //unit the y is (-1,1)
	float t = 0.5*(unit_direction.y() + 1.0f);//make the y is (0,1)
	return Vector3(1.0f, 1.0f, 1.0f)*(1 - t) + Vector3(0.5f, 0.7f, 1.0f)*t;//linear blend
}


int main()
{
	ofstream raytrace; 
	raytrace.open("raytrace7.ppm", std::ios::out | std::ios::app); //以写入和在文件末尾添加的方式打开.txt文件，没有的话就创建该文件。 if (!location_out.is_open()) return 0;
	if (!raytrace.is_open())
	{
		return 0;
	}

	int nx = 800;
	int ny = 400;
	int ns = 10;//Sample number in a single piexel, for antialiasing
	raytrace << "P3\n" << nx << " " << ny << "\n255\n";
	Hitable *list[2];
	list[0] = new Sphere(Vector3(0, 0, -1), 0.5);
	list[1] = new Sphere(Vector3(0, -100.5, -1), 100);
	Hitable* world = new HitableList();
	((HitableList*)world)->AddHitableObject(list[0]);
	((HitableList*)world)->AddHitableObject(list[1]);

	Camera cam;
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			Vector3 col(0,0,0);	
			for (int s = 0; s < ns; s++)
			{
				float u = float((i + rand0_1(mt)) / float(nx));
				float v = float((j + rand0_1(mt)) / float(ny));
				Ray godray = cam.getRay(u, v);
				col += Sampler(godray, world);
			}
			col /= float(ns); 
			/*
			float u = float((i) / float(nx));
			float v = float((j) / float(ny));
			ray godray = cam.getRay(u, v);
			col += color(godray, world);*/
			//Gamma矫正
			col = Vector3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			std::cout << "process:" << j << " " << i << std::endl;
			raytrace << ir << " "<<ig << " " << ib << "\n";
		}
	}
	raytrace.close();
	system("pause");

}

