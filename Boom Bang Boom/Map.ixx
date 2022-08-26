export module Map;

import <array>;
import <fstream>;
import <vector>;
import <string>;
import Object;
import PublicEnum;

export struct Map;

export constexpr int MAX_MAP_SIZE{ 30 };
export const std::string MAP_EXT{ ".map" };


export struct Map {
	std::string name;
	std::array<std::array<ID, MAX_MAP_SIZE>, MAX_MAP_SIZE> code;
	std::array<std::array<std::vector<std::unique_ptr<Object>>, MAX_MAP_SIZE>, MAX_MAP_SIZE> objects;

	Map() : code{}, objects{}
	{
		clearObjects();
	}

	Map( std::string mapName ) : code{}, objects{}
	{
		name = mapName;
		mapName += MAP_EXT;
		Load( mapName );
		initObjects();
	}

	void Save( std::string fileName );
	void Load( std::string fileName );
	void destroyObjects();
	void clearObjects();
	void initObjects();
};

void Map::Save( std::string fileName )
{
	fileName += MAP_EXT;
	std::ofstream out{ fileName, std::ios::binary };

	for ( int y{}; y < MAX_MAP_SIZE; ++y ) {
		for ( int x{}; x < MAX_MAP_SIZE; ++x ) {
			out.write( (const char*)&code[y][x], sizeof( ID ) );
		}
	}

}

void Map::Load( std::string fileName )
{
	std::ifstream in{ fileName, std::ios::binary };

	if ( !in ) {
		return;
	}

	for ( int y{}; y < MAX_MAP_SIZE; ++y ) {
		for ( int x{}; x < MAX_MAP_SIZE; ++x ) {
			in.read( (char*)&code[y][x], sizeof( ID ) );
		}
	}
}

void Map::destroyObjects()
{
	for ( auto& y : objects )
		for ( auto& x : y )
			x.clear();
}

void Map::clearObjects()
{
	for ( auto& y : objects )
		for ( auto& x : y ) {
			x.clear();
			x.push_back( std::make_unique<Block>(ID::BL_BLANK) );
		}
}

void Map::initObjects()
{
	clearObjects();

	for ( int y{}; y < MAX_MAP_SIZE; ++y )
		for ( int x{}; x < MAX_MAP_SIZE; ++x ) {
			if ( code[y][x] >= ID::BL_START and code[y][x] < ID::BL_END )
				objects[y][x].push_back( std::make_unique<Block>( code[y][x] ) );
			
			else if ( code[y][x] >= ID::AC_START and code[y][x] < ID::AC_END ) {
				if ( code[y][x] >= ID::AC_PLAYER and code[y][x] < ID::AC_ASSAULTER )
					objects[y][x].push_back( std::make_unique<Player>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_PLAYER and code[y][x] < ID::AC_ASSAULTER )
					objects[y][x].push_back( std::make_unique<Player>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_ASSAULTER and code[y][x] < ID::AC_CHASER )
					objects[y][x].push_back( std::make_unique<Assaulter>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_CHASER and code[y][x] < ID::AC_SNIPER )
					objects[y][x].push_back( std::make_unique<Chaser>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_SNIPER and code[y][x] < ID::AC_BULLDOZER )
					objects[y][x].push_back( std::make_unique<Sniper>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_BULLDOZER and code[y][x] < ID::AC_TANK )
					objects[y][x].push_back( std::make_unique<Bulldozer>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_TANK and code[y][x] < ID::AC_TURRET )
					objects[y][x].push_back( std::make_unique<Tank>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_TURRET and code[y][x] < ID::AC_MORTAR )
					objects[y][x].push_back( std::make_unique<Turret>( code[y][x] ) );

				else if ( code[y][x] >= ID::AC_MORTAR and code[y][x] < ID::AC_END )
					objects[y][x].push_back( std::make_unique<Mortar>( code[y][x] ) );
			}
		}
}
