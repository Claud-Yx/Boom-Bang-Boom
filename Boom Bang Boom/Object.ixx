export module Object;

import <string>;
import Utility;

using namespace Util;

// Parent
class Object {
protected:
	int id;
	Coord crd;
	Coord size;
	Coord pivot;
	std::string renderChar;

public:
	Object() {};
	Object( Coord crd ) : crd{ crd }, size{ 1, 1 }, pivot{}, renderChar{} {}

	virtual std::string getRchar() = 0;
};

// Block object
class Block : public Object {
	uint16_t trait;
	int hp;
};