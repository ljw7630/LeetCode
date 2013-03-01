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
	bool isPalindrome(string s) {
		string tmpString;
		for(int i=0;i<s.size();++i)
		{
			if( (s[i]>='a'&&s[i]<='z') ||
				(s[i]>='0'&&s[i]<='9') )
			{
				tmpString.push_back(s[i]);
			}
			else if(s[i]>='A'&&s[i]<='Z')
				tmpString.push_back(s[i]-'A'+'a');			
		}

		for(int i=0;i<tmpString.size()/2;++i)
		{
			if(tmpString[i] != tmpString[tmpString.size()-1-i])
				return false;			
		}
		return true;
	}
};

//int main()
//{
//	Solution().isPalindrome("A man, a plan, a canal: Panama");
//	return 0;
//}