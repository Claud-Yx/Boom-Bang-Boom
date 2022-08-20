export module Client:InGame;

import <string>;
import Frame;
import Renderer;
import Utility;

namespace InGame {
	Render::PartedOutputBuffer stageMap;	// �÷��� ȭ��
	Render::PartedOutputBuffer upperNotice;	// ��� UI
	Render::PartedOutputBuffer sideNotice;	// ���� UI (��ġ ���� ����

	void Render();
	std::string Update( unsigned short key );
	void Init();

	export Frame inGameFrame{ "InGame", Render, Update, Init };
}