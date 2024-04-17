#include "../lib/Catch2/catch.hpp"
#include "../src/solver.hpp"

TEST_CASE("isValid tests") {
    Solver solver;

    SECTION("empty board") {
        
        solver = Solver();
    }

    SECTION("valid") {

    }

    SECTION("not valid") {

    }

    SECTION("completed board, valid") {

    }

    SECTION("completed board, not valid") {

    }
}

