#pragma once
#include <iostream>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "Renderer.h"
#include <gl/GL.h>
#include <gl/GLU.h>
class applicationmanager
{
public:
	GLFWwindow * window; 
	int i;
//	Renderer * re = new Renderer();
	double window_height, window_width; 
	double mouseposx, mouseposy; 
	double time; 
	bool initgraphics(); 
	applicationmanager();
	~applicationmanager();
};

