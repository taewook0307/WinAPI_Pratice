#include <Windows.h>

int WINAPI WinMain(HINSTANCE _hinstance, HINSTANCE, char*, int)
{
	MessageBoxA(0, "Test Message", "Box Name", MB_OK);					// Ȯ�� ��ư �޼��� â
	MessageBoxA(0, "Test Message", "Box Name", MB_OKCANCEL);			// Ȯ�� ��� ��ư �޼��� â
	MessageBoxA(0, "Test Message", "Box Name", MB_ABORTRETRYIGNORE);	// �ߴ� �ٽýõ� ���� ��ư �޼��� â
	return 0;
}

// HINSTANCE : ������ ���α׷��� ������ �ִ� ���� ID, �ڵ� �ν��Ͻ�

/*
������Ʈ �Ӽ����� ��Ŀ -> �ý��� -> ���� �ý����� ������� ����
*/