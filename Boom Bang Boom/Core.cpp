module Core;

namespace Core {
	void Run()
	{
		Init();

		while ( running ) {
			Render::Render();
			Update::keyEvent();
			Update::Update();

			if ( currentFrameName == "" ) 
				continue;
			else if ( currentFrameName == "quit" ) 
				break;
			else
				changeFrame( currentFrameName );
		}
	}

	void Init()
	{
		// variable init
		Update::currentFrameName = &currentFrameName;
		
		// Window setting
		Render::setConsoleSize(80, 25);
		Render::setConsoleTitle( "Boom Bang Boom!" );
		Render::showCursor( false );
		
		// Frames
		frames.push_back( &FS::fontSpaceMenuFrame );
		frames.push_back( &TEST::testFrame );
		changeFrame( "FontSpaceMenu" );
	}

	void changeFrame( std::string frameName )
	{
		Render::clearConsole();
		auto frame = find_if( frames.begin(), frames.end(), [&frameName]( const Frame* lhs ) {
			return lhs->getName() == frameName;
			} );

		if ( frame == frames.end() ) {
			std::cerr << "ERROR: no frame" << std::endl;
			exit( 1 );
		}

		Render::setDisplayMethod( *frame );
		Update::setUpdateMethod( *frame );
		
		Update::Init();
	}
}