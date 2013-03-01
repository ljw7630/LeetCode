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
    string longestCommonPrefix(vector<string> &strs) {
		string result;
		int index = 0;
		if( strs.size() == 0 )
			return "";
		while(true)
		{
			char c;
			bool end = false;
			for(int i=0;i<strs.size();++i)
			{
				if( strs[i].size() > index )
				{
					if( i == 0 )
						c = strs[i][index];
					else if( strs[i][index] != c )
					{
						end = true;
						break;
					}
				}
				else
				{
					end = true;
					break;
				}
				if( i == strs.size() - 1)
					result.push_back( c );
			}
			if( end ) 
				break;
			index++;
		}
		return result;
    }
};