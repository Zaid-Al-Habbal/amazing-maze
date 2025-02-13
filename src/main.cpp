#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <bits/stdc++.h>

#include <shader_s.h>
#include <stb_image.h>
#include <filesystem.h>
#include <camera.h>
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"

void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
float vis = 0.01, red = 0.3, blue = 0.2, green = 0.4;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;


// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback); 
    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    
    
    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader program:
    Shader ourShader("../src/shaders/shader.vs", "../src/shaders/shader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes:
float vertices[] = {
        //positions          //colors           //texture
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,   0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };

    Texture containerTex("../resources/textures/pattern.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    containerTex.texUnit(ourShader, "tex1", 0);

    Texture awesomefaceTex("../resources/textures/awesomeface.png", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
    awesomefaceTex.texUnit(ourShader, "tex2", 1);
    stbi_set_flip_vertically_on_load(true);
    
    // Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	// EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	// EBO1.Unbind();

    //  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    ourShader.use();
            
    glm::vec3 cubePositions[] = {
        //front wall:
        glm::vec3( 1.0f,  0.0f,  0.0f), 
        // glm::vec3( 2.0f,  0.0f,  0.0f), 
        glm::vec3( 3.0f,  0.0f,  0.0f), 
        glm::vec3( 4.0f,  0.0f,  0.0f), 
        glm::vec3( 5.0f,  0.0f,  0.0f), 
        glm::vec3( 6.0f,  0.0f,  0.0f), 
        glm::vec3( 7.0f,  0.0f,  0.0f), 
        glm::vec3( 8.0f,  0.0f,  0.0f), 
        glm::vec3( 9.0f,  0.0f,  0.0f), 
        glm::vec3( 10.0f,  0.0f,  0.0f), 
        glm::vec3( 11.0f,  0.0f,  0.0f),
        glm::vec3( 12.0f,  0.0f,  0.0f),
        glm::vec3( 13.0f,  0.0f,  0.0f),
        glm::vec3( 14.0f,  0.0f,  0.0f),
        glm::vec3( 15.0f,  0.0f,  0.0f),

        //left wall:
        glm::vec3( 1.0f, 0.0f, -1.0f),
        glm::vec3( 1.0f, 0.0f, -2.0f),  
        glm::vec3( 1.0f, 0.0f, -3.0f),
        glm::vec3( 1.0f, 0.0f, -4.0f),
        glm::vec3( 1.0f, 0.0f, -5.0f),
        glm::vec3( 1.0f, 0.0f, -6.0f),
        glm::vec3( 1.0f, 0.0f, -7.0f),
        glm::vec3( 1.0f, 0.0f, -8.0f),
        glm::vec3( 1.0f, 0.0f, -9.0f),
        glm::vec3( 1.0f, 0.0f, -10.0f),
        glm::vec3( 1.0f, 0.0f, -11.0f),
        glm::vec3( 1.0f, 0.0f, -12.0f), 
        glm::vec3( 1.0f, 0.0f, -13.0f), 
        glm::vec3( 1.0f, 0.0f, -14.0f), 
        glm::vec3( 1.0f, 0.0f, -15.0f), 
        glm::vec3( 1.0f, 0.0f, -16.0f), 

        //back wall
        glm::vec3( 1.0f, 0.0f, -16.0f),
        glm::vec3( 2.0f, 0.0f, -16.0f), 
        glm::vec3( 3.0f, 0.0f, -16.0f), 
        glm::vec3( 4.0f, 0.0f, -16.0f), 
        glm::vec3( 5.0f, 0.0f, -16.0f), 
        glm::vec3( 5.0f, 0.0f, -16.0f), 
        glm::vec3( 6.0f, 0.0f, -16.0f), 
        glm::vec3( 7.0f, 0.0f, -16.0f), 
        glm::vec3( 8.0f, 0.0f, -16.0f), 
        glm::vec3( 9.0f, 0.0f, -16.0f), 
        glm::vec3( 10.0f, 0.0f, -16.0f), 
        glm::vec3( 11.0f, 0.0f, -16.0f),  
        glm::vec3( 12.0f, 0.0f, -16.0f),  
        glm::vec3( 13.0f, 0.0f, -16.0f),  
        // glm::vec3( 14.0f, 0.0f, -16.0f),
        glm::vec3( 15.0f, 0.0f, -16.0f),  

        //right wall:
        glm::vec3( 15.0f, 0.0f, -15.0f),  
        glm::vec3( 15.0f, 0.0f, -14.0f),  
        glm::vec3( 15.0f, 0.0f, -13.0f),  
        glm::vec3( 15.0f, 0.0f, -12.0f),  
        glm::vec3( 15.0f, 0.0f, -11.0f),  
        glm::vec3( 15.0f, 0.0f, -10.0f),  
        glm::vec3( 15.0f, 0.0f, -9.0f),  
        glm::vec3( 15.0f, 0.0f, -8.0f),  
        glm::vec3( 15.0f, 0.0f, -7.0f),  
        glm::vec3( 15.0f, 0.0f, -6.0f),  
        glm::vec3( 15.0f, 0.0f, -5.0f),  
        glm::vec3( 15.0f, 0.0f, -4.0f),  
        glm::vec3( 15.0f, 0.0f, -3.0f),  
        glm::vec3( 15.0f, 0.0f, -2.0f),  
        glm::vec3( 15.0f, 0.0f, -1.0f),

        //second right wall:
        glm::vec3( 13.0f, 0.0f, -15.0f),  
        // glm::vec3( 13.0f, 0.0f, -14.0f),  
        glm::vec3( 13.0f, 0.0f, -13.0f),  
        glm::vec3( 13.0f, 0.0f, -12.0f),  
        // glm::vec3( 13.0f, 0.0f, -11.0f),  
        // glm::vec3( 13.0f, 0.0f, -10.0f),  
        glm::vec3( 13.0f, 0.0f, -9.0f),  
        glm::vec3( 13.0f, 0.0f, -8.0f),  
        glm::vec3( 13.0f, 0.0f, -7.0f),  
        glm::vec3( 13.0f, 0.0f, -6.0f),  
        glm::vec3( 13.0f, 0.0f, -5.0f),  
        // glm::vec3( 13.0f, 0.0f, -4.0f),  
        glm::vec3( 13.0f, 0.0f, -3.0f),  
        glm::vec3( 13.0f, 0.0f, -2.0f),  
        glm::vec3( 13.0f, 0.0f, -1.0f),  

        //third right wall:
        glm::vec3( 11.0f, 0.0f, -15.0f),  
        // glm::vec3( 11.0f, 0.0f, -14.0f),  
        glm::vec3( 11.0f, 0.0f, -13.0f),  
        glm::vec3( 11.0f, 0.0f, -12.0f),  
        glm::vec3( 11.0f, 0.0f, -11.0f),  
        // glm::vec3( 11.0f, 0.0f, -10.0f),  
        glm::vec3( 11.0f, 0.0f, -9.0f),  
        glm::vec3( 11.0f, 0.0f, -8.0f),  
        // glm::vec3( 11.0f, 0.0f, -7.0f),  
        glm::vec3( 11.0f, 0.0f, -6.0f),  
        glm::vec3( 11.0f, 0.0f, -5.0f),  
        glm::vec3( 11.0f, 0.0f, -4.0f),  
        glm::vec3( 11.0f, 0.0f, -3.0f),  
        glm::vec3( 11.0f, 0.0f, -2.0f),  
        glm::vec3( 11.0f, 0.0f, -1.0f),

        //forth right wall:
        // glm::vec3( 9.0f, 0.0f, -15.0f),  
        glm::vec3( 9.0f, 0.0f, -14.0f),  
        glm::vec3( 9.0f, 0.0f, -13.0f),  
        // glm::vec3( 9.0f, 0.0f, -12.0f),  
        glm::vec3( 9.0f, 0.0f, -11.0f),  
        // glm::vec3( 9.0f, 0.0f, -10.0f),  
        // glm::vec3( 9.0f, 0.0f, -9.0f),  
        glm::vec3( 9.0f, 0.0f, -8.0f),  
        // glm::vec3( 9.0f, 0.0f, -7.0f),  
        glm::vec3( 9.0f, 0.0f, -6.0f),  
        glm::vec3( 9.0f, 0.0f, -5.0f),  
        glm::vec3( 9.0f, 0.0f, -4.0f),  
        // glm::vec3( 9.0f, 0.0f, -3.0f),  
        glm::vec3( 9.0f, 0.0f, -2.0f),  
        glm::vec3( 9.0f, 0.0f, -1.0f),

        //fifth right wall:
        glm::vec3( 7.0f, 0.0f, -15.0f),  
        glm::vec3( 7.0f, 0.0f, -14.0f),  
        glm::vec3( 7.0f, 0.0f, -13.0f),  
        // glm::vec3( 7.0f, 0.0f, -12.0f),  
        glm::vec3( 7.0f, 0.0f, -11.0f),  
        glm::vec3( 7.0f, 0.0f, -10.0f),  
        // glm::vec3( 7.0f, 0.0f, -9.0f),  
        glm::vec3( 7.0f, 0.0f, -8.0f),  
        // glm::vec3( 7.0f, 0.0f, -7.0f),  
        glm::vec3( 7.0f, 0.0f, -6.0f),  
        glm::vec3( 7.0f, 0.0f, -5.0f),  
        glm::vec3( 7.0f, 0.0f, -4.0f),  
        // glm::vec3( 7.0f, 0.0f, -3.0f),  
        glm::vec3( 7.0f, 0.0f, -2.0f),  
        glm::vec3( 7.0f, 0.0f, -1.0f),

        //sixth right wall:
        glm::vec3( 5.0f, 0.0f, -15.0f),  
        glm::vec3( 5.0f, 0.0f, -14.0f),  
        // glm::vec3( 5.0f, 0.0f, -13.0f),  
        glm::vec3( 5.0f, 0.0f, -12.0f),  
        // glm::vec3( 5.0f, 0.0f, -11.0f),  
        glm::vec3( 5.0f, 0.0f, -10.0f),  
        glm::vec3( 5.0f, 0.0f, -9.0f),  
        glm::vec3( 5.0f, 0.0f, -8.0f),  
        // glm::vec3( 5.0f, 0.0f, -7.0f),  
        glm::vec3( 5.0f, 0.0f, -6.0f),  
        glm::vec3( 5.0f, 0.0f, -5.0f),  
        glm::vec3( 5.0f, 0.0f, -4.0f),  
        // glm::vec3( 5.0f, 0.0f, -3.0f),  
        glm::vec3( 5.0f, 0.0f, -2.0f),  
        glm::vec3( 5.0f, 0.0f, -1.0f),

        //seventh right wall:
        glm::vec3( 3.0f, 0.0f, -15.0f),  
        // glm::vec3( 3.0f, 0.0f, -14.0f),  
        glm::vec3( 3.0f, 0.0f, -13.0f),  
        // glm::vec3( 3.0f, 0.0f, -12.0f),  
        glm::vec3( 3.0f, 0.0f, -11.0f),  
        glm::vec3( 3.0f, 0.0f, -10.0f),  
        glm::vec3( 3.0f, 0.0f, -9.0f),  
        glm::vec3( 3.0f, 0.0f, -8.0f),  
        // glm::vec3( 3.0f, 0.0f, -7.0f),  
        glm::vec3( 3.0f, 0.0f, -6.0f),  
        glm::vec3( 3.0f, 0.0f, -5.0f),  
        glm::vec3( 3.0f, 0.0f, -4.0f),  
        // glm::vec3( 3.0f, 0.0f, -3.0f),  
        glm::vec3( 3.0f, 0.0f, -2.0f),  
        // glm::vec3( 3.0f, 0.0f, -1.0f),

        //second front wall:-
        glm::vec3( 1.0f,  0.0f,  -2.0f), 
        // glm::vec3( 2.0f,  0.0f,  -2.0f), 
        glm::vec3( 3.0f,  0.0f,  -2.0f), 
        // glm::vec3( 4.0f,  0.0f,  -2.0f), 
        glm::vec3( 5.0f,  0.0f,  -2.0f), 
        glm::vec3( 6.0f,  0.0f,  -2.0f), 
        glm::vec3( 7.0f,  0.0f,  -2.0f), 
        // glm::vec3( 8.0f,  0.0f,  -2.0f), 
        glm::vec3( 9.0f,  0.0f,  -2.0f), 
        // glm::vec3( 10.0f,  0.0f, -2.0f), 
        glm::vec3( 11.0f,  0.0f, -2.0f),
        glm::vec3( 12.0f,  0.0f, -2.0f),
        // glm::vec3( 13.0f,  0.0f, -2.0f),
        glm::vec3( 14.0f,  0.0f, -2.0f),
        glm::vec3( 15.0f,  0.0f, -2.0f),

        //third front wall-:
        glm::vec3( 1.0f,  0.0f,  -4.0f), 
        // glm::vec3( 2.0f,  0.0f,  -4.0f), 
        glm::vec3( 3.0f,  0.0f,  -4.0f), 
        glm::vec3( 4.0f,  0.0f,  -4.0f), 
        // glm::vec3( 5.0f,  0.0f,  -4.0f), 
        glm::vec3( 6.0f,  0.0f,  -4.0f), 
        glm::vec3( 7.0f,  0.0f,  -4.0f), 
        // glm::vec3( 8.0f,  0.0f,  -4.0f), 
        glm::vec3( 9.0f,  0.0f,  -4.0f), 
        glm::vec3( 10.0f,  0.0f, -4.0f), 
        // glm::vec3( 11.0f,  0.0f, -4.0f),
        glm::vec3( 12.0f,  0.0f, -4.0f),
        glm::vec3( 13.0f,  0.0f, -4.0f),
        // glm::vec3( 14.0f,  0.0f, -4.0f),
        glm::vec3( 15.0f,  0.0f, -4.0f),

        //forth front wall:
        glm::vec3( 1.0f,  0.0f,  -6.0f), 
        glm::vec3( 2.0f,  0.0f,  -6.0f), 
        // glm::vec3( 3.0f,  0.0f,  -6.0f), 
        glm::vec3( 4.0f,  0.0f,  -6.0f), 
        // glm::vec3( 5.0f,  0.0f,  -6.0f), 
        glm::vec3( 6.0f,  0.0f,  -6.0f), 
        glm::vec3( 7.0f,  0.0f,  -6.0f), 
        // glm::vec3( 8.0f,  0.0f,  -6.0f), 
        glm::vec3( 9.0f,  0.0f,  -6.0f), 
        glm::vec3( 10.0f,  0.0f, -6.0f), 
        // glm::vec3( 11.0f,  0.0f, -6.0f),
        glm::vec3( 12.0f,  0.0f, -6.0f),
        glm::vec3( 13.0f,  0.0f, -6.0f),
        // glm::vec3( 14.0f,  0.0f, -6.0f),
        glm::vec3( 15.0f,  0.0f, -6.0f),

        //fifth front wall:
        glm::vec3( 1.0f,  0.0f,  -8.0f), 
        glm::vec3( 2.0f,  0.0f,  -8.0f), 
        glm::vec3( 3.0f,  0.0f,  -8.0f), 
        // glm::vec3( 4.0f,  0.0f,  -8.0f), 
        glm::vec3( 5.0f,  0.0f,  -8.0f), 
        // glm::vec3( 6.0f,  0.0f,  -8.0f), 
        glm::vec3( 7.0f,  0.0f,  -8.0f), 
        glm::vec3( 8.0f,  0.0f,  -8.0f), 
        // glm::vec3( 9.0f,  0.0f,  -8.0f), 
        glm::vec3( 10.0f,  0.0f, -8.0f), 
        glm::vec3( 11.0f,  0.0f, -8.0f),
        glm::vec3( 12.0f,  0.0f, -8.0f),
        glm::vec3( 13.0f,  0.0f, -8.0f),
        // glm::vec3( 14.0f,  0.0f, -8.0f),
        glm::vec3( 15.0f,  0.0f, -8.0f),

        //sixth front wall:
        glm::vec3( 1.0f,  0.0f,  -10.0f), 
        glm::vec3( 2.0f,  0.0f,  -10.0f), 
        // glm::vec3( 3.0f,  0.0f,  -10.0f), 
        glm::vec3( 4.0f,  0.0f,  -10.0f), 
        glm::vec3( 5.0f,  0.0f,  -10.0f), 
        // glm::vec3( 6.0f,  0.0f,  -10.0f), 
        glm::vec3( 7.0f,  0.0f,  -10.0f), 
        // glm::vec3( 8.0f,  0.0f,  -10.0f), 
        glm::vec3( 9.0f,  0.0f,  -10.0f), 
        // glm::vec3( 10.0f,  0.0f, -10.0f), 
        glm::vec3( 11.0f,  0.0f, -10.0f),
        glm::vec3( 12.0f,  0.0f, -10.0f),
        glm::vec3( 13.0f,  0.0f, -10.0f),
        // glm::vec3( 14.0f,  0.0f, -10.0f),
        glm::vec3( 15.0f,  0.0f, -10.0f),

        //seventh front wall:
        glm::vec3( 1.0f,  0.0f,  -12.0f), 
        // glm::vec3( 2.0f,  0.0f,  -12.0f), 
        glm::vec3( 3.0f,  0.0f,  -12.0f), 
        glm::vec3( 4.0f,  0.0f,  -12.0f), 
        // glm::vec3( 5.0f,  0.0f,  -12.0f), 
        glm::vec3( 6.0f,  0.0f,  -12.0f), 
        glm::vec3( 7.0f,  0.0f,  -12.0f), 
        // glm::vec3( 8.0f,  0.0f,  -12.0f), 
        glm::vec3( 9.0f,  0.0f,  -12.0f), 
        glm::vec3( 10.0f,  0.0f, -12.0f), 
        glm::vec3( 11.0f,  0.0f, -12.0f),
        // glm::vec3( 12.0f,  0.0f, -12.0f),
        glm::vec3( 13.0f,  0.0f, -12.0f),
        glm::vec3( 14.0f,  0.0f, -12.0f),
        glm::vec3( 15.0f,  0.0f, -12.0f),
    }; 
    unsigned int n = sizeof(cubePositions) / sizeof(cubePositions[0]);
    while(!glfwWindowShouldClose(window)){

        // per-frame time logic
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        processInput(window);

        // render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        // activate shader
        ourShader.setFloat("visibility", vis);
        ourShader.setFloat("red", red);
        ourShader.setFloat("blue", blue);
        ourShader.setFloat("green", green);

        awesomefaceTex.Bind(); 
        containerTex.Bind();
        VAO1.Bind();

        for (unsigned int i = 0; i < n ; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    // Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	// EBO1.Delete();
    containerTex.Delete();
    awesomefaceTex.Delete();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        vis = (vis>=0.999) ? 1.0f : vis+0.001f;
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        vis = (vis<=0.001) ? 0.0f : vis-0.001f;
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        blue = (blue>=0.999) ? 1.0f : blue+0.001f;
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
        blue = (blue<=0.001) ? 0.0f : blue-0.001f;
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        red = (red>=0.999) ? 1.0f : red+0.001f;
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        red = (red<=0.001) ? 0.0f : red-0.001f;
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        green = (green>=0.999) ? 1.0f : green+0.001f;
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        green = (green<=0.001) ? 0.0f : green-0.001f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}  

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}