#include <windows.h>

#include "ConsoleFunctions.hpp"

void SetCursor(int x, int y) 
{ 
  COORD pos = {x, y};
  HANDLE std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(std_handle, pos);
}

void ClearConsole() 
{
  COORD topLeft  = {0, 0};
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;

  GetConsoleScreenBufferInfo(console, &screen);
  FillConsoleOutputCharacterA(
      console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );
  
  SetConsoleCursorPosition(console, topLeft);
}