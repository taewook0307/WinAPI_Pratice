#include <Windows.h>

/*
���� ����Ǵ� �޼���
1. WM_CREATE							�����찡 �����Ǹ� ������ �޼���
2. WM_DESTROY							�����찡 ����Ǹ� (X��ư ������) ������ �޼���
3. WM_PAINT								�������� �׷����� �߻��ϴ� �޼���
4. WM_KEYDOWN, WM_KEYUP					Ű������ Ư�� Ű(shift, enter ��)�� �����ų�(DOWM) ����(UP) ����� �޼���
5. WM_CHAR								�Ϲ����� ���� Ű(���� ��)�� ������ ����� �޼���
6. WM_COMMAND							�������� �޴� ���� ������ ����� �޼���
7. WM_LBUTTONDOWN, WM_LBUTTONUP			���� ���콺�� �����ų� �� �� �߻��ϴ� �޼���
8. WM_RBUTTONDOWN, WM_RBUTTONUP			������ ���콺�� �����ų� �� �� �߻��ϴ� �޼���
*/

LRESULT CALLBACK WndProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	switch (_msg)
	{
		case WM_CREATE:			//������ �����Ǹ� �߻�
			MessageBoxA(_hwnd, "wm_create : ������ ����", "�޼���", MB_OK);
			break;
		case WM_LBUTTONDOWN:	//���� ���콺 ������ �߻�
			MessageBoxA(_hwnd, "wm_lbuttondown : ���� ��ư ����", "�޼���", MB_OK);
			break;
		case WM_CHAR:			//Ű ������ �߻�
			MessageBoxA(_hwnd, "wm_char : ���� Ű ����", "�޼���", MB_OK);
			break;
		case WM_DESTROY:		//�ı��Ǹ� �߻�
			MessageBoxA(_hwnd, "wm_destroy : ������ ����", "�޼���", MB_OK);
			PostQuitMessage(0);
			break;
	}

	return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE, char*, int)
{
	// ���� ������ �Ӽ� ���� �� ���
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.hInstance = _hInstance;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc;
	RegisterClassExA(&win);

	// ������ ���� ��û�� ���� �� ID��(Handle ��) ��ȯ
	HWND hwnd;
	hwnd = CreateWindowA
	(
		"my window",
		"Open Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		0, 0, _hInstance, 0
	);

	// ���� �ڵ鰪�� �̿��� ������ â�� ���������� ��û
	ShowWindow(hwnd, 1);

	// ������ â�� �޼��� ó�� �κ�
	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}