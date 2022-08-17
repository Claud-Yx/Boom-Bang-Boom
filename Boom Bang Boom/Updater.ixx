export module Updater;

import <functional>;
import <string>;
import Utility;

export namespace Update {
	std::function<std::string(Util::KEYBOARD)> updateFunc;
	std::string currentFrame{};
	Util::KEYBOARD key{};

	export bool* running;

	export inline void setUpdateFunc( std::function<std::string( Util::KEYBOARD )> func ) { updateFunc = func; }
	export inline void Update() 
	{ 
		currentFrame = updateFunc(key); 

		if ( currentFrame == "quit" )
			*running = false;
	}

	export void keyEvent()
	{
		key = Util::inputKey();
	}
}