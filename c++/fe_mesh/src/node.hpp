#ifndef __NODE_HPP__
#define __NODE_HPP__

///A node class
template<class PointT> class Node {
  PointT location;
  int index;
  int sharingElements;
public:
  //! \brief Constructuor
  //! \param loc Location in space
  //! \param ind Index for current node
  //! \param sharing Number of elements that share current node
  Node(const PointT&loc=0., int ind=-1, int sharing=0)
    : location(loc), index(ind), sharingElements(sharing)
  {}

  //! Copy constructor
  Node(const Node& n)
    : location(n.location), index(n.index), sharingElements(n.sharingElements){}

  //! \brief Assignement operator
  //! \param node: Node objet whose values shall be copied
  //! \returnsx: Current node, after actualization
  const Node& operator=(const Node& node);

  //! Destructor
  ~Node(){}

  //! Read the location of this Node
  const PointT& operator()() const {
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
  void moreSharingElements(){
    sharingElements++;
  }

  //! Decrease number of elements that share this node
  int lessSharingElements(){
    return !(--sharingElements);
  }

  //! Indicate a dangling node
  int noSharingElement() const{
    return !sharingElements;
  }

};


#endif // __NODE_HPP__
