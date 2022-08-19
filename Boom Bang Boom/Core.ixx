export module Core;

import <vector>;
import <iostream>;
import <algorithm>;
import <format>;
import EngineTest;
import Renderer;
import Updater;
import Utility;
import FontSpace;
import Frame;

namespace Core {
	bool running{ true };
	std::vector<Frame*> frames{};
	std::string currentFrameName{};

	export void Run();
	void Init();

	void changeFrame( std::string frameName );
}