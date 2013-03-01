#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		
		sort(num.begin(),num.end());
		vector<vector<int> >allQuadruplets;

		for(int i=0;i<(int)num.size()-3;++i)
		{
			if(i>0&&num[i]==num[i-1])
				continue;
			for(int j=i+1;j<(int)num.size()-2;++j)
			{
				if(j>i+1&&num[j] == num[j-1])
					continue;

				int leftIndex = j+1;
				int rightIndex = num.size()-1;

				while(leftIndex < rightIndex)
				{
					int sum = num[i]+num[j]+num[leftIndex]+num[rightIndex];
					bool lFlag = false;
					bool rFlag = false;

					if(sum == target)
					{
						vector<int> quadruplet;
						quadruplet.push_back(num[i]);
						quadruplet.push_back(num[j]);
						quadruplet.push_back(num[leftIndex]);
						quadruplet.push_back(num[rightIndex]);
						allQuadruplets.push_back(quadruplet);

						lFlag = true;
						rFlag = true;
					}
					else
					{
						if(sum < target)
						{
							lFlag = true;
						}
						else
						{
							rFlag = true;
						}
					}

					if(lFlag)
					{
						while(true)
						{
							leftIndex ++;
							if(num[leftIndex] != num[leftIndex-1])
								break;
						}
					}
					if(rFlag)
					{
						while(true)
						{
							rightIndex --;
							if(num[rightIndex] != num[rightIndex+1])
								break;
						}
					}
				}				
			}
		}

		return allQuadruplets;
	}
};

//int main()
//{
//	int s[] = {6,4,-6,4,-4,-7,1,-3,6,9,-10,-9,-9,-6};
//	vector<int> num = Utility::createVector(s, 14);
//	vector<vector<int> > vecOfVec = Solution().fourSum(num,10);
//	Utility::printVectorOfVector(vecOfVec);
//
//	getchar();
//	return 0;
//}