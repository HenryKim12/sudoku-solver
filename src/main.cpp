#include <iostream>
#include <string>
#include "solver.hpp"

using namespace std;

int main() //int argc, char *argv[]
{
    vector<vector<int> > board(9);
    int rows = 9;
    int cols = 9;
    board.resize(rows);
    for (int i = 0; i < rows; ++i) {
        board[i].resize(cols);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = i * cols + j;
        }
    }
    
    Solver solver = Solver(board);
    bool valid = solver.isValid(board);
    cout << to_string(valid) << endl;
    return 0;
}