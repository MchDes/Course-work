#include <vector>
#include <iostream>

#include "Window.hpp"
#include "tabulate/table.hpp"
#include "App.hpp"
#include "EquationTypes.hpp"
#include "ConsoleFunctions.hpp"
#include "WindowAction.hpp"

using namespace tabulate;

GeneralWindow::GeneralWindow(App* app) : app(app) {};

void GeneralWindow::draw() 
{
  std::cout << "\n";

  std::vector<double> coefs = ReadCoef();

  std::cout << "\n";

  action(coefs);
  
  eq->PrintDescription();

  std::cout << "\n";

  eq->ShowAns(eq->FindRoots());

  exit_action();
}

void GeneralWindow::exit_action()
{
  std::cout << "\n\n";

  std::cout << "Нажмите клавишу enter для выхода в меню...";

  char c = getchar();
  c = getchar();

  app->ChangeWindow(WindowAction::MENU);
}

void GeneralWindow::action(std::vector<double> coefs)
{
  double a, b, c;  
  a = coefs[0];
  b = coefs[1];
  c = coefs[2];
  
  if (IsZero(a) && IsZero(b) && IsZero(c)) 
  {
    eq = new Type1();
  } 
  else if (IsZero(a) && IsZero(b) && !IsZero(c)) 
  {
    eq = new Type2(c);
  }
   else if (!IsZero(a) && !IsZero(b) && !IsZero(c))
  {
    eq = new Type3(a, b, c);
  } 
  else if (!IsZero(a) && !IsZero(b) && IsZero(c)) 
  {
    eq = new Type4(a, b);
  } 
  else if (!IsZero(a) && IsZero(b) && !IsZero(c)) 
  {
    eq = new Type5(a, b);
  } 
  else if (!IsZero(a) && IsZero(b) && IsZero(c)) 
  {
    eq = new Type6(a);
  } 
  else if (IsZero(a) && !IsZero(b) && !IsZero(c)) 
  {
    eq = new Type7(b, c);
  } 
  else if (IsZero(a) && !IsZero(b) && IsZero(c)) 
  {
    eq = new Type8(b);
  }
}

MenuWindow::MenuWindow(App* app) 
{
  this->app = app;
};
  
void MenuWindow::draw() {
  Table menu;
  menu.format()
      .font_color(Color::white)
      .padding_left(15)
      .padding_right(0)
      .corner_color(Color::green)
      .border_color(Color::green);

  menu.column(0).format().width(40).font_align(FontAlign::center);

  Table embedded_table;

  embedded_table.add_row(Table::Row_t{"МЕНЮ"});
  embedded_table.add_row(Table::Row_t{"1. Решение уравнений с помощью дискриминанта"});
  embedded_table.add_row(Table::Row_t{"2. Решение уравнений с помощью теоремы Виета"});
  embedded_table.add_row(Table::Row_t{"3. Решение уравнений методом подбора"});
  embedded_table.add_row(Table::Row_t{"4. Выход"});
  embedded_table.row(0).format().font_align(FontAlign::center);

  menu.add_row(Table::Row_t{embedded_table});

  SetCursor(0, 3);
  std::cout << menu;

  SetCursor(16, 16);

  std::cout << "==> Введите номер пункта : ";
  
  action();
};

void MenuWindow::action() 
{
  int choice;  
  std::cin >> choice;

  switch (choice) 
  {
    case 1:
      app->ChangeWindow(WindowAction::GENERAL);
      break;

    case 2:
      app->ChangeWindow(WindowAction::VIET);
      break;

    case 3:
      app->ChangeWindow(WindowAction::GUESS);
      break;

    case 4:
      app->ChangeWindow(WindowAction::EXIT);
      break;

    default:
      std::cerr << "uknown window type";
  }        
}

VietWindow::VietWindow(App* app) : app(app) {}

void VietWindow::draw()
 {
  std::cout << "\n";

  std::vector<double> coefs = ReadCoef();

  std::cout << "\n";

  action(coefs);
  
  eq->PrintDescription();

  std::cout << "\n";

  eq->ShowAns(eq->FindRoots());

  exit_action();
}

void VietWindow::exit_action()
 {
  std::cout << "\n\n";

  std::cout << "Нажмите клавишу enter для выхода в меню...";

  char c = getchar();
  c = getchar();

  app->ChangeWindow(WindowAction::MENU);
}

void VietWindow::action(std::vector<double> coefs) 
{
  eq = new Viet(coefs[0], coefs[1], coefs[2]);
}

GuessWindow::GuessWindow(App* app) : app(app) {}

void GuessWindow::draw() 
{
  std::cout << "\n";

  std::vector<double> coefs = ReadCoef();

  std::cout << "\n";

  action(coefs);
  
  eq->PrintDescription();

  std::cout << "\n";

  eq->ShowAns(eq->FindRoots());

  exit_action();
}

void GuessWindow::exit_action() 
{
  std::cout << "\n\n";

  std::cout << "Нажмите клавишу enter для выхода в меню...";

  char c = getchar();
  c = getchar();

  app->ChangeWindow(WindowAction::MENU);
}

void GuessWindow::action(std::vector<double> coefs) 
{
  eq = new Guess(coefs[0], coefs[1], coefs[2]);
}

std::vector<double> Window::ReadCoef()
 { 
  std::vector<double> coefs(3);

  std::cout << "Введите коэффиценты уравнения:\n";
  std::cout << "a = ";
  std::cin >> coefs[0];
  std::cout << "b = ";
  std::cin >> coefs[1];
  std::cout << "c = ";
  std::cin >> coefs[2];

  return coefs;
}
