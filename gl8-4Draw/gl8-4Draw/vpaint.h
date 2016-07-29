#ifndef VPAINT_H
#define VPAINT_H

#include <QtWidgets/QWidget>
#include "ui_vpaint.h"
#include "LoadShaders.h"
#include <QtOpenGL/qgl.h>
class VPaint : public QGLWidget
{
	Q_OBJECT

public:
	VPaint(QGLWidget *parent = 0);
	~VPaint();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);
private:
	Ui::VPaintClass ui;
	//for draw
	float aspect;
    GLuint render_prog;
    GLuint ebo[1];
    GLuint vao[1];
    GLuint vbo[1];

    GLint render_model_matrix_loc;
    GLint render_projection_matrix_loc;
};

#endif // VPAINT_H
