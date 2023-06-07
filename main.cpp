#include <iostream>

#include "EquationTypes.hpp"

#include "tabulate/table.hpp"
#include "ConsoleFunctions.hpp"

#include "App.hpp"

#include <windows.h>

using namespace tabulate;
using Row_t = Table::Row_t;

int main(int argc, char const *argv[]) {
  SetConsoleTitle("solver");
  
  App app;

  app.Run();
}
