#ifndef COMMON_H
#define COMMON_H

// Global constants
#define DEFAULT_WIN_TITLE "Engine - "
#define DEFAULT_WIN_W 800
#define DEFAULT_WIN_H 600
#define DEFAULT_FRAMERATE 30

// STD Lib
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// SDL
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

// Engine
#include "Audio.h"
#include "Input.h"
#include "Timer.h"
#include "ResourcesManager.h"

// Custom lib
#include "Point.h"

#endif