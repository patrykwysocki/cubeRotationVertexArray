#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	m_cubePoints[0] = MyVector3D(1.0f, 1.0f, 1.0f); //front top right
	m_cubePoints[1] = MyVector3D(-1.0f, 1.0f, 1.0f); //front bottom right
	m_cubePoints[2] = MyVector3D(-1.0f, -1.0f, 1.0f); //front bottom left
	m_cubePoints[3] = MyVector3D(1.0f, -1.0f, 1.0f); //front top left
	m_cubePoints[4] = MyVector3D(1.0f, 1.0f, -1.0f); //back top right
	m_cubePoints[5] = MyVector3D(-1.0f, 1.0f, -1.0f); //back bottom right
	m_cubePoints[6] = MyVector3D(-1.0f, -1.0f, -1.0f); //back bottom left
	m_cubePoints[7] = MyVector3D(1.0f, -1.0f, -1.0f); //back top left

}

Game::~Game() {}
const unsigned int vertices_size = 24u;
const unsigned int vertex_size = 3u;
float vertices[] = { 1.0f, 1.0f, -1.0f, //0
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
0.0f,1.0f,0.0f,
1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f,
0.0f,1.0f,0.0f
	
};
const unsigned int vertex_index_size = 36u;
unsigned int vertex_index[] = {
	0, 1, 2, //Front
	3, 0, 2,

	5 ,1 ,0, //top
	5, 0, 4,

	7, 4, 0, //right
	7, 0, 3,

	2, 1, 5, //left
	2, 5, 6,

	2, 6, 7, //bottom
	2, 7, 3,

	6, 5, 4, //back
	6, 4, 7




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
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.scale(99,99) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}

				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.scale(99,99)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
			{				
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
							//{
							//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
							//	point = m_matrix.scale(101,101) *point;
							//	vertices[i] = point.getX();
							//	vertices[i + 1u] = point.getY();
							//	vertices[i + 2u] = point.getZ();
							//}

				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.scale(101,101)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationX(5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}

				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationX(5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationX(-5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}

				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationX(-5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationY(-5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}


				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationY(-5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationY(5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}

				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationY(5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationZ(-5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationZ(-5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.rotationZ(5) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.rotationZ(5)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.translate(0,-1) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.translate(0,-1)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.translate(0, 1) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.translate(0, 1)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				//for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.translate(1, 0) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
				for (int i = 0; i < 8; i++)
				{

					m_cubePoints[i] = m_matrix.translate(1, 0)*m_cubePoints[i];
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				for (unsigned int i = 0u; i < vertices_size; i += vertex_size)
				//{
				//	MyVector3D point = MyVector3D(vertices[i], vertices[i + 1u], vertices[i + 2u]);
				//	point = m_matrix.translate(-1, 0) *point;
				//	vertices[i] = point.getX();
				//	vertices[i + 1u] = point.getY();
				//	vertices[i + 2u] = point.getZ();
				//}
					for (int i = 0; i < 8; i++)
					{

						m_cubePoints[i] = m_matrix.translate(-1, 0)*m_cubePoints[i];
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
	for (int i = 0; i < 8; i++)
	{
		vertices[i * 3] = m_cubePoints[i].getX();
		vertices[i * 3 + 1] = m_cubePoints[i].getY();
		vertices[i * 3 + 2] = m_cubePoints[i].getZ();
	}
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

