#ifndef _COMMON_H_INCLUDED_
#define _COMMON_H_INCLUDED_
#include <irrlicht.h>
#include <iostream>
using namespace irr;
using namespace core;
using namespace scene;
using namespace gui;
using namespace video;

// Enums
enum BUILD_TYPE
{
	NBT_NB = 1, // Just the node box table
	NBT_NBS = 2, // The node box table with draw type and parent holder (nodebox={})
	NBT_FULL = 3 // Whole node definition
};


enum FileParserType
{
	EFPT_SAVE_PROJ = 1,
	EFPT_LOAD_PROJ = 2,
	EFPT_EXPORT = 3,
	EFPT_IMPORT = 4
};

// Defines
#define EDITOR_TEXT_VERSION "0.6.3 - Stone"
#define EDITOR_VERSION 1
#define EDITOR_PARSER 1

#endif

