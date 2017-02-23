#ifndef __CELL_H__
#define __CELL_H__

#include "element.h"

/// A cell is an element class who stores aditional data
template<class NodeT, int N, class DataT=int>
class Cell: public Element<NodeT, N>
{
public:
  //! Parent element class
  typedef Element<NodeT,N> ElementT;

  //! Default constructor
  Cell();

  //! Construtor from three nodes
  explicit Cell(NodeT& a, NodeT& b, NodeT& c, DataT data=0):
    ElementT(a,b,c), _data(data) {}

  //! Construtor from four nodes
  explicit Cell(NodeT& a, NodeT& b, NodeT& c, NodeT& d, DataT data=0):
    ElementT(a,b,c,d), _data(data) {}

  //! Copy constructor
  explicit Cell(Cell<NodeT,N,DataT> const& c): ElementT(c), _data(c._data) {}

  //! Assignement operator
  const Cell<NodeT,N,DataT>& operator=(Cell<NodeT,N,DataT> const&);

  //! Destructor
  ~Cell() {}

  //! Access to data (constant)
  DataT const& data() const { return _data; }

  //! Access to data
  DataT& data() { return _data; }


private:
  DataT _data;
};

// // Copy constructor
// template<class NodeT, int N>
// Cell<NodeT,N>::Cell(Cell<NodeT,N> const& e) {
//   for(int i=0; i<N; i++) {
//     node_ptr[i] = e.node_ptr[i];
//   }
// }

// // Assignment operator
// template<class NodeT, int N>
// const Cell<NodeT,N>& Cell<NodeT,N>::operator=(Cell<NodeT,N> const& e) {
//   if(this != &e) {
//     for(int i=0; i<N; i++) {
//       node_ptr[i] = e.node_ptr[i];
//     }
//   }
//   return *this;
// }

//! Print a Cell
template<class NodeT, int N, class DataT>
std::ostream& operator<<(std::ostream& os, Cell<NodeT,N,DataT> const& c) {
  for(int i=0; i<N; i++) os << c[i] << std::endl;
  os << "  data: " << c.data();
  return os;
}

#endif // __CELL_H__
