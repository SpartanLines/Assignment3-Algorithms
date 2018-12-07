#include <iostream>
#include <string>
#include <string.h>

using namespace std;
string name = "formoemenbjnemeomfor";
string dp[100][100];
string solve(int i, int j);
int main() {
	//wmemset(dp, 1, sizeof(dp));
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			dp[i][j] = "-1";

	string solution = solve(0, name.length() - 1);
	cout << solution;

	system("pause");
	return 0;

}
string solve(int i, int j) {
	if (dp[i][j] != "-1")return dp[i][j];
	if (name[i] == name[j]) {
		if ((j - i) < 2)return name.substr(i, (j - i)+1);
		else {
			string temp = solve(i + 1, j - 1);
			if (temp.length() != (name.substr(i, (j - i) + 1).length() - 2))return dp[i][j]=temp;
			else return dp[i][j] = name[i] + temp + name[j];
		}
	}
	else {
		if ((j - i) < 2) return "";
		else {
			string temp1 = solve(i + 1, j);
			string temp2 = solve(i, j - 1);
			return dp[i][j] = temp1.length() > temp2.length() ? temp1 : temp2;
		}
	}
	//else if (name[i] == name[j])return name[i] + solve(i + 1, j - 1) + name[j];

}