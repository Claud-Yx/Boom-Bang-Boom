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

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
};

// Weapon
export class Weapon : public Object {
	TRAIT trait;
	int damage;
public:
	Weapon() : Object{}, trait{}, damage{} {}
	Weapon( ID id ) : Object{ id }, trait{}, damage{} {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
};

// Actor object
export class Actor : public Object {
protected:
	Weapon weapon;
	TRAIT trait;
	int hp;

public:
	Actor( ID id ) : Object{ id }, trait{}, hp{}, weapon{} {}

	virtual void Init() override = 0;
	virtual void Update() override = 0;
	virtual std::string getRchar() override = 0;
	virtual void Attack() = 0;
	virtual void Move() = 0;
};

// Player : Actor
export class Player : public Actor {
	
public:
	Player( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};

// Assaulter : Actor
export class Assaulter : public Actor {

public:
	Assaulter( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};


// Chaser : Actor
export class Chaser : public Actor {

public:
	Chaser( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};


// Sniper : Actor
export class Sniper : public Actor {

public:
	Sniper( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};


// Bulldozer : Actor
export class Bulldozer : public Actor {

public:
	Bulldozer( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};


// Tank : Actor
export class Tank : public Actor {

public:
	Tank( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};

// Turret : Actor
export class Turret : public Actor {

public:
	Turret( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};

// Mortar : Actor
export class Mortar : public Actor {

public:
	Mortar( ID id ) : Actor{ id } {}

	virtual void Init() final;
	virtual void Update() final;
	virtual std::string getRchar() final;
	virtual void Attack() final;
	virtual void Move() final;
};