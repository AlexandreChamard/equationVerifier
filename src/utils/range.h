
#pragma once

#include <optional>
#include <cstdint>
#include <stdexcept>

class Range {
public:
    enum type {
        NUMBER,
        FLOATING,
        INFINITY,
        NEG_INFINITY,
        ZERO_POS,
        ZERO_NEG,
        NONE,
    };

private:
    union {
        int64_t _fromN;
        double _fromF;
    };
    union {
        int64_t _toN;
        double _toF;
    };
    type _fromType;
    type _toType;

    type fromType() const { return _fromType; }
    type toType() const { return _toType; }

    int64_t fromNumber() const { 
        if (fromType() != NUMBER) {
            throw std::runtime_error{"from value is not typed as Number"};
        }
        return _fromN;
    }

    double fromFloating() const { 
        if (fromType() != FLOATING) {
            throw std::runtime_error{"from value is not typed as Floating"};
        }
        return _fromF;
    }

    int64_t toNumber() const { 
        if (toType() != NUMBER) {
            throw std::runtime_error{"to value is not typed as Number"};
        }
        return _toN;
    }

    double toFloating() const { 
        if (toType() != FLOATING) {
            throw std::runtime_error{"to value is not typed as Floating"};
        }
        return _toF;
    }

    std::optional<Range> compare(Range const &r) {

    }
};