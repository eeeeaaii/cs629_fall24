#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "color.h"
#include "frame.h"

class Renderer {
 private:
  GLFWwindow *window;

  GLuint vao;
  GLuint vbo;
  GLuint tex;

  bool initGL(GLfloat *tex_data);
  std::vector<GLfloat> getTextureData(const Frame &frame);

 public:
  void changeFrame(const Frame &frame);
  bool init(const Frame &frame);
  bool render();
};