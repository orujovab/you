#include <iostream>

using namespace std;

int main()
{
	double tmp, MAX = -1;
	while (cin)
	{
		cin >> tmp;
		if (tmp > MAX) MAX = tmp;
	}
	cout << fixed << MAX << endl;
}
