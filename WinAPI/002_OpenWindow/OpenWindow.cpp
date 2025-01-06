#include <Windows.h>

LRESULT CALLBACK WndProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	if (_msg == WM_DESTROY)	// 윈도우가 파괴될 때
	{
		PostQuitMessage(0); //프로그램 종료
	}
	return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE, char*, int)
{
	// 만들 윈도우 속성 정의 및 등록
	WNDCLASSEXA win = { 0 };
	win.cbSize = sizeof(win);
	win.style = CS_HREDRAW | CS_VREDRAW;	// 크기 변환 시 재렌더링
	win.hInstance = _hInstance;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.lpszClassName = "my window";
	win.lpfnWndProc = WndProc;
	RegisterClassExA(&win);					// 생성한 윈도우 속성을 등록

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

/*
윈도우가 만들어지는 과정

1. 열려고 하는 윈도우의 속성을 지정
	: 윈도우 속성(WNDCLASSEXA) 구조체로 지정

2. 해당 속성으로 윈도우 창을 오픈
	: 

3. 해당 윈도우의 메세지 처리를 반복

*/

/*
WNDCLASSEXA 구조체 내부 속성

UINT        cbSize;				구조체의 크기 결정
UINT        style;				출력 형태
WNDPROC     lpfnWndProc;		프로시저 함수
int         cbClsExtra;			윈도우 클래스에서 사용할 추가 메모리 지정
int         cbWndExtra;			개별 윈도우 인스턴스에서 사용할 추가 메모리 지정
HINSTANCE   hInstance;			윈도우 인스턴스
HICON       hIcon;				아이콘 변경
HCURSOR     hCursor;			커서 변경
HBRUSH      hbrBackground;		배경 색
LPCSTR      lpszMenuName;		메뉴 이름
LPCSTR      lpszClassName;		클래스 이름
HICON       hIconSm;			작은 아이콘
*/

// HWND : 윈도우 핸들, 윈도우 고유의 ID를 의미
/*
HWND CreateWindowA(
	클래스 이름, 윈도우 타이틀, 윈도우 스타일,
	윈도우 위치 x 좌표, y 좌표,
	윈도우의 너비, 윈도우의 높이,
	부모 윈도우 핸들, 메뉴,
	인스턴스, 윈도우 정보
);

CreateWindowA는 넣어준 매개변수로 윈도우를 생성하고 해당 윈도우의 핸들값을 반환해줌

*/