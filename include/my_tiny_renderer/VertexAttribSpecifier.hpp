//
// Created by scp on 2019/11/6.
//

#ifndef VERTEX_ATTRIB_SPECIFIER_HPP
#define VERTEX_ATTRIB_SPECIFIER_HPP

#include <vector>
#include <map>

class VertexAttribSpecifier {
    /// \brief
    /// key: attribName, value: (startIndex, size)
    std::map<std::string, std::pair<unsigned, unsigned>> _attribs;

    /// \brief
    /// total size of all attributes
    unsigned _attribTotalSize;

    /// \biref
    /// throws an exception when it is invalid
    void _Validate();

public:
    VertexAttribSpecifier();

    ~VertexAttribSpecifier();

    /// \return
    /// the number of vertex attribute count excluding position
    unsigned GetAttribCount() const;

    /// \param names
    /// the vector to receives names
    void GetAttribNames(std::vector<std::string> &names) const;

    /// \param name attrib name
    /// \param size attrib size
    /// \brief throws an exception when the name is already in use
    void AddAttrib(const std::string &name, unsigned size);

    /// \param name
    /// the name of the vertex attrib to query
    /// \return
    /// (startIndex, size)
    /// (0, 0) if the attrib is not found
    std::pair<unsigned, unsigned> GetAttrib(const std::string &name) const;
};


#endif //VERTEX_ATTRIB_SPECIFIER_HPP
