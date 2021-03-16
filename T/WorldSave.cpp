#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include "WorldSave.h"
#include <cassert>
using namespace std;

/*
.worldsave

worldsave0.1 400 300
0 0 0 0 00000
....

*/

bool save_world(const char* filename, sCell cells[], int width, int height)
{
    ofstream f{ filename };

    f << "worldsave0.1 " << width << " " << height << "\n";
    for (int i = 0; i < width * height; ++i) {
        auto cell = cells[i];
        f << cell.edge_id[0] << " " << cell.edge_id[1] << " " << cell.edge_id[2] << " " << cell.edge_id[3] << " "
          << cell.edge_exist[0] << cell.edge_exist[1] << cell.edge_exist[2] << cell.edge_exist[3] << cell.exist << "\n";
    }
    f.flush();
    return true;
}

bool load_world(const char* filename, sCell world[], int width, int height) {
    auto f = fopen(filename, "r");
    int new_width, new_height;
    (void)fscanf(f, "worldsave0.1 %i %i\n", &new_width, &new_height);
    assert(width == new_width && height == new_height);
    for (int i = 0; i < width * height; ++i) {
        sCell cell;
        char e0, e1, e2, e3, exists;
        (void)fscanf(f, "%i %i %i %i %c%c%c%c%c\n", &cell.edge_id[0], &cell.edge_id[1], &cell.edge_id[2], &cell.edge_id[3],
            &e0, &e1, &e2, &e3, &exists);
        cell.edge_exist[0] = e0 - '0';
        cell.edge_exist[1] = e1 - '0';
        cell.edge_exist[2] = e2 - '0';
        cell.edge_exist[3] = e3 - '0';
        cell.exist         = exists - '0';
        world[i]           = cell;
    }
    return true;
}
