#include "catch2/catch_test_macros.hpp"
#include "mylib.h"

TEST_CASE("Add function works correctly", "[add]") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(0, 0) == 0);
    REQUIRE(add(-7, 3) == -4);
}