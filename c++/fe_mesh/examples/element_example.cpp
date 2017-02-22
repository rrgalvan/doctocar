#include <iostream>
#include "element.h"

using namespace std;

int main() {
  cout << "Testing FiniteElement class..."  << endl;
  Element<double,2> fe_1;  // Default constructor
  cout << fe_1;
}
