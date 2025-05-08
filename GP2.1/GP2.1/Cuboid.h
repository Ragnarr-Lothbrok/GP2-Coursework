#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Cuboid {
public:
    // Constructor that takes width, height, depth
    Cuboid(float width, float height, float depth);

    // Draw the cuboid using the given shader
    void Draw(Shader& shader);

private:
    unsigned int VAO, VBO;

    // Sets up the vertex data and buffers
    void setupCuboid(float width, float height, float depth);
};
