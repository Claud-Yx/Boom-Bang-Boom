export module Core;

import Renderer;
import Updater;
import Utility;
import FontSpace;
import Frame;
import <vector>;

namespace Core {
	bool running{ true };
	std::vector<Frame> frames{};

	export void Run();
	void Init();
}