#include "camera.h"



camera::camera()
{
	postion = vec3(0, 0, 0);
	eye = vec3(40, 40, 40); 
	upvector = vec3(0, 1, 0); 
	prespective_ratio = 4.0f / 3.0f; 
	prespective_angle = 45.0f; 
	nearr = 0.1f; 
	farr = 100000.0f; 

}


camera::~camera()
{
}
void camera::walk_forward()
{
	eye.x -= 0.8; 
	eye.z -= 0.8;
    eye.y -= 0.8; 
	postion.x -= 0.8;
	postion.y -= 0.8;
	postion.z -= 0.8;
}
void camera:: walk_right()
{
	eye.x += 0.8;
	postion.x += 0.8;
}
void camera::walk_left()
{
	eye.x -= 0.8;
	postion.x -= 0.8;

}
void camera::walk_backward()
{
	eye.x += 0.8;
	eye.z += 0.8;
	eye.y += 0.8;

	postion.x += 0.8;
	postion.y += 0.8;
	postion.z += 0.8;

}
void camera::set_camera(vec3 v)
{

}
void camera::set_camera()
{
	camera_projection = perspective(prespective_angle, prespective_ratio, nearr, farr); 
	camera_view = lookAt(eye, postion, upvector);
}