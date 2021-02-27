#include "applicationmanager.h"



applicationmanager::applicationmanager()
{
	window_height = 768; 
	window_width = 1024; 
	mouseposx = window_height / 2; 
	mouseposy = window_width / 2; 
}


applicationmanager::~applicationmanager()
{
}
bool applicationmanager::initgraphics()
{
	int i = glGenLists(1); 
	glPopMatrix(); glTranslatef(1, 1, 1); 
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(window_width, window_height, "Solar", NULL, NULL);

	glfwSetCursorPos(window, mouseposx, mouseposy);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}
	return true; 
}