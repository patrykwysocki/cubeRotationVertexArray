#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}
const unsigned int vertices_size = 24u;
const unsigned int vertex_size = 3u;
float vertices[vertices_size] = { 1.0f, 1.0f, -1.0f, //0
-1.0f, 1.0f, -1.0f, //1
-1.0f, -1.0f, -1.0f,//2
1.0f,-1.0f,-1.0f,//3
1.0f,1.0f,-1.0f,//4
-1.0f,1.0f,-1.0f,//5
-1.0f,-1.0f,-1.0f,//6
1.0f,-1.0f,-1.0f//7
};
float colors[] = { 
1.0f, 0.0f, 0.0f, 
0.0f, 1.0f, 0.0f, 
0.0f, 0.0f, 1.0f, 

1.0f,1.0f,0.0f,
1.0f,0.0f,1.0f,
0.0f,1.0f,1.0f,
1.0f,0.0f,0.0f
};
const unsigned int vertex_index_size = 36u;
unsigned int vertex_index[vertex_index_size] = {
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.scale(99,99) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.scale(110, 110) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationX(5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationX(-5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationY(-5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationY(5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationZ(-5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.rotationZ(5) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.translate(0,-1) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.translate(0, 1) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.translate(1, 0) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				{
					MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
					point = m_matrix.translate(-1, 0) *point;
					vertices[i] = point.getX();
					vertices[i + 1u] = point.getY();
					vertices[i + 2u] = point.getZ();
				}
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	glEnable(GL_CULL_FACE);
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 0.0, -5.0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	glCullFace(GL_BACK);
	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(vertex_size, GL_FLOAT, 0, &vertices);
	glColorPointer(vertex_size, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, vertex_index_size, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

