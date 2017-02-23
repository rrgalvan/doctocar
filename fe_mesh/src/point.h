#ifndef __POINT_H__
#define __POINT_H__

/// Point class with template dimension and data type
// Based on http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean

template <std::size_t Dim, typename T>
class Point
{
public:
  typedef T Scalar;

  /// Default constructor
  Point() {
    std::fill_n(coord, Dim, T());
  }

  /// Constructor just for 1d points
  explicit Point(const T& x) : coord{x}
  {
    std::fill_n(coord, Dim, T(x));
  }

  /// Constructor just for 2d points
  explicit Point(const T& x, const T& y) : coord{x,y}
  {
    static_assert(Dim == 2, "XY constructor only usable in 2D");
  }

  /// Constructor just for 3d points
  explicit Point(const T& x, const T& y, const T& z)
    : coord{x,y,z}
  {
    static_assert(Dim == 3, "XYZ constructor only usable in 3D");
  }

  const T* getCoords() const {
    return coord;
  }

private:
  T coord[Dim];
};

//! 1d point
typedef Point<size_t(1), double> Point1D;
//! 2d point
typedef Point<size_t(2), double> Point2D;
//! 3d point
typedef Point<size_t(3), double> Point3D;

//! Print a node
template <std::size_t Dim, typename T>
std::ostream &operator<<(std::ostream &os, Point<Dim,T> const &p) {
  const T* coord = p.getCoords();
  os << "(" << coord[0];
  for (int i=1; i<Dim; i++) os << ", " << coord[i];
  os << ")";
  return os;
}

#endif // __POINT_H__
