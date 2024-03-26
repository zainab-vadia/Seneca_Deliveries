#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"
#include "math.h"

struct Map populateMap()
{
	struct Map result = {
		//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
		//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
		{
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
		{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
		{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
		},
		MAP_ROWS, MAP_COLS
	};
	return result;
}

int getNumRows(const struct Map* map)
{
	return map->numRows;
}

int getNumCols(const struct Map* map)
{
	return map->numCols;
}

void printMap(const struct Map* map, const int base1, const int alphaCols)
{
	//              01234567890123456
	//              1248F
	char sym[] = { " XB?G?.?Y?-?*?+?P" };
	int r, c, rowMax;

	rowMax = map->numRows + base1;

	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{	
		if (alphaCols) printf("%c", 'A' + c);
		else printf("%d", c % 10);
	}
	printf("\n");
	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		printf("-");
	}
	printf("\n");

	for (r = base1; r < rowMax; r++)
	{
		printf("%3d|", r);
		for (c = 0; c < map->numCols; c++)
		{
			printf("%c", sym[map->squares[r - base1][c]]);
		}
		printf("\n");
	}
}

struct Route getBlueRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
	};
	return result;
}

struct Route getGreenRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}
			
		},
			42, GREEN
	};
	return result;
}

struct Route getYellowRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, 
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
	};
	return result;
}

struct Map addRoute(const struct Map* map, const struct Route* route)
{
	int r, c;
	struct Map result = { {0}, 0 };

	for (r = 0; r < map->numRows; r++)
	{
		for (c = 0; c < map->numCols; c++)
		{
			result.squares[r][c] = map->squares[r][c];
		}
	}
	result.numRows = map->numRows;
	result.numCols = map->numCols;

	for (r = 0; r < route->numPoints; r++)
	{
		result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
	}

	return result;
}

void addPtToRoute(struct Route* route, struct Point pt)
{
	route->points[route->numPoints++] = pt;
}

void addPointToRoute(struct Route* route, const int row, const int col)
{
	struct Point pt = { row, col };
	addPtToRoute(route, pt);
}

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
	struct Point pt = { row, col };
	if(notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

double distance(const struct Point* p1, const struct Point* p2)
{
	int deltaRow = p2->row - p1->row;
	int deltaCol = p2->col - p1->col;

	return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
{
	struct Route result = { {0,0}, 0, DIVERSION };
	struct Route empty = { {0,0}, 0, DIVERSION };
	struct Point last = { -1, -1 };
	struct Point current = start;
	struct Route possible = { {0,0},0,0 };
	int close = 0;
	addPtToRoute(&result, start);
	
	while (!eqPt(current, dest) && close >= 0)
	{
		if (areDirectNeighbors(current, dest))
		{
			addPtToRoute(&result, dest);
			return result;
		}
		possible = getPossibleMoves(map, current, last);
		close = getClosestPoint(&possible, dest);
		if (close >= 0)
		{
			last = current;
			current = possible.points[close];
			if (containsPoint(result, current))
			{
				return empty; 
			}
			addPtToRoute(&result, current);
		}
	}

	return result;
}

struct Route BestRoute(const struct Map* map, const struct Point start, const struct Point dest, struct Route route)
{
	if (areDirectNeighbors(start, dest) || eqPt(dest, start))
	{
		addPtToRoute(&route, start);
		addPtToRoute(&route, dest);
		return route;
	}

	addPtToRoute(&route, start);
	struct Route temp = getPossibleMoves(map, start, start);
	int distance = abs(dest.col - start.col) + abs(dest.row - start.row);
	int i = 0;
	for (i = 0; i < temp.numPoints; i++)
	{
		int newdist = abs(dest.col - temp.points[i].col) + abs(dest.row - temp.points[i].row);
		if (newdist < distance)
			return BestRoute(map, temp.points[i], dest, route);
	}
	struct Route empty = { {0,0}, 0, DIVERSION };
	return empty;
}


struct Route findClosestPoint(const struct Map* map, const struct Route route, const struct Point dest)
{
	struct Route result = { {0,0}, 1000, DIVERSION };
	struct Route empty = { {0,0}, 0, DIVERSION };
	struct Route temp = { {0,0}, 0, DIVERSION };
	struct Point dropOff;

	struct Route temp1 = getPossibleMoves(map, dest, dest);
	if (temp1.numPoints == 0) return empty; 
		int idx = getClosestPoint(&temp1, dest);
		dropOff = temp1.points[idx];


	int i = 0;
	for (i = 0; i < route.numPoints; i++)
	{
		if (areDirectNeighbors(route.points[i], dest))
		{
			struct Route empty = { {0,0}, 0, DIVERSION };
			addPtToRoute(&empty, route.points[i]);
			addPtToRoute(&empty, dest);
			result = empty; 
		}
		else
		{
			// temp = shortestPath(map, route.points[i], dest);
			temp = BestRoute(map, route.points[i], dropOff, empty);
			if (!eqPt(dest, dropOff) && temp.numPoints != 0) addPtToRoute(&temp, dest);
		}
		if (temp.numPoints != 0 && temp.numPoints < result.numPoints)
		{
			result = temp;
		}
	}

	return result; 
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
	struct Route result = { {0,0}, 0, DIVERSION };

	if (p1.row > 0 )
	{
		if(map->squares[p1.row - 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
		//if (p1.col > 0 && map->squares[p1.row - 1][p1.col-1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col-1, backpath);	// top left
		//if (p1.col < (map->numCols-1) && map->squares[p1.row - 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
	}
	if (p1.row < (map->numRows - 1))
	{
		if (map->squares[p1.row + 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
		//if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
		//if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath);	// top right
	}
	if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);	// left
	if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right

	return result;
}

int getClosestPoint(const struct Route* route, const struct Point pt)
{
	int i, closestIdx = -1;
	double closestDist = 999999.9, dist;

	for (i = 0; i < route->numPoints; i++)
	{
		dist = distance(&pt, &route->points[i]);
		if (dist < closestDist)
		{
			closestDist = dist;
			closestIdx = i;
		}
	}
	return closestIdx;
}

int eqPt(const struct Point p1, const struct Point p2)
{
	return p1.row == p2.row && p1.col == p2.col;
}

int BuildingBlock(const struct Point point, const struct Map map)
{
	if (point.row < 0 || point.row >= MAP_ROWS || point.col < 0 || point.col >= MAP_COLS)
	{
		return 0;
	}
	return map.squares[point.row][point.col];
}

int areDirectNeighbors(const struct Point current, const struct Point target)
{
	// This function checks if two points are directly next to each other on a grid
	return (current.col == target.col && (current.row == target.row + 1 || current.row == target.row - 1)) ||
		(current.row == target.row && (current.col == target.col + 1 || current.col == target.col - 1));
}

int containsPoint(const struct Route route, const struct Point point)
{
	// This function iterates through a route to check if a specific point is included
	for (int i = 0; i < route.numPoints; i++)
	{
		if (eqPt(route.points[i], point))  // Assuming eqPt checks for equality between two points
		{
			return 1; // The route contains the specified point
		}
	}
	return 0; // The point is not part of the route
}

