#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int isPalindrome(char str[], int s, int e){
    if(!isalpha(str[s])) return isPalindrome(str, s+1, e);
    if(!isalpha(str[e])) return isPalindrome(str, s, e-1);

    if(s == e){
        return 1;
    }

    if(str[s] != str[e]){
        return 0;
    }

    if(s < e + 1){
        return isPalindrome(str, s+1, e-1);
    }
    
    return 1;
}

void isP(){
    char str[100];
    while(scanf("%[^\n]", str) != EOF){
        getchar();
        
        if(isPalindrome(str, 0, strlen(str))){
            printf("%s", "yes\n");
        }
        else{
            printf("%s", "no\n");
        }
    }
}

void p1(int n){
    printf("p1: %d\n", n+1);
}

void p2(int n){
    printf("p2: %d\n", n+2);
}

void p3(int n){
    printf("p3: %d\n", n+3);
}

void p4(int n){
    printf("p4: %d\n", n+4);
}

void ptrfunc(){
    void (*add_func[4])(int) = {p1, p2, p3, p4};

    int n;
    while(scanf("%d", &n) != -1){
        for(int i=0; i<4; i++){
            add_func[i](n);
        }
    }
}

int rec_prime(int x, int y){
    if(x == y) return 1;
    else if(x%y == 0) return 0;
    else return rec_prime(x, y+1);
}

void call_rec_prime(){
    int n;
    while(scanf("%d",&n) && n != 0){
        if(rec_prime(n, 2)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}

int rec_gdc(int x, int y){
    if(y == 0) return x;
    else return rec_gdc(y, x%y);
}

int loop_gdc(int x, int y){
    while(y > 0){
        int temp = x%y;
        x = y;
        y = temp;
        
    }
    return x;
}

void call_gdc(){
    int n, m;
    while(scanf("%d %d", &n, &m) && n>0 && m>0){
        // printf("%d\n", rec_gdc(n, m));
        printf("%d\n", loop_gdc(n, m));
    }
}

void nnn(int n){
    int _n = n;
    for(int i = 10000; i>=1; i/=10){
        if(n%i != _n){
            printf("%d ", n/i);
            n %= i;
        }
    }
    printf("\n");
}

void call_nnn(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == -1) break;
        
        nnn(n);
    }
}

int loop_digitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int rec_digitSum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n % 10 + rec_digitSum(n/10);
    }
}

void call_digitSum(){
    int n;

    while(scanf("%d", &n) != EOF) {
        printf("loop: %d\n", rec_digitSum(n));
        printf("rec: %d\n", rec_digitSum(n));
    }
}

void rec_reverse_str(char str[], int i){
    if(str[i]== '\0'){
        return;
    }
    rec_reverse_str(str, i+1);
    printf("%c", str[i]);
}

void loop_rev_str(char str[]){
    for(int i=strlen(str)-1; i>=0; i--){
        printf("%c", str[i]);
    }
    printf("\n");
}

void call_rev_string(){
    char str[100];

    while(scanf("%[^\n]", str) != EOF){
        getchar();
        printf("rec: ");
        rec_reverse_str(str, 0);
        printf("\nloop: ");
        loop_rev_str(str);
    }
}

void union_set(){
    int n, input;
    int index = 0;
    int bool_set[100] = {0};
    int _set[100];
    
    while(scanf("%d", &n) != EOF){
        while(n){
            scanf("%d", &input);

            if(!bool_set[input]){
                bool_set[input] = 1;
                _set[index] = input;
                index++;
            }
            n--;
        }

        for(int i=0; i<index; i++){
            printf("%d ", _set[i]);
        }
        printf("\n");
    }
}

int power(int n){
    if(n == 1){
        return n;
    }
    else{
        return n * power(n-1);
    }
}

void call_power(){
    int n;

    while(scanf("%d", &n) != EOF){
        printf("power %d\n", power(n));
    }
}

int poww(int n, int d){
    if(d == 0){
        return 1;
    }
    else{
        return n * poww(n, d-1);
    }
}

void call_poww(){
    int n, d;

    while(scanf("%d %d", &n, &d) != EOF){
        printf("poww %d\n", poww(n, d));
    }
}

void binarySearch(int arr[], int n, int x){
    int s = 0;
    int e = n-1;
    int mid;

    while(s <= e){
        mid = (s+e)/2;

        if(arr[mid] == x){
            printf("%d\n", mid);
            return;
        }
        else if(arr[mid] > x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    printf("%d\n", -1);
}



int main(){
    // isP();
    // ptrfunc();
    // call_rec_prime();
    // call_gdc();
    // call_nnn();
    // call_digitSum();
    // call_rev_string();
    // union_set();
    // call_power();
    // call_poww();
}

// give me a coding interview problems to solve
// https://www.geeksforgeeks.org/c-program-to-print-all-permutations-of-a-given-string/