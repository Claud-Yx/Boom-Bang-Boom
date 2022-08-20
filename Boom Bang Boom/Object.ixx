export module Object;

import <string>;
import Utility;

namespace ObjectNS {
	using TRAIT = uint8_t;

	enum class ID {
		// BL : BLOCK		1'000
		// AC : ACTOR		2'000
		// IT : ITEM		3'000
		// WP : WEAPON		4'000
		BL_START = 1'000,
		BL_BLANK = 1'000,
		BL_UNBREAKABLE_WALL,
		BL_BREAKABLE_WALL,
		BL_BLOCKED_CHAIN_WALL,
		BL_BOX,
		BL_DOOR,
		BL_POWDER_KEG = 1'100,
		BL_BOMB_TIMER,
		BL_BOMB_PIERCE,
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
		IT_KEY,
		IT_END,

		WP_START = 4'000,
		WP_DAGGER = 4'000,
		WP_SWORD,
		WP_SPEAR,
		WP_HAND_GUN,
		WP_END
	};
}

using namespace Util;
using namespace ObjectNS;

// Parent
class Object {
protected:
	ID id;
	Coord crd;
	Coord size;
	Coord pivot;
	std::string rChar;

public:
	Object() {};
	Object( ID id ) : id{ id }, crd{}, size{ 1, 1 }, pivot{}, rChar{} {}
	Object( ID id, Coord crd ) : id{ id }, crd{crd}, size{ 1, 1 }, pivot{}, rChar{} {}
	Object( ID id, Coord crd, Coord size, Coord pivot ) : 
		id{ id }, crd{crd}, size{ size }, pivot{pivot}, rChar{} {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual std::string getRchar() = 0;
};

// Block object
class Block : public Object {
private:
	TRAIT trait;
	int hp;

public:
	Block( ID id ) : Object{ id }, trait{}, hp{} {}
	Block( ID id, Coord crd ) : Object{ id, crd }, trait{}, hp{} {}

	virtual void Init() override;
	virtual void Update() override;
	virtual std::string getRchar() override;
};