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
    int lengthOfLastWord(const char *s) {
		int current = 0;
		int pre = 0;
		for(int i=0;s[i]!='\0';++i)
		{
			if( s[i] == ' ')
			{
				if( current != 0 )
				{
					pre = current;
				}
				current = 0;
			}
			else
			{
				current++;
			}
		}
		if( current == 0 )
			return pre;
		else
			return current;
    }
};