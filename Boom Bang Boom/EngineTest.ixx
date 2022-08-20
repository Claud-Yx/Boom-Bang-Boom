export module EngineTest;

import <format>;
import Renderer;
import Frame;

namespace TEST {
	void renderTest()
	{
		Render::getFgColorCode( 1 );

		Render::PartedOutputBuffer out;

		std::string word = std::format( "{}H{}e{}l{}l{}o {}w{}o{}r{}l{}d{}",
			Render::getFgColorCode( 1 ), Render::getFgColorCode( 2 ), Render::getFgColorCode( 3 ),
			Render::getFgColorCode( 4 ), Render::getFgColorCode( 5 ), Render::getColorCode( 6, 15 ),
			Render::getColorCode( 7, 15 ), Render::getColorCode( 8, 15 ), Render::getColorCode( 9, 15 ),
			Render::getColorCode( 10, 15 ), Render::getColorCode( 15, 0 )
		);

		out << word << '\n';

		out.showBuffer();
		out.renderInParted( { 10, 10 } );
		out.renderInParted( { 40, 10 } );
		out.renderInParted( { 10, 20 } );
		out.renderInParted( { 40, 20 } );
	}

	std::string updateTest( unsigned short key ) { return ""; }

	export Frame testFrame{ "TestFrame", renderTest, updateTest };
}