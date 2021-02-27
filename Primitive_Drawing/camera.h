#pragma once
#include <iostream>
#include <gl/glew.h>
#include<gl\glfw3.h>
#include "shader.hpp"
#include"Shape.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
#include "glm/glm.hpp"

using namespace glm; 
class camera
{

public:
	GLfloat prespective_angle;
	GLfloat prespective_ratio;
	GLfloat nearr;
	GLfloat farr;
	vec3 eye, postion, upvector;
	mat4 camera_projection, camera_view; 

	void set_camera();
	void walk_forward(); 
	void walk_backward(); 
	void set_camera(vec3 v);
	void walk_left(); 
	void walk_right(); 
	camera();
	~camera();
};

