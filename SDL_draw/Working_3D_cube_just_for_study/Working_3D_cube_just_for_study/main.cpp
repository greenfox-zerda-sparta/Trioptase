#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <glut.h>

#define WIDTH 640
#define HEIGHT 480
#define WINDOW_NAME "My Game Window"
#define WIN_POS_X 0
#define WIN_POS_Y 30

void drawer(SDL_Window*);

double angleX;
double angleZ;

bool igaz = false;

int main(int argc, char *argv[]) {

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow(WINDOW_NAME, WIN_POS_X, WIN_POS_Y, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  //create a currently used OpenGL context from the window
  SDL_GL_CreateContext(window);

  // specify which matrix is the currently used matrix (https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml)
  glMatrixMode(GL_PROJECTION);
  //replace the current matrix with the identity matrix (https://www.opengl.org/sdk/docs/man2/xhtml/glLoadIdentity.xml)
  glLoadIdentity();
  //set up projection perspective matrix (https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml)
  gluPerspective(70, (double)WIDTH / HEIGHT, 1, 1000);
  //enable or disable server side GL capabilities (https://www.opengl.org/sdk/docs/man2/xhtml/glEnable.xml)
  glEnable(GL_DEPTH_TEST);

  //this drawer function is not necessary
  //drawer(window);

  ///SDL event handling

  bool running = true;
  SDL_Event event;

  // get the number of milliseconds since the SDL library initialization ( SDL_Init() )
  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time, ellapsed_time, start_time;

  while (running) {
    start_time = SDL_GetTicks();

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
          angleZ += 10;
          break;
        case SDLK_LEFT:
          angleZ -= 10;
          break;
        case SDLK_UP:
          angleX += 10;
          break;
        case SDLK_DOWN:
          angleX -= 10;
          break;
        case SDLK_ESCAPE:
          running = false;
          break;
        }
        break;
        /*
        case SDL_MOUSEMOTION:
        angleZ = event.motion.x - WIDTH / 2;
        angleX = HEIGHT / 2 - event.motion.y;
        break;
        */
      }
    }
    current_time = SDL_GetTicks();
    ellapsed_time = current_time - last_time;
    last_time = current_time;

    /*
    //This two lines is responsible for auto rotating if you need
    angleZ += 0.05 * ellapsed_time;
    angleX += 0.05 * ellapsed_time;
    */

    drawer(window);

    ellapsed_time = SDL_GetTicks() - start_time;

    // i dont understand the goal of this part of the code - it works just as fine as w/out it
    /*
    if (ellapsed_time < 10) {
    SDL_Delay(10 - ellapsed_time);
    }*/

  } //end of while loop
  SDL_Quit();

  return 0;
} // end of main

void drawer(SDL_Window* screen) {

  //clear buffers to preset values
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //specify which matrix is the current matrix (GL_MODELVIEW => Applies subsequent matrix operations to the modelview matrix stack )
  glMatrixMode(GL_MODELVIEW);
  //replace the current matrix with the identity matrix
  glLoadIdentity();

  //define a viewing transformtion 9 * GLdouble :
  ///eye(XYZ) Specifies the position of the eye point. 
  ///center(XYZ) Specifies the position of the reference point.
  ///up(XYZ) Specifies the direction of the up vector ???
  /*
  (https://www.google.hu/search?q=glulookat&safe=off&espv=2&biw=1242&bih=615&tbm=isch&tbo=u&source=univ&sa=X&ved=0ahUKEwiToJLS08zRAhXGvBQKHdxUC2IQsAQIHg)
  */
  gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1); // camera

                                        ///here we can not use the Original OpenGL function glRotate(w/ the same arguments) BUT WHY??
                                        // multiplies the current matrix w/ rotation matrix
  glRotated(angleX, 1, 0, 0);
  glRotated(angleZ, 0, 0, 1);

  // delimit the vertices of a primitive or a group of primitives (GL_QUADS => treat each group of 4 vertices as an independent rectangle)
  // sthing about initializing that we'll use rects here 
  glBegin(GL_QUADS); //Here starts the drawing

                     //set the currently usied color
  glColor3ub(255, 0, 0); //red side FRONT
  glVertex3d(1, 1, 1);
  glVertex3d(1, 1, -1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, 1, 1);

  glColor3ub(0, 255, 0); //green side LEFT
  glVertex3d(1, -1, 1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, 1, -1);
  glVertex3d(1, 1, 1);

  glColor3ub(0, 0, 255); //blue side BACK
  glVertex3d(-1, -1, 1);
  glVertex3d(-1, -1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(1, -1, 1);

  glColor3ub(255, 255, 0); //yellow side RIGHT
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, 1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, -1, 1);

  glColor3ub(255, 88, 0); //orange side BOTTOM
  glVertex3d(1, 1, -1);
  glVertex3d(1, -1, -1);
  glVertex3d(-1, -1, -1);
  glVertex3d(-1, 1, -1);

  glColor3ub(255, 255, 255); //white side TOP
  glVertex3d(1, -1, 1);
  glVertex3d(1, 1, 1);
  glVertex3d(-1, 1, 1);
  glVertex3d(-1, -1, 1);

  glEnd();

  glFlush();
  SDL_GL_SwapWindow(screen);
}
