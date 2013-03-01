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

	string longestPalindrome(string s) {

		if( s.size() == 0  || s.size() == 1)
			return s;

		string str("!#");
		for(int i=0;i<s.size();++i)
		{
			str.push_back(s[i]);
			str.push_back('#');
		}
		str.push_back('$');

		int mx = 0,id = 0;
		vector<int> p(str.size());
		p[0] = 0;
		for(int i=1;i<str.size();++i)
		{
			if( mx > i )
			{
				p[i] = min( mx - i, p[2*id-i] );
			}
			else
			{
				p[i] = 1;
			}

			while( str[i+p[i]] == str[i-p[i]] )
				p[i]++;

			if( mx < i + p[i] )
			{
				mx = i+p[i];
				id = i;
			}
		}
		int index = 0;
		for(int i=0;i<p.size();++i)
		{
			if( p[i] > p[index] )
			{
				index= i;
			}
		}

		return s.substr( (index - p[index])/2, p[index]-1);
	}


	/// O(n^2) solution, dynamic programming
	/// MLE

 //   string longestPalindrome(string s) {
	//	vector<vector<int> > matrix(s.size()+2, vector<int>(s.size()+2, 0) );
	//	string result;
	//	int maxi = 0;
	//	int max_len = 0;
	//	for(int i=0;i<s.size();++i)
	//	{
	//		for(int j=s.size()-1; j>=i; --j)
	//		{
	//			if( s[i] == s[j] )
	//			{
	//				matrix[s.size() - j][i+1] = matrix[s.size() - j - 1][i]+1;
	//				matrix[s.size() - i][j+1] = matrix[s.size() - i + 1][j+2] + 1;
	//				if( i + 1 == j || i == j)
	//				{
	//					if( maxi <= matrix[s.size()-j][i+1] )
	//					{
	//						maxi = matrix[s.size()-j][i+1];
	//						int len = i == j ? matrix[s.size() - i][j+1]*2-1:matrix[s.size() - i][j+1]*2;
	//						if( max_len < len )
	//						{
	//							result = s.substr( i - matrix[s.size() - i][j+1] + 1, len );
	//							max_len = len;
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}

	//	return result;
	//}
};

//int main()
//{
//	cout << Solution().longestPalindrome("abb") << endl;
//	cout << Solution().longestPalindrome("abababa") << endl;
//	cout << Solution().longestPalindrome("asdagbffdhabafdhdba") << endl;
//	getchar();
//	return 0;
//}