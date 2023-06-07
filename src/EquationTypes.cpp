#include <iostream>
#include <math.h>

#include "tabulate/table.hpp"

#include "EquationTypes.hpp"

#define PRECISION_VALUE 1e-6

using namespace tabulate;
using namespace std;

General::General(double a, double b, double c) 
{
  this->a = a;
  this->b = b;
  this->c = c;
}

Type1::Type1()  : General(0, 0, 0) {}
Root Type1::FindRoots() 
{ 
  return Root(); 
}
void Type1::ShowAns(const Root& roots)
{
  cout << "��� ��������� ����� ��� ����� �" << "\n";
}

void Type1::PrintDescription() 
{
  cout << "��� ��������� ���� ���-1, � ������� a = 0, b = 0, c = 0\n";
}

Type2::Type2(double c)  : General(0, 0, c) {}
Root Type2::FindRoots() 
{ 
  return Root(); 
}
void Type2::ShowAns(const Root& roots)
{
    cout << "��� ��������� �� ����� ������ � �����������\n";
}

void Type2::PrintDescription() 
{
  cout << "��� ��������� ���� ���-2, � ������� a = 0, b = 0, c != 0\n";
}

Type3::Type3(double a, double b, double c)  : General(a, b, c) {}
Root Type3::FindRoots() 
{
  Root roots;
  roots.x1 = 0;
  roots.x2 = NAN;
  double D = b * b - 4 * a * c;

  cout << "�������� ������������ D = " << D << endl;

  if (fabs(D) >= PRECISION_VALUE)
  {
    roots.x1 = (-b + sqrt(D)) / 2 * a;
    roots.x2 = (-b - sqrt(D)) / 2 * a;
  }
  else if (fabs(D) < PRECISION_VALUE) 
  {
      roots.x1 = -b / 2 * a;
  }
  else
  {
      roots.x = NAN;
  }

  return roots;
}

void Type3::ShowAns(const Root& roots) 
{
	if (isnan(roots.x)) 
	{
		cout << "��� ��������� �� ����� ������\n";
	} 
  else if (roots.x1 == 0)
	{
		cout << "��� ��������� ����� ���� ������: x =" << roots.x << endl;
	}
	else
	{
  		cout << "��� ��������� ����� ��� �����: x1 = "  << roots.x1 << "\t" << "x2 = " << roots.x2 << endl;
	}
}

void Type3::PrintDescription() 
{
  cout << "��� ��������� ���� ���-3, � ������� a != 0, b != 0, c != 0\n";
  cout << "\n������� ���� ����� ������������ D = b^2 - 4ac\n";
  cout << "����� �������� ����� � ����: x = (-b +- D)/2a\n";
}

Type4::Type4(double a, double b) : General (a, b, 0) {}
Root Type4::FindRoots() 
{ 
  Root roots;
  roots.x1 = 0;
  roots.x2 = -b / a; 

  return roots;
}
void Type4::ShowAns(const Root& roots)
{
  cout << "��� ��������� ����� ��� �����: x1 = "  << roots.x1 << "\t" << "x2 = " << roots.x2 << endl;
}

void Type4::PrintDescription()
{
  cout << "��� ��������� ���� ���-4, � ������� a != 0, b != 0, c = 0\n";
  cout << "\n������ ������ ����� ����� x = 0\n";
  cout << "����� �������� ������ ������ � ����: x = -b/a\n";
}

Type5::Type5(double a, double c) : General (a, 0, c) {}

Root Type5::FindRoots()
{
    Root roots;
    if ((-c / a)  < 0) 
    {
        cout << "�����: -�/a = " << (-c) / a << " < 0\n";
        roots.x = NAN;
    }
    else
    { 
        cout << "�����: -�/a = " << -c / a << " > 0\n";
        roots.x1 = sqrt(-c / a);
        roots.x2 = -sqrt(-c / a);
    }

    return roots;
}

void Type5::ShowAns(const Root& roots) 
{
  if (std::isnan(roots.x))
  {
    cout << "��� ��������� �� ����� ������\n";
  } 
  else 
  {
    cout << "��� ��������� ����� ��� �����: x1 = "  << roots.x1 << "\t" << "x2 = " << roots.x2 << endl;
  }
}

void Type5::PrintDescription() 
{
  cout << "��� ��������� ���� ���-5, � ������� a != 0, b = 0, c != 0\n";
  cout << "\n������� ���� ����� ���������� ��.����� �� -� / a\n";
  cout << "�������� ����� � ����: x = sqrt(-c/a)\n";
}

Type6::Type6(double a) : General (a, 0, 0) {}
Root Type6::FindRoots() 
{ 
  Root roots;
  roots.x = 0;

  return roots;
}

void Type6::ShowAns(const Root& roots)
{
   cout << "��� ��������� ����� ���� ������: x =" << roots.x << endl;
}

void Type6::PrintDescription() 
{
  cout << "��� ��������� ���� ���-6, � ������� a != 0, b = 0, c = 0\n";
  cout << "�������� ������������ ������ � ����: x = 0\n";
}

Type7::Type7(double b, double c) : General (0, b, c) {}
Root Type7::FindRoots() 
{ 
  Root roots;
  roots.x = -c / b;

  return roots;
}
void Type7::ShowAns(const Root& roots)
{
  cout << "��� ��������� ����� ���� ������: x =" << roots.x << endl;
}

void Type7::PrintDescription() 
{
  cout << "��� ��������� ���� ���-7, � ������� a = 0, b != 0, c != 0\n";
  cout << "�������� ������������ ������ � ����: x = -�/b\n";
}

Type8::Type8(double b) : General (0, b, 0) {}
Root Type8::FindRoots() 
{ 
  Root roots;
  roots.x = 0;

  return roots;
}
void Type8::ShowAns(const Root& roots)
{
    cout << "��� ��������� ����� ���� ������: x =" << roots.x << endl;
}

void Type8::PrintDescription() 
{
  cout << "��� ��������� ���� ���-8, � ������� a = 0, b != 0, c = 0\n";
  cout << "�������� ������������ ������ � ����: x = 0\n";
}

Viet::Viet(double a, double b, double c) : General(a, b, c) {}

Root Viet::FindRoots() 
{ 
  Root roots;

  Table errors;
  errors.format()
      .font_color(Color::white)
      .padding_right(0);

  errors.column(0).format().width(20).font_align(FontAlign::center);
  errors.column(1).format().width(20).font_align(FontAlign::center);
  errors.column(2).format().width(40).font_align(FontAlign::center);

  errors.add_row(Table::Row_t{"X1", "X2", "Error"});

  double min_error = 100000;
  double curr_error = min_error;
  double table_error = curr_error;

  for (double x1 = -100; x1 < 100; x1 += 0.01) 
  {
    for (double x2 = 100; x2 > -100; x2 -= 0.01) 
    {
      curr_error = fabs(fabs(x1 * x2 - c / a) + fabs(x1 + x2 + b / a));
      if (curr_error < min_error)
      {
        min_error = curr_error;
        roots.x1 = x1;
        roots.x2 = x2;
      }

      if (curr_error < table_error / 2) 
      {
        table_error = curr_error;
        errors.add_row(Table::Row_t{std::to_string(x1), std::to_string(x2), std::to_string(table_error)});
      }
    }
  }

  errors.add_row(Table::Row_t{std::to_string(roots.x1), std::to_string(roots.x2), std::to_string(min_error)});

  cout << errors << endl << endl;

  return roots;
}

void Viet::ShowAns(const Root& roots)
{
  cout << "��� ��������� ����� ��� �����: x1 = "  << roots.x1 << "\t" << "x2 = " << roots.x2 << endl;
}

void Viet::PrintDescription() 
{
  cout << "��� ��������� ����� ������ � ����������� ������� �����:\n\n";
  cout << "����� ��������� ����� ����� x1, x2 ����� ������ ����� ���������: x1 * x2 = c/a, x1 + x2 = -b/a\n";
  cout << "����� ���������� ��� ����� �1, �2 � �������������� ������ error = fabs(x1 * x2 - c / a) + fabs(x1 + x2 + b / a)\n";
}

Guess::Guess(double a, double b, double c) : General(a, b, c) {}

Root Guess::FindRoots() 
{ 
  Root roots;

  Table errors;
  errors.format()
      .font_color(Color::white)
      .padding_right(0);

  errors.column(0).format().width(20).font_align(FontAlign::center);
  errors.column(1).format().width(20).font_align(FontAlign::center);

  errors.add_row(Table::Row_t{"X", "Error"});

  double min_error = 100000;
  double curr_error = min_error;
  double table_error = curr_error;

  for (double x = -100; x < 100; x += 0.001) 
  {
    curr_error = fabs(a * x * x + b * x + c);
    if (curr_error < min_error)
    {
      min_error = curr_error;
      roots.x = x;
    }

    if (curr_error < table_error / 2) 
    {
      table_error = curr_error;
      errors.add_row(Table::Row_t{std::to_string(x), std::to_string(table_error)});
    }

  }

  errors.add_row(Table::Row_t{std::to_string(roots.x), std::to_string(min_error)});

  cout << errors << endl << endl;

  return roots;
}

void Guess::ShowAns(const Root& roots) 
{
  cout << "��� ��������� ����� ������: x = "  << roots.x << endl;
}

void Guess::PrintDescription() 
{
  cout << "��� ��������� ����� ������ � ����������� ������ �������:\n\n";
  cout << "����� ���������� ��� x ���� ������ ����� ��������� �� �������� � ����� ������\n";
  cout << "����� �������������� ������ error = fabs(a * x * x + b * x + c)\n";
}
