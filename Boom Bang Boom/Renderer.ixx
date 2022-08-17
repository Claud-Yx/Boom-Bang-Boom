export module Renderer;

import Utility;
import <iostream>;
import <string>;
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
		//std::size_t lineCnt;

		PartedOutputBuffer() : buffer{} {}

		PartedOutputBuffer& operator<<( const std::string rhs )
		{
			buffer += rhs;
			return *this;
		}

		PartedOutputBuffer& operator<<( char rhs )
		{
			buffer += rhs;
			return *this;
		}

		PartedOutputBuffer& operator<<( int rhs )
		{
			buffer += std::to_string( rhs );
			return *this;
		}

		inline void clear() { buffer.clear(); }

		inline const void showBuffer() { std::cout << buffer << std::endl; }
		void renderInParted( Util::Coord start_pos );
	};

	// Color
}