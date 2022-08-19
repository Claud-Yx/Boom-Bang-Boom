export module FontSpace;

import <string>;
import <format>;
import <iostream>;
import Frame;

export namespace FS {
	bool ONE_BYTE_SPECIAL_CHARACTERS{};

	void setOneByteFontSpace( bool bl ) { ONE_BYTE_SPECIAL_CHARACTERS = bl; }

	void Render()
	{
		using namespace std;

		cout << endl << endl;

		cout << format( "{:^80}", "Choose the normal display" ) << endl << endl << endl;

		cout << format( "{:^80}", "No.1      " ) << endl;
		cout << format( "{:^80}", "¡á¡à¡á¡à¡á" ) << endl;
		cout << format( "{:^80}", "¡á  ¡Ú  ¡á" ) << endl;
		cout << format( "{:^80}", "¡á¡à¡á¡à¡á" ) << endl << endl << endl;

		cout << format( "{:^80}", "No.2      " ) << endl;
		cout << format( "{:^80}", "¡á¡à¡á¡à¡á" ) << endl;
		cout << format( "{:^80}", "¡á ¡Ú ¡á  " ) << endl;
		cout << format( "{:^80}", "¡á¡à¡á¡à¡á" ) << endl << endl << endl;

		cout << format( "{:^80}", "If the number 2 is normal," ) << endl;
		cout << format( "{:^80}", "I recommand change your font to basic font" ) << endl << endl << endl;
		cout << format( "{:^80}", "Select the number 1 or 2" ) << endl;
	}

	std::string Update( unsigned short key )
	{
		switch ( key ) {
		case '1':
			setOneByteFontSpace( false );
			break;
		case '2':
			setOneByteFontSpace( true );
			break;
		default:
			return "";
		}

		return "TestFrame";
		//return "mainMenu";
	}

	export Frame fontSpaceMenuFrame{ "FontSpaceMenu", Render, Update };
}

export std::string sc()
{
	if ( FS::ONE_BYTE_SPECIAL_CHARACTERS )
		return " ";
	else
		return "  ";
}