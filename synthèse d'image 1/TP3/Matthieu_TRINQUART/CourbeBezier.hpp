#include <iostream>
#include <ostream>
#include <deque>
#include <cmath>
#include "point3.h"
using namespace std;

class CourbeBezier {

public:

	CourbeBezier(); //constructeurs

  ~CourbeBezier() ;//destructeur

  vector<point3> Bernstein(int pas , std::deque<point3> * controlPointList);
  int factorial(const int n) ;//fonction de Bernstein

};
