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
	/// First in first out
	/// so can be implemented by vector or queue
	/// special case for i == 0 && i == size()-1
	/// clear queue
	/// delete resources after "new"
    string countAndSay(int n) {
		string result;
		if(n <= 0)
			return result;

		vector<int> *vectorToRead = new vector<int>();
		vector<int> *vectorToStore = new vector<int>();
	
		vectorToRead->push_back(1);

		int step = n-1;

		while(step)
		{			
			int pre = -1;
			int count = 0;
			for(int i = 0;i<vectorToRead->size();++i)
			{
				int v = (*vectorToRead)[i];
				if(v!=pre)
				{
					if(pre!=-1)
					{
						vectorToStore->push_back(count);
						vectorToStore->push_back(pre);
					}
					count = 1;
					pre = v;
				}
				else
				{
					count ++;
				}

				if( i == vectorToRead->size()-1)
				{
					vectorToStore->push_back(count);
					vectorToStore->push_back(v);
				}
			}
			vectorToRead->clear();
			swap(vectorToRead, vectorToStore);
			step --;
		}

		for(int i=0;i<vectorToRead->size();++i)
		{
			result.push_back((*vectorToRead)[i]+'0');
		}
		delete vectorToRead;
		delete vectorToStore;
		return result;
    }
};

//int main()
//{
//	Solution().countAndSay(4);
//	return 0;
//}