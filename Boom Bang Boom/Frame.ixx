export module Frame;

import <string>;
import <functional>;

export class Frame {
	std::string name{};
	std::function<void()> Renderer;
	std::function<std::string( unsigned short )> Updater;

public:
	Frame(
		std::string name,
		std::function<void()> renderer,
		std::function < std::string( unsigned short )> updater
	) : name{ name }, Renderer{ renderer }, Updater{ updater } {}

public:
	inline const std::string& getName() const { return name; }
	inline std::function<void()> getRenderer() { return Renderer; }
	inline std::function<std::string( unsigned short )> getUpdater() { return Updater; }

	inline void Render() { Renderer(); }
	inline std::string Update( unsigned short key ) { return Updater( key ); }

	inline void setRenderer( std::function<void()> renderer ) { Renderer = renderer; }
	inline void setUpdater( std::function<std::string( unsigned short )> updater ) { Updater = updater; }
};