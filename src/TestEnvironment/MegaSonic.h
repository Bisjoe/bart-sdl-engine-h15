#pragma once

#include "Common.h"
#include "Animation.h"

class MegaSonic :
	public Animation
{
public:
	MegaSonic();
	~MegaSonic();

	const std::string MEGASONIC_PATH;
	const point<int> START_SRC_POS;
	const point<int> FRAME_SRC_SIZE;
};

