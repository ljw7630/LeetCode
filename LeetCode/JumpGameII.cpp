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

/// check how many steps required for all positions that can be reached by the current jump value
/// !!!!!

class Solution {
public:
    int jump(int A[], int n) {
		if( n == 0 || n == 1)
			return 0;
		int maxJump = -1;
		int count = 1;
		vector<int> left(n-1);
		for(int i=0;i<n-1;++i)
		{
			left[i] =  n - i - A[i];
		}
		vector<pair<int,int> > jumps;
		for(int i=0;i<n-1;)
		{			
			if(maxJump == -1)
				maxJump = A[i];
			else
			{
				maxJump --;
				jumps.push_back(make_pair(left[i], i));
			}
			if( maxJump == 0 )
			{
				int minimum = INT_MAX;				
				for(int j = jumps.size()-1; j > -1; --j)
				{
					if( jumps[j].first <= 0 )
					{
						return count + 1;
					}
					if( jumps[j].first < minimum )
					{
						minimum = jumps[j].first;
						i = jumps[j].second;
						maxJump = A[i];
						i++;
					}
				}
				jumps.clear();
				count ++;
			}
			else
			{
				i++;
			}
		}

		return count;
    }
};

//int main()
//{
//	int a [] = {1,1,1,1};
//	Solution solution;
//	cout << solution.jump(a, 4) << endl;
//	int b [] = {1,2,3,4,5};
//	cout << solution.jump(b, 0) << endl;
//	cout << solution.jump(b, 1) << endl;
//	cout << solution.jump(b, 2) << endl;
//	cout << solution.jump(b, 5) << endl;
//	getchar();
//	return 0;
//}