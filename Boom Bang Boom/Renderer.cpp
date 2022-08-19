#include <Windows.h>

module Renderer;

import <format>;
import <iostream>;
import <string>;

namespace Render {

	void Render()
	{
		setCursorPos( { 0, 0 } );

		switch ( renderMode ) {
		case 'f':
			displayFunc();
			break;
		case 'm':
			displayMethod(*currentFrame);
			break;
		default:
			std::cerr << std::format("ERROR: wrong render mode( '{}' )", renderMode) << std::endl;
			system( "pause" );
			exit(1);
		}
	}

	void setCursorPos( Util::Coord pos )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { short( pos.x ), short( pos.y ) } );
	}

	void showCursor( bool show )
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		if ( !show ) {
			cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
			cursorInfo.bVisible = false; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è
		}
		else {
			cursorInfo.dwSize = 100; //Ä¿¼­ ±½±â (1 ~ 100)
			cursorInfo.bVisible = true; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è
		}
		SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &cursorInfo );
	}

	void setConsoleSize( unsigned short width, unsigned short height )
	{
		Render::width = width;
		Render::height = height;
		Util::width = width;
		Util::height = height;

		system( std::format( "mode con lines={} cols={}", height, width ).c_str() );
	}

	void setConsoleTitle( const char* title )
	{
		system( std::format( "title {}", title ).c_str() );
	}

	void clearConsole()
	{
		std::string blank{ std::format( "{0:<{1}}", "", width ) };
		for ( int y{}; y < height; ++y )
			std::cout << blank << std::endl;
	}

	void setConsoleColor( int fg, int bg )
	{
		CUR_BG_COLOR = (bg << 4) & 0xf0;
		CUR_FG_COLOR = fg & 0xf;

		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), CUR_FG_COLOR | CUR_BG_COLOR );
	}

	void setConsoleFgColor( int color )
	{
		CUR_FG_COLOR = color & 0xf;
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), CUR_FG_COLOR | CUR_BG_COLOR );
	}

	void setConsoleBgColor( int color )
	{
		CUR_BG_COLOR = (color << 4) & 0xf0;
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), CUR_FG_COLOR | CUR_BG_COLOR );
	}

	std::string getColorCode( int fg, int bg )
	{
		return std::format( "\a{:x}{:x}", bg, fg );
	}

	std::string getFgColorCode( int fg )
	{
		return std::format( "\a{:x}{:x}", CUR_BG_COLOR, fg );
	}

	std::string getBgColorCode( int bg )
	{
		return std::format( "\a{:x}{:x}", bg, CUR_FG_COLOR );
	}

	void PartedOutputBuffer::renderInParted( Util::Coord start_pos )
	{
		setCursorPos( start_pos );
		
		for ( auto i{ buffer.begin() }; i != buffer.end(); ++i ) {
			if ( *i == '\n' ) {
				++start_pos.y;
				setCursorPos( start_pos );
				continue;
			}

			else if ( *i == '\a' ) {
				int bg = Util::hexCharToInt( *(++i) );
				int fg = Util::hexCharToInt( *(++i) );

				setConsoleColor( fg, bg );
				continue;
			}

			std::cout << *i;
		}
	}
}