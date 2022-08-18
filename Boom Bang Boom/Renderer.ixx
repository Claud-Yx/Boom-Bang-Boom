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
		void renderInParted( Util::Coord start_pos = { 0, 0 } );
	};

	// Color
	enum COLOR{
		BLACK,
		DARK_BLUE,
		DARK_GREEN,
		DARK_SKYBLUE,
		DARK_RED,
		DARK_VOILET,
		DAKR_YELLOW,
		GRAY,
		DARK_GRAY,
		BLUE,
		GREEN,
		SKYBLUE,
		RED,
		VIOLET,
		YELLOW,
		WHITE,
	};

	const int BASIC_BG_COLOR{ BLACK << 4 };
	const int BASIC_FG_COLOR{ WHITE };

	int CUR_BG_COLOR{BASIC_BG_COLOR};
	int CUR_FG_COLOR{BASIC_FG_COLOR};

	// change color
	export void setConsoleColor( int fg, int bg );
	export void setConsoleFgColor( int color );
	export void setConsoleBgColor( int color );

	// color code to string
	export std::string getColorCode( int fg, int bg );
	export std::string getFgColorCode( int fg );
	export std::string getBgColorCode( int bg );
}