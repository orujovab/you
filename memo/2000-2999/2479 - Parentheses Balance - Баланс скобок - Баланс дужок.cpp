#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
string str;

string f()
{
	if (str == "") return "Yes";
	stack <bool> st;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(': st.push(true); break;
		case ')':
		{
			if (st.empty()) return "No";
			if (!st.top()) return "No";
			st.pop();
		}
		break;
		case '[': st.push(false); break;
		case ']':
		{
			if (st.empty()) return "No";
			if (st.top()) return "No";
			st.pop();
		}
		break;
		}
	}
	if (!st.empty()) return "No";
	return "Yes";
}

int main()
{
	cin >> n;
	getline(cin, str);
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		cout << f() << endl;
	}
}
