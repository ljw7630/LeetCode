#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

/// !!!!!! check discussion forum
/// really cool dynamic programming
/// hard to think about the solution

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		if( matrix.empty() )
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> height(n);
		vector<int> leftZero(n,-1);
		vector<int> rightZero(n,n);
		int area = 0;
		for(int i=0;i<m;++i)
		{
			int left = -1, right = n;
			for(int j=0;j<n;++j)
			{
				if(matrix[i][j] == '1')
				{
					leftZero[j] = max(left, leftZero[j]);
					height[j]++;
				}
				else
				{
					left = j;
					leftZero[j] = -1;
					rightZero[j] = n;
					height[j] = 0;					
				}
			}

			for(int j=n-1;j>-1;--j)
			{
				if( matrix[i][j] == '1')
				{
					rightZero[j] = min(right, rightZero[j]);
					area = max(area, height[j] * (rightZero[j] - leftZero[j] - 1));
				}
				else
				{
					right = j;
				}
			}
		}

		return area;
	}
};

//int main()
//{
//	char arr[][5] = {
//		'1', '1', '1', '0', '0'
//		,'0', '1', '1', '1', '1'
//		,'0', '1', '0', '1', '0'
//	};
//	vector<vector<char> >vec = AlgorithmImpl::Utility::createVectorOfVector((char*)arr, 3, 5);
//	cout << Solution().maximalRectangle(vec) << endl;
//
//	getchar();
//	return 0;
//}