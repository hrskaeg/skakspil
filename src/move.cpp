#include "move.h"
#include <string>

std::string Move::toString() const {
    auto posToStr = [](const Position& p) {
        std::string s;
        s += static_cast<char>('a' + p.col);
        s += static_cast<char>('1' + p.row);
        return s;
    };

    return posToStr(from) + posToStr(to);
}
