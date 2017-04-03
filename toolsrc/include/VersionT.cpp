#include "pch.h"
#include "VersionT.h"
#include "vcpkg_Strings.h"

namespace vcpkg
{
    VersionT::VersionT() : value("0.0.0") {}
    VersionT::VersionT(const std::string& value) : value(value) {}
    bool operator==(const VersionT& left, const VersionT& right) { return left.value == right.value; }
    bool operator!=(const VersionT& left, const VersionT& right) { return left.value != right.value; }
    std::string to_printf_arg(const VersionT& version) { return version.value; }

    VersionDiff::VersionDiff() : left(), right() {}
    VersionDiff::VersionDiff(const VersionT& left, const VersionT& right) : left(left), right(right) {}

    std::string VersionDiff::toString() const
    {
        return Strings::format("%s -> %s", left.value, right.value);
    }
}
