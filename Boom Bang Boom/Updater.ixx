export module Updater;

import <functional>;
import <string>;
import <format>;
import <iostream>;
import Frame;
import Utility;

namespace Update {
	std::function<std::string( Util::KEYBOARD )> updateFunc;
	std::function<std::string( Frame&, Util::KEYBOARD )> updateMethod{ &Frame::Update };
	char updateMode{};

	std::function<void( Frame& )> initMethod( &Frame::Init );

	Frame* currentFrame {};
	Util::KEYBOARD key{};

	export std::string* currentFrameName{};

	export void setUpdateFunc( std::function<std::string( Util::KEYBOARD )> func )
	{
		updateFunc = func;
		updateMode = 'f';
	}

	export void setUpdateMethod( Frame* updateFrame )
	{
		updateMode = 'm';
		currentFrame = updateFrame;
	}

	export void Update()
	{
		switch ( updateMode ) {
		case 'f':
			*currentFrameName = updateFunc( key );
			break;
		case 'm':
			*currentFrameName = updateMethod( *currentFrame, key );
			break;
		default:
			std::cerr << std::format( "ERROR: wrong update mode( '{}' )", updateMode ) << std::endl;
			system( "pause" );
			exit( 1 );
		}
	}

	//export void setInitializer( Frame* initialieFrame )
	//{

	//}

	export void Init()
	{
		initMethod(*currentFrame);
	}

	export void keyEvent()
	{
		key = Util::inputKey();
	}

	export inline std::string getCurrentFrame() { return *currentFrameName; }
}