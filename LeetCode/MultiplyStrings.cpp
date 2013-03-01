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
	string multiply(string num1, string num2) {

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		vector<int> result(num1.size() + num2.size(), 0);

		for(int i=0;i<num1.size();++i){
			for(int j=0;j<num2.size();++j){
				int tmp = (num1[i]-'0')*(num2[j]-'0');
				result[i+j] = tmp + result[i+j];
			}
		}

		int carry = 0;
		for(int i=0;i<result.size();++i){
			int tmp = carry+result[i];
			carry = tmp / 10;
			result[i] = tmp%10;
		}
		for(int i=result.size()-1;i>0;--i){
			if(result[i] == 0)
				result.pop_back();
			else
				break;
		}
		string resultString;
		for(int i=result.size()-1;i>-1;--i){
			resultString.push_back(result[i]+'0');
		}
		return resultString;
	}
};

//int main(){
//	string a = "0";
//	string b = "0";
//	cout << Solution().multiply(a, b) << endl;
//	getchar();
//	return 0;
//}