#include <iostream>
#include <vector>
#include <algorithm>
#include <AlgorithmImpl.h>
#include <set>
using namespace std;
using namespace AlgorithmImpl;

class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{		
		vector<vector<int> > allTriples;

		sort(num.begin(),num.end());

		for(int i=0;i<(int)num.size()-2;++i)
		{
			if(num[i]>0)
				break;
			int leftIndex = i+1;
			int rightIndex = num.size()-1;

			while(leftIndex<rightIndex)
			{
				int sum = num[i]+num[leftIndex]+num[rightIndex];
				if(sum == 0)
				{
					vector<int> triple;
					triple.push_back(num[i]);
					triple.push_back(num[leftIndex]);
					triple.push_back(num[rightIndex]);
					allTriples.push_back(triple);
					leftIndex++;
					rightIndex--;
				}
				else if(sum<0)
				{
					leftIndex++;
				}
				else
				{
					rightIndex--;
				}
			}
		}

		set<vector<int> > s(allTriples.begin(), allTriples.end());
		allTriples = vector<vector<int> >(s.begin(), s.end());
		// allTriples.erase( unique(allTriples.begin(), allTriples.end()), allTriples.end());

		return allTriples;
	}
};

//int main()
//{
//	int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//	vector<int> num = Utility::createVector(arr, 15);
//	vector<vector<int> > allTriples = Solution().threeSum(num);
//	Utility::printVectorOfVector(allTriples);
//
//	
//	allTriples = Solution().threeSum(vector<int>());
//	Utility::printVectorOfVector(allTriples);
//
//	getchar();
//	return 0;
//}