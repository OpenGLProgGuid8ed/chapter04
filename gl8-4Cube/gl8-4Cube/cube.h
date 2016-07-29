#ifndef CUBE_H
#define CUBE_H

#include <QtWidgets/QWidget>
#include "ui_cube.h"
#include "LoadShaders.h"
#include "vmath.h"
#include <qgl.h>
class Cube : public QGLWidget
{
	Q_OBJECT

public:
	Cube(QGLWidget *parent = 0);
	~Cube();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);

private:
	Ui::CubeClass ui;
	// Member variables
    float aspect;
    GLuint render_prog;
    GLuint vao[1];
    GLuint vbo[1];
    GLuint ebo[1];
    GLint render_model_matrix_loc;
    GLint render_projection_matrix_loc;
};

#endif // CUBE_H
