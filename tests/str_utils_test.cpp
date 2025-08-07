#include "util/str_utils.h"
#include <cassert>
#include <vector>
#include <string>

int main() {
    auto tokens = util::split("a,b,c", ',');
    assert(tokens.size() == 3);
    assert(tokens[0] == "a");
    assert(tokens[1] == "b");
    assert(tokens[2] == "c");
    return 0;
}
