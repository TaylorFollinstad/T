#pragma once
struct sEdge
	// s is for start. e is for end.
{
	float sx, sy;
	float ex, ey;
};
// hello hi
struct sCell
{
	int edge_id[4];
	bool edge_exist[4];
	bool exist = false;
};