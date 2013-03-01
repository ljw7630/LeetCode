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
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		for(int i=0;i<numbers.size();++i){
			for(int j=0;j<i;++j){
				if(numbers[j] + numbers[i] == 0){
					result.push_back(j+1);
					result.push_back(i+1);
					return result;
				}
			}
			numbers[i] = numbers[i] - target;
		}
		return result;
	}
};

int main(){
	//int a[] = {150,24,79,50,88,345,3};
	//vector<int> number = AlgorithmImpl::Utility::createVector(a,7);

	//vector<int> result = Solution().twoSum(number, 200);
	//AlgorithmImpl::Utility::printVector(result);

	cout << abs(INT_MIN) << endl;

	getchar();
	return 0;
}