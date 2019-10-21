#include "Renderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Shader sources
const GLchar* vertexSource = R"glsl(
    #version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texcoord;

out vec3 Color;
out vec2 Texcoord;

uniform mat4 trans;

void main()
{
    Color = color;
    Texcoord = texcoord;
    gl_Position = trans * vec4(position, 0.0, 1.0);
}
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 330 core
    in vec3 Color;
	in vec2 textCoord;

    out vec4 outColor;

	uniform sampler2D myTexture;

    void main()
    {
        outColor = texture(myTexture, textCoord) * vec4(Color, 1.0);
    }
)glsl";



Renderer::Renderer()
{

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	/*
	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	GLfloat vertices[] = {
		//  Position            Color             Texcoords
<<<<<<< HEAD
			-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // Top-left
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Top-right
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Bottom-right
=======
			-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, // Bottom-right
>>>>>>> Shape
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f  // Bottom-left
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create an element array
	GLuint ebo;
	glGenBuffers(1, &ebo);

	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
//-------------------------------------------SHADERS-------------------------------------------------------
	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
//-------------------------------------------TEXTURES-------------------------------------------------------
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load("../texture.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		std::cout << "Width "<< width << std::endl;
		std::cout << "Height "<< height<< std::endl;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//-------------------------------------------TRANSFORM-------------------------------------------------------
	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));


	uniTrans = glGetUniformLocation(shaderProgram, "trans");
	
	*/
}


Renderer::~Renderer()
{
}

void Renderer::newShape() {
	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	Shape shaper;

	/*GLfloat veatrices[] = {
		//  Position            Color             Texcoords
			-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, // Bottom-right
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f  // Bottom-left
	};*/
	
	GLfloat vertices[SIZESQV];

	shaper.setSquareVertex(vertices);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create an element array
	GLuint ebo;
	glGenBuffers(1, &ebo);

	/*GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};*/

	GLuint elements[SIZESQE];

	shaper.setSquareElements(elements);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));


	uniTrans = glGetUniformLocation(shaderProgram, "trans");
}

void Renderer::WindowRefresh(GLFWwindow* window)
{
	if (chronoAct)
	{
		auto t_start = std::chrono::high_resolution_clock::now();
		chronoAct = false;
	}

	//Crea el color con el que luego limpiar el buffer(RGBA)
	glClearColor(135.f/255.f, 135.f / 255.f, 135.f / 255.f, 1);
	//Limpia el buffer con el color creado
	glClear(GL_COLOR_BUFFER_BIT);
	//Reneriza las primitivas(Que primitivas renderizar, especifica el indice inicial, el numero de indices para ser renderizados )
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glm::mat4 trans = glm::mat4(1.0f);
	//posicion
	trans = glm::translate(trans, glm::vec3(posicionX, posicionY, posicionZ));
	//rotacion
	trans = glm::rotate(trans, glm::radians(rotateZ), glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::rotate(trans, glm::radians(rotateY), glm::vec3(0.0f, 1.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(rotateX), glm::vec3(1.0f, 0.0f, 0.0f));
	//tamano
	trans = glm::scale(trans, glm::vec3(sizeX, sizeY, sizeZ));

	glm::vec4 result = trans * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
	
	//Invierte el buffer frontal y el de atras
	glfwSwapBuffers(window);
	//Esta funcion procesa solo los eventos que ya estan en la cola, el procesamiento de eventos hace que se invoquen las devoluciones de llamada de la ventana
	glfwPollEvents();
}
