export module Renderer;

import Utility;
import <functional>;

namespace Render {
	std::function<void()> displayFunc;

	export unsigned short width{}, height{};

	export void setDisplayFunc( std::function<void()> fn ) { displayFunc = fn; }
	export void Render();

	export void setCursorPos( Util::Coord );
	export void showCursor( bool show );
	export void setConsoleSize( unsigned short width = 80, unsigned short height = 25 );
	export void setConsoleTitle( const char* title );
	export void clearConsole();
}