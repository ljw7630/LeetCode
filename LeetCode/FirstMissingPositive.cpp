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

/// careful!  edge case. So we nee to store i in pos i-1 to make sure no
/// element will be skipped
/// use while to avoid missing some elements
/// !!!!

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		for(int i=0;i<n;++i)
		{
			while( A[i] > 0 && A[i] < n && A[i] != i+1 && A[A[i]-1] != A[i])
			{
				swap(A[A[i]-1],A[i]);
			}
		}
		for(int i=0;i<n;++i)
		{
			if(A[i] != i+1)
			{
				return i+1;
			}
		}
		return n+1;
    }
};

//int main()
//{
//	int a[] = {1,1};
//	//int b[] = {3,4,-1,1};
//	Solution solution;
//	cout << solution.firstMissingPositive(a, 2) << endl;
//	// cout << solution.firstMissingPositive(b, 4) << endl;
//	getchar();
//	return 0;
//}