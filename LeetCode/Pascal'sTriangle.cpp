#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include "ListNode.h"
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl; 

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > triangles;
		if( numRows == 0 ){
			return triangles;
		}

		triangles.push_back(vector<int>(1, 1));
		numRows --;
		while(numRows){
			vector<int> newRow;
			int size = triangles[triangles.size()-1].size();
			for(int i=-1;i<size;++i){
				int value1, value2;
				if( i < 0 )
					value1 = 0;
				else
					value1 = triangles[triangles.size()-1][i];
				if( i+1 == size)
					value2 = 0;
				else
					value2 = triangles[triangles.size()-1][i+1];
				newRow.push_back(value1+value2);
			}
			triangles.push_back(newRow);
			numRows--;
		}
    }
};