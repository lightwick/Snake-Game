#include <windows.h>
#include <iostream>

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void cls()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(out, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(out, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(out, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(out, topLeft);
}

void ShowConsoleCursor(int showFlag)
{
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setTextColor(WORD color) {
	SetConsoleTextAttribute(out, color);
}

void consoleInit() {
	LPCWSTR consoleTitle = L"Snake Game - By Noh Yong Jae";
	SetConsoleTitle(consoleTitle);

	HWND hwnd = GetConsoleWindow();
	// struct RECT: left, top, right bottom in that order
	RECT rect = { 100, 100, 780, 700 };

	MoveWindow(hwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);

	ShowConsoleCursor(0);
}