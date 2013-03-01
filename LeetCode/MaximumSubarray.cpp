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

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if( n == 0 )
			return 0;
		int result = INT_MIN;
		int sum = 0;
		for(int i=0;i<n;++i)
		{
			sum += A[i];
			result = max(result, sum);
			if( sum < 0 )
				sum = 0;
		}
		return result;
    }
};