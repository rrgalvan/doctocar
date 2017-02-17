#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <ostream>

/// A node class
template<class PointT> class Node {
  PointT location;
  int index;
  int sharingElements;
public:
  //! \brief Default constructuor
  //! \param loc Location in space
  //! \param ind Index for current node
  //! \param sharing Number of elements that share current node
  Node(const PointT&loc=0., int ind=-1, int sharing=0)
    : location(loc), index(ind), sharingElements(sharing)
  {}

  //! Copy constructor
  Node(const Node& n)
    : location(n.location), index(n.index), sharingElements(n.sharingElements){}

  //! Assignement operator
  const Node& operator=(const Node& node);

  //! Destructor
  ~Node(){}

  //! Read the location of this Node
  const PointT& getLocation() const {
    return location;
  }

  //! Read index of this node
  int getIndex() const {
    return index;
  }

  //! Read number of elements that share this node
  int getSharingElements() const{
    return sharingElements;
  }

  //! Increase number of elements that share this node
  void incSharingElements(){
    sharingElements++;
  }

  //! Decrease number of elements that share this node
  int decSharingElements(){
    return !(--sharingElements);
  }

  //! Indicate a dangling node
  int noSharingElement() const{
    return !sharingElements;
  }

};

//! Print a node
template<class PointT>
void print(const Node<PointT>&n){
  print(n());
  printf("index=%d; %d sharing elements\n",
	 n.getIndex(),n.getSharingElements());
}

// Assignment operator
template<class PointT>
const Node<PointT>& Node<PointT>::operator=(const Node<PointT>& n){
  if(this != &n){
    location = n.location;
    index = n.index;
    sharingElements = n.sharingElements;
  }
  return *this;
}

//! Print a node
template<class PointT>
std::ostream &operator<<(std::ostream &os, Node<PointT> const &n) {
  os << n.getLocation() << ": index=" << n.getIndex()
     << ", sharing_elements=" << n.getSharingElements();
  return os;
}

#endif // __NODE_HPP__
