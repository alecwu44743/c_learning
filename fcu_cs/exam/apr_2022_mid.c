#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>



// a743: 10420 - List of Conquests - https://zerojudge.tw/ShowProblem?problemid=a743
void ListofConquests(){
    int n;
    char country[2001][76] = {0};
    char name[76] = {0};
    char temp[76] = {0};

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", country[i]);
        gets(name);

        if(strlen(name) > 75) i--;
    }

    // sort country
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(strcmp(country[j], country[j+1]) > 0){
                strcpy(temp, country[j]);
                strcpy(country[j], country[j+1]);
                strcpy(country[j+1], temp);
            }
        }
    }

    int flag = false;
    int cnt = 0;
    int i = 0;

    while(i < n){
        if(!flag){
            printf("%s ", country[i]);
            cnt++;
            flag = true;
        }
        else if(flag){
            if(strcmp(country[i], country[i+1]) == 0){
                cnt++;
            }
            else{
                printf("%d\n", cnt);
                flag = false;
                cnt = 0;
            }
            i++;
        }
    }
}



// c004: 10812 - Beat the Spread! - https://zerojudge.tw/ShowProblem?problemid=c004
// (1) s = x + y
// (2) d = x - y
// 
// (1) + (2) and (1) - (2)
//  => s + d = 2x, must be even
//  => s – d = 2y, must be greater than zero
void beat(){
    int t, s, d;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &s, &d);
        if((s+d) % 2 || s < d){
            printf("impossible\n");
        }
        else{
            printf("%d %d\n", (s+d)/2, (s-d)/2);
        }
    }
}



// d712: The 3n + 1 problem - https://zerojudge.tw/ShowProblem?problemid=d712
// fcu_oj -> pass
// zerojudge by C -> TLE
// zerojudge by C++ -> pass
// the other solution - Fake Segment Tree (Data Strcutures)
void threeNplusOne(){
    int x, y;
    
    while(scanf("%d %d", &x, &y)){
        if(x==0 && y==0) break;

        int max_seq = 0;
        for(int i=x; i<=y; i++){
            int n = i;
            int cnt = 1;
            while(n != 1){
                if(n%2) n = 3*n+1;
                else n /= 2;
                cnt++;
            }
            if(max_seq < cnt) max_seq = cnt;
        }

        printf("%d %d %d\n", x, y, max_seq);
    }
}



// d186: 11461 - Square Numbers - https://zerojudge.tw/ShowProblem?problemid=d186
void squre_find(){
    int x, y;

    while(scanf("%d %d", &x, &y)){
        if(x==0 && y==0) break;

        int cnt = 0;
        for(int i=x; i<=y; i++){
            if(i == (int)sqrt(i)*(int)sqrt(i)) cnt++;
        }

        printf("%d\n", cnt);
    }
}



// a011: 00494 - Kindergarten Counting Game - https://zerojudge.tw/ShowProblem?problemid=a011
void counting_words(){
    char str[200];

    while(scanf("%[^\n]s", str) != EOF){
        int cnt = 0;

        for(int i=0; i<strlen(str); i++){
            if(isalpha(str[i]) && !isalpha(str[i+1])){
                cnt++;
            }
        }

        printf("%d\n", cnt);
        getchar();
    }
}



// f502: 10036 - Divisibility - https://zerojudge.tw/ShowProblem?problemid=f502

// Recursive
// fcu_oj -> pass
// zerojudge -> did not pass QQ
int check(int arr[], int i, int sum, int *N, int *K){
    if(i == *N) return abs(sum) % (*K);

    if(check(arr, i+1, sum+arr[i], N, K) == 0) return 0;
    if(check(arr, i+1, sum-arr[i], N, K) == 0) return 0;

    return 1;        
}

void rec_divisibility(){
    int nn;
    int n, k;
    int arr[10000];

    while(scanf("%d", &nn)){
        for(int ii=0; ii<nn; ii++){
            scanf("%d %d", &n, &k);
            
            for(int i=0; i<n; i++) scanf("%d", &arr[i]);

            if(check(arr, 0, 0, &n, &k) == 0) printf("Divisible\n");
            else printf("Not Divisible\n");
        }
    }
}

// DP
// fcu_oj -> pass
// zerojudge -> TLE QQ
void dp_divisibility(){
    int nn;
    int n, k;
    int num[10004];
    int dp[10004][10004];

    while(scanf("%d", &nn)){
        for(int ii=0; ii<nn; ii++){
            scanf("%d %d", &n, &k);

            for(int i=0; i<n; i++){
                scanf("%d", &num[i]);
                num[i] = abs(num[i]) % k;
            }

            memset(dp, 0, sizeof(dp)), dp[0][0] = 1;
            for(int i=0; i<n; i++){
                for(int j=0; j<k; j++){
                    if(dp[i][j]){
                        dp[i+1][(j+num[i]+k) % k] = 1;
                        dp[i+1][(j-num[i]+k) % k] = 1;
                    }
                }
            }

            if(dp[n][0]){
                printf("Divisible\n");
            }
            else{
                printf("Not divisible\n");
            }
        }
    }
}



// FCU OJ Problems - pB, Week 5
void easy_find_smallest_period(){
    int n;
    char str[256];
    char c;
    
    while(scanf("%d", &n) != EOF){
        

        for(int ss = 0; ss < n; ss++){
            scanf("%c", &c);
            scanf("%s", str);

            int llen = strlen(str);
            int i, j;

            for(i=1; i<llen; i++){
                for(j=0; j+i<llen; j++){
                    if(str[j] != str[j+i]) break;
                }
                if(i+j == llen) break;
            }

            if(llen % i != 0){
                printf("%d\n", llen);
            }
            else{
                printf("%d\n", i);
            }
        }
    }
}



// d670: 10921 - Find the Telephone - https://zerojudge.tw/ShowProblem?problemid=d670
void phone_number(){
    char str[100];
    int data[26];

    for(int i=0; i<18; i++){
        data[i] = i / 3 + 2;
    }
    data[18] = 7;
    data[19] = data[20] = data[21] = 8;
    data[22] = data[23] = data[24] = data[25] = 9;

    while(scanf("%s", str) != EOF){
        int alpha = 0;
        int hyphen = 0;

        for(int i=0; i<strlen(str); i++){
            if(isalpha(str[i])){
                printf("%d", data[str[i] - 'A']);
                alpha++;
            }
            else if(str[i] == '-'){
                printf("%c", str[i]);
                hyphen++;
            }
            else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
        // printf(" %d %d\n", alpha, hyphen);
    }
}



// c044: 10008 - What's Cryptanalysis - https://zerojudge.tw/ShowProblem?problemid=c044
void crypt(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;

        int arr_alpha[26] = {0};
        int max_cnt = -1;
        char str[100];
        char c;
        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int idx=0; idx<strlen(str); idx++){
                c = str[idx];

                if(isalpha(c)){
                    arr_alpha[toupper(c) - 'A']++;

                    if(arr_alpha[toupper(c) - 'A'] > max_cnt) max_cnt = arr_alpha[toupper(c) - 'A'];
                }
            }
        }

        for(int cnt = max_cnt; cnt > 0; cnt--){
            for(int i=0; i<26; i++){
                if(arr_alpha[i] == cnt){
                    printf("%c %d\n", 'A'+i, cnt);
                }
            }
        }

    }
}



// create a online judge
int ans_n;
int test_n;
char ans_str[100][150];
char test_str[100][150];

int judge_checkAC(){
    for(int i=0; i<ans_n; i++){
        for(int j=0; j<strlen(ans_str[i]); j++){
            if(ans_str[i][j] != test_str[i][j] || strlen(ans_str[i]) != strlen(test_str[i])){
                return 0;
            }
        }
    }

    return 1;
}

int judge_checkPE(){
    char pe_ans[ans_n*100+1];
    char pe_test[test_n*100+1];
    int ans_index = 0;
    int test_index = 0;

    for(int i=0; i<ans_n; i++){
        for(int j=0; ans_str[i][j]!='\0'; j++){
            if(!iscntrl(ans_str[i][j]) && !isspace(ans_str[i][j])){
                pe_ans[ans_index] = ans_str[i][j];
                ans_index++;
            }
        }
    }
    pe_ans[ans_index] = '\0';

    for(int i=0; i<test_n; i++){
        for(int j=0; test_str[i][j]!='\0'; j++){
            if(!iscntrl(test_str[i][j]) && !isspace(test_str[i][j])){
                pe_test[test_index] = test_str[i][j];
                test_index++;
            }
        }
    }
    pe_test[test_index] = '\0';

    return strcmp(pe_ans, pe_test) == 0;
}

void judge(){
    int ccase = 1;

    while(scanf("%d", &ans_n) != EOF){
        if(ans_n == 0) break;

        int ans_strlen = 0;

        for(int i=0; i<ans_n; i++){
            getchar();
            scanf("%[^\n]", ans_str[i]);
            ans_strlen += strlen(ans_str[i]);
        }

        scanf("%d", &test_n);
        for(int i=0; i<test_n; i++){
            getchar();
            scanf("%[^\n]", test_str[i]);
        }

        printf("Run #%d: ", ccase);
        if(judge_checkAC()){
            printf("Accepted ");
        }
        else if(judge_checkPE()){
            printf("Presentation Error ");
        }
        else{
            printf("Wrong Answer ");
        }
        printf("%d\n", ans_strlen);

        ccase++;
    }
}



// d139: Compressed String - https://zerojudge.tw/ShowProblem?problemid=d139
void comprStr(){
    int n;
    int cc;
    char str[1000];

    // scanf("%d", &cc);
    // for(int cc=0; cc<n; cc++){
        while(scanf("%s", str) != EOF){
            int cnt = 0;
            for(int i=0; i<strlen(str); i++){
                char c = str[i];
                cnt++;

                if(str[i+1] != c){
                    if(cnt > 2){
                        printf("%d%c", cnt, c);
                    }
                    else{
                        for(int j=0; j<cnt; j++) printf("%c", c);
                    }
                    cnt = 0;
                }
            }

            printf("\n");

        }

        // printf("\n");
}



// integer palindrome
long long int intReverse(long long int n){
    int _sum = 0;

    while(n > 0){
        _sum *= 10;
        _sum += n%10;
        n /= 10;
    }

    return _sum;
}

void integerPalindrome(){
    int n;
    long long int num;
    long long int rev_n;

    scanf("%d", &n);
    for(int ss=0; ss<n; ss++){
        scanf("%lld", &num);

        rev_n = intReverse(num);

        if(rev_n == num){
            printf("%d %lld\n", 0, num);
        }
        else{
            int cnt = 0;

            while(rev_n != num){
                cnt++;
                num += rev_n;
                rev_n = intReverse(num);
            }
            printf("%d %lld\n", cnt, num);
        }
    }
}



// f508: 12041 - BFS (Binary Fibonacci String) - https://zerojudge.tw/ShowProblem?problemid=f508
// my code (.cpp) - https://github.com/alecwu44743/c_learning/blob/main/fcu_cs/mar_29_2022/pC.cpp



// FCU OJ Problems - pB, Week 4 (UVa 11713)
int isVow(char c){
    return c == 'a' || c == 'e' || c == 'i'
           || c == 'i' || c == 'o' || c== 'u';
}

void abstractNames(){
    int n;

    scanf("%d", &n);
    for(int ss=0; ss<n; ss++){
        char a[100];
        char b[100];

        scanf("%s", a);
        scanf("%s", b);

        if(strlen(a) != strlen(b)){
            printf("%s\n", "No");
            continue;
        }

        int isSame = 1;
        for(int i=0; i<strlen(a); i++){
            if(a[i] != b[i] && (!isVow(a[i]) || !isVow(b[i]))){
                isSame = 0;
                break;
            }
        }

        printf("%s\n", isSame ? "Yes" : "No");
    }
}



// Problems - String and Character

// a132: 10931 - Parity - https://zerojudge.tw/ShowProblem?problemid=a132
void parity(){
    int num;

    while(scanf("%d", &num) && num != 0){
        char appnd;
        char str_bin[1000] = "";
        int cnt = 0;
        int len = 0;

        while(num){
            cnt += (num & 1);
            appnd = '0' + (num & 1);
            strncat(str_bin, &appnd, 1);
            num >>= 1;
        }

        printf("The parity of ");
        for(int i=strlen(str_bin)-1; i>=0; i--){
            printf("%c", str_bin[i]);
        }
        printf(" is %d (mod 2).\n", cnt);
    }
}



int main(){
    // ListofConquests();
    // beat();
    // threeNplusOne();
    // squre_find();
    // counting_words();
    // rec_divisibility();
    // dp_divisibility();
    // phone_number();
    // judge();
    // comprStr();
    // integerPalindrome();
    // abstractNames();
    // crypt();

    // parity();
}