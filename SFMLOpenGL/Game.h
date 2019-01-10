#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>

using namespace std;
using namespace sf;
using namespace gpp;

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
	unsigned int vertex_index[24] = { 0, 1, 2, 1 , 2, 3,
									  4, 5, 6, 5, 6, 7,
									  0, 4, 2, 2, 4, 6,
									  1, 5, 3, 3, 5, 7};
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};