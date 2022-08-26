export module Client:InGame;

import <string>;
import Frame;
import Renderer;
import Utility;
import Stage;

namespace InGame {
	Render::PartedOutputBuffer stageMap;	// 플레이 화면
	Render::PartedOutputBuffer upperNotice;	// 상단 UI
	Render::PartedOutputBuffer sideNotice;	// 측면 UI (위치 변경 가능



	void Render();
	std::string Update( unsigned short key );
	void Init();

	export Frame inGameFrame{ "InGame", Render, Update, Init };
}