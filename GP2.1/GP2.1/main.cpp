#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Texture.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "3D Textured Objects", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -1;

    glEnable(GL_DEPTH_TEST);

    Shader shader("shader.vert", "shader.frag");

    Cube cube;
    Cuboid cuboid(2.0f, 1.0f, 1.0f);
    Sphere sphere;

    // Load textures
    unsigned int cubeTex = LoadTexture("Textures/cube_texture.jpg");
    unsigned int cuboidTex = LoadTexture("Textures/cuboid_texture.jpg");
    unsigned int sphereTex = LoadTexture("Textures/sphere_texture.jpg");

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        float angle = glfwGetTime();
        float radius = 15.0f;
        glm::vec3 camPos = glm::vec3(sin(angle) * radius, 0.0f, cos(angle) * radius);
        glm::mat4 view = glm::lookAt(camPos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
            (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);

        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        // Draw Cube (top)
        glBindTexture(GL_TEXTURE_2D, cubeTex);  // Texture unit 0 is default
        glm::mat4 model1 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 3.0f, 0.0f));
        shader.setMat4("model", model1);
        cube.Draw(shader);

        // Draw Cuboid (middle)
        glBindTexture(GL_TEXTURE_2D, cuboidTex);
        glm::mat4 model2 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        shader.setMat4("model", model2);
        cuboid.Draw(shader);

        // Draw Sphere (bottom)
        glBindTexture(GL_TEXTURE_2D, sphereTex);
        glm::mat4 model3 = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -3.0f, 0.0f));
        shader.setMat4("model", model3);
        sphere.Draw(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
