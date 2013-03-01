#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include "AlgorithmImpl.h"
using namespace std;

#pragma region 9.1

int possible_ways(int n){
	vector<int> vec(n+1);
	vec[0] = 1;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;

	if( n <= 3 )
		return vec[n];
	else{
		for(int i=4;i<=n;++i){
			vec[i]=vec[i-3]+vec[i-2]+vec[i-1];
		}
		return vec[n];
	}
}

#pragma endregion 9.1

#pragma region 9.2

bool get_path_helper(vector<vector<int> > &grid, int x, int y, vector<pair<int, int> > &path, map<pair<int, int>, bool> & visited){
	pair<int, int> p (x, y);
	if( visited.find(p) != visited.end() ) {
		return visited[p];
	}
	if( x == 0 && y == 0 ){
		path.push_back(make_pair(x,y));
		return true;
	}

	bool success = false;
	if( x >= 1 && grid[x-1][y] == 0){
		success = get_path_helper(grid, x-1, y, path, visited);
	}
	if( success == false && y>=1 && grid[x][y-1] == 0){
		success = get_path_helper(grid, x, y-1, path, visited);
	}

	if( success ){
		path.push_back(p);
		visited[p] = true;
	}
	else{
		visited[p] = false;
	}
	return success;
}

vector<pair<int, int> > get_path(vector<vector<int> > &grid, int x, int y){
	map<pair<int,int>, bool> visited;
	vector<pair<int, int> > path;
	get_path_helper(grid, x, y, path, visited);
	return path;
}

#pragma endregion 9.2

#pragma region 9.3

int find_magic_index(vector<int> &arr){
	int left = 0;
	int right = arr.size()-1;

	while(left <= right){
		int mid = (right-left)/2+left;
		if( arr[mid] == mid )
			return mid;
		else if(arr[mid] > mid){
			right = mid-1;
		}
		else{
			left = mid + 1;
		}
	}

	return -1;
}

int find_magic_index_duplicate(vector<int> &arr, int s, int e){
	if( s<=e ){
		int mid = (s-e)/2+s;
		if( arr[mid] == mid ){
			return mid;
		}
		else{
			int leftResult = find_magic_index_duplicate(arr, s, min(arr[mid], mid-1));
			if( leftResult >= 0 )
				return leftResult;
			int rightResult = find_magic_index_duplicate(arr, max(arr[mid], mid+1), e);
			if( rightResult >= 0 )
				return rightResult;
		}
	}
	return -1;
}

#pragma endregion 9.3

#pragma region 9.4

void all_subset_helper(std::vector<int> &input, int index, std::vector<int> &temp, std::vector<std::vector<int> > &result){
	if( index == input.size()){
		result.push_back(temp);
		return;
	}

	all_subset_helper(input, index+1, temp, result);
	temp.push_back(input[index]);
	all_subset_helper(input, index+1, temp, result);
	temp.pop_back();
}


vector<vector<int> > all_subset(vector<int> &input){
	std::vector<int> temp;
	std::vector<vector<int> > result;
	all_subset_helper(input, 0, temp, result);
	return result;
}

#pragma endregion 9.4


//int main(){
//	int a[] = {1,2,3,4,5};
//	vector<int> vec = AlgorithmImpl::Utility::createVector(a,5);
//	AlgorithmImpl::Utility::printVectorOfVector(all_subset(vec));
//	getchar();
//	return 0;
//}
