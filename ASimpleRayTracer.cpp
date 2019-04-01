// ASimpleRayTracer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <random>
#include "hitable_list.h"
#include "sphere.h"
#include "float.h"
#include "camera.h"
using namespace std;

#define MAX_FLOAT 9999.0
std::mt19937 mt;
std::uniform_real_distribution<float> rand0_1;


vec3 random_in_unit_sphere()
{
	vec3 p;
	do 
	{
		p = (vec3(rand0_1(mt), rand0_1(mt), rand0_1(mt)) - vec3(1, 1, 1))*2.0;
	} while (dot(p, p) >= 1.0);
	return p;
}


vec3 color(const ray& r, hitable* world)
{
	hit_record rec;
	if (world->hit(r, 0.0, MAX_FLOAT, rec))
	{
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		return color(ray(rec.p, target - rec.p), world)*0.5f;
		//return vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1)*0.5;
	}
	//Get the unit vector of the direction
	vec3 unit_direction = make_unit_vector(r.direction()); //unit the y is (-1,1)
	float t = 0.5*(unit_direction.y() + 1.0f);//make the y is (0,1)
	return vec3(1.0f, 1.0f, 1.0f)*(1 - t) + vec3(0.5f, 0.7f, 1.0f)*t;//linear blend

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
	hitable *list[2];
	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable* world = new hitable_list(list, 2);
	camera cam;
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 col(0,0,0);	
			for (int s = 0; s < ns; s++)
			{
				float u = float((i + rand0_1(mt)) / float(nx));
				float v = float((j + rand0_1(mt)) / float(ny));
				ray godray = cam.getRay(u, v);
				col += color(godray, world);
			}
			col /= float(ns); 
			/*
			float u = float((i) / float(nx));
			float v = float((j) / float(ny));
			ray godray = cam.getRay(u, v);
			col += color(godray, world);*/
			//Gamma矫正
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			raytrace << ir << " "<<ig << " " << ib << "\n";
		}
	}
	raytrace.close();
	system("pause");

}

