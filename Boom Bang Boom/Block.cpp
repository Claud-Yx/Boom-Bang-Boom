module Object;

// class Block
using namespace Util;
using namespace Render;

void Block::Init() 
{
	switch ( id ) {
		case ID::BL_BLANK:
			rCharOrigin = getColorCode( GRAY, WHITE ) + sc();
			rChar = rCharOrigin;
			trait = BLT::UNBREAKABLE | BLT::PASS_ALL;
			break;

		case ID::BL_UNBREAKABLE_WALL:
			rCharOrigin = getColorCode( BLACK, WHITE ) + "¡á";
			rChar = rCharOrigin;
			trait = BLT::UNBREAKABLE;
			break;

		case ID::BL_BREAKABLE_WALL:
			rCharOrigin = getColorCode( DARK_GRAY, WHITE ) + "¡á";
			rChar = rCharOrigin;
			trait = BLT::IMMUNE_MELEE | BLT::IMMUNE_BULLET;
			break;

		case ID::BL_BLOCKED_CHAIN_WALL:
			rCharOrigin = getColorCode( DARK_BLUE, WHITE ) + "¢Ë";
			rChar = rCharOrigin;
			trait = BLT::UNBREAKABLE;
			break;

		case ID::BL_HEAVY_BLOCK:
			rCharOrigin = getColorCode( GRAY, BLACK ) + "¢Ì";
			rChar = rCharOrigin;
			trait = BLT::UNBREAKABLE;
			break;

		case ID::BL_BOX:
			rCharOrigin = getColorCode( DAKR_YELLOW, WHITE ) + "¢É";
			rChar = rCharOrigin;
			trait = BLT::UNBREAKABLE;
			break;

		case ID::BL_DOOR_YELLOW:
			rCharOrigin = getColorCode( DARK_GRAY, YELLOW) + "¢È";
			rChar = rCharOrigin;
			trait = 0;
			break;
	}
}

void Block::Update()
{

}

std::string Block::getRchar()
{
	return rChar;
}