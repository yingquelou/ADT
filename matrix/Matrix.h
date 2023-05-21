#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
namespace Matrix
{
    using super = std::vector<std::vector<long double>>;
    class Base : protected super
    {
    public:
        using row_type = super::value_type;
        using element_type = row_type::value_type;
        using super::size_type;

    public:
        Base &operator=(Base b) { return swap(b), *this; }
        
    };

} // namespace Matrix

#endif