#include <iostream>
#include <string>
using namespace std;

unsigned Fibonacci[24][2] = { { 1, 1 } };
string BFSs[4] = { "0", "1", "01", "101" };

void Initialize() {
	for (int i = 1; i < 24; ++i) {
		Fibonacci[i][0] = Fibonacci[i - 1][0] + Fibonacci[i - 1][1];
		Fibonacci[i][1] = Fibonacci[i - 1][1] + Fibonacci[i][0];
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(nullptr);
	long long times, number, left, right, nowIndex, buffer;
	unsigned sums;
	Initialize();
	cin >> times;
	while (times--) {
		cin >> number >> left >> right;

		if (number > 47)
			number = 46 + (number % 2); // n = 46 + (k % 2)

		for (int i = left; i <= right; i++) {
			nowIndex = i;
            buffer = number;

			while (buffer >= 4) { // buffer = n
				sums = 0;
				if (buffer % 2) {
					if (nowIndex < Fibonacci[(buffer / 2) - 1][1]) {
						buffer -= 2;
						continue;
					}
					sums += Fibonacci[(buffer / 2) - 1][1];
				}
				for (int j = 0; j < 2; j++) {
					if (nowIndex < sums + Fibonacci[(buffer / 2) - 1][j]) {
						buffer = (buffer - 2 - (buffer % 2)) + j;
						nowIndex -= sums;
						break;
					}
					sums += Fibonacci[(buffer / 2) - 1][j];
				}
			}
			cout << BFSs[buffer][nowIndex];
		}
		cout << '\n';
	}
}