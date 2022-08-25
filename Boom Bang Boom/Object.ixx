export module Object;

import <string>;
import <functional>;
import PublicEnum;
import Utility;
import Renderer;
import FontSpace;

using namespace Util;

// Parent
export class Object {
protected:
	ID id;
	Coord crd;
	std::string rChar;
	std::string rCharOrigin;

public:
	Object() {};
	Object( ID id ) : id{ id }, crd{}, rChar{} {}
	Object( ID id, Coord crd ) : id{ id }, crd{crd}, rChar{} {}
	Object( ID id, Coord crd, Coord size, Coord pivot ) : 
		id{ id }, crd{crd}, rChar{} {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual std::string getRchar() = 0;
};

// Block object
export class Block : public Object {
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