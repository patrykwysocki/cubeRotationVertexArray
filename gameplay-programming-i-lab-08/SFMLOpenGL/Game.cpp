#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

float vertices[] = { 1.0f, 1.0f, -5.0f, //0
-1.0f, 1.0f, -5.0f, //1
-1.0f, -1.0f, -5.0f,//2
1.0f,-1.0f,-5.0f,//3
1.0f,1.0f,-15.0f,//4
-1.0f,1.0f,-15.0f,//5
-1.0f,-1.0f,-15.0f,//6
1.0f,-1.0f,-15.0f//7
};
float colors[] = { 
1.0f, 0.0f, 0.0f, 
0.0f, 1.0f, 0.0f, 
0.0f, 0.0f, 1.0f, 

1.0f,1.0f,0.0f,
1.0f,0.0f,1.0f,
0.0f,1.0f,1.0f

};
unsigned int vertex_index[] = { 
0, 1, 2, //front
3,0,2,//front

5,1,0, //top
5,4,0,//top

6,2,3, //bottom
6,7,3, //bottom

1,2,6, //left
6,5,1,  //left

0,3,7, //right
7,4,0,  //right

6,5,4,  //back
4,6,7   //back


};

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
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
	glTranslatef(0, 0, -2);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

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

