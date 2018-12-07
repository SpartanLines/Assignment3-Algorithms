#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int arr[] = {8,150,300,7,2,1};
int dp[100][100]; 
int solve(int i, int j,int length);
int main() {
	memset(dp, -1, sizeof(dp));
	int solution = solve(0, 5, 4);
	cout << "solution is " << solution << endl;



	system("pause");
	return 0;
}
int solve(int i, int j,int length) {
	//if ( j) return 0;
	//if (i == j)return arr[i];
	//else {
	//		int solve1 = arr[i]+solve(i + 1, j,length);
	//		int solve2 = arr[j] + solve(i, j-1, length);
	//		if (((i + j) %2)==0) {
	//			return 0;
	//		}
	//		else {
	//			return solve1>solve2?solve1:solve2;
	//		}
	//	}
	if ((j - i) == 2) { if (arr[i] > arr[j])return solve(i + 1, j, length); else return  solve(i, j - 1, length); }
	if ((j - i) == 1)return arr[i] > arr[j] ? arr[i] : arr[j];
	else {
		int solve1 = solve(i + 1, j, length);
		int solve2=  solve(i, j - 1, length);
		if (((i + j) % 2) == 0) {
					return solve1<solve2?solve1:solve2;
					}
		else {
			return (solve1+arr[i])>(solve2+arr[j]) ? arr[i]+solve1 :arr[j]+ solve2;
		}
	}
	
	
}