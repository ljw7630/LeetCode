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
    bool isPalindrome(int x) {
		if( x < 0 )
			return false;
		int upper = 1;
		while( x / upper >= 10 ){
			upper *= 10;
		}

		while( x >= 10 ){
			int l = x / upper;
			int r = x % 10;
			if( l != r ){
				return false;
			}
			x = (x%upper-r) / 10;
			upper /= 100;			
		}

		return true;
	}
};

//int main(){
//
//	//cout << Solution().isPalindrome(12321) << endl;
//	cout << Solution().isPalindrome(10) << endl;
//
//	//cout << Solution().isPalindrome(101) << endl;
//	getchar();
//	return 0;
//}