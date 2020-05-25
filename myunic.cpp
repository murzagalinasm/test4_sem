#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool sort_key(string i, string j)
{
	return (i<j);
}

int main()
{
	vector<string> strl;
	string str;
	int k = 0;

	while (getline(cin,str))
	{
		strl.push_back(str);
		k++;
	}

	sort(strl.begin(), strl.end(), sort_key);

	for (int i = 0; i < k; i++)
	{
		cout << strl[i] << "\n";

	}

	return 0;
}
