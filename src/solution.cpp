#include"../inc/solution.h"


void Solution::GenerateSolvedBoards(int col, Board& board, BoardVec& solutions, 
                                        iVec& rowCount, iVec& upperDiagCount, iVec& lowerDiagCount)
{
    // a valid configuration was found, append board to solutions before unwinding the recursive calls on the stack
    if(col == board.size()){ solutions.push_back(board); return; }

    for(int row{0}; row < board.size(); ++row)
    {
        // board coords are mapped to elements of these vecs, rowCount counts queens in current row and others count Qs in diagonals;
        // program is iterating from first to last column of the board, so only elements in previous columns need to be checked. 
        if(!rowCount[row] && !upperDiagCount[col-row + board.size()-1] && !lowerDiagCount[col+row])
        {
            board[row][col] = 'Q';  // place a queen, won't necessarily be part of a valid board configuration
            ++rowCount[row]; ++upperDiagCount[col-row + board.size()-1]; ++lowerDiagCount[col+row];  // increment the three counters

            // a queen has been placed in the current column, recursively search for a solution starting from the next column
            GenerateSolvedBoards(col+1, board, solutions, rowCount, upperDiagCount, lowerDiagCount);

            // reset board & counters regardless of whether a valid solution was found, ready to start searching from the next row
            board[row][col] = '.';
            --rowCount[row]; --upperDiagCount[col-row + board.size()-1]; --lowerDiagCount[col+row]; 
        }
    }
}


BoardVec Solution::solveNQueens(int n)
{
    BoardVec solutions{};
    Board board(n,std::string(n,'.'));
    iVec rowCount(n,0), upperDiagCount(2*n-1,0), lowerDiagCount(2*n-1,0);
    GenerateSolvedBoards(0, board, solutions, rowCount, upperDiagCount, lowerDiagCount);

    return solutions;
}