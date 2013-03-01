#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		if(a.size()==0||b.size()==0)
			return result;

		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		

		if(a.size()<b.size())
		{
			swap(a,b);
		}

		int carry = 0;
		for(int i=0;i<b.size();++i)
		{
			int value = a[i]-'0'+b[i]-'0'+carry;
			if(value >= 2)
			{
				value = value%2;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			result.push_back('0'+value);
		}

		for(int i=b.size();i<a.size();++i)
		{
			int value = a[i]-'0'+carry;

			if(value >= 2)
			{
				value = value%2;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			result.push_back('0'+value);
		}
		if(carry)
			result.push_back('1');

		reverse(result.begin(),result.end());

		return result;
	}
};

//int main()
//{
//	string a = "11";
//	string b = "1";
//	cout << Solution().addBinary(a, b) << endl;
//
//	getchar();
//
//	return 0;
//}