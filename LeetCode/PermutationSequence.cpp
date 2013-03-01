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
 //   string getPermutation(int n, int k) {
 //   	string s;
 //   	for(int i=0;i<n;++i)
 //   		s.push_back(i+'1');
 //   	k--;
 //   	
 //   	while(k > 0){
 //   		pair<int,int> indexAndFact = getFactorialInIndex(n,k);
 //   		int d = k / indexAndFact.second;
 //   		int r = k % indexAndFact.second;

 //   		//swap( s.begin() + indexAndFact.first, s.begin() + indexAndFact.first + d);
	//		//iter_swap( s.begin() + indexAndFact.first, s.begin() + indexAndFact.first + d );
	//		//reverse( s.begin() + indexAndFact.first + 1, s.begin() + indexAndFact.first + d +1);
	//		char c = s[indexAndFact.first + d];
	//		s.erase(s.begin() + indexAndFact.first + d);
	//		s.insert(s.begin() + indexAndFact.first, c);
 //   		k = r;
 //   	}
	//	return s;
	//}

	//pair<int,int> getFactorialInIndex(int n, int k){
	//	int j = 1;
	//	int i = 1;
	//	for(i = n-1; i >= 0;--i){
	//		j *= (n-i);
	//		if( j > k )
	//			break;
	//	}
	//	if( j > k )
	//	{
	//		j /= (n-i);
	//	}
	//	else
	//	{
	//		i--;
	//	}
	//	return make_pair(i,j);
	//}

	string getPermutation(int n, int k) {
		string result;
		for(int i=0;i<n;++i){
			result.push_back(i+1+'0');
		}
		k--;
		while( k > 0 ){
			pair<int,int> p = getIndexAndFactorial(n, k);
			int d = k / p.second;
			int r = k % p.second;
			char c = result[p.first + d];
			result.erase(p.first+d, 1);
			result.insert(p.first, 1, c);
			k = r;
		}

		return result;
    }

	pair<int,int> getIndexAndFactorial(int n, int k){
		int fact = 1;
		int i = 1;
		for(;i<=n;++i){
			fact *= i;
			if( fact > k ){
				break;
			}
		}
		fact /= i;
		i = n-i;
		return make_pair( i, fact);
	}
};

//int main()
//{
//	cout << Solution().getPermutation(1, 1) << endl;
//	cout << Solution().getPermutation(2, 1) << endl;
//	cout << Solution().getPermutation(2, 2) << endl;
//	cout << Solution().getPermutation(3, 1) << endl;
//	cout << Solution().getPermutation(3, 2) << endl;
//	cout << Solution().getPermutation(3, 3) << endl;
//	cout << Solution().getPermutation(3, 4) << endl;
//	cout << Solution().getPermutation(4, 19) << endl;
//	getchar();
//	return 0;
//}