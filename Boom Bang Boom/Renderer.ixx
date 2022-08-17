export module Renderer;

import Utility;
import <iostream>;
import <vector>;
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

	export struct PartedOutputBuffer {
		std::string buffer;

		PartedOutputBuffer(std::string str) : buffer{str} {}

		PartedOutputBuffer& operator<<( const PartedOutputBuffer rhs )
		{
			buffer += rhs.buffer;
			return *this;
		}

		inline const void showBuffer() { std::cout << buffer << std::endl; }
	};
	export void renderInParted( Util::Coord start_pos, )
	{

	}
}