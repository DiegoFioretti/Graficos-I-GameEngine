#include "Renderer.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <ctime>
#include <iostream>

#include <array>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

// Shader sources
const GLchar* vertexSource = R"glsl(
#version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texcoord;

out vec4 Color;
out vec2 Texcoord;

uniform mat4 trans;

void main()
{
	gl_Position = trans * vec4(position, 0.0, 1.0);
    Color = color;
    Texcoord = texcoord;
}
)glsl";

const GLchar* fragmentSource = R"glsl(
    #version 330 core
    out vec4 outColor;

	in vec4 Color;
	in vec2 Texcoord;

	uniform sampler2D myTexture;

    void main()
    {
        outColor = texture(myTexture, Texcoord) * Color;
    }
)glsl";




Renderer::Renderer()
{
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/*// Create Vertex Array Object
	glGenVertexArrays(1, &vao);
	//binds the vertex array object
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo);
	//Specifies the target to which the buffer object is bound
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Create an element array
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	*/
	nEntity = 0;
}


Renderer::~Renderer()
{

}

void Renderer::addEntity(string& textloc) {
	if (nEntity < MAXENTITIES)
	{
		Entity simple;
		_gameEntities[nEntity] = simple;

		_gameEntities[nEntity].Initialize(textloc);

		//glBufferData(GL_ARRAY_BUFFER, sizeof(_gameEntities[nEntity].getVertices()), &_gameEntities[nEntity].getVertices(), GL_STATIC_DRAW);

		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_gameEntities[nEntity].getElements()), &_gameEntities[nEntity].getElements(), GL_STATIC_DRAW);

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

		//-------------------------------------------TRANSFORM-------------------------------------------------------
	/// Specify the layout of the vertex data
		GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);

		GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
		glEnableVertexAttribArray(colAttrib);
		glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
		glEnableVertexAttribArray(texAttrib);
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)(7 * sizeof(GLfloat)));

		uniTrans = glGetUniformLocation(shaderProgram, "trans");

		//-------------------------------------------TEXTURES-------------------------------------------------------
		/*unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(image, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

		glBindTexture(GL_TEXTURE_2D, texture);*/

		nEntity++;
	}
	else
	{
		cout << "ERROR: MAX AMOUNT OF ENTITIES REACHED" << endl;
	}
}



array<Entity, MAXENTITIES> Renderer::getGameEntities()
{
	return _gameEntities;
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

	if (nEntity > 0)
	{
		for (size_t i = 0; i < nEntity; i++)
		{		//posicion
			trans = glm::translate(trans, glm::vec3(_gameEntities[i].GetPositionX(), _gameEntities[i].GetPositionY(), _gameEntities[i].GetPositionZ()));
			//rotacion
			trans = glm::rotate(trans, glm::radians(_gameEntities[i].GetRotationX()), glm::vec3(0.0f, 1.0f, 0.0f));
			trans = glm::rotate(trans, glm::radians(_gameEntities[i].GetRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
			trans = glm::rotate(trans, glm::radians(_gameEntities[i].GetRotationZ()), glm::vec3(1.0f, 0.0f, 0.0f));
			//tamano
			trans = glm::scale(trans, glm::vec3(_gameEntities[i].GetScaleX(), _gameEntities[i].GetScaleY(), _gameEntities[i].GetScaleZ()));

			glm::vec4 result = trans * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
			glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
		}
	}
	
	//Invierte el buffer frontal y el de atras
	glfwSwapBuffers(window);
	//Esta funcion procesa solo los eventos que ya estan en la cola, el procesamiento de eventos hace que se invoquen las devoluciones de llamada de la ventana
	glfwPollEvents();
}

float Renderer::entityPosMod(bool& willChange, char& axis, int& entity, float& amount)
{
	if (willChange)
	{
		switch (axis)
		{
		case 'x':
			_gameEntities[entity].SetPositionX(amount);
			break;
		case 'y':
			_gameEntities[entity].SetPositionY(amount);
			break;
		case 'z':
			_gameEntities[entity].SetPositionZ(amount);
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
	else
	{
		switch (axis)
		{
		case 'x':
			return _gameEntities[entity].GetPositionX();
			break;
		case 'y':
			return _gameEntities[entity].GetPositionY();
			break;
		case 'z':
			return _gameEntities[entity].GetPositionZ();
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
}
float Renderer::entityScaleMod(bool& willChange, char& axis, int& entity, float& amount)
{
	if (willChange)
	{
		switch (axis)
		{
		case 'x':
			_gameEntities[entity].SetScaleX(amount);
			break;
		case 'y':
			_gameEntities[entity].SetScaleY(amount);
			break;
		case 'z':
			_gameEntities[entity].SetScaleZ(amount);
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
	else
	{
		switch (axis)
		{
		case 'x':
			return _gameEntities[entity].GetScaleX();
			break;
		case 'y':
			return _gameEntities[entity].GetScaleY();
			break;
		case 'z':
			return _gameEntities[entity].GetScaleZ();
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
}
float Renderer::entityRotMod(bool& willChange, char& axis, int& entity, float& amount)
{
	if (willChange)
	{
		switch (axis)
		{
		case 'x':
			_gameEntities[entity].SetRotationX(amount);
			break;
		case 'y':
			_gameEntities[entity].SetRotationY(amount);
			break;
		case 'z':
			_gameEntities[entity].SetRotationZ(amount);
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
	else
	{
		switch (axis)
		{
		case 'x':
			return _gameEntities[entity].GetRotationX();
			break;
		case 'y':
			return _gameEntities[entity].GetRotationY();
			break;
		case 'z':
			return _gameEntities[entity].GetRotationZ();
			break;
		default:
			cout << "Error: Non-existant axis" << endl;
			break;
		}
	}
}