export module Frame;

import <string>;
import <functional>;
import Utility;

export class Frame {
	std::string name{};
	std::function<void()> Render;
	std::function<std::string( Util::KEYBOARD )> Update;

public:
	Frame(
		std::string name,
		std::function<void()> renderer,
		std::function < std::string(Util::KEYBOARD)> updater
	) : name{ name }, Render{ renderer }, Update{ updater } {}


public:
	inline const std::string& getName() { return name; }
	inline std::function<void()> getRenderer() { return Render; }
	inline std::function<std::string( Util::KEYBOARD )> getUpdater() { return Update; }
	
	inline void setRenderer( std::function<void()> renderer ) { Render = renderer; }
	inline void setUpdater( std::function<std::string( Util::KEYBOARD )> updater ) { Update = updater; }
};