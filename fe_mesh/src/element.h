#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <memory>
#include "node.h"

/// A finite element class who stores pointers to N nodes (they can be
/// usually identified with vertices).
template<class NodeT, int N>
class Element
{
public:
  typedef NodeT Node;
  int Nnod=N;

  //! Default constructor
  Element();

  //! Construtor from three nodes
  explicit Element(NodeT&, NodeT&, NodeT&);

  //! Construtor from four nodes
  explicit Element(NodeT&, NodeT&, NodeT&, NodeT&);

  //! Copy constructor
  explicit Element(Element<NodeT,N> const&);

  //! Assignement operator
  const Element<NodeT,N>& operator=(Element<NodeT,N> const&);

  //! Destructor
  ~Element() {}

  //! Read/write ith node
  NodeT& operator[](int i) {
    return *(node_ptr[i]);
  }
  //! Read only ith node
  const NodeT& operator[](int i) const {
    return *(node_ptr[i]);
  }

private:
  std::shared_ptr<NodeT> node_ptr[N];
};

// Default constructor
template<class NodeT, int N>
Element<NodeT,N>::Element() {
  for(int i=0; i<N; i++) node_ptr[i] = std::shared_ptr<NodeT>(new NodeT);
}

// Constructor from 3 nodes
template<class NodeT, int N>
Element<NodeT,N>::Element(NodeT& a, NodeT& b, NodeT& c) {
  static_assert(N==3, "3 nodes needed for Element<NodeT,3> constructor");
  node_ptr[0] = std::shared_ptr<NodeT>(&a);
  node_ptr[1] = std::shared_ptr<NodeT>(&b);
  node_ptr[2] = std::shared_ptr<NodeT>(&c);
}

// Constructor from 4 nodes
template<class NodeT, int N>
Element<NodeT,N>::Element(NodeT& a, NodeT& b, NodeT& c, NodeT& d) {
  static_assert(N==4, "4 nodes needed for Element<NodeT,4> constructor");
  node_ptr[0] = std::shared_ptr<NodeT>(&a);
  node_ptr[1] = std::shared_ptr<NodeT>(&b);
  node_ptr[2] = std::shared_ptr<NodeT>(&c);
  node_ptr[3] = std::shared_ptr<NodeT>(&d);
}


// Copy constructor
template<class NodeT, int N>
Element<NodeT,N>::Element(Element<NodeT,N> const& e) {
  for(int i=0; i<N; i++) {
    node_ptr[i] = e.node_ptr[i];
  }
}

// Assignment operator
template<class NodeT, int N>
const Element<NodeT,N>& Element<NodeT,N>::operator=(Element<NodeT,N> const& e) {
  if(this != &e) {
    for(int i=0; i<N; i++) {
      node_ptr[i] = e.node_ptr[i];
    }
  }
  return *this;
}

//! Print a Element
template<class NodeT, int N>
std::ostream& operator<<(std::ostream& os, Element<NodeT,N> const& e) {
  for(int i=0; i<N; i++) os << e[i] << std::endl;
  return os;
}

#endif // __ELEMENT_H__
