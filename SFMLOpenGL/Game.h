#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "MyMatrix3.h"
#include "MyVector3.h"



using namespace std;
using namespace sf;


class Game
{
public:
	Game();
	~Game();
	void run();
private:
	// Vertices for one Triangle
	//float vertices[9] = { 1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f };
	float vertices[24] = { -1.5f, 1.5f, -8.0f,
							1.5f, 1.5f, -8.0f,
							-1.5f,-1.5f,-8.0f,
							1.5f,-1.5f, -8.0f,
							-1.5f, 1.5f, -10.0f,
							1.5f, 1.5f, -10.0f,
							-1.5f,-1.5f,-10.0f,
							1.5f,-1.5f, -10.0f };

	// Colors for those vertices
	float colors[24] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f };

	// Index to be drawn
	unsigned int vertex_index[36] = { 0, 1, 2, 1 , 2, 3,
									  4, 5, 6, 5, 6, 7,
									  0, 4, 2, 2, 4, 6,
									  1, 5, 3, 3, 5, 7,
									  0, 1, 4, 1, 4, 5,
									  1, 5, 7, 1, 7, 3};
	MyVector3 m_points[8];
	MyVector3 m_emptyVect{ 0,0,0 };
	MyMatrix3 m_matrices[3];
	MyMatrix3 m_rot;
	MyMatrix3 m_scale;
	MyMatrix3 m_tran;
	
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	int m_pauseTime = 0;
	Clock clock;
	Time elapsed;
	void rotate();
	void translate();
	void scale();
	void applyChanges();


	float rotationAngle = 0.0f;
};