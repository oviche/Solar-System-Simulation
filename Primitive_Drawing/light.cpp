#include "light.h"


light::light()
{
	light_postion = vec3(0, 0, 0);
	light_color = vec3(0, 0, 0);
	ambient_color = vec3(0, 0, 0);
	camera_postion = vec3(0, 0, 0);
}
void light::update_camera(vec3 pos)
{
	camera_postion = pos; 
}

void light::set_ambient(vec3 lc, vec3 ac)
{
	light_color = lc;
	ambient_color = ac;
}
void light::set_location_uniform(GLuint pd)
{
	ambient_color_id = glGetUniformLocation(pd, "ambid");
	light_color_id= glGetUniformLocation(pd, "lightcolor");
	light_postion_id = glGetUniformLocation(pd, "lightpos");
}
void light::set_diffuse(vec3 lc, vec3 lp)
{
	light_color = lc;
	light_postion = lp;
}
vec3 light::get_ambient()
{
	return ambient_color;
}
vec3 light::get_light()
{
	return light_color;
}
vec3 light::get_light_positon()
{
	return light_postion;
}
vec3 light::get_camera_postion()
{
	return camera_postion;
}
light::~light()
{
}
