#ifndef __MAP_GENERATOR_H__
#define __MAP_GENERATOR_H__

#include "Map.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MAP_KEY 2333333333

class MapGenerator
{
public:

	MapGenerator();

	~MapGenerator();

	/// <summary>
	/// Generate and return Dungeon map
	/// </summary>
	/// <param name="row">: map row</param>
	/// <param name="col">: map col</param>
	/// <param name="rooms">: numbers of room you want to create</param>
	/// <param name="tileWidth">: tile width in pixel</param>
	/// <param name="tileHeight">: tile height in pixel</param>
	/// <param name="eSeek">: map encrypted seek</param>
	/// <returns></returns>
	Map* GenerateDungeonMap(uint row, uint col, uint rooms = 1, uint tileWidth = 10, uint tileHeight = 10, int eSeed = 0);

	void TestDungeonMapBacktrack();

	/// <summary>
	/// Generate and return Dungeon map with CellularAutomation
	/// </summary>
	/// <param name="row">: map row</param>
	/// <param name="col">: map col</param>
	/// <param name="tileWidth">: tile width in pixel</param>
	/// <param name="tileHeight">: tile height in pixel</param>
	/// <param name="eSeek">>: map encrypted seek</param>
	/// <returns></returns>
	Map* GenerateDungeonMapCA(uint row, uint col, uint tileWidth = 10, uint tileHeight = 10, int eSeed = 0);

	void TestGenerateDungeonMapCA();

private: 

	void DungeonMapBacktrack(Map* map, uint* rooms, iPoint currentPos);

	void CreateBaseMap(Map* map);


	void CreateBaseMapCA(Map* map);

	void LoopOptimizeMapCA(Map* map, uint loopCA = 3);

	std::vector<std::vector<Tile>> FindAreasMapCA(Map* map);

	void ConnectAreasMapCA(Map* map, std::vector<std::vector<Tile>> areas);


	void InitSeed(int eSeed);

	void SaveSeed(int seed);

	int Encryption(int data);

	uint Decrypt(int data);

public:

	bool debugMode = false;

private:
	uint tileWidth = 1;

	uint tileHeight = 1;

	// For testing HARDCODE DO NOT USE FOR PROJECT
	Map* map_t = nullptr;

	uint rooms_t = 0;

	int mapCAStep_t = 4;
};

#endif // !__MAP_GENERATOR_H__