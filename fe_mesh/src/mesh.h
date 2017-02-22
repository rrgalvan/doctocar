#ifndef __MESH_H__
#define __MESH_H__

#include <list>
#include "element.h"

template<class ElementT>
class Mesh
{
 public:
  //! Default constructor
  Mesh() {}
  //! Destructor
  ~Mesh() {}
  /// Access to elements
  std::list<ElementT> elements() {
    return _elements;
  }
  /// Append an element
  void append_element(ElementT& e) {
    _elements.push_back(e);
  }
 public:
  // Elements stored in current mesh
  std::list<ElementT> _elements;

  /// Copy constructor is forbidden (private and not implemented)
  Mesh(Mesh const&);
};

#endif // __MESH_H__