#ifndef __NODE_H__
#define __NODE_H__

#include <ostream> // For definition of operator <<

typedef std::size_t size_t;

/// A node class
template<class PointT> class Node {
public:
  //! \brief Default constructuor
  //! \param coord Coordinates in space
  //! \param ind Index for current node
  //! \param sharing Number of elements that share current node
  Node(const PointT&coord=0., size_t ind=-1, size_t sharing=0)
    : coord(coord), index(ind), sharingElements(sharing)
  {}

  //! Copy constructor
  explicit Node(const Node& n)
    : coord(n.coord), index(n.index), sharingElements(n.sharingElements){}

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

  //! Read number of elements that share this node
  size_t getSharingElements() const{
    return sharingElements;
  }

  //! Increase number of elements that share this node
  void incSharingElements(){
    sharingElements++;
  }

  //! Decrease number of elements that share this node
  size_t decSharingElements(){
    return !(--sharingElements);
  }

  //! Indicate a dangling node
  size_t noSharingElement() const {
    return !sharingElements;
  }

private:
  PointT coord;
  size_t index;
  size_t sharingElements;
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
    coord = n.coord;
    index = n.index;
    sharingElements = n.sharingElements;
  }
  return *this;
}

//! Print a node
template<class PointT>
std::ostream &operator<<(std::ostream &os, Node<PointT> const &n) {
  os << n.getCoord() << ": index=" << n.getIndex()
     << ", sharing_elements=" << n.getSharingElements();
  return os;
}

#endif // __NODE_H__
