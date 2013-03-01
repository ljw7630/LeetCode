#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
    int longestValidParentheses(string s) {
		vector<int> vec(s.size()+1,0);
		stack<int> posStack;
		int maxi = 0;
		for(int i=0;i<s.size();++i)
		{
			if( s[i] == '(' )
			{
				posStack.push(i+1);
				vec[i+1] = 0;
			}
			else if( s[i] == ')' )
			{
				if( !posStack.empty() )
				{
					int pos = posStack.top();
					posStack.pop();
					vec[i+1] = vec[pos - 1] + (i+1 - pos) + 1;
					maxi = max( maxi, vec[i+1] );
				}
			}
		}
		return maxi;
    }
};

//int main()
//{
//	cout << Solution().longestValidParentheses("()(()") << endl;
//	getchar();
//	return 0;
//}