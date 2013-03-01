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
	/// dp, dynamic programming

	int numDistinct(string S, string T) {
		vector<vector<int> > dp(T.size()+1);

		for(int i=0;i<T.size()+1;++i)
		{
			dp[i] = vector<int>( S.size()+1,0 );
			
		}
		for(int i=0;i<S.size()+1;++i)
		{
			dp[0][i] = 1;
		}
		for(int i = 1;i<T.size()+1;++i)
		{
			for(int j=1;j<S.size()+1;++j)
			{
				if( T[i-1] == S[j-1])
				{
					dp[i][j] += dp[i-1][j-1];
				}
				dp[i][j] += dp[i][j-1];
			}
		}

		return dp[T.size()][S.size()];
	}
 //   int numDistinct(string S, string T) {
	//	return numDistinctHelper(S, 0, T, 0);
 //   }

	//int numDistinctHelper(const string &s, int indexS, const string &t, int indexT)
	//{
	//	if(indexS == s.size() && indexT == t.size())
	//		return 1;
	//	else if(indexT == t.size())
	//		return 1;
	//	else if(indexS == s.size())
	//		return 0;

	//	int sum = 0;
	//	if( s[indexS] == t[indexT] )
	//	{
	//		sum += numDistinctHelper(s, indexS+1, t, indexT + 1);
	//	}
	//	sum += numDistinctHelper(s, indexS+1, t, indexT);

	//	return sum;
	//}
};

//int main()
//{
//	string S = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
//	string T = "bddabdcae";
//
//	cout << Solution().numDistinct(S,T) << endl;
//	S = "rabbbit";
//	T = "rabbit";
//	cout << Solution().numDistinct(S,T) << endl;
//
//	getchar();
//	return 0;
//}