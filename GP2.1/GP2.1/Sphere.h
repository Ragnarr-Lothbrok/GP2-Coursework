#ifndef SPHERE_H
#define SPHERE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Sphere {
public:
    Sphere(unsigned int segments = 32, unsigned int rings = 16);
    void Draw(Shader& shader);
private:
    unsigned int VAO, VBO, indexCount;
};

#endif
