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

/// caution! everything is unsigned!!!
/// !!!

class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0 || dividend == 0)
			return 0;
		
		int sign = 1;		
		if( dividend < 0)
			sign *= -1;
		if( divisor < 0 )
			sign *= -1;

		unsigned newDivident = abs(dividend);
		unsigned newDivisor = abs(divisor);
		

		if( newDivident < newDivisor )
			return 0;
		if( newDivident == newDivisor )
			return sign;

		unsigned int div = newDivisor;
		unsigned v = 1;

		// shouldn't be greater that INT_MAX
		while( div < INT_MAX && div < newDivident)
		{
			div <<= 1;
			v <<= 1;
		}

		if( div > newDivident)
			div = div >> 1, v = v >> 1;		

		int quotient = 0;

		// caution the edge case
		while(div >= newDivisor)
		{
			// caution the edge case
			if( div <= newDivident)
			{
				newDivident -= div;
				quotient += v;
			}
			div >>= 1;
			v >>= 1;
		}

		return quotient * sign;
    }
};

//int main()
//{
//	cout << Solution().divide(2147483647, 1) << endl;
//	getchar();
//	return 0;
//}