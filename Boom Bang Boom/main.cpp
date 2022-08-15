import Core;
import Utility;

int main()
{
	Util::Option mainMenu( "This is main manu" );
	mainMenu.addOption( "Start" );
	mainMenu.addOption( "Save" );
	mainMenu.addOption( "Load" );
	mainMenu.addOption( "Exit" );

	mainMenu.outputMenu(35);
}