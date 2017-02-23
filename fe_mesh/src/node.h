#ifndef __NODE_H__
#define __NODE_H__

#include <ostream> // For definition of operator <<
#include "point.h"

typedef std::size_t size_t;

/// A node class
template<class PointT> class Node {
public:
  typedef PointT Point;

  //! \brief Default constructuor
  //! \param coord Coordinates in space
  //! \param ind Index for current node
  Node(const PointT&coord=PointT(0.), size_t ind=-1)
    : coord(coord), index(ind)
  {}

  //! Copy constructor
  explicit Node(const Node& n)
    : coord(n.coord), index(n.index) {}

  //! Assignement operator
  const Node& operator=(const Node& node);

  //! Destructor
  ~Node(){}

  //! Read the coord of this Node
  const PointT& getCoord() const {
    return coord;
  }

  //! Read index of this node
  size_t getIndex() const {
    return index;
  }


private:
  PointT coord;
  size_t index;
};

/// Node1D
typedef Node<Point1D> Node1D;
/// Node2D
typedef Node<Point2D> Node2D;
/// Node3D
typedef Node<Point3D> Node3D;

//! Print a node
template<class PointT>
void print(const Node<PointT>&n){
  print(n());
  printf("index=%d \n", n.getIndex());
}

// Assignment operator
template<class PointT>
const Node<PointT>& Node<PointT>::operator=(const Node<PointT>& n){
  if(this != &n){
    coord = n.coord;
    index = n.index;
  }
  return *this;
}

//! Print a node
template<class PointT>
std::ostream &operator<<(std::ostream &os, Node<PointT> const &n) {
  os << n.getCoord() << ": index=" << n.getIndex();
  return os;
}

#endif // __NODE_H__
