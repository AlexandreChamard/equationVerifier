
#pragma once

#include <string>

namespace eqver {

enum struct operator_e {

};

using identifier = std::string;

struct Arg {
    identifier id;
    operator_e op;
};

}