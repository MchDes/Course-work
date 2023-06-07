#pragma once

#include <map>
#include <string>

#include "WindowAction.hpp"

class Window;

class App 
{
 public:
  App();

  void Run();

  void ChangeWindow(WindowAction action);

 private:
  
  Window* main_window;

  std::map<WindowAction, Window*> window_map;
};