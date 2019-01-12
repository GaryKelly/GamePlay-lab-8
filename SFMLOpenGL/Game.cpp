#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	for (int i = 0; i < 8; i++)
	{
		m_points[i] = MyVector3(vertices[(3 * i)], vertices[1 + (3 * i)], vertices[2 + (3 * i)]);
	}
	m_matrices[0] = MyMatrix3(m_points[0], m_points[1], m_points[2]);
	m_matrices[1] = MyMatrix3(m_points[3], m_points[4], m_points[5]);
	m_matrices[2] = MyMatrix3(m_points[6], m_points[7], m_emptyVect);
}

Game::~Game() {}




void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

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
	//cout << "Update up" << endl;
}

void Game::render()
{
	//cout << "Drawing" << endl;

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
	//cout << "Cleaning up" << endl;
}

void Game::rotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 3; i++)
		{
			m_rot = m_rot.rotationX(0.5);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		for (int i = 0; i < 3; i++)
		{
			m_rot = m_rot.rotationY(0.5);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 3; i++)
		{
			m_rot = m_rot.rotationZ(0.5);
		}
	}
	else
	{
		m_rot = MyMatrix3();
	}
	for (int i = 0; i < 3; i++)
	{
		m_matrices[i]=m_matrices[i].operator*(m_rot);
	}
}

void Game::translate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_tran = m_tran.transalteY(1);
		for (int i = 0; i < 3; i++)
		{
			m_matrices[i] = m_matrices->operator+(m_tran);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_tran = m_tran.transalteY(-1);
		for (int i = 0; i < 3; i++)
		{
			m_matrices[i] = m_matrices->operator+(m_tran);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_tran = m_tran.translateX(-1);
		for (int i = 0; i < 3; i++)
		{
			m_matrices[i] = m_matrices->operator+(m_tran);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_tran = m_tran.translateX(1);
		for (int i = 0; i < 3; i++)
		{
			m_matrices[i] = m_matrices->operator+(m_tran);
		}
	}
}

void Game::scale()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
	{
		m_scale = m_scale.scale(-1.5);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		m_scale = m_scale.scale(1.5);
	}
	else
	{
		m_scale = MyMatrix3(1, 1, 1, 1, 1, 1, 1, 1, 1);
	}
	for (int i = 0; i < 3; i++)
	{
		m_matrices[i] = m_matrices->operator+(m_scale);
	}
}

void Game::applyChanges()
{
	m_points[7] = m_matrices[3].row(0);
	m_points[8] = m_matrices[3].row(1);

	
}

