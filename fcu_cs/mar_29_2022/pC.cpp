// reference - https://home.gamer.com.tw/artwork.php?sn=5021122
#include <iostream>
#include <string>
using namespace std;

// 觀察 BST 的前八項：
// 0                1
// 01               101
// 01101            10101101
// 0110110101101    10101101 0110110101101
// 而每個字串的長度為
// 1                           1
// 2                           3
// 5                           8
// 13                         21
// 為典型的費氏數列
//
// 此時我們替換 BST 的每一項：
// X:                     Y:
// X0 - X0                Y0 - Y0
// X1 - X0Y0              Y1 - Y0X0Y0
// X2 - X1Y1              Y2 - Y1X1Y1
// X3 - X2Y2              Y3 - Y2X2Y2
// 其中 Xi = Xi-1Yi-1 、 Yi = Yi-1Xi-1Yi-1 ，而 X0 = 0 、 Y0 = 1

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
				sum = 0; // pre-length
				if(buffer % 2){ // if buffer is at the Y
					if(nowIndex < fib[(buffer / 2) - 1][1]){ // check if nowIndex is in the Y((buffer / 2) - 1)
						buffer -= 2;
						continue;
					}
					sum += fib[(buffer / 2) - 1][1];
				}

				for(int j=0; j<2; j++){
					if(nowIndex < sum + fib[(buffer / 2) - 1][j]){
						buffer = (buffer - 2  - (buffer % 2)) + j;	// buffer % 2 ->  check X or Y
						                                        	// + j -> 0 or 1
						nowIndex -= sum; // minus the preceding length
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