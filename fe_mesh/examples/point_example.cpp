#include <iostream>
#include "mesh/point.h"

int main() {
  std::cout << "Testing Point class..."  << std::endl;
  Point1D p1(2.0);
  std:: cout << p1 << std::endl;

  Point2D p2(1, 2.5);
  std:: cout << p2 << std::endl;

  Point3D p3(1, 2.5, -1./3);
  std:: cout << p3 << std::endl;
}
