#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	//int count;
 //   int climbStairs(int n) {
 //       count = 0;
	//	climbStairsHelper(0, n);
	//	return count;
 //   }

	//void climbStairsHelper(int current, int n)
	//{
	//	if( current == n)
	//	{
	//		count++;
	//	}
	//	if(current > n)
	//		return;
	//	climbStairsHelper(current+1, n);
	//	climbStairsHelper(current+2, n);
	//}

	///
	/// summary: use combination to calculate the number of possible ways
	/// be careful for overflow. in case it happens, use while-loop, devide
	/// the value from low to high (otherwise, the value might not be divisible
	///

	int climbStairs(int n) {
		if ( n == 0 )
		{
			return 0;
		}
		int result = 0;
		int i = 0;
		while( i * 2 <= n)
		{
			int num = i + n - i * 2;
			int tmp = combinations(num, i);
			result += tmp;
			i++;
		}

		return result;
	}

	int combinations(int n, int r)
	{
		int nMinusR = n-r;
		if(nMinusR < r)
			swap(r, nMinusR);
		long long result = 1;		
		int tmp = 2;
		while( n > nMinusR)
		{
			result *= n;
			n--;

			while(result > INT_MAX)
			{
				result /= tmp;
				tmp++;
			}
		}

		while( tmp <= r)
		{
			result /= tmp;
			tmp++;
		}

		return result;
	}
};

//int main()
//{
//	Solution().climbStairs(44);
//	return 0;
//}