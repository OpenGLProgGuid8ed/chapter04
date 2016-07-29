#include "points.h"
#include <iostream>
using namespace std;
#define POINT_COUNT 4
namespace vtarga {
unsigned char * load_targa(const char * filename)
{
	unsigned char * data;
	if (filename == NULL)
     {
         return false;
     }
	 // read volume data from file
	 FILE *fp = fopen(filename, "r");
	 fp = fopen(filename, "rb");
	 if(fp == NULL) {
		 cout<<"Can't open data file "<<filename<<endl;
		 return false;
	 }

	 data = new unsigned char[64*64*4];
	 fread(data, sizeof(unsigned char), 64*64*4, fp);
	 fclose(fp);
	 unsigned char str[64][64][4];
	 for(int i =0;i<64;i++)
		 for(int j = 0;j<64;j++)
			 for(int k = 0;k<4;k++)
				 str[i][j][k] = data[i*64+j*64+k];
	 return data;
}
};
static inline float random_float()
{
    float res;
    unsigned int tmp;
    static unsigned int seed = 0x13371337;
    seed *= 16807;
    tmp = seed ^ (seed >> 4) ^ (seed << 15);
    *((unsigned int *) &res) = (tmp >> 9) | 0x3F800000;
    return (res - 1.0f);
}
Points::Points(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

Points::~Points()
{

}

void Points::initializeGL()
{
	if(glewInit())
	{
		cout<<"Unable to Init GLEW"<<endl;
		exit(EXIT_FAILURE);
	}
	GLenum format = GL_RGBA;
    int width=64, height=64;
	unsigned char * data;
    glGenTextures(1, &sprite_texture);
    glBindTexture(GL_TEXTURE_2D, sprite_texture);
    data = vtarga::load_targa("sprite.tga");
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    delete [] data;
    glGenerateMipmap(GL_TEXTURE_2D);
    static ShaderInfo shader_info[] =
    {
        { GL_VERTEX_SHADER, "pointsprites.vs.glsl"},
        { GL_FRAGMENT_SHADER, "pointsprites.fs.glsl"},
        { GL_NONE, NULL,}
    };
    render_prog = LoadShaders(shader_info);
    glUseProgram(render_prog);
    render_model_matrix_loc = glGetUniformLocation(render_prog, "model_matrix");
    render_projection_matrix_loc = glGetUniformLocation(render_prog, "projection_matrix");
    static vmath::vec4 * vertex_positions;

    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);
    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, POINT_COUNT * sizeof(vmath::vec4), NULL, GL_STATIC_DRAW);

    vertex_positions = (vmath::vec4 *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    for (int n = 0; n < POINT_COUNT; n++)
    {
        vertex_positions[n] = vmath::vec4(random_float() * 2.0f - 1.0f, random_float() * 2.0f - 1.0f, random_float() * 2.0f - 1.0f, 1.0f);
    }
    glUnmapBuffer(GL_ARRAY_BUFFER);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)sizeof(vertex_positions));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Points::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
	float t = float(GetTickCount() & 0x1FFF) / float(0x1FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

    vmath::mat4 model_matrix;
    // Activate simple shading program
    glUseProgram(render_prog);
    vmath::mat4 projection_matrix(vmath::frustum(-1.0f, 1.0f, -aspect, aspect, 1.0f, 8.0f));
    glUniformMatrix4fv(render_projection_matrix_loc, 1, GL_FALSE, projection_matrix);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glPointSize(32.0f);

    // Draw Arrays...
    model_matrix = vmath::translate(0.0f, 0.0f, -2.0f) *
                   vmath::rotate(t * 360.0f, Y) * vmath::rotate(t * 720.0f, Z);
    glUniformMatrix4fv(render_model_matrix_loc, 1, GL_FALSE, model_matrix);
    glDrawArrays(GL_POINTS, 0, POINT_COUNT);
}

void Points::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	glViewport(0,0,w,h);
	aspect = float(h)/float(w);
	glLoadIdentity();
}

void Points::timerEvent(QTimerEvent*)
{
	updateGL();
}