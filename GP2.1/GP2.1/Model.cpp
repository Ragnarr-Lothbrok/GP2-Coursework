#include "Model.h"
#include <vector>
#include <fstream>
#include <sstream>

Model::Model(const std::string& path) {
    loadOBJ(path);
}

void Model::loadOBJ(const std::string& path) {
    std::vector<float> vertices;
    std::ifstream file(path);
    std::string line;
    std::vector<glm::vec3> temp_vertices;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string word;
        ss >> word;
        if (word == "v") {
            glm::vec3 v;
            ss >> v.x >> v.y >> v.z;
            temp_vertices.push_back(v);
        }
        else if (word == "f") {
            int a, b, c;
            ss >> a >> b >> c;
            for (int idx : {a - 1, b - 1, c - 1}) {
                vertices.push_back(temp_vertices[idx].x);
                vertices.push_back(temp_vertices[idx].y);
                vertices.push_back(temp_vertices[idx].z);
            }
        }
    }

    vertexCount = vertices.size() / 3;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Model::Draw(Shader& shader) {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
