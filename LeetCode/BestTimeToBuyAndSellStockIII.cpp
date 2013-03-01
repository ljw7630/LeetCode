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

		vector<int> leftProfit(prices.size(), 0);

		int minimum = prices[0];
		
		for(int i=1;i<prices.size();++i)
		{
			int tmp = prices[i] - minimum;
			leftProfit[i] = max( tmp, leftProfit[i-1]);

			minimum = min(prices[i], minimum);
		}

		int maximum = prices[prices.size()-1];
		int rightProfit = 0;
		int profit = 0;
		for(int i=prices.size()-2; i>=-1;--i)
		{
			int tmp = maximum - prices[i+1];
			rightProfit = max(tmp, rightProfit);

			maximum = max(maximum, prices[i+1]);

			if(i >= 0)
			{
				if(profit < tmp + leftProfit[i])
				{
					profit = tmp + leftProfit[i];
				}
			}
			else
			{
				profit = profit>tmp?profit:tmp;
			}
		}

		return profit;
	}

	// TLE
 //   int maxProfit(vector<int> &prices) {
	//	if(prices.size()==0||prices.size()==1)
	//		return 0;

	//	int result = 0;
	//	for(int i=1; i < prices.size(); ++i)
	//	{
	//		int value1 = findMaxProfit(prices, 0, i);
	//		int value2 = findMaxProfit(prices, i+1, prices.size()-1);
	//		int sum = value1+value2;

	//		result = sum>result?sum:result;
	//	}

	//	return result;
	//}

	//int findMaxProfit(vector<int> &prices, int start, int end)
	//{
	//	int result = 0;
	//	int minimum = prices[start];

	//	for(int i=start+1;i<=end; ++i)
	//	{
	//		int tmp = prices[i] - minimum;

	//		result = tmp>result?tmp:result;

	//		minimum = min(prices[i], minimum);
	//	}

	//	return result;
	//}
};

//int main()
//{
//	vector<int> input;
//	input.push_back(1);
//	input.push_back(2);
//
//	Solution().maxProfit(input);
//	return 0;
//}