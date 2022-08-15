export module Updater;

import <functional>;
import Utility;

export namespace Update {
	std::function<void(Util::KEYBOARD)> updateFunc;
	Util::KEYBOARD key{};

	export inline void setUpdateFunc( std::function<void( Util::KEYBOARD )> func ) { updateFunc = func; }
	export inline void Update() { updateFunc(key); }

	export void keyEvent()
	{
		key = Util::inputKey();
	}
}