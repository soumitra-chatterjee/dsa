// find the Nth 'super ugly number', where a 'super ugly number' 
// is defined as a positive integer having all of its prime factors
// present in the given 'primes' array
// 
// * '1' is the first such number because the only factor of 1 is
// itself, which is not a prime number; therefore, it doest not have 
// any prime factor that are not present in the given array
//
// https://www.geeksforgeeks.org/super-ugly-number-number-whose-prime-factors-given-set/
// https://leetcode.com/problems/super-ugly-number/
// 

#include <bits/stdc++.h>
using namespace std;

class SuperUglyNum {
	
	// using arrays 
	int findNum(int m, vector<int>& primes, int N) {
		vector<int> arr(N);
		arr[0] = 1;
		vector<int> pointer(m);
		for(int i = 1; i < N; i++) {
			int ithNum = INT_MAX;
			for(int j = 0; j < m; j++) {
				ithNum = min(ithNum, primes[j] * arr[pointer[j]]);
			}
			arr[i] = ithNum;
			for(int j = 0; j < m; j++) {
				if(primes[j] * arr[pointer[j]] == ithNum) {
					pointer[j]++;
				}
			}
		}
		return arr[N-1];
	}
	
	// using priority queue
	int findNum(int m, vector<int>& primes, int N) {
	}
		
		
	
public:	
	void solve() {
		int N;
		cin >> N;
		int m;   // no of given primes
		cin >> m;
		vector<int> primes(m);
		for(int& prime: primes) {
			cin >> prime;
		}
		cout << findNum(m, primes, N) << endl;
	}
};


int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		SuperUglyNum().solve();
	}
	return 0;
}

