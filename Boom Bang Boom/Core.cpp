module Core;

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

	void Init()
	{
		// running init
		Update::running = &running;
		
		// Window setting
		Render::setConsoleSize(80, 25);
		Render::setConsoleTitle( "Boom Bang Boom!" );
		Render::showCursor( false );

		Render::setDisplayFunc( FS::displaySelectFontSpaceMenu );
		Update::setUpdateFunc( FS::Update );
	}
}