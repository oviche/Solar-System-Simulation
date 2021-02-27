#pragma once
#include <gl/glew.h>
#include<gl\glfw3.h>


#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
#include "glm/glm.hpp"
using namespace glm;
using namespace std; 

class light
{

	
	vec3 light_postion; 
	vec3 light_color; 
	vec3 ambient_color; 
	vec3 camera_postion; 
	public:
	GLuint light_postion_id;
	GLuint camera_postion_id; 
	GLuint ambient_color_id;
	GLuint light_color_id; 
	light();
	void set_ambient(vec3 lc, vec3 ac);
	void set_diffuse(vec3 lc, vec3 lp);
	void set_location_uniform(GLuint);
	vec3 get_ambient();
	vec3 get_light();
	vec3 get_light_positon();
	vec3 get_camera_postion();
	void update_camera(vec3 pos);
	
	~light();
};

