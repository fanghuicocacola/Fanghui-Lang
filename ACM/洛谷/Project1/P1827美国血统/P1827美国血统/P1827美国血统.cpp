#include <string>
#include <iostream>
using namespace std;

void DFS(string aa, string bb)
{
	if (!(int)bb.size())
		return;
	int pos = aa.find(bb[0]);
	DFS(aa.substr(0, pos), bb.substr(1, pos)); 
	DFS(aa.substr(pos + 1), bb.substr(pos + 1)); 
	printf("%c", bb[0]); 
	return; 

}
int main()
{
	string a, b;
	cin >> a >> b;
	DFS(a, b);
	return 0;
}