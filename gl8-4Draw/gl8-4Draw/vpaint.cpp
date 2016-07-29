#include "vpaint.h"
#include "vmath.h"
#include <iostream>
using namespace std;

VPaint::VPaint(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(5);
}

VPaint::~VPaint()
{
	glUseProgram(0);
    glDeleteProgram(render_prog);
    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(1, vbo);
}

void VPaint::initializeGL()
{
	setGeometry(200,100,640,480);
	if(glewInit())
	{
		cout << "Unable to init GLEW.... exiting" <<endl;
		exit(EXIT_FAILURE);
	}
	ShaderInfo shader_info[] =
    {
		{ GL_VERTEX_SHADER, "primitive_restart.vs.glsl" },
		{ GL_FRAGMENT_SHADER, "primitive_restart.fs.glsl" },
        { GL_NONE, NULL }
    };
    render_prog = LoadShaders(shader_info);
    glUseProgram(render_prog);
    // "model_matrix" 是四维矩阵
    render_model_matrix_loc = glGetUniformLocation(render_prog, "model_matrix");
    render_projection_matrix_loc = glGetUniformLocation(render_prog, "projection_matrix");

	static const GLfloat cube_positions[] =
    {
        -0.5f, -0.5f, -0.5f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f,
        -0.5f,  0.5f, -0.5f, 1.0f,
        -0.5f,  0.5f,  0.5f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f,
         0.5f, -0.5f,  0.5f, 1.0f,
         0.5f,  0.5f, -0.5f, 1.0f,
         0.5f,  0.5f,  0.5f, 1.0f
    };

    static const GLfloat cube_colors[] =
    {
        1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f
    };

    // Indices for the triangle strips
    static const GLushort cube_indices[] =
    {
        0, 1, 2, 3, 6, 7, 4, 5,         // First strip
        0xFFFF,                         // <<-- This is the restart index
        2, 6, 0, 4, 1, 5, 3, 7          // Second strip
    };
    // 设置元素数组缓存
    glGenBuffers(1, ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
		sizeof(cube_indices), 
		cube_indices, GL_STATIC_DRAW);
	// 设置顶点属性
    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, 
		sizeof(cube_positions) + sizeof(cube_colors),
		NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0,
		sizeof(cube_positions), cube_positions);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(cube_positions),
		sizeof(cube_colors), cube_colors);

    glVertexAttribPointer(0, 4, GL_FLOAT, 
		GL_FALSE, 0, NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, 
		GL_FALSE, 0, 
		(const GLvoid *)sizeof(cube_positions));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void VPaint::paintGL()
{
	//float t = float(GetTickCount() & 0x3FFFF) / float(0x3FFFF);
    //static float q = 0.0f;
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);
  
	//vmath::mat4 model_matrix;
    // Setup

    //glEnable(GL_CULL_FACE);
    //glDisable(GL_DEPTH_TEST);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Activate simple shading program
    glUseProgram(render_prog);
   // Set up the model and projection matrix
    vmath::mat4 model_matrix(vmath::translate(0.0f, 0.0f, -5.0f) * vmath::rotate(360.0f, Y) * vmath::rotate(720.0f, Z));
    vmath::mat4 projection_matrix(vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, 500.0f));

    glUniformMatrix4fv(render_model_matrix_loc, 4, GL_FALSE, model_matrix);
    glUniformMatrix4fv(render_projection_matrix_loc, 1, GL_FALSE, projection_matrix);

    // Set up for a glDrawElements call
    glBindVertexArray(vao[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);

    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, NULL);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT,
		(const GLvoid *)(9 * sizeof(GLushort)));
}

void VPaint::resizeGL(int w,int h)
{
	if(0 == h)
		h =1 ;
	glViewport(0,0,w,h);
	aspect = float(h) / float(w);
}

void VPaint::timerEvent(QTimerEvent *)
{
	updateGL();
}
