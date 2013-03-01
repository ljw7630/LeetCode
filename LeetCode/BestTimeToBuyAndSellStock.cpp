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
	int maxProfit(vector<int> &prices) {
		if(prices.size()==0||prices.size()==1)
			return 0;
		int minumum = prices[0];
		int result = 0;

		for(int i=1;i<prices.size();++i)
		{
			int tmp = prices[i]-minumum;
			result = result>tmp?result:tmp;
			minumum = min(prices[i], minumum);
		}

		return result;
	}
};

//int main()
//{
//	int arr[] = {1};
//	vector<int> vec = Utility::createVector(arr, 0);
//	cout << Solution().maxProfit(vec) << endl;
//
//	getchar();
//	return 0;
//}