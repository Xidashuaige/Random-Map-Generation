#include "Map.h"
#include "ModuleRender.h"

Map::Map(int row, int col, int gridWidth, int gridHeight) :row(row), col(col), gridWidth(gridWidth), gridHeight(gridHeight)
{	
	mapWidth = col * gridWidth;
	mapHeight = row * gridHeight;
}

Map::~Map()
{
}

// BUG!!!!
bool Map::CheckRoom(iPoint mapPos)
{
	if (mapPos.x < 0 || mapPos.y < 0 || mapPos.x > (col-1) || mapPos.y > (row-1)) return true;

	for (int i = 0, count = tiles.count(); i < count; i++)
	{
		iPoint tilePos = tiles[i].mapPos;

		//printf("X : %d|%d\tY: %d|%d\n", tilePos.x, mapPos.x, tilePos.y, mapPos.y);

		if (tilePos.x == mapPos.x && tilePos.y == mapPos.y) return true;
	}

	return false;
}

void Map::PostUpdate()
{
	// Draw tiles;
	for (int i = 0, count = tiles.count(); i < count; ++i)
	{
		Tile t = tiles[i];

		if (t.type == 0) continue;

		App->render->AddRectRenderQueue({ t.worldPos.x, t.worldPos.y, t.width, t.height }, { 255, 80, 80, 255 });
	}

	// Draw grid row
	for (int i = 0; i <= row; i++)
	{
		App->render->AddRectRenderQueue({ 0, i * gridWidth, mapWidth, 1 }, { 100, 100, 100, 255 });
	}

	// Draw grid col
	for (int i = 0; i <= col; i++)
	{
		App->render->AddRectRenderQueue({ i * gridHeight, 0 , 1, mapHeight }, { 100, 100, 100, 255 });
	}
}
