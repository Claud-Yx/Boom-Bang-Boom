export module Renderer;

import Utility;
import <functional>;

namespace Render {
	std::function<void()> displayFunc;

	export void setDisplayFunc( std::function<void()> fn );
	export void Display();

	export void setCursorPos( Util::Coord );
}