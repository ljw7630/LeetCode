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

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		string s;
		generateParenthesisHelper(result, s, 0, 0, n);

		return result;
	}

	void generateParenthesisHelper(vector<string> &result, string &s,
			int l, int r, int n)
	{
		if ( s.size() == n*2)
		{
			if( l == r )
				result.push_back(s);
			else
				return;
		}

		if( l < n )
		{
			s.push_back('(');
			generateParenthesisHelper(result, s, l+1, r, n);
			s.erase( s.size() -1 );
		}
		if( l > r )
		{
			s.push_back(')');
			generateParenthesisHelper(result, s, l, r+1, n);
			s.erase( s.size() -1 );
		}
	}
};

//int main()
//{
//	vector<string> vec = Solution().generateParenthesis(3);
//	for(int i=0;i<vec.size();++i)
//		cout << vec[i] << endl;
//	getchar();
//	return 0;
//}