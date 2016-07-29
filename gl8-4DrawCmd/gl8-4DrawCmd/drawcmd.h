#ifndef DRAWCMD_H
#define DRAWCMD_H

#include <QtWidgets/QWidget>
#include "ui_drawcmd.h"
#include "LoadShaders.h"
#include "vmath.h"
#include <qgl.h>
class DrawCmd : public QGLWidget
{
	Q_OBJECT

public:
	DrawCmd(QGLWidget *parent = 0);
	~DrawCmd();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
private:
	Ui::DrawCmdClass ui;
	// Member variables
    float aspect;
    GLuint render_prog;
    GLuint vao[1];
    GLuint vbo[1];
    GLuint ebo[1];

	GLuint pos_buf;
	GLuint col_buf;
    GLint render_model_matrix_loc;
    GLint render_projection_matrix_loc;
};

#endif // DRAWCMD_H
