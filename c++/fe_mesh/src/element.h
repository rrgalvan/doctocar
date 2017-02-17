#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "node.h"

/// A finite element class who stores pointers to N nodes (they can be
/// usually identified with vertices).
template<class PointT, int N> class Element {
public:
  //! Default constructor
  Element() {
    for(int i=0; i<N; i++)
      node[i] = new Node<PointT>;
  }
  //! Construtor from three nodes
  explicit Element(Node<PointT>&, Node<PointT>&, Node<PointT>&);
  //! Copy constructor
  explicit Element(Element<PointT,N>&);
  //! Assignement operator
  const Element<PointT,N>& operator=(Element<PointT,N>&);
  //! Destructor
  ~Element();

  //! Read/write ith node
  Node<PointT>& operator[](int i) {
    return *(node[i]);
  }
  //! Read only ith node
  const Node<PointT>& operator[](int i) const {
    return *(node[i]);
  }

  //! Reset all indices to -1
  void resetIndices() {
    for(int i=0; i<N; i++)
      node[i]->setIndex(-1);
  }

private:
  Node<PointT>* node[N];
};

// Default constructor
template<class PointT, int N>
Element<PointT,N>::Element(Node<PointT>& a, Node<PointT>& b, Node<PointT>& c) {
  node[0]=a.noSharingElement() ? new Node<PointT>(a) : &a;
  node[1]=b.noSharingElement() ? new Node<PointT>(b) : &b;
  node[2]=c.noSharingElement() ? new Node<PointT>(c) : &c;
  for(int i=0; i<N; i++) node[i]->incSharingElements();
}

// Copy constructor
template<class PointT, int N>
Element<PointT,N>::Element(Element<PointT,N>& e) {
  for(int i=0; i<N; i++) {
    node[i] = e.node[i];
    node[i]->incSharingElements();
  }
}

// Assignment operator
template<class PointT, int N>
const Element<PointT,N>&
Element<PointT,N>::operator=(Element<PointT,N>& e) {
  if(this != &e) {
    for(int i=0; i<N; i++)
      if(node[i]->decSharingElements()) delete node[i];
    for(int i=0; i<N; i++) {
      node[i] = e.node[i];
      node[i]->incSharingElements();
    }
  }
  return *this;
}

// Destructor
template<class PointT, int N>
Element<PointT,N>:: ~Element() {
  for(int i=0; i<N; i++)
    if(node[i]->decSharingElements()) delete node[i];
}

//! Print a Element
template<class PointT, int N>
std::ostream& operator<<(std::ostream& os, Element<PointT,N> const& e) {
  for(int i=0; i<N; i++) os << e[i] << std::endl;
  return os;
}

#endif // __ELEMENT_H__
