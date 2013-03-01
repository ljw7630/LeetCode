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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > result;
		vector<int> tmpVec;
		recursiveAdd(num, 0, target, result, tmpVec);

		return result;
    }

	void recursiveAdd(vector<int> &num, int index, int target,
					vector<vector<int> > &res, vector<int> &tmpVec)
	{
		if(target == 0)
		{
			res.push_back(tmpVec);
			return;
		}
		//for(int i = index; i < num.size() && target >= num[i]; )
		int i = index;
		if(i < num.size() && target >= num[i])
		{
			tmpVec.push_back(num[i]);
			recursiveAdd(num, i+1, target-num[i], res, tmpVec);
			tmpVec.pop_back();
			int current = i;
			while( i<num.size() && num[i] == num[current])
				i++;	
			recursiveAdd(num, i, target, res, tmpVec);
		}
	}
};

