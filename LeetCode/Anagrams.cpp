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
	vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string> > m;
		
		for(int i=0;i<strs.size();++i)
		{
			string s = strs[i];
			sort(s.begin(),s.end());
			m[s].push_back(strs[i]);
		}

		// int num=1;
		vector<string> res;
		for(map<string, vector<string> >::iterator itr=m.begin();itr!=m.end();++itr)
		{
			if(itr->second.size()>1)
			{
				res.insert(res.end(), itr->second.begin(),itr->second.end());
			}
		}

		return res;
	}
};

//int main()
//{
//	string ss[] = {"tea","and","ate","eat","dan"};
//	vector<string> vecs;
//	for(int i=0;i<5;++i)
//		vecs.push_back(ss[i]);
//	//vecs.push_back(string("edcba"));
//	vector<string> res = Solution().anagrams(vecs);
//	for(int i=0;i<vecs.size();++i)
//		cout << res[i] << endl;
//
//	getchar();
//	return 0;
//}