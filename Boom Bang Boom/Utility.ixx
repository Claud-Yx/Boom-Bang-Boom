export module Utility;

import <vector>;
import <string>;
import <iostream>;
import <format>;
import <conio.h>;
import FontSpace;

export namespace Util {
	export unsigned short width{}, height{};

	export enum KEY_EVENT {
		ENTER = 13,
		ALT_L = 18,
		ALT_R = 21,
		CTRL_L = 17,
		CTRL_R = 25,
		SHIFT = 16,
		ESC = 27,
		SPACE = 32,
		KEY_UP = 296,
		KEY_DOWN = 304,
		KEY_LEFT = 299,
		KEY_RIGHT = 301,
		ARROW_KEY_CODE = 224
	}KE;

	export using KEYBOARD = unsigned short;

	export struct Coord {
		int x, y;

		Coord() : x{}, y{} {}
		Coord( int x, int y ) : x{ x }, y{ y } {}
		Coord( int value ) : x{ value }, y{ value } {}

		inline Coord operator+( Coord rhs ) { return { x + rhs.x, y + rhs.y }; }
		inline Coord operator+( int offset ) { return { x + offset, y + offset }; }
		inline Coord operator-( Coord rhs ) { return { x - rhs.x, y - rhs.y }; }
		inline Coord operator-( int offset ) { return { x - offset, y - offset }; }
		inline Coord operator*( Coord rhs ) { return { x * rhs.x, y * rhs.y }; }
		inline Coord operator*( int offset ) { return { x * offset, y * offset }; }
		inline Coord operator/( Coord rhs ) { return { x / rhs.x, y / rhs.y }; }
		inline Coord operator/( int offset ) { return { x / offset, y / offset }; }

		inline void operator+=( Coord rhs ) { x += rhs.x; y += rhs.y; }
		inline void operator+=( int offset ) { x += offset; y += offset; }
		inline void operator-=( Coord rhs ) { x -= rhs.x; y -= rhs.y; }
		inline void operator-=( int offset ) { x -= offset; y -= offset; }
		inline void operator*=( Coord rhs ) { x *= rhs.x; y *= rhs.y; }
		inline void operator*=( int offset ) { x *= offset; y *= offset; }
		inline void operator/=( Coord rhs ) { x /= rhs.x; y /= rhs.y; }
		inline void operator/=( int offset ) { x /= offset; y /= offset; }

		inline bool operator<( Coord rhs ) { return x < rhs.x and y < rhs.y; }
		inline bool operator>( Coord rhs ) { return x > rhs.x and y > rhs.y; }
		inline bool operator<=( Coord rhs ) { return x <= rhs.x and y <= rhs.y; }
		inline bool operator>=( Coord rhs ) { return x >= rhs.x and y >= rhs.y; }
		inline bool operator==( Coord rhs ) { return x == rhs.x and y == rhs.y; }
		inline bool operator!=( Coord rhs ) { return x != rhs.x and y != rhs.y; }

	}*pCoored;

	export class Option {
		std::string title;
		std::vector<std::string> options;
		int indent{};
		size_t selected{};

	public:
		Option() : title{}, options{} {}
		Option( std::string title ) : title{ title }, options{} {}
		Option( std::string title, std::vector<std::string> options ) : title{ title }, options{ options } {}

		void outputTitle();
		void outputOptions();
		void outputMenu();

		inline void setTitle( std::string newTitle ) { title = newTitle; }
		inline void addOption( std::string newOption ) { options.emplace_back( newOption ); }

		void moveUp();
		void moveDown();
	};

	export const KEYBOARD inputKey()
	{
		KEYBOARD key = _getch();

		if ( key == ARROW_KEY_CODE )
			key += _getch();

		return key;
	}
}

using namespace Util;

void Option::outputTitle()
{
	std::string sortedTitle = " " + title + " ";
	std::cout << std::format( "{0:=^{1}}\n", sortedTitle, width );
}

void Option::outputOptions()
{
	indent = width / 2 - title.size() / 2 + 2;

	for ( size_t i{}; auto & option : options ) {
		if ( i == selected )
			std::cout << std::format( "{0:<{1}}¢º{3}{2:<}\n", "", indent-3, option, sc());
		else
			std::cout << std::format( "{0:<{1}}{2:<}\n", "", indent, option);
		++i;
	}
}

void Option::outputMenu()
{
	outputTitle();
	outputOptions();
	std::cout << std::format( "{0:=<{1}}\n", "", width );
}

void Option::moveUp()
{
	if ( long long(--selected) < 0 )
		selected = options.size() - 1;
}

void Option::moveDown()
{
	if ( ++selected >= options.size() )
		selected = 0;
}