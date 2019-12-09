#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
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
			if (event.type == Event::KeyPressed)
			{
				m_state++;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (m_state)
	{
	case 0:
		break;
	case 1:
		glBegin(GL_TRIANGLES); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;

	case 2:
		glBegin(GL_POINTS); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;

	case 3:
		glBegin(GL_LINES); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(0.0, 2.0, -5.0);
		}
		glEnd();
		break;

	case 4:
		glBegin(GL_LINE_STRIP); {
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(-1.0, 2.0, -5.0);
			glVertex3f(0.0, -2.0, -5.0);
			glVertex3f(1.0, 2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;

	case 5:
		glBegin(GL_LINE_LOOP); {
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(-1.0, 2.0, -5.0);
			glVertex3f(1.0, 2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;
	}	

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

