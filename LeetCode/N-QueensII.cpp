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
	int count;
	int upper;
    int totalNQueens(int n) {
		count = 0;
		upper = (1<<n)-1;
		NQueeenHelper(0,0,0);
		return count;
	}

	void NQueeenHelper(int row, int ld, int rd){

		if( row != upper ){
			int availablePos = upper & (~(row | ld | rd));
			
			while( availablePos != 0) {
				int p = availablePos & (-availablePos);
				availablePos -= p;
				NQueeenHelper(row+p, (ld+p) << 1, (rd+p) >> 1);
			}
		}
		else{
			count++;
		}
	}
};