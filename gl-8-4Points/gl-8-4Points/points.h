#ifndef POINTS_H
#define POINTS_H

#include <QtWidgets/QWidget>
#include "ui_points.h"
#include "LoadShaders.h"
#include "vmath.h"
#include <qgl.h>
class Points : public QGLWidget
{
	Q_OBJECT

public:
	Points(QGLWidget *parent = 0);
	~Points();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);
private:
	Ui::PointsClass ui;
	// Member variables
    float aspect;
    GLuint render_prog;
    GLuint vao[1];
    GLuint vbo[1];
    GLuint sprite_texture;
    GLint render_model_matrix_loc;
    GLint render_projection_matrix_loc;
};

#endif // POINTS_H
