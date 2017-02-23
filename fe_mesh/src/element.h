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
  //! Default constructor
  Element();

  //! Construtor from three nodes
  explicit Element(NodeT&, NodeT&, NodeT&);

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

template<class NodeT, int N>
Element<NodeT,N>::Element(NodeT& a, NodeT& b, NodeT& c) {
  node_ptr[0] = std::shared_ptr<NodeT>(&a);
  node_ptr[1] = std::shared_ptr<NodeT>(&b);
  node_ptr[2] = std::shared_ptr<NodeT>(&c);
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
