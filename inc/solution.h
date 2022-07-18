#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<string>

using Board = std::vector<std::string>;
using BoardVec = std::vector<Board>;
using iVec = std::vector<int>;

class Solution
{
    public:
        void GenerateSolvedBoards(int, Board&, BoardVec&, iVec&, iVec&, iVec&);
        BoardVec solveNQueens(int);
};

#endif // SOLUTION_H