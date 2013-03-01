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
    vector<int> plusOne(vector<int> &digits) {
		vector<int> result(digits.size()+1, 0);
		reverse(digits.begin(), digits.end() );
		int carry = 1;
		for(int i=0;i<digits.size();++i){
			int tmp = digits[i] + carry;
			carry = tmp / 10;
			result[i] = tmp % 10;
		}

		if( carry ){
			result[digits.size()] = carry;			
		}
		else{
			result.pop_back();
		}

		reverse(result.begin(), result.end());
		return result;
    }
};