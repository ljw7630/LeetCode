#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>

using namespace std;

bool BalancedSmileysRecursiveSolver(const string &str, int index, char pre, stack<char> &left)
{
	if( index == str.size() )
	{
		if(left.empty())
			return true;
		else
			return false;
	}

	if(str[index] == ')')
	{
		if(left.empty())
		{
			if(pre!=':')
			{
				return false;
			}
			else
			{
				return BalancedSmileysRecursiveSolver(str, index+1, str[index], left);
			}
		}
		else
		{
			bool asSmiley = false;
			if(pre == ':')
			{
				asSmiley = BalancedSmileysRecursiveSolver(str, index+1, str[index], left);
			}
			bool asParenthese = false;
			if(!left.empty())
			{
				left.pop();
				asParenthese = BalancedSmileysRecursiveSolver(str, index+1, str[index], left);
			}

			return asSmiley || asParenthese;
		}
	}
	else if(str[index] == '(')
	{
		bool asFrowny = false;
		if(pre == ':')
		{
			asFrowny = BalancedSmileysRecursiveSolver(str, index+1, str[index], left);
		}
		left.push(str[index]);
		bool asParenthese = BalancedSmileysRecursiveSolver(str, index+1, str[index], left);

		return asFrowny || asParenthese;
	}
	else
	{
		return BalancedSmileysRecursiveSolver(str, index+1, str[index], left);
	}
}

void BalancedSmileysSolver()
{
	freopen("balanced_smileystxt.txt", "r", stdin);
	freopen("out.txt","w", stdout);
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	int idx = 0;
	while(getline(cin, str))
	{
		stack<char> left;
		bool result = BalancedSmileysRecursiveSolver(str, 0, ' ', left);
		idx++;
		if(result)
		{
			cout << "Case #" << idx << ": " << "YES" << endl;
		}
		else
		{
			cout << "Case #" << idx << ": " << "NO" << endl;
		}
	}
}

//int main()
//{
//	BalancedSmileysSolver();
//	//getchar();
//	return 0;
//}