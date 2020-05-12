#include <iostream>
#include <math.h>
#include <string>
struct  stu
{
	int chinese, maths, english, score;
	std::string name;
}a[1001];

using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].chinese >> a[i].maths >> a[i].english;
		a[i].score = a[i].chinese + a[i].maths + a[i].english;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ans[4];
			ans[0] = abs(a[i].chinese - a[j].chinese);
			ans[1] = abs(a[i].maths - a[j].maths);
			ans[2] = abs(a[i].english - a[j].english);
			ans[3] = abs(a[i].score - a[j].score);
			if (ans[0] <= 5 && ans[1] <= 5 && ans[2] <= 5 && ans[3] <= 10) {
				if (a[i].name < a[j].name)
					cout << a[i].name << " " << a[j].name;
				else
					cout << a[j].name << " " << a[i].name;
				cout << std::endl;
			}
		}
	}
}


