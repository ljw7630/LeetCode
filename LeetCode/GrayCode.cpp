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
    vector<int> grayCode(int n) {

		vector<int> result;
		result.push_back(0);

		for(int i = 1; i <= n; ++i)
		{
			int pre = result.size();
			while( pre > 0 )
			{
				int tmp = ( 1 << (i-1) ) + result[pre-1];
				result.push_back( tmp );
				pre --;
			}
		}

		return result;
    }
};

//int main()
//{
//	AlgorithmImpl::Utility::printVector( Solution().grayCode(2) );
//
//	getchar();
//	return 0;
//}