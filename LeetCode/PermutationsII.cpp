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

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		
		vector<vector<int> > result;

		if(num.size() == 0)
			return result;

		sort(num.begin(), num.end());
		result.push_back(num);

		int index = num.size()-1;
		while(true)
		{			
			int pos1 = -1;
			for(int i=num.size()-2; i>=0; --i)
			{
				if( num[i] < num[i+1])
				{
					pos1 = i;
					break;
				}
			}
			if(pos1 == -1)
				break;

			for(int i=num.size()-1; i>=pos1+1; --i)
			{
				if( num[pos1] < num[i] )
				{
					swap(num[pos1], num[i]);
					reverse(num.begin()+pos1+1, num.end());
					break;
				}
			}

			result.push_back(num);
		}

		return result;
    }
};

//int main()
//{
//	int arr[] = {1,1,2};
//	vector<int> vec = AlgorithmImpl::Utility::createVector(arr, 3);
//	Solution().permuteUnique(vec);
//	return 0;
//}