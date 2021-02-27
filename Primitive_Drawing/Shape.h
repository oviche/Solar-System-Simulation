#pragma once
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp> 
#include <string>
#include <iostream>
#include "texture.h"
#include <vector>
using namespace std; 
using namespace glm;

class Shape
{
public:
	
	Texture *shap_tex; 
	double rot_speed=0; 
	//double x, y, z;
	vec3 Position;
	vec3 Scale;
	vec3 Rotation;
	mat4 mvp;
	mat4 modelmatrix;
	float g, a; 
	void texture_loader(std::string path); 
	Shape();
	~Shape();
};
class Sphere :public Shape
{
public :
	
	float self_rotation_step;
	float sun_rotation_step;
	float self_angle;
	float sun_angle;
	float radius ;
	unsigned int rings ;
	unsigned int sectors ;
	int countv ;
	int countn ;
	int countt;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
	GLfloat* vertexs1 ;
	
	Sphere(float r, unsigned int r1, unsigned int sec);
	Sphere(); 
	~Sphere();
	void init(int sign); 

};
class Moon :public Sphere 
{
public:
	Moon();
	Sphere s; 
	Moon(float r, unsigned int r1, unsigned int sec); 
	float self_step;
	float earth_step;
	float self_angle;
	float earth_angle;
};
class planet :public Sphere
{
public :
	vector<Moon> moons;
	float self_rotation_step;
	float sun_rotation_step;
	float self_angle;
	float sun_angle;
	float radius;
	void drawplanet(); 
	void add_moon(); 
	planet(); 
};