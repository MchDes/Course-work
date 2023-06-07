#pragma once
#include <cmath>

struct Root 
{
  double x;
  double x1;
  double x2;
};

class General 
{
  public:
    General(double a, double b, double c);
    virtual ~General() = default;
    virtual Root FindRoots() = 0;
    virtual void ShowAns(const Root& roots) = 0;
    virtual void PrintDescription() = 0;

  protected:
    double a;
    double b;
    double c;
};


class Type1 : public General
{
  public:
    Type1();
    ~Type1() override = default;
    Root FindRoots() override;
	  void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};

class Type2 : public General 
{
  public:
    Type2(double c);
    ~Type2() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};


class Type3 : public General
{
  public:
	  Type3(double a, double b, double c);
    ~Type3() override = default;
	  Root FindRoots() override;
	  void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};


class Type4 : public General
{
  public:
    Type4(double a, double b);
    ~Type4() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};

class Type5 : public General
{
    public:
    Type5(double a, double c);
    ~Type5() override = default;
    Root FindRoots();
    void ShowAns(const Root& roots);
    void PrintDescription() override;
};

class Type6 : public General
{
  public:
    Type6(double a);
    ~Type6() override = default;
    Root FindRoots();
    void ShowAns(const Root& roots);
    void PrintDescription() override;
};

class Type7 : public General
{
  public:
    Type7(double b, double c);
    ~Type7() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots);
    void PrintDescription() override;
};

class Type8 :  public General
{
  public:
    Type8(double b);
    ~Type8() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};

class Viet : public General 
{
    public:
    Viet(double a, double b, double c);
    ~Viet() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};

class Guess : public General 
{
    public:
    Guess(double a, double b, double c);
    ~Guess() override = default;
    Root FindRoots() override;
    void ShowAns(const Root& roots) override;
    void PrintDescription() override;
};