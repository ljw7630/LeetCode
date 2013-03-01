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
    vector<int> getRow(int rowIndex) {
		vector<int> pre(1,1);
		vector<int> result;
		if( rowIndex == 0 ){
			return pre;
		}
		
		//rowIndex --;
		while(rowIndex){
			
			int size = pre.size();
			for(int i=-1;i<size;++i){
				int value1, value2;
				if( i < 0 )
					value1 = 0;
				else
					value1 = pre[i];
				if( i+1 == size)
					value2 = 0;
				else
					value2 = pre[i+1];
				result.push_back(value1+value2);
			}
			pre.clear();
			swap(pre, result);
			rowIndex--;
		}

		return pre;
	}
};