#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>

using namespace std;

int charToInt(char c)
{
	if( c >= 'A' && c <= 'Z')
		return c - 'A';
	else if( c >= 'a' && c <= 'z')
		return c - 'a';
	else
		return -1;
}

class cmp
{
public:
	bool operator () (const pair<int, int> &a,const pair<int,int> &b)
	{
		return a.first > b.first;
	}
};

void BeatifulStringsSolver()
{
	// freopen("beautiful_stringtxt.txt","r",stdin);
	freopen("sample.txt","r",stdin);
	int m;

	cin >> m;
	string str;
	getline(cin,str);
	int idx = 0;
	while(getline(cin, str))
	{
		vector<pair<int, int> > count(26);
		for(int i=0;i<26;++i)
		{
			count[i].first = 0;
			count[i].second = i;
		}
		for(int i=0;i<str.size();++i)
		{
			int v = charToInt(str[i]);
			if(v >= 0)
				count[v].first ++;
		}
		sort(count.begin(), count.end(), cmp());

		int sum = 0;
		
		for(int i=0;i<26;++i)
		{
			sum += count[i].first * (26-i);
		}

		idx ++;
		cout << "Case #" << idx <<": " << sum << endl;
	}
}

//int main()
//{
//	BeatifulStringsSolver();
//	system("pause");
//	return 0;
//}