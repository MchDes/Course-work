#include "Util.hpp"
#include <cmath>

bool IsZero(double num) 
{ 
  return std::fabs(num) < PRECISION_VALUE;
}