export module PublicEnum;

import <iostream>;

export using TRAIT = uint16_t;

export enum ID : int {
	// BL : BLOCK		1'000
	// AC : ACTOR		2'000
	// IT : ITEM		3'000
	// WP : WEAPON		4'000
	// BB : BOMB		5'000

	BL_START = 1'000,
	BL_BLANK = 1'000,
	BL_UNBREAKABLE_WALL,
	BL_BREAKABLE_WALL,
	BL_BLOCKED_CHAIN_WALL,
	BL_HEAVY_BLOCK,
	BL_BOX,
	BL_DOOR_YELLOW,
	BL_DOOR_BLUE,
	BL_DOOR_RED,
	BL_END,

	AC_START = 2'000,
	AC_PLAYER = 2'000,
	AC_ASSAULTER = 2'010,
	AC_CHASER = 2'020,
	AC_SNIPER = 2'030,
	AC_BULLDOZER = 2'040,
	AC_BULLDOZER_INV = 2'049,
	AC_TANK = 2'050,
	AC_TURRET = 2'060,
	AC_MORTAR = 2'070,
	AC_END,

	IT_START = 3'000,
	IT_COIN_5 = 3'000,
	IT_COIN_10,
	IT_COIN_20,
	IT_COIN_50,
	IT_COIN_100,
	IT_HEAL,
	IT_HEAL_FULL,
	IT_BOMB,
	IT_KEY_YELLOW,
	IT_KEY_BLUE,
	IT_KEY_RED,
	IT_END,

	WP_START = 4'000,
	WP_DAGGER = 4'000,
	WP_SWORD,
	WP_SPEAR,
	WP_HAND_GUN,
	WP_END,

	BB_START = 5'000,
	BB_POWDER_KEG = 5'000,
	BB_TIMER,
	BB_PIERCE,
	BB_END
};

export typedef enum BLOCK_TRAIT : TRAIT {
	UNBREAKABLE = 0x1,
	MOVABLE = 0x2,
	PASS_ACTOR = 0x4,
	COVER_ACTOR = 0x8,

	PASS_FLAME = 0x10,
	PASS_BULLET = 0x20,
	IMMUNE_FLAME = 0x40,
	IMMUNE_BULLET = 0x80,

	IMMUNE_MELEE = 0x100,
	PASS_ALL = 0x200,


}BLT;