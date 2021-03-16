#pragma once
#include "T.h"
/*
.worldsave

worldsave0.1 400 300
0 0 0 0 00000
....

*/


bool save_world(const char* filename, sCell cells[], int width, int height);
bool load_world(const char* filename, sCell world[], int width, int height);

