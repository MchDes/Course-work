#include <iostream>

#include "Window.hpp"
#include "ConsoleFunctions.hpp"

App::App() 
{
  window_map.insert({WindowAction::MENU, new MenuWindow(this)});
  window_map.insert({WindowAction::GENERAL, new GeneralWindow(this)});
  window_map.insert({WindowAction::VIET, new VietWindow(this)});
  window_map.insert({WindowAction::GUESS, new GuessWindow(this)});
}

void App::Run() 
{
  system("color 2F");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL, "Russian");
  ClearConsole();
  ChangeWindow(WindowAction::MENU);
}

void App::ChangeWindow(WindowAction action) 
{
  if (action == WindowAction::EXIT) 
  {
    ClearConsole();
    system("color 0F");
    std::exit(0);
  }

  main_window = window_map.at(action);
  ClearConsole();
  main_window->draw();
}
