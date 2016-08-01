#ifndef SHADOWMAP_H
#define SHADOWMAP_H

#include <QtWidgets/QWidget>
#include "ui_shadowmap.h"
#include "LoadShaders.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class shadowMap : public QGLWidget
{
	Q_OBJECT

public:
	shadowMap(QGLWidget *parent = 0);
	~shadowMap();
	void initializeGL();
	void paintGL();
	void DrawScene(bool depth_only);
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	Ui::shadowMapClass ui;
	 // Member variables
    float aspect;
    // Program to render from the light's position
    GLuint render_light_prog;
	 struct
    {
        GLint model_view_projection_matrix;
    } render_light_uniforms;
    GLuint  depth_fbo;
    GLuint  depth_texture;
    // Program to render the scene from the viewer's position
    GLuint render_scene_prog;
	 struct
    {
        GLint model_matrix;
        GLint view_matrix;
        GLint projection_matrix;
        GLint shadow_matrix;
        GLint light_position;
        GLint material_ambient;
        GLint material_diffuse;
        GLint material_specular;
        GLint material_specular_power;
    } render_scene_uniforms;
	 // Ground plane
    GLuint  ground_vbo;
    GLuint  ground_vao;
    VBObject object;
    GLint current_width;
    GLint current_height;
};

#endif // SHADOWMAP_H
