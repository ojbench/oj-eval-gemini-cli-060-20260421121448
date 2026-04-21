#ifndef SRC_HPP
#define SRC_HPP

#include <vector>

template <typename T>
class Validator {
private:
    T val;
    bool result;
    bool negated;

public:
    Validator(const T& v) : val(v), result(true), negated(false) {}

    Validator& toBe(const T& y) {
        bool cond = (val == y);
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& toBeOneOf(const std::vector<T>& y) {
        bool found = false;
        for (typename std::vector<T>::const_iterator it = y.begin(); it != y.end(); ++it) {
            if (val == *it) {
                found = true;
                break;
            }
        }
        bool cond = found;
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& le(const T& y) {
        bool cond = (val < y || val == y);
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& ge(const T& y) {
        bool cond = (y < val || val == y);
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& lt(const T& y) {
        bool cond = (val < y);
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& gt(const T& y) {
        bool cond = (y < val);
        if (negated) cond = !cond;
        result = result && cond;
        return *this;
    }

    Validator& Not() {
        negated = !negated;
        return *this;
    }

    operator bool() const {
        return result;
    }
};

template <typename T>
Validator<T> expect(const T& x) {
    return Validator<T>(x);
}

#endif