#version 430 core

in vec4 vs_fs_color;

layout (location = 0) out vec4 color;

void main(void)
{
    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);//vs_fs_color;
}
