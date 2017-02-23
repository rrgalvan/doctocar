#ifndef __MESH_H__
#define __MESH_H__

#include <list>
#include <vector> // For read mesh
#include <fstream> // For read mesh
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
  std::list<ElementT> elements() const {
    return _elements;
  }
  /// Append an element
  void append_element(ElementT const& e) {
    _elements.push_back(e);
  }
 private:
  // Elements stored in current mesh
  std::list<ElementT> _elements;

  /// Copy constructor is forbidden (private and not implemented)
  Mesh(Mesh const&);
};


//! Print Mesh contents
template<class ElementT>
std::ostream& operator<<(std::ostream& os, Mesh<ElementT> const& m) {
  int i=0;
  for(auto const& e : m.elements()) {
    os << "Element " << i++ << std::endl;
    os << e << std::endl;
  }
  return os;
}


/**
 * Read mesh (msh format) from a file
 *
 * Try to read mesh contents from a .msh file (for information about the
 * structure of these files, see FreeFem++ documentation).
 *
 * @param filename
 */
template<class ElementT>
void read_file_msh(Mesh<ElementT>&m, std::string filename) {
  using Node = typename ElementT::Node;
  using Point = typename Node::Point;
  using Scalar = typename Point::Scalar;
  using Triangle = ElementT;

  std::cout << "opening msh file: " << filename << std::endl;
  std::fstream meshfile(filename, std::ios_base::in);

  unsigned int nver, ncel, nedg;
  meshfile >> nver; // >> ncel >> nedg;
  std::cout << "nver=" << nver << " ncel=" << ncel
  	    << " nedg=" << nedg << std::endl;
  std::vector<Node*> vertices(nver);

  /* for(int i=0; i<nver; i++) { */
  /*   std::cout << "i=" << i << std::endl; */
  /*   Scalar x, y; */
  /*   std::size_t label; */
  /*   meshfile >> x >> y >> label; */
  /*   std::cout << "i=" << i << std::endl; */
  /*   auto p = new Node( Point(x, y), label); */
  /*   vertices[i]=p; */
  /* } */

  /* for(int i=0; i<ncel; i++) { */
  /*   unsigned int id0, id1, id2, zero; */
  /*   meshfile >> id0 >> id1 >> id2 >> zero; */
  /*   Triangle t( *vertices[id0-1], *vertices[id1-1], *vertices[id2-1] ); */
  /*   m.append_element(t); */
  /* } */

}

#endif // __MESH_H__
