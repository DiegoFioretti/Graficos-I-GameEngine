#include "BaseGame.h"
#include <GLFW/glfw3.h>
BaseGame::BaseGame()
{
	gameWindow.CustomWindow(WIDTH, HEIGHT);
}

BaseGame::~BaseGame()
{
}

int BaseGame::ScreenInit() 
{
	//GLFWwindow* window;

	/* Initialize the library 
	if (!glfwInit())
		return -1;*/

	/* Create a windowed mode window and its OpenGL context 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}*/

	/* Make the window's context current */
	//glfwMakeContextCurrent(gameWindow.window());

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(gameWindow.window()))
	{
		/* Render here 
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers 
		glfwSwapBuffers(gameWindow.window());

		/* Poll for and process events 
		glfwPollEvents();*/
		gameRender.WindowRefresh(gameWindow.window());
	}

	glfwTerminate();
	return 0;
}