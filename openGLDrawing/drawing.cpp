#include <glew.h>
#include <freeglut.h>

using namespace std;

#define BUFFER_OFFSET(offset) ((void*)(offset))


enum Attrib_IDs { vPosition = 0 };


GLuint VAOs[1];
GLuint Buffers[1];


void Init(void)
{
	glGenVertexArrays(1, VAOs);
	glBindVertexArray(VAOs[0]);

	GLfloat vertices[6][2] =
	{
		{ -0.1, -0.9 },
		{ -0.9,  0.0 },
		{ -0.1,  0.9 },
		{  0.1, -0.9 },
		{  0.9,  0.0 },
		{  0.1,  0.9 }
	};

	glGenBuffers(1, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);




}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glFlush();


}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Finally");
	glewInit();
	Init();
	glutDisplayFunc(Display);

	glutMainLoop();

}
