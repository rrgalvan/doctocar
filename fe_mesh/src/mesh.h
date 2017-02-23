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


/*!
 * Read mesh (msh format) from a file
 *
 * Try to read mesh contents from a .msh file (for information about the
 * structure of these files, see FreeFem++ documentation).
 *
 * \param filename
 * \returns 0 if file was successfully opened and read
 */
template<class ElementT> int read_file_msh(Mesh<ElementT>&m, std::string filename);

template<>
int read_file_msh(Mesh<Element<Node2D, 3> >&m, std::string filename) {
  using Triangle = Element<Node2D, 3>;
  using Node = typename Triangle::Node;
  using Point = typename Node::Point;
  using Scalar = typename Point::Scalar;

  std::clog << "opening msh file: " << filename << std::endl;
  std::fstream meshfile;
 // file.exceptions ( ifstream::failbit | ifstream::badbit );
  try {
    meshfile.open(filename, std::ios_base::in);
    if( !meshfile ) throw std::ios::failure( "Error opening file!" ) ;
  }
  catch (const std::ifstream::failure& e) {
    std::cerr << e.what() << '\n';
    return(1);
  }
  unsigned int nver, ncel, nedg;
  meshfile >> nver >> ncel >> nedg;
  std::clog << "nver=" << nver << " ncel=" << ncel
  	    << " nedg=" << nedg << std::endl;
  std::vector<Node*> vertices(nver);

  for(int i=0; i<nver; i++) {
    Scalar x, y;
    std::size_t label;
    meshfile >> x >> y >> label;
    std::clog << "Node (" << i << "): ";
    auto p = new Node( Point(x, y), i);
    std::clog << *p << std::endl;
    vertices[i]=p;
  }

  for(int i=0; i<ncel; i++) {
    unsigned int id0, id1, id2, zero;
    meshfile >> id0 >> id1 >> id2 >> zero;
    Triangle t( *vertices[id0-1], *vertices[id1-1], *vertices[id2-1] );
    m.append_element(t);
  }

  return(0);
}

#endif // __MESH_H__
