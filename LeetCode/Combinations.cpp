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
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> tmp;
		combineHelper(1, k, n, result, tmp);

		return result;
    }

	void combineHelper(int v, int k, const int maximum,
			vector<vector<int> > &result, vector<int> &tmp)
	{
		if(k == 0)
		{
			result.push_back(tmp);
			return;
		}
		if(v>maximum) // edge case
		{
			return;
		}
		tmp.push_back(v);
		combineHelper(v+1, k-1, maximum, result, tmp);
		tmp.pop_back();
		combineHelper(v+1, k, maximum, result, tmp);
	}
};