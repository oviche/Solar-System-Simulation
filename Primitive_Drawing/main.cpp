#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "Renderer.h"
#include <gl/GL.h>
#include <gl/GLU.h>
int keypress;
double mousexpos; 
double mouseypos; 
bool InitGraphics();
void radwa2(GLFWwindow *window, int key, int scanecde, int action, int mods);
void radwa(GLFWwindow *window, int key, int scanecde, int action, int mods);
int main( void )
{
	PlaySound(TEXT("inter_test.wav"), NULL, SND_ASYNC | SND_FILENAME);
	
	InitGraphics();
	
	return 0;
}

/** 
Creates the main window and initializes OpenGL stuff.
*/
bool InitGraphics()
{
	int i = glGenLists(1); 
	glPopMatrix(); glTranslatef(1, 1, 1); 
	Renderer *renderer = new Renderer(); //All drawing code goes here
	GLFWwindow* window;

	// ******************** Initialise GLFW ******************** //
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}


	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //If requesting an OpenGL version below 3.2, GLFW_OPENGL_ANY_PROFILE

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Red triangle", NULL, NULL);
	mousexpos = 1024 / 2; 
	mouseypos = 768 / 2; 
	//glfwGetCursorPos(window, (double*)2, (double*)2);
	glfwSetCursorPos(window, mousexpos, mouseypos); 
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); 
	glfwSetKeyCallback(window, &radwa);
	//glfwSetKeyCallback(window, &radwa2); 
	double one, two;
	// ******************** Initialize OpenGL ******************** //
	renderer->Initialize();
	keypress = -1;
	do{ // Loop
		
		glfwGetCursorPos(window, &one, &two); 
		//glfwSetCursorPosCallback(window, &MouseMoved);
	
      //		MouseMovedd(window, one, two);
		/*if (one > 1024 || two > 768 || one <0  || two< 0)
			glfwSetCursorPos(window, 512, 768 / 2); */
		mousexpos = one; 
		mouseypos = two; 
		renderer->Draw();
		if (keypress != -1)
		{
			renderer->handlekeyboardinput(keypress);
			keypress = -1;
		}
		if (mousexpos != 1024 / 2 || mouseypos != 768 / 2)
		{
			double mousespeed = 0.01; 
			double moveddistancex, moveddistancey; 
			moveddistancex = double(512 - mousexpos)*mousespeed;
			moveddistancey = double(768/2 - mouseypos)*mousespeed;
			renderer->handlemousemove(moveddistancex , moveddistancey);
			//renderer->nothing(); 
			//renderer->nothing2(moveddistancex, moveddistancey); 
			mousexpos = 512; 
			mouseypos = 768 / 2; 
			glfwSetCursorPos(window, mousexpos, mouseypos); 
		}
		
		renderer->Draw();
		renderer->Update();

		// Swap buffers
		glfwSwapBuffers(window); //Displaying our finished scene
		glfwPollEvents(); //try to comment it

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
    // Deleting renderer object will deallocate it's memory and call it's destructor (which calls the renderer's Cleanup method)
    delete renderer;
    return true;
	
}
void radwa(GLFWwindow *window, int key, int scanecde, int action, int mods)
{
	if (action == GLFW_REPEAT || action == GLFW_PRESS)//lama ydos   releas awl maseb    repeat tol mana days
	{
		
		keypress = key;
	}
}
void MouseMovedd(GLFWwindow* window, double xpos, double ypos)
{ 
	//set the new mouse position to the MousXPos and MousYPos
	mousexpos = xpos;  mouseypos = ypos;
}
void radwa2(GLFWwindow *window, int key, int scanecde, int action, int mods)
{
	if (action == GLFW_PRESS)//lama ydos   releas awl maseb    repeat tol mana days
	{
		keypress = key;
	}
}