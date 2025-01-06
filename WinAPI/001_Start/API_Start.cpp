#include <Windows.h>

int WINAPI WinMain(HINSTANCE _hinstance, HINSTANCE, char*, int)
{
	MessageBoxA(0, "Test Message", "Box Name", MB_OK);					// 확인 버튼 메세지 창
	MessageBoxA(0, "Test Message", "Box Name", MB_OKCANCEL);			// 확인 취소 버튼 메세지 창
	MessageBoxA(0, "Test Message", "Box Name", MB_ABORTRETRYIGNORE);	// 중단 다시시도 무시 버튼 메세지 창
	return 0;
}

// HINSTANCE : 윈도우 프로그램이 가지고 있는 고유 ID, 핸들 인스턴스

/*
프로젝트 속성에서 링커 -> 시스템 -> 하위 시스템을 윈도우로 변경
*/