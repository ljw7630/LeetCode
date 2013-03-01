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
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > resultSet;
		vector<int> result;
		permuteHelper(0, num, result, resultSet);
		return resultSet;
	}

	void permuteHelper(int index, vector<int> &num, vector<int> &result, vector<vector<int> > &resultSet){
		if( index == num.size()){
			resultSet.push_back( result );
			return;
		}
		for(int i=index; i< num.size();++i){
			swap( num[index], num[i] );
			result.push_back( num[index] );
			permuteHelper( index+1, num, result, resultSet);
			result.pop_back();
			swap( num[index], num[i] );
		}
	}
};

//int main(){
//	int arr[] = {1,2,3};
//	vector<int> vec = AlgorithmImpl::Utility::createVector<int>(arr, 3);
//	AlgorithmImpl::Utility::printVectorOfVector<int>( Solution().permute(vec) );
//	getchar();
//	return 0;
//}