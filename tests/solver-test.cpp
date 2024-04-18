#include "../lib/Catch2/catch.hpp"
#include "../src/solver.hpp"

TEST_CASE("isValid tests") {
    Solver solver;

    SECTION("empty board") {
        vector<vector<string>> board {
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", "", ""}
        };
        solver = Solver(board);
        
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

