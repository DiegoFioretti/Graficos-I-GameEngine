#include "Renderer.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

Renderer::Renderer()
{
	//??
	static glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));
	//Inicializa las librerias de GLEW
	glewInit();
	
	//Se le asignan los 3 vertices para crear el triangulo (X,Y,Z);
	static const GLfloat vertices[] = {
		0.0f, 1.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};

	//Un uint tiene un tamaño diferente dependiendo la plataforma que se use, el GLuint se adapta a la plataforma
	GLuint VBO;
	//Genera buffers(la cantidad de buffers, especifica un array donde los buffers seran guardados)
	glGenBuffers(1, &VBO);
	//Lo enlaza al buffer creado(Especifica que va a contener el buffer, da el nombre del buffer)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Crea e inicializa el buffer(Especifica el objeto al cual el buffer esta enlazado,el tamaño que va a tener, el puntero, el patron de uso)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//Activa el atributo generico de los vertices(Se especifica el indice)
	glEnableVertexAttribArray(0);
	//Define un array de atributos genericos para el vertice (
	glVertexAttribPointer(	0,			//Especifica el indice para ser modificado
							3,			//la cant de componentes
							GL_FLOAT,	//el tipo de dato
							GL_FALSE,	//si lo tiene que normalizar
							0,			//El es desplazamiento de bytes entre los atributos, si se ingresa 0 se entiende que tienen que estar comprimidos
							0);			//Es el desplazamiento del primer componente del primer vertice generico. Se inicializa en 0
}


Renderer::~Renderer()
{
}

void Renderer::WindowRefresh(GLFWwindow* window)
{
	//Crea el color con el que luego limpiar el buffer(RGBA)
	glClearColor(0.82, 0.420, 0.69, 1);
	//Limpia el buffer con el color creado
	glClear(GL_COLOR_BUFFER_BIT);
	//Reneriza las primitivas(Que primitivas renderizar, especifica el indice inicial, el numero de indices para ser renderizados )
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//Invierte el buffer frontal y el de atras
	glfwSwapBuffers(window);
	//Esta funcion procesa solo los eventos que ya estan en la cola, el procesamiento de eventos hace que se invoquen las devoluciones de llamada de la ventana
	glfwPollEvents();
}
