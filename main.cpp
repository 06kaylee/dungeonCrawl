// Main.cpp
#include <GLFW/glfw3.h>
#include <math.h>

using namespace std;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "DUNGEON", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    const float DEG2RAD = 3.14159 / 180;
    float radi = .1;
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / float(height);
        glViewport(0,0,width,height);
        // zeros out the screen? 
        glClear(GL_COLOR_BUFFER_BIT);
        
        //drawing 
        glBegin(GL_LINE_STRIP);
            for (int i=0;i<360;i++){
                float degRad = i * DEG2RAD;
                glVertex2f(cos(degRad)*radi,sin(degRad)*radi);
            }
           
        glEnd();
        
        
        
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        
        // my stuff
        
        
    }

    glfwTerminate();
    return 0;
}