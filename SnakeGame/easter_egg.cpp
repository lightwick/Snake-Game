#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

// TODO: get x, y as parameters and draw from there
void drawSans() {
	wprintf(L"                ██████████████████\n            ████                  ████\n          ██                          ██\n          ██                          ██\n        ██                              ██\n        ██                    ██████    ██\n        ██                    ██████    ██\n        ██    ██████    ██    ██████    ██\n          ██          ██████          ██\n        ████  ██                  ██  ████\n        ██    ██████████████████████    ██\n        ██      ██  ██  ██  ██  ██      ██\n          ████    ██████████████    ████\n        ██████████              ██████████\n      ██  ██████████████████████████████  ██\n    ████  ██    ██      ██      ██    ██  ████\n    ██      ██    ██████  ██████    ██      ██\n  ██    ████  ██████    ██    ██████  ████    ██\n  ██        ██    ██          ██    ██        ██\n  ██          ██  ██          ██  ██          ██\n    ██      ██    ████      ████    ██      ██\n      ████  ██    ██          ██    ██  ████\n        ██████    ██████████████    ██████\n          ████    ██████████████    ████\n        ██████████████████████████████████\n        ████████████████  ████████████████\n          ████████████      ████████████\n      ██████        ██      ██        ██████\n      ██          ████      ████          ██\n        ██████████              ██████████\n");
}

void easterInit() {
	_setmode(_fileno(stdout), _O_U16TEXT);
}

void playMusic()
{
	PlaySound(TEXT("src/megalovania.wav"), NULL, SND_ASYNC || SND_LOOP);
}

void musicOff() {
	PlaySound(NULL, 0, 0);
}