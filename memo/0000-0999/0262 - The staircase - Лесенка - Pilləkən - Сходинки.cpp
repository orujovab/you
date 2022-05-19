#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> vect;
int n, k, dn[2000], tmp;
bool dnbool[2000];

int rec(int index)
{
	if (index >= 2 * n) return 0;
	if (dnbool[index]) return dn[index];
	int tmpmin = rec(index + 1);
	for (int i = 2; i <= k; i++) tmpmin = max(tmpmin, rec(index + i));
	dnbool[index] = true;
	return dn[index] = vect[index] + tmpmin;
}

int main()
{
	cin >> n;
	vect.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < n; i++) vect.push_back(0);
	for (int i = 0; i < 2000; i++) dn[i] = dnbool[i] = 0;
	cout << rec(0) << endl;
}
