#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

/// be careful for the initial value !!!
/// the starting case is tricky
/// draw a matrix would help!!!

class Solution {
public:
    int minDistance(string word1, string word2) {
		if(word1.size() == 0)
			return word2.size();
		else if(word2.size() == 0)
			return word1.size();
		vector<vector<int> > matrix(word2.size()+1);
		const int maxi = 1000000;
		for(int i=0;i<matrix.size();++i)
			matrix[i] = vector<int>(word1.size()+1, maxi);

		for(int i=0;i<word1.size()+1;++i){
			matrix[0][i] = i;			
		}
		for(int i=0;i<word2.size()+1;++i){
			matrix[i][0] = i;
		}

		for(int i=1;i<word2.size()+1;++i)
		{
			for(int j=1;j<word1.size()+1; ++j)
			{
				if( word2[i-1] == word1[j-1] )
					matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j]);
				// delete
				matrix[i][j] = min(matrix[i][j], matrix[i][j-1]+1);
				// insert
				matrix[i][j] = min(matrix[i][j], matrix[i-1][j] + 1);
				//replace
				matrix[i][j] = min(matrix[i][j], matrix[i-1][j-1] + 1);
			}
		}

		return matrix[word2.size()][word1.size()];
    }
};

//int main()
//{
//	string s = "ab";
//	string t = "a";
//	cout << Solution().minDistance(s, t) << endl;
//	getchar();
//	return 0;
//}