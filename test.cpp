#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "src.hpp"

int main() {
    // Test basic functionality
    assert(expect(10).toBe(10));
    assert(!expect(10).toBe(11));

    // Test chaining
    assert(expect(10).ge(5).le(15));
    assert(!expect(10).ge(15).le(20));

    // Test Not()
    assert(expect(10).Not().toBe(11));
    assert(!expect(10).Not().toBe(10));

    // Test Not() affecting all subsequent
    assert(expect(10).Not().toBe(11).toBe(12));
    assert(!expect(10).Not().toBe(10).toBe(12));
    assert(!expect(10).Not().toBe(11).toBe(10));

    // Test Not() toggle
    assert(expect(10).Not().Not().toBe(10));
    assert(!expect(10).Not().Not().toBe(11));

    // Test toBeOneOf
    std::vector<int> v = {1, 2, 3, 10};
    assert(expect(10).toBeOneOf(v));
    assert(!expect(5).toBeOneOf(v));
    assert(expect(5).Not().toBeOneOf(v));

    // Test string
    std::string s = "hello";
    assert(expect(s).toBe("hello"));
    assert(expect(s).lt("world"));
    assert(expect(s).gt("apple"));

    // Test complex case from README
    int num = 114;
    assert(expect(num).ge(114).lt(514).Not().toBe(321));
    num = 321;
    assert(!expect(num).ge(114).lt(514).Not().toBe(321));
    num = 514;
    assert(!expect(num).ge(114).lt(514).Not().toBe(321));

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
