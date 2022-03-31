// reference - https://home.gamer.com.tw/artwork.php?sn=5021122
#include <iostream>
#include <string>
using namespace std;

unsigned int fib[24][2] = { {1, 1} };
string BFSs[4] = {"0", "1", "01", "101"};

void fib_init() {
	for (int i = 1; i < 24; ++i) {
		fib[i][0] = fib[i - 1][0] + fib[i - 1][1];
		fib[i][1] = fib[i - 1][1] + fib[i][0];
	}
}


int main() {
	cin.sync_with_stdio(false); cin.tie(nullptr);

	long long int t, n, l, r, nowIndex, buffer;
	unsigned sum;

	fib_init();

	cin >> t;
	while(t--){
		cin >> n >> l >> r;

		if(n > 47) n = 46 + (n % 2);

		for(int i=l; i<=r; i++){
			nowIndex = i;
			buffer = n;

			while(buffer >= 4){
				sum = 0;
				if(buffer % 2){
					if(nowIndex < fib[(buffer / 2) - 1][1]){
						buffer -= 2;
						continue;
					}
					sum += fib[(buffer / 2) - 1][1];
				}

				for(int j=0; j<2; j++){
					if(nowIndex < sum + fib[(buffer / 2) - 1][j]){
						buffer = (buffer - 2 - (buffer % 2)) + j;
						nowIndex -= sum;
						break;
					}
					sum += fib[(buffer / 2) - 1][j];
				}

			}
			cout << BFSs[buffer][nowIndex];
		}
		cout << '\n';
	}
}