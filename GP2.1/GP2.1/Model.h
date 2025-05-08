#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Model {
public:
    Model(const std::string& path);
    void Draw(Shader& shader);
private:
    unsigned int VAO, VBO;
    unsigned int vertexCount;
    void loadOBJ(const std::string& path);
};

#endif
