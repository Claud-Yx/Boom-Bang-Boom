export module Utility;

import <vector>;
import <string>;
import <iostream>;

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

	export struct Option {
		std::string title;
		std::vector<std::string> options;
		int selected{};

		Option() : title{}, options{} {}
		Option( std::string title ) : title{ title }, options{} {}
		Option( std::string title, std::vector<std::string> options ) : title{ title }, options{ options } {}

		void outputTitle();
		void outputOptions();
	};
}