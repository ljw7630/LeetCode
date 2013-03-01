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
	vector<pair<int, char>> values;
	void init()
	{
		values.push_back(pair<int,char>(1,'I'));
		values.push_back(pair<int,char>(5,'V'));
		values.push_back(pair<int,char>(10,'X'));
		values.push_back(pair<int,char>(50,'L'));
		values.push_back(pair<int,char>(100,'C'));
		values.push_back(pair<int,char>(500,'D'));
		values.push_back(pair<int,char>(1000,'M'));											
	}
    string intToRoman(int num) {
		init();
        string s;
		for( int i = 0; num; num /=10, i+=2)
		{
			int v = num%10;
			switch(v)
			{
			case 0:
				break;
			case 1:
			case 2:
			case 3:
				s = string(v, values[i].second) + s;
				break;
			case 4:
				s = values[i+1].second + s;
				s = values[i].second + s;
				break;
			case 5:
				s = values[i+1].second + s;
				break;
			case 6:
			case 7:
			case 8:
				s = values[i+1].second + string(v-5, values[i].second) + s;
				break;
			case 9:
				s = values[i+2].second + s;
				s = values[i].second + s;
				break;
			default:
				break;
			}
		}
		return s;
    }
};