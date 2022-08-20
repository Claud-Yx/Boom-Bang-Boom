export module Frame;

import <string>;
import <functional>;

export class Frame {
	std::string name{};
	std::function<void()> Renderer;
	std::function<std::string( unsigned short )> Updater;
	std::function<void()> Initializer;

public:
	Frame( std::string name ) : name{ name }, Renderer{}, Updater{}, Initializer{} {};
	Frame(
		std::string name,
		std::function<void()> renderer,
		std::function < std::string( unsigned short )> updater
	) : name{ name }, Renderer{ renderer }, Updater{ updater }, Initializer{} {}
	Frame(
		std::string name,
		std::function<void()> renderer,
		std::function < std::string( unsigned short )> updater,
		std::function<void()> initializer
	) : name{ name }, Renderer{ renderer }, Updater{ updater }, Initializer{ initializer } {}

public:
	inline const std::string& getName() const { return name; }

	inline void Render() { Renderer(); }
	inline std::string Update( unsigned short key ) { return Updater( key ); }
	inline void Init() { if (Initializer) Initializer(); }

	inline void setRenderer( std::function<void()> renderer ) { Renderer = renderer; }
	inline void setUpdater( std::function<std::string( unsigned short )> updater ) { Updater = updater; }
	inline void setInitializer( std::function<void()> initializer ) { Initializer = initializer; }
};