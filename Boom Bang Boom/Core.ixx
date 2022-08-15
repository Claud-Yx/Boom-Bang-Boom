export module Core;

import Renderer;
import Updater;
import Utility;
import FontSpace;

namespace Core {
	bool running{ true };

	export void Run();
	void Init();
}