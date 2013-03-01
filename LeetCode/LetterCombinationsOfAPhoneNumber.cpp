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

    vector<string> letterCombinations(string digits) {
		vector<string> digitCharMapping;
		digitCharMapping.push_back("");
		digitCharMapping.push_back("");
		digitCharMapping.push_back("abc");
		digitCharMapping.push_back("def");
		digitCharMapping.push_back("ghi");
		digitCharMapping.push_back("jkl");
		digitCharMapping.push_back("mno");
		digitCharMapping.push_back("pqrs");
		digitCharMapping.push_back("tuv");
		digitCharMapping.push_back("wxyz");
		digitCharMapping.push_back("");
		digitCharMapping.push_back("");
		digitCharMapping.push_back("");
		vector<string> result;
		string s;
		letterCombinationsHelper(result, 0, digits, digitCharMapping, s);
		return result;
    }

	void letterCombinationsHelper(vector<string> &result, int index, const string &src, const vector<string> &digitCharMapping, string &s) const
	{
		if( index == src.size() )
		{
			result.push_back(s);
			return;
		}

		int pos = src[index]-'0';

		// it's possible that current value has no content
		if( digitCharMapping[pos].size() == 0)
			letterCombinationsHelper(result, index+1, src, digitCharMapping, s);

		
		for(int i=0;i<digitCharMapping[pos].size();++i)
		{
			s.push_back(digitCharMapping[pos][i]);
			letterCombinationsHelper(result, index+1, src, digitCharMapping, s);
			s.erase(s.size()-1);
		}
	}
};

//int main()
//{
//	vector<string> res = Solution().letterCombinations("23");
//	return 0;
//}