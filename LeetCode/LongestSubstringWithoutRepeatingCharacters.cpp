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
    int lengthOfLongestSubstring(string s) {
		vector<int> chars(300,0);
		queue<int> q;

		int maxi = 0;
		for(int i=0;i<s.size();++i)
		{
			if( chars[s[i]] != 0)
			{
				maxi = max(maxi, (int)q.size());

				while( true )
				{
					char tmp = q.front();
					chars[tmp] --;
					q.pop();
					if (tmp == s[i] )
						break;
				}							
			}
			
			chars[s[i]]++;
			q.push(s[i]);
		}
		return max(maxi,(int)q.size());
    }
};

//int main()
//{
//	Solution().lengthOfLongestSubstring("abbabababa");
//	return 0;
//}