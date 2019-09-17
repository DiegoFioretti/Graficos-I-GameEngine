#include "Shape.h"

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

Shape::Shape()
{
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

	glGenVertexArrays(1, &_vertexArrayObject);
	glBindVertexArray(_vertexArrayObject);

	//Un uint tiene un tamaño diferente dependiendo la plataforma que se use, el GLuint se adapta a la plataforma
	//Genera buffers(la cantidad de buffers, especifica un array donde los buffers seran guardados)
	glGenBuffers(1, &_vertexBufferObject);
	//Lo enlaza al buffer creado(Especifica que va a contener el buffer, da el nombre del buffer)
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
	//Crea e inicializa el buffer(Especifica el objeto al cual el buffer esta enlazado,el tamaño que va a tener, el puntero, el patron de uso)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_elementBuferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &vertexSource, NULL);
	glCompileShader(_vertexShader);

	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(_fragmentShader);

	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, _vertexShader);
	glAttachShader(_shaderProgram, _fragmentShader);
	glBindFragDataLocation(_shaderProgram, 0, "outColor");
	glLinkProgram(_shaderProgram);
	glUseProgram(_shaderProgram);

	static GLint posAttrib = glGetAttribLocation(_shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	static GLint colAttrib = glGetAttribLocation(_shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

Shape::~Shape()
{
}

void Shape::DrawSelf() 
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

GLuint Shape::getShaderProgram() 
{
	return _shaderProgram;
}