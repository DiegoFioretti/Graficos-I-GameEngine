#include "Renderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
/*
const char* vertexSource = R"glsl(
    #version 150 core
	in vec2 position;
    in vec3 color;
    out vec3 Color;
	uniform mat4 trans;
	uniform mat4 view;
	uniform mat4 proj;
    void main()
    {
		Color = color;
        gl_Position = proj * view * trans * vec4(position, 0.0, 1.0);
    }
)glsl";

const char* fragmentSource = R"glsl(
    #version 150 core
	in vec3 Color;
    out vec4 outColor;

    void main()
    {
        outColor = vec4(Color, 1.0);
    }
)glsl";
*/
Renderer::Renderer()
{
	//Inicializa las librerias de GLEW
	glewInit();
	/*
	GLfloat vertices[] = {
		-0.5f,  0.5f, 1.0f, // Top-left
		 0.5f,  0.5f, 0.0f, // Top-right
		 0.5f, -0.5f, 0.0f, // Bottom-right
		-0.5f, -0.5f, 1.0f // Bottom-left
	};

	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	static GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Un uint tiene un tamaño diferente dependiendo la plataforma que se use, el GLuint se adapta a la plataforma
	static GLuint VBO;
	//Genera buffers(la cantidad de buffers, especifica un array donde los buffers seran guardados)
	glGenBuffers(1, &VBO);
	//Lo enlaza al buffer creado(Especifica que va a contener el buffer, da el nombre del buffer)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Crea e inicializa el buffer(Especifica el objeto al cual el buffer esta enlazado,el tamaño que va a tener, el puntero, el patron de uso)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	static GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	static GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	static GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	static GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	static GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	*/
	// Variables de transformacion de vertices
	/*glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	// Variables de transformacion de vista y proyeccion
	glm::mat4 view = glm::lookAt(
		glm::vec3(1.2f, 1.2f, 1.2f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	GLint uniView = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));*/
}


Renderer::~Renderer()
{
}

void Renderer::AddShape(std::vector<Shape>& auxShapes)
{
	Shape _testSquare;

	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	GLint uniTrans = glGetUniformLocation(_testSquare.getShaderProgram(), "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	// Variables de transformacion de vista y proyeccion
	glm::mat4 view = glm::lookAt(
		glm::vec3(1.2f, 1.2f, 1.2f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	GLint uniView = glGetUniformLocation(_testSquare.getShaderProgram(), "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
	GLint uniProj = glGetUniformLocation(_testSquare.getShaderProgram(), "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));

	auxShapes.push_back(_testSquare);
}

void Renderer::WindowRefresh(GLFWwindow* window, std::vector<Shape>& auxShapes)
{
	//Crea el color con el que luego limpiar el buffer(RGBA)
	glClearColor(0.82, 0.420, 0.69, 1);
	//Limpia el buffer con el color creado
	glClear(GL_COLOR_BUFFER_BIT);
	//Reneriza las primitivas(Que primitivas renderizar, especifica el indice inicial, el numero de indices para ser renderizados )
	if (!auxShapes.empty())
	{
		for (shapeIterator = auxShapes.begin(); shapeIterator != auxShapes.end(); shapeIterator++)
			shapeIterator->DrawSelf();
	}
	//Invierte el buffer frontal y el de atras
	glfwSwapBuffers(window);
	//Esta funcion procesa solo los eventos que ya estan en la cola, el procesamiento de eventos hace que se invoquen las devoluciones de llamada de la ventana
	glfwPollEvents();
}
