#include <iostream>
#include <vector>
#include <algorithm>
#include <AlgorithmImpl.h>
#include <set>
using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int previousBetween = INT_MAX;
		int result = INT_MAX;

		sort(num.begin(),num.end());

		for(int i=0;i<(int)num.size()-2;++i)
		{
			int leftIndex = i+1;
			int rightIndex = num.size()-1;

			while(leftIndex < rightIndex)
			{
				int threeSum = num[i]+num[leftIndex]+num[rightIndex];
				
				int tmp = threeSum-target;

				if(tmp == 0)
					return target;
				else if(tmp<0)
					leftIndex ++;
				else rightIndex--;

				int currentBetween = abs(tmp);

				if(currentBetween < previousBetween)
				{
					previousBetween = currentBetween;
					result = threeSum;
				}
			}
		}

		return result;
	}
};

//int main()
//{
//	int arr[] = {0,2,1,-3};
//	vector<int> num = Utility::createVector(arr, 4);
//	cout << Solution().threeSumClosest(num,1) << endl;
//	getchar();
//	return 0;
//}