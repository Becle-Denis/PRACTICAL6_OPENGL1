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

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == Event::KeyPressed)
			{
				m_displayedInfo = false;
				m_state++;
				if (m_state > m_stateMax)
				{
					m_state = 1;
				}
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
	m_stateMax = 11;
}

void Game::update()
{
	
}

void Game::draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (m_state)
	{
	case 0:
		break;
	case 1:
		if (!m_displayedInfo)
		{
			std::cout << "GL_TRIANGLES" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_TRIANGLES); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;

	case 2:
		if (!m_displayedInfo)
		{
			std::cout << "GL_POINTS" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_POINTS); {
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);

			
			
		}
		glEnd();
		break;

	case 3:
		if (!m_displayedInfo)
		{
			std::cout << "GL_LINES" << std::endl;
			m_displayedInfo = true;
		}

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
		if (!m_displayedInfo)
		{
			std::cout << "GL_LINE_STRIP" << std::endl;
			m_displayedInfo = true;
		}

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
		if (!m_displayedInfo)
		{
			std::cout << "GL_LINE_LOOP" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_LINE_LOOP); {
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(-1.0, 2.0, -5.0);
			glVertex3f(1.0, 2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
		break;

	case 6:
		if (!m_displayedInfo)
		{
			std::cout << "GL_TRIANGLES" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_TRIANGLES); {
			glVertex3f(-2.0, 0.0, -10.0);
			glVertex3f(-4.0, -4.0, -10.0); 
			glVertex3f(0.0, -4.0, -10.0); 
			
			glVertex3f(2.0, 0.0, -10.0);
			glVertex3f(0.0, -4.0, -10.0);
			glVertex3f(4.0, -4.0, -10.0);

			
			glVertex3f(0.0, 4.0, -10.0);
			glVertex3f(-2.0, 0.0, -10.0);
			glVertex3f(2.0, 0.0, -10.0);
			
		}
		glEnd();
		break;

	case 7:
		if (!m_displayedInfo)
		{
			std::cout << "GL_TRIANGLE_STRIP" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(-4.0, -4.0, -10.0);
			glVertex3f(-2.0, 0.0, -10.0);
			glVertex3f(0.0, -4.0, -10.0);
			
			glVertex3f(4.0, -4.0, -10.0);

			glVertex3f(0.0, 4.0, -10.0);

		}
		glEnd();
		break;

	case 8:
		if (!m_displayedInfo)
		{
			std::cout << "GL_TRIANGLE_FAN" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_TRIANGLE_FAN); {
			glVertex3f(0.0, -4.0, -10.0);

			glVertex3f(-2.0, 0.0, -10.0);
			

			glVertex3f(0.0, 4.0, -10.0);

			glVertex3f(4.0, -4.0, -10.0);
		


		}
		glEnd();
		break;

	case 9:
		if (!m_displayedInfo)
		{
			std::cout << "GL_QUADS" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_QUADS); {
			glVertex3f(0.0, -2.0, -10.0);

			glVertex3f(-2.0, 0.0, -10.0);


			glVertex3f(0.0, 2.0, -10.0);

			glVertex3f(2.0, 0.0, -10.0);

		}
		glEnd();
		break;

	case 10:
		if (!m_displayedInfo)
		{
			std::cout << "GL_QUAD_STRIP" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_QUAD_STRIP); {
			glVertex3f(0.0, -2.0, -10.0);

			glVertex3f(-2.0, 0.0, -10.0);

			glVertex3f(2.0, 0.0, -10.0);

			glVertex3f(0.0, 2.0, -10.0);

			glVertex3f(4.0, 2.0, -10.0);

			glVertex3f(2.0, 4.0, -10.0);


		}
		glEnd();
		break;

	case 11:
		if (!m_displayedInfo)
		{
			std::cout << "GL_POLYGON" << std::endl;
			m_displayedInfo = true;
		}

		glBegin(GL_POLYGON); {

			glVertex3f(0.0, -4.0, -10.0);

			glVertex3f(-3.0,-3.0,-10.0);

			glVertex3f(-4.0, 0.0, -10.0);

			glVertex3f(-3.0, 3.0, -10.0);

			glVertex3f(0.0, 4.0, -10.0);

			glVertex3f(3.0, 3.0, -10.0);

			glVertex3f(4.0, 0.0, -10.0);

			glVertex3f(3.0, -3.0, -10.0);
			
		}
		glEnd();
		break;
	}	

	window.display();
}

void Game::unload()
{
	
}

