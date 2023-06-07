#pragma once

#include <vector>
#include <iostream>

#include "tabulate/table.hpp"
#include "App.hpp"
#include "EquationTypes.hpp"
#include "ConsoleFunctions.hpp"
#include "Util.hpp"

using namespace tabulate;

class Window 
{
 public:
  Window() = default;
  virtual ~Window() = default;

  std::vector<double> ReadCoef();
  
  virtual void draw() = 0;
};

class GeneralWindow : public Window 
{
public:
  GeneralWindow(App* app);
  ~GeneralWindow() override = default;

  void draw() override;

  void exit_action();

  void action(std::vector<double> coefs);

 private:
  App* app;
  General* eq;
};


class MenuWindow : public Window 
{
 public:
  MenuWindow(App* app);
  ~MenuWindow() override = default;
  
  void draw() override;

  void action();

 private:
  App* app;
};

class VietWindow : public Window 
{
public:
  VietWindow(App* app);
  ~VietWindow() override = default;

  void draw() override;

  void exit_action();

  void action(std::vector<double> coefs);

 private:
  App* app;
  General* eq;
};

class GuessWindow : public Window 
{
public:
  GuessWindow(App* app);
  ~GuessWindow() override = default;

  void draw() override;

  void exit_action();

  void action(std::vector<double> coefs);

 private:
  App* app;
  General* eq;
};