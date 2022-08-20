export module Map;

import <fstream>;
import <string>;
import <vector>;
import Object;
import PublicEnum;

export struct Map;

constexpr int MAX_MAP_SIZE{ 30 };
const std::string MAP_EXT{ ".map" };


export struct Map {
	std::string name;
	std::vector<std::vector<ID>> code;

	Map()
	{
		code.assign( 30, std::vector<ID>{30, ID::BL_BLANK} );
	}

	Map( std::string mapName )
	{
		name = mapName;
		mapName += MAP_EXT;
		Load( mapName );
	}

	void Save( std::string fileName );
	void Load( std::string fileName );
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

	code.assign( 30, std::vector<ID>{30, ID::BL_BLANK} );

	if ( !in ) {
		return;
	}

	for ( int y{}; y < MAX_MAP_SIZE; ++y ) {
		for ( int x{}; x < MAX_MAP_SIZE; ++x ) {
			in.read( (char*)&code[y][x], sizeof( ID ) );
		}
	}
}