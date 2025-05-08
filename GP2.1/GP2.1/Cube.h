#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>
#include "Shader.h"

class Cube {
public:
    Cube();
    void Draw(Shader& shader);
private:
    unsigned int VAO, VBO;
};

#endif
