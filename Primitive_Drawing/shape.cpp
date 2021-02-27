#include "Shape.h"



Shape::Shape()
{
	Position = vec3(0, 0, 0);
	Scale = vec3(1, 1, 1);
	Rotation = vec3(0, 0, 0);
	
}
Moon::Moon()
{

}
Moon::Moon(float r, unsigned int r1, unsigned int sec)
{
	radius = r; 
	rings = r1; 
	sectors = sec; 
	self_step = 100;
	earth_step = 200;
	self_angle = 0;
	earth_angle = 0;
}
Sphere::Sphere(float r, unsigned int r1, unsigned int sec)
{
	radius = r; 
	rings = r1; 
	sectors = sec; 
	vertexs1 = new GLfloat[rings * sectors * 8];
	self_rotation_step = 50;
	sun_rotation_step = 25;
	self_angle = 0;
	sun_angle = 0;
	countt = 0;
	countn = 0;
	countv = 0;

}
void Shape:: texture_loader(std::string path)
{
	shap_tex = new Texture(path, 0); 
	shap_tex->Bind(); 

}
void Sphere::init(int sign)
{
	

	float const R = 1. / (float)(rings - 1);
	float const S = 1. / (float)(sectors - 1);
	int r, s;

	vertices.resize(rings * sectors * 3);
	normals.resize(rings * sectors * 3);
	texcoords.resize(rings * sectors * 2);
	std::vector<GLfloat>::iterator v = vertices.begin();
	std::vector<GLfloat>::iterator n = normals.begin();
	std::vector<GLfloat>::iterator t = texcoords.begin();

	std::vector<GLfloat>::iterator v1 = vertices.begin();
	std::vector<GLfloat>::iterator n1 = normals.begin();
	std::vector<GLfloat>::iterator t1 = texcoords.begin();
	for (r = 0; r < rings; r++) {
		for (s = 0; s < sectors; s++) {
			float const y = sin(-3.1415 / 2 + 3.1415 * r * R);
			float const x = cos(2 * 3.1415 * s * S) * sin(3.1415 * r * R);
			float const z = sin(2 * 3.1415 * s * S) * sin(3.1415 * r * R);

			*t++ = s*S;
			*t++ = r*R;

			*v++ = x * radius;
			*v++ = y * radius;
			*v++ = z * radius;

			*n++ = sign*x;
			*n++ = sign*y;
			*n++ = sign*z;
		}
	}
	indices.resize(rings * sectors * 6);
	std::vector<GLushort>::iterator i = indices.begin();
	for (r = 0; r < (rings - 1); r++) {
		for (s = 0; s < (sectors - 1); s++) {
			*i++ = r * sectors + s; //1
			*i++ = r * sectors + (s + 1); // 2
			*i++ = (r + 1) * sectors + (s + 1); // 3
			*i++ = r * sectors + s;
			*i++ = (r + 1) * sectors + (s + 1);
			*i++ = (r + 1) * sectors + s; // 4
		}

	}

	for (int i1 = 0;i1<(vertices.size() / 3);i1++)
	{
		for (int l = 0; l < 3; l++)
		{
			if (countv>vertices.size())
				break;
			else {
				vertexs1[i1 * 8 + l] = *v1;
				v1++;
				countv++;
			}

		}
		for (int m = 0; m < 2; m++)
		{
			if (countt>texcoords.size())
				break;
			else
			{
				vertexs1[i1 * 8 + m + 3] = *t1;
				t1++;
				countt++;



			}
		}
		for (int p = 0; p< 3; p++)
		{
			if (countn>normals.size())
				break;
			else {
				vertexs1[i1 * 8 + p + 5] = *n1;
				n1++;
				countn++;
			}
		}
	}
 
}
Shape::~Shape()
{
}
Sphere::Sphere()
{

}
Sphere::~Sphere()
{

}
planet::planet()
{
	radius = 1;
	rings = 90;
	sectors = 90;
	vertexs1 = new GLfloat[rings * sectors * 8];
	self_rotation_step = 50;
	sun_rotation_step = 25;
	self_angle = 0;
	sun_angle = 0;
	init(90); 
}