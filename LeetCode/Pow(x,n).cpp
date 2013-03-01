#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

/*
 * edge case: value not change
 */

class Solution {
public:
    double pow(double x, int n) {
		bool sign = false;
		if (n<0 ){
			sign = true;
			n = -n;
		}
		double x1 = x;
		double pre = x1;
		double result = 1;
		int powN = 1;
		while( n > 1 ){
			if( 2 * powN <= n){
				x1 = x1*x1;				
				powN *= 2;
				if( pre == x1 )
					return pre;
				else
					pre = x1;
			}
			else{
				result *= x1;
				n -= powN;
				powN = 1;
				x1 = x;
			}
		}
		if( n == 1 ){
			result *= x;
		}
		if( sign ){
			return 1.0/result;
		}

		return result;
	}
};

//int main(){
//	cout << Solution().pow(0.00001, 2147483647) << endl;
//	//cout << pow(0.00001, 2147483647) << endl;
//	getchar();
//	return 0;
//}