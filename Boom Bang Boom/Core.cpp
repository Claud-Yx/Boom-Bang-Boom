module Core;

import <format>;

namespace Core {
	void Run()
	{
		Init();

		while ( running ) {
			Render::Render();
			Update::keyEvent();
			Update::Update();
		}
	}

	void showTest() 
	{
		Render::getFgColorCode( 1 );

		Render::PartedOutputBuffer out;

		std::string word = std::format( "{}H{}e{}l{}l{}o {}w{}o{}r{}l{}d{}",
			Render::getFgColorCode( 1 ), Render::getFgColorCode( 2 ), Render::getFgColorCode( 3 ),
			Render::getFgColorCode( 4 ), Render::getFgColorCode( 5 ), Render::getFgColorCode( 6 ),
			Render::getFgColorCode( 7 ), Render::getFgColorCode( 8 ), Render::getFgColorCode( 9 ),
			Render::getFgColorCode( 10 ), Render::getFgColorCode( 15 )
		);

		out << word << '\n';

		out.showBuffer();
		out.renderInParted( { 10, 10 } );
		out.renderInParted( { 40, 10 } );
		out.renderInParted( { 10, 20 } );
		out.renderInParted( { 40, 20 } );
	}

	void Init()
	{
		// running init
		Update::running = &running;
		
		// Window setting
		Render::setConsoleSize(80, 25);
		Render::setConsoleTitle( "Boom Bang Boom!" );
		Render::showCursor( false );

		//Render::setDisplayFunc( FS::displaySelectFontSpaceMenu );
		Render::setDisplayFunc( showTest );
		Update::setUpdateFunc( FS::Update );
	}
}