// https://leetcode.com/problems/n-queens/

#include<iostream>
#include"../inc/solution.h"


void PrintSolutions(BoardVec&& solutions)
{
	std::cout << solutions.size() << " solutions found:\n\n";
	for(auto board : solutions)
	{
		for(auto str : board)
		{
			std::cout << str << '\n';
		}
		std::cout << '\n'; 
	}
}

int main()
{
	Solution sol;
	PrintSolutions( sol.solveNQueens(6) );
	return 0;
}

