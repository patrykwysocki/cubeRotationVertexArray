#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

//#include <Vector3.h>
//#include <Matrix3.h>

#include "MyMatrix3D.h"
#include "MyVector3D.h"

using namespace std;
using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	MyMatrix3 m_matrix;
	MyVector3D m_cubePoints[8];
	float rotationAngle = 0.0f;
};