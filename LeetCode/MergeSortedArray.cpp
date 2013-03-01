#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>

#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl; 

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int len = m+n;
		m--;
		n--;
		for(int i=len-1;i>-1;--i){
			if( m > -1 && n > -1 ){
				if( A[m] > B[n] ){
					A[i] = A[m];
					m--;
				}
				else{
					A[i] = B[n];
					n--;
				}
			}
			else{
				if( m < 0 ){
					A[i] = B[n];
					n--;
				}
				else{
					A[i] = A[m];
					m--;
				}
			}
		}
	}
};


//int main(){
//	int a[20] = {1,3,5,7,9,11,13};
//	int b[13] = {2,4,6,8,10,12,14,15,16,17,18,19,20};
//
//	Solution().merge(a,7,b,13);
//	for(int i=0;i<20;++i)
//		cout << a[i] << endl;
//	getchar();
//	return 0;
//}