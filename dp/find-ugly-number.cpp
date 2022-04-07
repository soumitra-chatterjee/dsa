// find the nth ugly number
// 'ugly number' is a positive integer having the only prime factors {2, 3, 5}
// https://leetcode.com/problems/ugly-number-ii/

#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
      vector<int> dp(n);
      dp[0] = 1;
      int p2 = 0;
      int p3 = 0;
      int p5 = 0;

      for(int i = 1; i < n; i++) {
          int a = dp[p2] * 2;
          int b = dp[p3] * 3;
          int c = dp[p5] * 5;
          int res = min({a, b, c});
          dp[i] = res;
          if(res == a) {
              p2++;
          }
          if(res == b) {
              p3++;
          }
          if(res == c) {
              p5++;
          }
      }
      return dp[n-1];
  }

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << nthUglyNumber(n) << endl;
	}
	return 0;
}
