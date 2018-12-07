#include <iostream>

#include <vector>
#include <map>
using namespace std;
vector<int> myvect = { -1 ,0 ,1 ,7 ,7 ,1 ,0, 2 ,0 ,7,9 };
map<int, int>height;
int solve(vector<int> vect);
int main() {
	


	cout << "solution is : " << solve(myvect) << endl;

	system("pause");
	return 0;
}
int solve(vector<int> vect) {
	int max = 0;
	std::map<int, int>::iterator it;
	int current = 0;
	for (int i = 0; i < vect.size(); i++) {
		int current = 1;
		int store = i;
		while (vect[i] != -1) {
			it = height.find(vect[i]);
			if (it != height.end()) { current += it->second; break; }
			i = vect[i];
			current++;
		}
		height[store] = current;
		if (current > max)max = current;
		i = store;
	}
	return max;
}
