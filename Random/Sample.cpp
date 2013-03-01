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

typedef class Complex{
	double x;
	double y;
} Complex;

class Complexlbllblblblblalalblalblablab{
};

typedef Complex Abc;

//int main(){
//	Abc object;
//	// Complex object
//}

//int main()
//{
//	int arr[] = {4,2,3,4,5,6,7};
//	vector<int> vec = AlgorithmImpl::Utility::createVector<int>(arr , 6);
//	Solution().largestRectArea(vec);
//
//	return 0;
//}

int main(){
	int a[] = {8,3,5,7,1,4,0};
	vector<int> vec = AlgorithmImpl::Utility::createVector(a, 7);
	AlgorithmImpl::Utility::my_quick_sort(vec, 0, vec.size()-1);
	AlgorithmImpl::Utility::printVector(vec);
	getchar();
	return 0;
}