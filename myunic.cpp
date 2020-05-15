#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
vector<string> str;

bool sort_key(string i, string j)
{
if ( i < j )
{
return 1;
}
return 0;
}

int main()
{

while (cin)
{
string a;
getline(cin, a);
str.push_back(a);
//break;
}

sort(str.begin(), str.end(), sort_key);

for (int i = 0; i < str.size(); ++i)
cout << str[i] << ' ';
}
