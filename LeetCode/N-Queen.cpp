#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	int upper;
	int num;
    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > resultSet;
		vector<string> tempResult;
		num = n;
		upper = (1<<n) - 1;
		solveNQueensHelper(resultSet, tempResult, 0, 0, 0);

		return resultSet;
	}

	void solveNQueensHelper(vector<vector<string> >&resultSet
		, vector<string> &temp, int row, int ld, int rd){

			if( row != upper ){
				int availablePos = upper & (~(row|ld|rd));
				while( availablePos ){
					int p = availablePos & (-availablePos);
					availablePos -= p;
					string s(num, '.');
					int queenPos = 0;
					int tempP = p;
					while( tempP != 1){
						tempP = tempP >> 1;
						queenPos++;
					}
					s[queenPos] = 'Q';
					temp.push_back(s);
					solveNQueensHelper(resultSet, temp, row+p, (ld+p)<<1, (rd+p)>>1);
					temp.pop_back();
				}
			}
			else{
				resultSet.push_back(temp);
			}
	}
};

//int main(){
//	
//	AlgorithmImpl::Utility::printVectorOfVector(Solution().solveNQueens(4));
//	getchar();
//	return 0;
//}