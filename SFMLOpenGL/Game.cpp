#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	for (int i = 0; i < 8; i++)
	{
		m_points[i] = MyVector3(vertices[(3 * i)], vertices[1 + (3 * i)], vertices[2 + (3 * i)]);
	}
	cout << "done";
}

Game::~Game() {}




void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	rotate();
	translate();
	scale();
	applyChanges();
	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);
	

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::rotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		m_rot = m_rot.rotationX(0.0005);
		for(int i = 0; i < 8; i++ )
		{
			m_points[i] = m_rot * m_points[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		
		m_rot = m_rot.rotationY(0.0005);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_rot * m_points[i];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_rot = m_rot.rotationZ(0.0005);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_rot * m_points[i];
		}
	}



}

void Game::translate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_tran = m_tran.transalteY(.01);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_tran.row(1) + m_points[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_tran = m_tran.transalteY(-.01);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_tran.row(1) + m_points[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_tran = m_tran.translateX(-.01);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_tran.row(0) + m_points[i];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_tran = m_tran.translateX(.01);
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = m_tran.row(0) + m_points[i];
		}
	}
}

void Game::scale()
{
	cout << "Scaling\n";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
	{
		
		for (int i = 0; i < 8; i++)
		{

			m_points[i] = MyMatrix3::scale(0.999) * m_points[i];
		}
		

		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = MyMatrix3::scale(1.001) * m_points[i];
		}
	}

	
}

void Game::applyChanges()
{
	


	vertices[0] = m_points[0].getX();
	vertices[1] = m_points[0].getY();
	vertices[2] = m_points[0].getZ();
	vertices[3] = m_points[1].getX();
	vertices[4] = m_points[1].getY();
	vertices[5] = m_points[1].getZ();
	vertices[6] = m_points[2].getX();
	vertices[7] = m_points[2].getY();
	vertices[8] = m_points[2].getZ();
	vertices[9] = m_points[3].getX();
	vertices[10] = m_points[3].getY();
	vertices[11] = m_points[3].getZ();
	vertices[12] = m_points[4].getX();
	vertices[13] = m_points[4].getY();
	vertices[14] = m_points[4].getZ();
	vertices[15] = m_points[5].getX();
	vertices[16] = m_points[5].getY();
	vertices[17] = m_points[5].getZ();
	vertices[18] = m_points[6].getX();
	vertices[19] = m_points[6].getY();
	vertices[20] = m_points[6].getZ();
	vertices[21] = m_points[7].getX();
	vertices[22] = m_points[7].getY();
	vertices[23] = m_points[7].getZ();
}

