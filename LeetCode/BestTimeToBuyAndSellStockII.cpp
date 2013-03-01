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
		int result = 0;

		int minIndex = 0;
		int maxIndex = 0;
		for(int i=1;i<prices.size();++i)
		{
			if(prices[i]>=prices[i-1])
			{
				maxIndex = i;
			}
			else
			{
				result += (prices[maxIndex] - prices[minIndex]);
				minIndex = i;
				maxIndex = i;
			}

			if(i == prices.size()-1)
			{
				result += (prices[maxIndex] - prices[minIndex]);;
			}
		}

		return result;
    }
};