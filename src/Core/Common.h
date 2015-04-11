#ifndef COMMON_H
#define COMMON_H

// Global constants
#ifndef DEFAULT_WIN_TITLE
#define DEFAULT_WIN_TITLE "Engine - "
#endif

#ifndef DEFAULT_WIN_W
#define DEFAULT_WIN_W 800
#endif

#ifndef DEFAULT_WIN_H
#define DEFAULT_WIN_H 600
#endif

#ifndef CHANNELS_COUNT
#define CHANNELS_COUNT 16
#endif

// STD Lib
#include <iostream>
#include <string>
#include <vector>

// SDL
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

// Engine
#include "Input.h"
#include "Timer.h"

// Custom lib
#include "Point.h"

#endif