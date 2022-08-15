export module Utility;

import <vector>;
import <string>;
import <iostream>;
import <format>;

export namespace Util {
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
		int selected{};

	public:
		Option() : title{}, options{} {}
		Option( std::string title ) : title{ title }, options{} {}
		Option( std::string title, std::vector<std::string> options ) : title{ title }, options{ options } {}

		void outputTitle();
		void outputOptions( int indent = 0 );
		void outputMenu( int indent = 0);

		inline void setTitle( std::string newTitle ) { title = newTitle; }
		inline void addOption( std::string newOption ) { options.emplace_back( newOption ); }
	};
}

using namespace Util;

void Option::outputTitle()
{
	std::string sortedTitle = " " + title + " ";
	std::cout << std::format( "{:=^80}", sortedTitle ) << std::endl;
}

void Util::Option::outputOptions(int indent)
{
	for ( auto& option : options ) 
		std::cout << std::format( "{0:<{1}}{2:<}", "", indent, option) << std::endl;
}

void Util::Option::outputMenu( int indent )
{
	outputTitle();
	outputOptions( indent );
}
