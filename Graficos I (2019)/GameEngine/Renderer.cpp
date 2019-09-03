#include "Renderer.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

Renderer::Renderer()
{
	static glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));

	glewInit();

	static const GLfloat vertices[] = {
		0.0f, 1.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};

	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}


Renderer::~Renderer()
{
}

void Renderer::WindowRefresh(GLFWwindow* window)
{
	/* Render here */

	glClearColor(0.62, 0.97, 0.34, 1);

	glClearColor(0.82, 0.420, 0.69, 0.3);

	//glColor4f(0.82, 0.420, 0.69, 0.3);

	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();
}
