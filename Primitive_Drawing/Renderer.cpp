#include "Renderer.h"

Renderer::Renderer()
{
	x = 4; 
	y = 3; 
	z = 3; 
	set = 1;
	changer = false;
	skybox = Sphere(1, 90, 90);
	chooser = 0; 
	postsign=1;
	negsign=-1;
}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Initialize()
{
	
	 press = 9;                     
	 
   planets_draw(); //0 sun  1 merc 2 venus 3 earth 4 mars 5 jupitar 6 sat 7 uranu 8 nep 9 pluto
	 
	

	
	tryout = camera(); 
	tryout.set_camera();
	obj = light(); 
	
	
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	
	
	
	
	
	
	//Earth.texture_loader("bricks.jpg");
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	if (chooser ==0)
	helpskybox.texture_loader("sun.gif"); 
	else
	Texture *t = new Texture("spacebig.png", 0); 
	
	GLfloat ver[] = {

	       	-0.5f,+0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,0,1,//  //0     //1
	       	+0.5f,+0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,1,1,////1
	       	+0.5f,-0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,1,0,////2
	       	-0.5f,+0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,0,1,////3
	       	-0.5f,-0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,0,0,////4
	       	+0.5f,-0.5f,+0.5f,      +0.3f,+0.06f,+0.0f      ,1,0,////5
															 //,1
			 +0.5f,+0.5f,+0.5f,      +0.3f,+0.0f,+0.0f      ,0,1,///6
			 +0.5f,-0.5f,+0.5f,      +0.3f,+0.0f,+0.0f       ,0,0,///7    ///2
			 +0.5f,-0.5f,-0.5f,      +0.3f,+0.0f,+0.0f       ,1,0,///8
			 +0.5f,+0.5f,+0.5f,      +0.3f,+0.0f,+0.0f        ,0,1,///9
			 +0.5f,+0.5f,-0.5f,      +0.3f,+0.0f,+0.0f        ,1,1,///10
			 +0.5f,-0.5f,-0.5f,      +0.3f,+0.0f,+0.0f         ,1,0,///11
																	//,1
			-0.5f,+0.5f,+0.5f,      +0.0f,+0.3f,+0.0f        ,1,1,///12    //3
			-0.5f,-0.5f,+0.5f,      +0.0f,+0.3f,+0.0f       ,1,0,///13
			-0.5f,+0.5f,-0.5f,      +0.0f,+0.3f,+0.0f      ,0,1,///14
			-0.5f,-0.5f,+0.5f,      +0.0f,+0.3f,+0.0f      ,1,0,///15
			-0.5f,-0.5f,-0.5f,      +0.0f,+0.3f,+0.0f      ,0,0,///16
			-0.5f,+0.5f,-0.5f,      +0.0f,+0.3f,+0.0f     ,0,1,///17

															   //,1
		   -0.5f,+0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,0,1,///18    //6
		   +0.5f,+0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,1,1,///19
		   +0.5f,-0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,1,0,///20
		   -0.5f,+0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,0,1,///21
		   -0.5f,-0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,0,0,///22
		   +0.5f,-0.5f,-0.5f,      +0.0f,+0.0f,+1.0f       ,1,0,///23
																													//,1

   			-0.5f,+0.5f,+0.5f,      +0.3f,+0.0f,+0.3f         ,0,0,///24
   			+0.5f,+0.5f,+0.5f,      +0.3f,+0.0f,+0.3f         ,1,0,///25
   			-0.5f,+0.5f,-0.5f,      +0.3f,+0.0f,+0.3f         ,0,1,///26
   			+0.5f,+0.5f,+0.5f,      +0.3f,+0.0f,+0.3f         ,1,0,///27 ///4
   			+0.5f,+0.5f,-0.5f,      +0.3f,+0.0f,+0.3f         ,1,1,///28
			-0.5f,+0.5f,-0.5f,      +0.3f,+0.0f,+0.3f         ,0,1,///29
																																																																				   //,1
																																																																				   -0.5f,-0.5f,+0.5f,      +0.0f,+1.0f,+0.0f         ,0,0,///30
																																																																				   +0.5f,-0.5f,+0.5f,      +0.0f,+1.0f,+0.0f         ,1,0,///31
																																																																				   -0.5f,-0.5f,-0.5f,      +0.0f,+1.0f,+0.0f         ,0,1,///32
																																																																				   +0.5f,-0.5f,+0.5f,      +0.0f,+1.0f,+0.0f         ,1,0,///33 ///5
																																																																				   +0.5f,-0.5f,-0.5f,      +0.0f,+1.0f,+0.0f         ,1,1,///34
																																																																				   -0.5f,-0.5f,-0.5f,      +0.0f,+1.0f,+0.0f         ,0,1,///35
	};
	
	
	//GLushort in[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };
	//GLushort in[] = { 1,2,5 ,5,6,2, 2,6,7 ,7,3,2 ,5,6,7,7,8,5, 1,2,3,3,4,1, 8,7,3, 3,4,8,5,1,8,8,4,1 };
	//GLushort in[] = {0,1,2,2,3,0  ,0,4,5,5,1,0  ,3,2,6,6,7,3  ,7,4,5,5,6,7   ,1,5,6,6,2,1  ,0,4,7,7,3,0 };
	

	for (int i = 0; i < 9; i++)
	{
		if(i==0){
		planets[i].init(negsign);
		}
		else
          planets[i].init(postsign);
	}
	
   
	glGenBuffers(1, &sunsphereBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, sunsphereBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * planets[0].rings * planets[0].sectors * 8, planets[0].vertexs1, GL_STATIC_DRAW);
	glGenBuffers(1, &sunsphereindexs);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sunsphereindexs);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(GLushort)*(planets[0].indices.size())), &planets[0].indices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &sphereBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, sphereBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * planets[1].rings * planets[1].sectors * 8, planets[1].vertexs1, GL_STATIC_DRAW);
	glGenBuffers(1, &sphereindexs);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereindexs);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(GLushort)*(planets[1].indices.size())), &planets[1].indices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &M);
	glGenBuffers(1, &N);
	glBindBuffer(GL_ARRAY_BUFFER, M);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, N);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ver), ver, GL_STATIC_DRAW);

	
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(in), in, GL_STATIC_DRAW);

	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	glUseProgram(programID);
	
	matrixID = glGetUniformLocation(programID, "MVP");
	matrixmodel = glGetUniformLocation(programID, "model");
	//set location matrix,light color and ambient color.....
	obj.set_location_uniform(programID);
	obj.set_ambient(vec3(0.9f, 0.9f, 0.9f), vec3(1.0f, 1.0f, 1.0f));
	obj.set_diffuse(vec3(0.9f, 0.9f, 0.9f), planets[0].Position);
	//get values of light color,ambient colorand light position.....
	LightColor = obj.get_light();
	AmbientColor = obj.get_ambient();
	LightPositon = obj.get_light_positon();
	glUniform3f(obj.ambient_color_id, AmbientColor.x, AmbientColor.y, AmbientColor.z);
	glUniform3f(obj.light_color_id, LightColor.x, LightColor.y, LightColor.z);
	glUniform3f(obj.light_postion_id, LightPositon.x, LightPositon.y, LightPositon.z);
	MVP = ProjectionMatrix * ViewMatrix * Cube.modelmatrix;
	time = glfwGetTime();
	
}

void Renderer::Draw()
{
	Cube.shap_tex->Bind(); 
	
	
	glBindBuffer(GL_ARRAY_BUFFER, M);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, N);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(programID);
	
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (char*)(6 * sizeof(GLfloat)));
	
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
	
	glDrawArrays(GL_TRIANGLES, 0, 36);
	//helpskybox.shap_tex->Bind();
	//draw sun.....................
	glBindBuffer(GL_ARRAY_BUFFER, sunsphereBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sunsphereindexs);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	//using normals layout.....................
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (char*)(5 * sizeof(GLfloat)));
	MVP = ProjectionMatrix * ViewMatrix * planets[0].modelmatrix;

		
			planets[0].shap_tex->Bind(); 
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
		
		glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);
	///////////////////////////////////
	
	glBindBuffer(GL_ARRAY_BUFFER, sphereBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereindexs);
	 

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (char*)(5 * sizeof(GLfloat)));
	MVP = ProjectionMatrix * ViewMatrix * skybox.modelmatrix;

	
		skybox.shap_tex->Bind();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
	if(box_bool)
	glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);


	for (int i = 1; i < press; i++)
	{
		MVP = ProjectionMatrix * ViewMatrix * planets[i].modelmatrix;

		
			planets[i].shap_tex->Bind(); 
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
		
		glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);
	}
	for (int i = 2; i < 8; i++)
	{
		MVP = ProjectionMatrix * ViewMatrix * moons1[i].modelmatrix;

		
			moons1[i].shap_tex->Bind();
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
		//glUniform3f(colorobject, shapes[z].color.x, shapes[z].color.y, shapes[z].color.z);
		glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);
	}
	for (int i = 0; i < dyna; i++)
	{
		MVP = ProjectionMatrix * ViewMatrix * dynamic_moons[i].modelmatrix;
		dynamic_moons[i].shap_tex->Bind();
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

		glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);
	}
	for (int i = 5; i < 8; i++)
	{
		MVP = ProjectionMatrix * ViewMatrix * moons2[i].modelmatrix;
		moons2[i].shap_tex->Bind();
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
		
		glDrawElements(GL_TRIANGLES, 89 * 89 * 6, GL_UNSIGNED_SHORT, 0);
	}
	
	ProjectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100000.0f);
	ViewMatrix = lookAt(tryout.eye ,tryout.postion , tryout.upvector);

	MVP = ProjectionMatrix * ViewMatrix * Cube.modelmatrix;
	

	
}


void Renderer::Cleanup()
{
	glDeleteBuffers(1, &vertexBufferID);
	glDeleteVertexArrays(1, &vertexArrayID);
	glDeleteProgram(programID);
}
void Renderer::Update()
{
	double current_time = glfwGetTime();
	double delta = (current_time - time) * 1;
	time = current_time;
	double rotation_step = 10;

	float ratios[9];
	ratios[0] = (float)(365.0 / 88.0); //mercury
	ratios[1] = (float)(365.0 / 243.0); // venus
	ratios[2] = 1;  //earth
	ratios[3] = (float)(365.0 / 687.0); //mars
	ratios[4] = (float)(365.0 / 4333.0); //juiptar
	ratios[5] = (float)(365.0 / 10759.0); //saturn 
	ratios[6] = (float)(365.0 / 30689.0); // ornus
	ratios[7] = (float)(365.0 / 60182.0); //neptune
	ratios[8] = (float)(365.0 / 248.0); //pluto

   //------sun matrics --------//
	mat4 scalesun;
	mat4 sun_self_rotation;
	//-------planets matrics-----//
	mat4 trans_to_planet_postion;
	mat4 scaleplanet;
	mat4 planet_self_rotation;
	mat4 rotate_around_sun;
	//----------Moon matrics --------//
	mat4 scalemoon;
	mat4 moon_self_rotation;
	mat4 trans_to_moon_postion;
	mat4 rotate_around_planet;
	
	planets[0].self_angle += planets[0].self_rotation_step * delta;
	scalesun = scale(planets[0].Scale);
	sun_self_rotation = rotate(planets[0].self_angle, 0.0f, 1.0f, 0.0f);//
	ModelMatrix = scalesun*sun_self_rotation;
	planets[0].modelmatrix = ModelMatrix; 
	MVP = ProjectionMatrix*ViewMatrix*ModelMatrix;
	planets[0].mvp = MVP;

	//------- planets-------------------//
	for (int i = 1;i<10;i++)
	{
		
		planets[i].self_angle += planets[i].self_rotation_step*delta;
	
		planets[i].sun_angle += planets[i].sun_rotation_step*delta*ratios[i - 1];

		trans_to_planet_postion = translate(planets[i].Position);
		scaleplanet = scale(planets[i].Scale);
		planet_self_rotation = rotate(planets[i].self_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_sun = rotate(planets[i].sun_angle, 0.0f, 1.0f, 0.0f);
		ModelMatrix = rotate_around_sun *trans_to_planet_postion *planet_self_rotation*scaleplanet;
		planets[i].modelmatrix = ModelMatrix;
		MVP = ProjectionMatrix*ViewMatrix*ModelMatrix;
		planets[i].mvp = MVP;
	}
	// moons
	for (int i = 0;i < 9;i++) {
		moons1[i].self_angle += delta *moons1[i].self_step;
		moons1[i].earth_angle += delta *moons1[i].earth_step;
		trans_to_moon_postion = translate(moons1[i].Position);
		trans_to_planet_postion = translate(planets[i + 1].Position);
		scalemoon = scale(moons1[i].Scale);
		moon_self_rotation = rotate(moons1[i].self_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_planet = rotate(moons1[i].earth_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_sun = rotate(planets[i + 1].sun_angle, 0.0f, 1.0f, 0.0f);
		ModelMatrix = rotate_around_sun* trans_to_planet_postion*rotate_around_planet
			*trans_to_moon_postion*moon_self_rotation*scalemoon;
		moons1[i].modelmatrix = ModelMatrix;
	}
	//moons2
	for (int i = 5;i < 9;i++) {
		moons2[i].self_angle += delta *moons2[i].self_step;
		moons2[i].earth_angle += delta *moons2[i].earth_step/1.5;
		trans_to_moon_postion = translate(moons2[i].Position);
		trans_to_planet_postion = translate(planets[i + 1].Position);
		scalemoon = scale(moons2[i].Scale);
		moon_self_rotation = rotate(moons2[i].self_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_planet = rotate(moons2[i].earth_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_sun = rotate(planets[i + 1].sun_angle, 0.0f, 1.0f, 0.0f);
		ModelMatrix = rotate_around_sun* trans_to_planet_postion*rotate_around_planet
			*trans_to_moon_postion*moon_self_rotation*scalemoon;
		moons2[i].modelmatrix = ModelMatrix;
	}
	for (int i = 0; i < dyna; i++)
	{
		dynamic_moons[i].self_angle += delta *dynamic_moons[i].self_step;
		if (i%2==0)
		dynamic_moons[i].earth_angle += delta *dynamic_moons[i].earth_step / 1.5;
		else
			dynamic_moons[i].earth_angle += delta *dynamic_moons[i].earth_step / 10 /dynamic_moons[i].rot_speed;

		trans_to_moon_postion = translate(dynamic_moons[i].Position);
		trans_to_planet_postion = translate(planets[7].Position);
		scalemoon = scale(dynamic_moons[i].Scale);
		moon_self_rotation = rotate(dynamic_moons[i].self_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_planet = rotate(dynamic_moons[i].earth_angle, 0.0f, 1.0f, 0.0f);
		rotate_around_sun = rotate(planets[7].sun_angle, 0.0f, 1.0f, 0.0f);
		ModelMatrix = rotate_around_sun* trans_to_planet_postion*rotate_around_planet
			*trans_to_moon_postion*moon_self_rotation*scalemoon;
		dynamic_moons[i].modelmatrix = ModelMatrix;
	}
	if (tryout.eye.x <= 12 && changer ==false)
	{
		tryout.eye.x = tryout.eye.x + 0.01;
		tryout.eye.y = tryout.eye.y + 0.01;
		tryout.eye.z = tryout.eye.z + 0.01;
		 
	}
	     if (tryout.eye.z >=12)
		changer = true; 
	    
		 if (tryout.eye.z < 6) {
			 collid = true;
			// PlaySound(TEXT("bloop_x.wav"), NULL, SND_ASYNC | SND_FILENAME);
		 }

		 if (collid)
			 tryout.walk_backward(); 

		 if (tryout.eye.z > 40)
			 collid = false; 

		 if (tryout.eye.z > 200)
		 {
			 collid2 = true;
			// PlaySound(TEXT("bloop_x.wav"), NULL, SND_ASYNC | SND_FILENAME);

		 }
		 if (collid2)
			 tryout.walk_forward(); 
		 if (tryout.eye.z < 100)
			 collid2 = false; 


}

void Renderer::handlemousemove(double x, double y)
{
	tryout.postion.x -= x;
	tryout.postion.y += y;
}

void Renderer::handlekeyboardinput(int key)
{
	glm::mat4 translatee;
	switch (key)
	{
	case GLFW_KEY_UP: 
		tryout.walk_forward(); 
		
		break;
	case GLFW_KEY_DOWN:
		tryout.walk_backward();
		break;
	case GLFW_KEY_LEFT:
		tryout.walk_left(); 
		break; 
	case GLFW_KEY_RIGHT:
		tryout.walk_right();
		break;
	case GLFW_KEY_T:
		if (box_bool)
			box_bool = false;
		else
			box_bool = true; 
		break;
	case GLFW_KEY_1:
		//PlaySound(TEXT("last.wav"), NULL, SND_ASYNC | SND_FILENAME);
		
			dyna++;
			dynamic_moons.push_back(Moon(1, 90, 90));
			r = rand() % 100; 
			dynamic_moons.back().Scale = vec3(1.6, 1.6, 1.6);
			dynamic_moons.back().rot_speed = init;
			init += 0.1;
			dynamic_moons.back().Position = vec3(poso, 0, 0);
			poso += 2;
			dynamic_moons.back().modelmatrix = translate(dynamic_moons.back().Position) *
				scale(dynamic_moons.back().Scale);
			printf("%f", r); 
			if(r >50)
			dynamic_moons.back().texture_loader("moon.tga");
			else
				dynamic_moons.back().texture_loader("venus.jpg");

	

		
		break;
	case GLFW_KEY_2:
		dyna--; 
		break;
	case GLFW_KEY_LEFT_SHIFT:
		
		tryout.postion.x = tryout.postion.y =tryout.postion.z= 0; 
		break;
	case GLFW_KEY_P:
		if (press == 10)
			press = 9;
		else
			press = 10;
			break;
	}

	mat4 translatemat;
	mat4 scalemat;
	mat4 rotatemat;
	printf("%f\n", tryout.eye.x); 
}
void Renderer:: planets_draw()
{
	Cube = Shape();
	Cube.texture_loader("spacebig.jpg");

	Cube.Position = vec3(1, 1, 1);
	Cube.Scale = vec3(600, 600, 600);
	
	TranslateMatrix = translate(Cube.Position);
	ScaleMatrix = scale(Cube.Scale);
	Cube.modelmatrix = TranslateMatrix*ScaleMatrix;

	skybox.Scale = vec3(400, 400, 400); 
	skybox.texture_loader("st4.png");
	skybox.Position = vec3(0, 0, 0); 
	skybox.modelmatrix = translate(skybox.Position) * scale(skybox.Scale); 
	planets[0] = Sphere(0.5, 90, 90);   // sun 
	planets[0].Scale = vec3(6, 6, 6);
	planets[0].texture_loader("sun.tga");

	planets[1] = Sphere(0.5, 90, 90);   // mercury  
	planets[1].Scale = vec3(1, 1, 1);
	planets[1].texture_loader("mercury.jpg");

	planets[2] = Sphere(0.5, 90, 90);   // venus
	planets[2].Scale = vec3(1.5, 1.5, 1.5);
	planets[2].texture_loader("venus.jpg");

	planets[3] = Sphere(0.5, 90, 90);   // earth 
	planets[3].Scale = vec3(1.8, 1.8, 1.8);
	planets[3].texture_loader("earth.jpg");

	planets[4] = Sphere(0.5, 90, 90);   // mars 
	planets[4].Scale = vec3(1.9, 1.9, 1.9);
	planets[4].texture_loader("mars.jpg");

	planets[5] = Sphere(0.5, 90, 90);   // jupitar 
	planets[5].Scale = vec3(3, 3, 3);
	planets[5].texture_loader("jupitar.jpg");

	planets[6] = Sphere(0.5, 90, 90);   // sun 
	planets[6].Scale = vec3(3.2, 3.2, 3.2);
	planets[6].texture_loader("saturn.jpg");

	planets[7] = Sphere(0.5, 90, 90);   // sun 
	planets[7].Scale = vec3(3.3, 3.3, 3.3);
	planets[7].texture_loader("download.jpg");

	planets[8] = Sphere(0.5, 90, 90);   // sun 
	planets[8].Scale = vec3(2.4, 2.4, 2.4);
	planets[8].texture_loader("neptune.jpg");

	planets[9] = Sphere(0.5, 90, 90);   // sun 
	planets[9].Scale = vec3(1, 1, 1);
	planets[9].texture_loader("pluto.jpg");

	double radius = 2;
	double pos = 15;

	for (int i = 1; i < 11; i++)
	{
		
		planets[i].Position = vec3(pos, 0, 0);
	
		if (i > 5)
			pos += 30; 
		else
		pos += 10;
		
	}
	for (int i = 0; i < 10; i++)
	{
		planets[i].Scale.x *= 2;
		planets[i].Scale.y *= 2;
		planets[i].Scale.z *= 2;

	}
	
	for (int i = 0; i < 9; i++)
	{
		moons1[i] = Moon(1, 90, 90); 
		moons1[i].Scale = vec3(1, 1, 1);
		moons1[i].Position = vec3(4, 0, 0);
		moons1[i].modelmatrix = translate(moons1[i].Position) * scale(moons1[i].Scale);
		moons1[i].texture_loader("moon_tex.jpg");
	}
	for (int i = 0; i < 9; i++)
	{
		moons2[i] = Moon(1, 90, 90);
		moons2[i].Scale = vec3(1.5, 1.5, 1.5);
		moons2[i].Position = vec3(6, 0, 0);
		moons2[i].modelmatrix = translate(moons2[i].Position) * scale(moons2[i].Scale);
		moons2[i].texture_loader("moon_tex.jpg");
	}
	 poso = 8; 
	 init = 1; 
	for (int i = 0; i < dyna; i++)
	{
		dynamic_moons.push_back(Moon(1, 90, 90)); 
		dynamic_moons[i].Scale = vec3(1.6, 1.6, 1.6); 
		dynamic_moons[i].rot_speed = init; 
		init += 0.1; 
		dynamic_moons[i].Position = vec3(poso, 0, 0); 
		poso += 2; 
		dynamic_moons[i].modelmatrix = translate(dynamic_moons[i].Position) * scale(dynamic_moons[i].Scale); 
		dynamic_moons[i].texture_loader("moon_tex.jpg"); 
	}
}




