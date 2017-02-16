#include "node.hpp"

template<class PointT>
const Node<PointT>& Node<PointT>::operator=(const Node<PointT>& n){
  if(this != &n){
    location = n.location;
    index = n.index;
    sharingElements = n.sharingElements;
  }
  return *this;
} // assignment operator
