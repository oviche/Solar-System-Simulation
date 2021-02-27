#pragma once
#include <gl/glew.h>
#include<gl\glfw3.h>
#include "shader.hpp"
#include"Shape.h"
#include "light.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
#include "glm/glm.hpp"
#include "texture.h"
#include "camera.h"
#include <Windows.h>
#include <mmsystem.h>
using namespace glm;
class Renderer
{
	
	int negsign;
	int postsign;
	
	GLfloat ver[100000]; 
	bool box_bool = false; 
	Sphere skybox ; 
	Sphere moons[10];
	Sphere planets[11]; 
	bool changer ; 
	double r; 
	double set ;
	double time;
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint programID;
	GLuint matrixID;
	GLuint matrixmodel;
	GLuint M;
	GLuint N;
	//sun buffers
	GLuint sunsphereBufferID;
	GLuint sunsphereindexs;
	GLuint sphereBufferID;
	GLuint sphereindexs;
	glm::mat4 Translate;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ScaleMatrix;
	glm::mat4 TranslateMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 RotateMatrix;
	glm::mat4 MVP;
	Shape helpskybox;
	Moon moons1[10]; 
	Moon moons2[10]; 
	Shape Cube; 
	light obj;
	vec3 LightColor;
	vec3 AmbientColor;
	vec3 LightPositon;
	float x, y, z; 
	int chooser; 
	int press; 
public:
// 	camera came;
//	camera c = camera();
	int poso; 
	double init; 
	camera tryout;
	bool collid = false; 
	vector<Moon> dynamic_moons; 
	int dyna = 0; 
	bool collid2 = false; 
    Renderer();
    ~Renderer();
    void Initialize();
	//void load_planets_textures(); 
	void handlekeyboardinput(int key);
	void handlemousemove(double x , double y); 
    void Draw();
	void nothing();
	void planets_draw(); 
	void nothing2(double one, double two); 
    void Cleanup();
	void Update();
};
