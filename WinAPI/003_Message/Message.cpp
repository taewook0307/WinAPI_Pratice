#include <Windows.h>

/*
자주 샤용되는 메세지
1. WM_CREATE							윈도우가 생성되면 나오는 메세지
2. WM_DESTROY							윈도우가 종료되면 (X버튼 누르면) 나오는 메세지
3. WM_PAINT								윈도우의 그래픽을 발생하는 메세지
4. WM_KEYDOWN, WM_KEYUP					키보드의 특수 키(shift, enter 등)를 누르거나(DOWM) 떼면(UP) 생기는 메세지
5. WM_CHAR								일반적인 문자 키(영어 등)를 누르면 생기는 메세지
6. WM_COMMAND							윈도우의 메뉴 등을 누르면 생기는 메세지
7. WM_LBUTTONDOWN, WM_LBUTTONUP			왼쪽 마우스를 누르거나 뗄 떼 발생하는 메세지
8. WM_RBUTTONDOWN, WM_RBUTTONUP			오른쪽 마우스를 누르거나 뗄 떼 발생하는 메세지
*/

LRESULT CALLBACK WndProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	switch (_msg)
	{
		case WM_CREATE:			//윈도우 생성되면 발생
			MessageBoxA(_hwnd, "wm_create : 윈도우 생성", "메세지", MB_OK);
			break;
		case WM_LBUTTONDOWN:	//왼쪽 마우스 누르면 발생
			MessageBoxA(_hwnd, "wm_lbuttondown : 왼쪽 버튼 눌림", "메세지", MB_OK);
			break;
		case WM_CHAR:			//키 눌리면 발생
			MessageBoxA(_hwnd, "wm_char : 문자 키 눌림", "메세지", MB_OK);
			break;
		case WM_DESTROY:		//파괴되면 발생
			MessageBoxA(_hwnd, "wm_destroy : 윈도우 종료", "메세지", MB_OK);
			PostQuitMessage(0);
			break;
	}

	return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE, char*, int)
{
	// 만들 윈도우 속성 정의 및 등록
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;
	win.hInstance = _hInstance;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc;
	RegisterClassExA(&win);

	// 윈도우 제작 요청을 보낸 뒤 ID값(Handle 값) 반환
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

	// 받은 핸들값을 이용해 윈도우 창이 보여지도록 요청
	ShowWindow(hwnd, 1);

	// 보여진 창의 메세지 처리 부분
	MSG msg;
	while (GetMessageA(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}