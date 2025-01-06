#include <Windows.h>

LRESULT CALLBACK WndProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	if (_msg == WM_DESTROY)	// �����찡 �ı��� ��
	{
		PostQuitMessage(0); //���α׷� ����
	}
	return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE, char*, int)
{
	// ���� ������ �Ӽ� ���� �� ���
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;	// ũ�� ��ȯ �� �緻����
	win.hInstance = _hInstance;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc;
	RegisterClassExA(&win);					// ������ ������ �Ӽ��� ���

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

/*
�����찡 ��������� ����

1. ������ �ϴ� �������� �Ӽ��� ����
	: ������ �Ӽ�(WNDCLASSEXA) ����ü�� ����

2. �ش� �Ӽ����� ������ â�� ����
	: 

3. �ش� �������� �޼��� ó���� �ݺ�

*/

/*
WNDCLASSEXA ����ü ���� �Ӽ�

UINT        cbSize;				����ü�� ũ�� ����
UINT        style;				��� ����
WNDPROC     lpfnWndProc;		���ν��� �Լ�
int         cbClsExtra;			������ Ŭ�������� ����� �߰� �޸� ����
int         cbWndExtra;			���� ������ �ν��Ͻ����� ����� �߰� �޸� ����
HINSTANCE   hInstance;			������ �ν��Ͻ�
HICON       hIcon;				������ ����
HCURSOR     hCursor;			Ŀ�� ����
HBRUSH      hbrBackground;		��� ��
LPCSTR      lpszMenuName;		�޴� �̸�
LPCSTR      lpszClassName;		Ŭ���� �̸�
HICON       hIconSm;			���� ������
*/

// HWND : ������ �ڵ�, ������ ������ ID�� �ǹ�
/*
HWND CreateWindowA(
	Ŭ���� �̸�, ������ Ÿ��Ʋ, ������ ��Ÿ��,
	������ ��ġ x ��ǥ, y ��ǥ,
	�������� �ʺ�, �������� ����,
	�θ� ������ �ڵ�, �޴�,
	�ν��Ͻ�, ������ ����
);

CreateWindowA�� �־��� �Ű������� �����츦 �����ϰ� �ش� �������� �ڵ鰪�� ��ȯ����

*/