#pragma once
#include <Windows.h>
#include "SDL.h"
#include <glut.h>
#include <iostream>

/*INITIALIZATION OF TEXTURE*/
void texture_init(GLuint &texture, char* image_name) {
  SDL_Surface* surf = SDL_LoadBMP(image_name);
  if (surf == NULL) { //If failed, say why and don't continue loading the texture
    printf("Error: \"%s\"\n", SDL_GetError()); return;
  }
  GLenum data_fmt; //Determine the data format of the surface by seeing how SDL arranges a test pixel.  This probably only works --  correctly for little-endian machines.
  Uint8 test = SDL_MapRGB(surf->format, 0xAA, 0xBB, 0xCC) & 0xFF;
  if (test == 0xAA) data_fmt = GL_RGB;
  else if (test == 0xCC) data_fmt = 0x80E0;//GL_BGR;
  else {
    printf("Error: \"Loaded surface was neither RGB or BGR!\""); return;
  }

  glGenTextures(1, &texture);//Generate an array of textures.  We only want one texture (one element array), so trick                      
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, data_fmt, GL_UNSIGNED_BYTE, surf->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  SDL_FreeSurface(surf); //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
  /*blind and enable was here*/
}
void texture_blind_and_enable(GLuint &texture) {
  glBindTexture(GL_TEXTURE_2D, texture); //Tell OpenGL that all subsequent drawing operations should try to use the current 2D texture
  glEnable(GL_TEXTURE_2D);
}

void texture_disable() {
  glDisable(GL_TEXTURE_2D);
}

void texture_deinit(GLuint &texture) {
  glDeleteTextures(1, &texture);
}
