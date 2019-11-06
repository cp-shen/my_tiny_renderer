//
// Created by scp on 2019/11/6.
//

#include "my_tiny_renderer/VertexAttribSpecifier.hpp"
#include <stdexcept>

VertexAttribSpecifier::VertexAttribSpecifier()
    : _attribs()
    , _attribTotalSize(0)
{ }

VertexAttribSpecifier::~VertexAttribSpecifier() = default;

unsigned VertexAttribSpecifier::GetAttribCount() const {
    return _attribs.size();
}

void VertexAttribSpecifier::GetAttribNames(std::vector<std::string> &names) const {
    for (const auto& a : _attribs) {
        names.push_back(a.first);
    }
}

void VertexAttribSpecifier::AddAttrib(const std::string& name, unsigned size) {
    if (_attribs.count(name)) {
        throw std::runtime_error("name is already in use: " + name);
    }

    _attribs[name] = std::pair<unsigned, unsigned>(_attribTotalSize, size);
    _attribTotalSize += size;
}

std::pair<unsigned, unsigned> VertexAttribSpecifier::GetAttrib(const std::string &name) const {
    if (!_attribs.count(name)) {
        return std::make_pair(0, 0);
    }

    return std::make_pair(_attribs.at(name).first, _attribs.at(name).second);
}

void VertexAttribSpecifier::_Validate() {
    unsigned total = 0;
    for (const auto& a : _attribs) {
        total += a.second.second;
    }
    if (total != _attribTotalSize)
        throw std::logic_error("_attribTotalSize is not correct");
}
