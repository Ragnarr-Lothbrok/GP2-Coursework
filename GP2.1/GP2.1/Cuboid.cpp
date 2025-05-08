#include "Cuboid.h"

Cuboid::Cuboid(float width, float height, float depth) {
    setupCuboid(width, height, depth);
}

void Cuboid::setupCuboid(float w, float h, float d) {
    float vertices[] = {
        // Front face
        -w / 2, -h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
         w / 2, -h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
         w / 2,  h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
         w / 2,  h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
        -w / 2,  h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
        -w / 2, -h / 2,  d / 2,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

        // Back face
        -w / 2, -h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
        -w / 2,  h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
         w / 2,  h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         w / 2,  h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         w / 2, -h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
        -w / 2, -h / 2, -d / 2,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        // Left face
        -w / 2,  h / 2,  d / 2, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -w / 2,  h / 2, -d / 2, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -w / 2, -h / 2, -d / 2, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -w / 2, -h / 2, -d / 2, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -w / 2, -h / 2,  d / 2, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -w / 2,  h / 2,  d / 2, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        // Right face
         w / 2,  h / 2,  d / 2,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         w / 2, -h / 2, -d / 2,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         w / 2,  h / 2, -d / 2,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         w / 2, -h / 2, -d / 2,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         w / 2,  h / 2,  d / 2,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         w / 2, -h / 2,  d / 2,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

         // Bottom face
         -w / 2, -h / 2, -d / 2,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
          w / 2, -h / 2, -d / 2,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
          w / 2, -h / 2,  d / 2,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
          w / 2, -h / 2,  d / 2,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
         -w / 2, -h / 2,  d / 2,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
         -w / 2, -h / 2, -d / 2,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

         // Top face
         -w / 2,  h / 2, -d / 2,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         -w / 2,  h / 2,  d / 2,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
          w / 2,  h / 2,  d / 2,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
          w / 2,  h / 2,  d / 2,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
          w / 2,  h / 2, -d / 2,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         -w / 2,  h / 2, -d / 2,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture coordinate
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Cuboid::Draw(Shader& shader) {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
