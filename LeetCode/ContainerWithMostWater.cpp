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
    /*int maxArea(vector<int> &height) {
		if(height.size() == 0 || height.size() == 1)
		{
			return 0;
		}
		int maxArea = 0;
		for(int i=0;i < height.size()-1; ++i)
		{
			for(int j=i+1;j<height.size(); ++j)
			{
				int area = (j - i) * min(height[j], height[i]);
				if(maxArea < area)
				{
					maxArea = area;
				}
			}
		}

		return maxArea;
	}*/

    int maxArea(vector<int> &height) {
        if(height.size() == 0 || height.size() == 1)
		{
			return 0;
		}
		int maxArea = 0;
		
        int leftIndex = 0;
        int rightIndex = height.size()-1;
        
        while(leftIndex < rightIndex)
        {
            int area = (rightIndex - leftIndex) * min(height[leftIndex], height[rightIndex]);
            if(maxArea < area)
            {
                maxArea = area;
            }
            if(height[leftIndex] > height[rightIndex])
            {
                rightIndex --;                
            }
            else
            {
                leftIndex ++;
            }
        }

		return maxArea;
	}
};