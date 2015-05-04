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

#ifndef DEFAULT_FRAMERATE
#define DEFAULT_FRAMERATE 30
#endif

#ifndef RESOLUTION_NTSC
#define RESOLUTION_NTSC {256, 240}
#endif

#ifndef RESOLUTION_PAL
#define RESOLUTION_PAL {256, 224}
#endif


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
#include "ResourceHolder.h"

// Custom lib
#include "Point.h"
#include "Vector.h"
#endif
