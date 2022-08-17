export module FontSpace;

import <string>;
import <format>;
import <iostream>;

export namespace FS {
	bool ONE_BYTE_SPECIAL_CHARACTERS{};

	export void setOneByteFontSpace( bool bl ) { ONE_BYTE_SPECIAL_CHARACTERS = bl; }

	export void displaySelectFontSpaceMenu()
	{
		using namespace std;

		cout << endl << endl;

		cout << format( "{:^80}", "Choose the normal display") << endl << endl << endl;

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

	export std::string Update( unsigned short key )
	{
		switch ( key ) {
		case '1':
			setOneByteFontSpace( false );
			break;
		case '2':
			setOneByteFontSpace( true );
			break;
		default:
			return "displaySelectFontSpaceMenu";
		}

		return "mainMenu";
	}
}

export std::string sc()
{
	if ( FS::ONE_BYTE_SPECIAL_CHARACTERS )
		return " ";
	else
		return "  ";
}