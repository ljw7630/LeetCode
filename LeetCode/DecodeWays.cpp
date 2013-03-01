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
 //   int numDecodings(string s) {
	//	int counter = 0;
	//	numDecodingsHelper(s, 0, 26);
	//	return counter;
 //   }

	//int numDecodingsHelper(const string &s, int currentIndex, int preValue)
	//{
	//	if(currentIndex == s.size())
	//	{
	//		if(preValue != 0)
	//			return 1;
	//		else
	//			return 0;
	//	}

	//	int currentValue = s[currentIndex];
	//	int value = preValue*10+currentValue;

	//	int num1 = numDecodingsHelper(s, currentIndex+1, 0);

	//}

	// dp or recursive, construct by previous result
	int numDecodings(string s) {
		if(s.size()==0)
			return 0;

		vector<int> dp(s.size()+1);

		dp[s.size()-1] = s[s.size()-1] == '0'?0:1;
		dp[s.size()] = 1;
		for(int i=s.size()-2; i > -1; --i){			
			if(s[i] == '0')
			{
				dp[i] = 0;
			}
			else
			{
				int value = (s[i] - '0')*10+s[i+1]-'0';
				if(value <= 26){
					dp[i] = dp[i+1]+dp[i+2];
				}
				else{
					dp[i] = dp[i+1];
				}
			}
		}

		return dp[0];
	}
};

//int main()
//{
//	Solution solution;
//
//	cout << solution.numDecodings("10") << endl;
//	getchar();
//	return 0;
//}