#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define DAY 24*60

enum {MAX_LEN = 256, MAX_LINE = 1000}; // strings...

enum {NUM_WORDS = 20}; // qsort...

enum {BIN_MAX_LEN = 100, BIN_NUM_WORDS = 1200}; // bin...

enum {SIZE = 4};

int permute_cnt = 0;

typedef struct ans{
    int ascii;
    int cnt;
}ANS;

struct aaa{
    int a;
    int b;
};

struct bbb{
    struct aaa ab;
    int c;
};

struct pos{
    int x;
    int y;
};
typedef struct pos pos;

struct aviation{
    struct pos loc;
    char name[10];
};

struct t_point {
    int x;
    int y;
};
typedef struct t_point Point;

struct t_rect {
    Point pt1;
    Point pt2;
};
typedef struct t_rect Rect;

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

// struct student {
//     char name[256];
//     int score;
//     float fscore;
// };
// typedef struct student student;

typedef enum {Female, Male} fm;

struct student{
    char name[25];
    int score;
    fm FM;
};
typedef struct student student;

// typedef enum sex Sex{
//     Female,
//     Male
// }

struct sstudent{
    char name[25];
    int score;
    char sex[20];
};
typedef struct sstudent sstudent;

Node * insertList(Node *np, int val){
    Node *newNode, *prev, *cur;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Out of memory!\n");
        return NULL;
    }
    
    newNode->data = val;
    newNode->next = NULL;

    prev = NULL;
    cur = np;

    while (cur != NULL && val > cur->data){
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL){
        newNode->next = np;
        np = newNode;
    }
    else{
        prev->next = newNode;
        newNode->next = cur;
    }

    return np;
}

Node * deleteList(Node *np, int val){
    Node *prev, *cur, *temp;

    if (val == np->data){
        temp = np;
        np = np->next;

        free(temp);

        return np;
    }

    prev = np;
    cur = np->next;

    while (cur != NULL && val != cur->data){ // cur!=NULL && cur<val
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL){
        printf("%d not found!\n", val);
    }
    else{
        if (cur->data == val){
            temp = cur;
            prev->next = cur->next;
            free(temp);
        }
    }

    return np;
}

void displayList(Node *np){
    if (np == NULL){
        printf("List is empty\n");
    }
    else{
        printf("Linked list: ");
        while (np != NULL){
            printf("%d--> ", np->data);
            np = np->next;
        }
        printf("NULL\n");
    }
}

void linkedlist(){
    Node * head;
    head = NULL;

    // Node n1, n2;

    // head = &n1;

    // n1.data = 4;
    // n1.next = &n2;

    // n2.data = 15;
    // n2.next = NULL;

    head = insertList(head, 4);
    displayList(head);

    head = insertList(head, 15);
    displayList(head);
    
    head = insertList(head, 8);
    displayList(head);

    head = insertList(head, 1);
    displayList(head);

    head = deleteList(head, 8);
    displayList(head);

    head = deleteList(head, 1);
    displayList(head);

    head = deleteList(head, 1000);
    displayList(head);
}

void push_stack(Node **top, int val){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Out of memory!\n");
    }else{
        newNode->data = val;
        newNode->next = *top; // stackptr
        *top = newNode;
    }
}

int pop_stack(Node **top){
    Node *temp;
    int popVal;

    if (*top == NULL){
        printf("Stack is empty!\n");
        return -1;
    }

    temp = *top;
    *top = (*top)->next;
    popVal = temp->data;
    free(temp);

    return popVal;
}

void displayStack(Node * cur){
    if (cur == NULL){
        printf("Stack is empty\n");
    }else{
        printf("Stack: ");
        while (cur != NULL){
            printf("%d--> ", cur->data);
            cur = cur->next;
        }
    }
    printf("NULL\n");
}

void stack(){
    Node * stackptr;
    stackptr = NULL;

    push_stack(&stackptr, 20);
    displayStack(stackptr);

    push_stack(&stackptr, 12);
    displayStack(stackptr);

    push_stack(&stackptr, 93);
    displayStack(stackptr);

    push_stack(&stackptr, 19);
    displayStack(stackptr);

    push_stack(&stackptr, 520);
    displayStack(stackptr);

    printf("Popped value: %d\n", pop_stack(&stackptr));
    displayStack(stackptr);
}

void enqueue(Node **front, Node **rear, int val){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Out of memory!\n");
    }else{
        newNode->data = val;
        newNode->next = NULL;
        if (*front == NULL){
            *front = newNode;
        }else{
            (*rear)->next = newNode;
        }
        *rear = newNode;
    }
}

int dequeue(Node **front, Node **rear){
    int dequeueVal;
    Node *temp;

    if (*front == NULL){
        printf("Queue is empty!\n");
        return -1;
    }

    dequeueVal = (*front)->data;
    temp = *front;
    *front = (*front)->next;

    if (*front == NULL){
        *rear = NULL;
    }
    free(temp);

    return dequeueVal;
}

void displayQueue(Node *cur){
    if (cur == NULL){
        printf("Queue is empty\n");
    }else{
        printf("Queue: ");
        while (cur != NULL){
            printf("%d--> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void queue(){
    Node * front;
    Node * rear;

    front = NULL;
    rear = NULL;

    enqueue(&front, &rear, 19);
    displayQueue(front);

    enqueue(&front, &rear, 93);
    displayQueue(front);

    enqueue(&front, &rear, 12);
    displayQueue(front);

    enqueue(&front, &rear, 20);
    displayQueue(front);

    enqueue(&front, &rear, 520);
    displayQueue(front);

    printf("Dequeued value: %d\n", dequeue(&front, &rear));
    displayQueue(front);

    printf("Dequeued value: %d\n", dequeue(&front, &rear));
    displayQueue(front);

    printf("Dequeued value: %d\n", dequeue(&front, &rear));
    displayQueue(front);

    printf("Dequeued value: %d\n", dequeue(&front, &rear));
    displayQueue(front);
}

int area(Rect rect) {
    return (rect.pt2.x - rect.pt1.x) * (rect.pt2.y - rect.pt1.y);
}

int pointer_area(Rect * rect) {
    // return ((*rect).pt2.x - (*rect).pt1.x) * ((*rect).pt2.y - (*rect).pt1.y);
    return (rect->pt2.x - rect->pt1.x) * (rect->pt2.y - rect->pt1.y);
}

void struct_avia() {
    struct aviation eva;

    eva.loc.x = 10;
    eva.loc.y = 20;

    strcpy(eva.name, "Eva");

    printf("%s is at (%d, %d)\n", eva.name, eva.loc.x, eva.loc.y);
}

void struct_rect() {
    struct t_point tp = {10, 20};
    Rect rectangle = {{10, 20}, {30, 40}};

    Rect rect1 = {{50, 60}, {70, 80}};
    Rect rect2;
    rect2 = rect1;
    // struct t_rect rectangle = { {10, 20}, {50, 60} };

    printf("tp: (%d, %d)\n", tp.x, tp.y);
    printf("rectangle: (%d, %d) to (%d, %d)\n", rectangle.pt1.x, rectangle.pt1.y, rectangle.pt2.x, rectangle.pt2.y);

    printf("pt1.x=%d, pt1.y=%d\n", rect2.pt1.x, rect2.pt1.y);
    printf("pt2.x=%d, pt2.y=%d\n", rect2.pt2.x, rect2.pt2.y);

    printf("area = %d\n", area(rect2));
    printf("area = %d\n", pointer_area(&rect2));
}

void ptr_arr(){
    int a[50];
    int * ptr[10];

    for (int i = 0; i < 50; i++) { a[i] = i; }

    for (int i = 0; i < 10; i++) { ptr[i] = &a[5*i]; }

    for (int i = 0; i < 10; i++) {
        printf("ptr[%d]=%p:", i, ptr[i]);
        for(int j = 0; j < 5; j++){
            // printf("%3d ", *(ptr[i]+j));
            printf("%3d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void strings(){
    char  * p[MAX_LINE];
    char buf[MAX_LEN];
    int i, j;

    i = 0;
    while (i < MAX_LINE && fgets(buf, MAX_LEN+1, stdin) != NULL) {
        p[i] = (char *)malloc(strlen(buf) + 1); // end line.
        if (p[i] != NULL){
            strcpy(p[i], buf);
            i++;
        }
    }

    printf("------------------------------- ENDED BY CONTROL+D (macOS)\n");
    // p[0] p[1] p[2] p[3] p[4] p[5] p[6] p[7] p[8] p[9]

    for (j = 0; j < i; j++){
        printf("%s", p[j]);
    }
}

int advance_strings(){
    char **p;
    char **q;
    char buf[MAX_LEN + 1];
    int max_line = 1;
    int i, j;

    p = (char **) malloc (max_line * sizeof(p[0]));

    i = 0;
    while (fgets(buf, MAX_LEN+1, stdin) != NULL) {
        if (i >= max_line) {
            max_line *= 2;
            q = (char **) realloc (p, max_line * sizeof(p[0]));
            if (q == NULL) {
                for (j = 0; j < i; j++){
                    free(p[j]);
                }
                free(p);
                return EXIT_FAILURE;
            }
            p = q;
        }

        p[i] = (char *)malloc(strlen(buf) + 1); // end line.
        if (p[i] == NULL){
            for (j = 0; j < i; j++){
                free(p[j]);
            }
            free(p);
            return EXIT_FAILURE;
        }

        strcpy(p[i], buf);
        i++;
    }

    for (j = 0; j < i; j++){
        printf("%s", p[j]);
    }

    for (j = 0; j < i; j++){
        free(p[j]);
    }
    free(p);
}

int scmp(const void *p1, const void *p2){
    char *v1, *v2;
    v1 = *(char **) p1; // p1->location of the pointer.
    v2 = *(char **) p2;

    return strcmp(v1, v2); // v1 < v2 -> -1
}

void qsort_using(){
    char buf[MAX_LEN + 1];
    char * words[NUM_WORDS];
    int i=0, j;

    while (i<NUM_WORDS && fgets(buf, MAX_LEN+1, stdin) != NULL) {
        buf[strlen(buf)-1] = '\0';  // be end earlier.
        words[i] = (char *)malloc(strlen(buf) + 1);
        strcpy(words[i], buf);
        i++;
    }

    qsort(words, i, sizeof(words[0]), scmp);

    printf("------------------------------- ENDED BY CONTROL+D (macOS)\n");

    for (j = 0; j < i; j++){
        printf("%s\n", words[j]);
    }

    for (j = 0; j < i; j++){
        free(words[j]);
    }
}

void strUpper(char *p){
    while (*p != '\0'){
        printf("%c", toupper(*p));
        p++;
    }
}

void strLower(char *p){
    while (*p != '\0'){
        printf("%c", tolower(*p));
        p++;
    }
}

void show(void (*pf)(char *), char *str){
    (*pf)(str); // *pf <- str, like as 'func(str)'
    printf("\n");
}

void functionPointers(){
    char str[100];
    void (*pf) (char *);

    fgets(str, 100, stdin);
    str[strlen(str)-1] = '\0';

    printf("strUpper:\n");
    pf = strUpper;
    show(pf, str);

    printf("strLower:\n");
    pf = strLower;
    show(pf, str);
}

int cmpfunc (const void * va, const void * vb){
    char *a, *b;
    a = *(char **) va;
    b = *(char **) vb;
    return strcmp(a, b);
}

void BinarySearch(){
    char **p;
    char buf[BIN_MAX_LEN + 1];
    char **np;
    char *key;

    int i, j;
    FILE *fin;

    fin = fopen("words.txt", "r");

    p = (char **) malloc (BIN_NUM_WORDS * sizeof(char *));
    i = 0;

    while (i<BIN_NUM_WORDS && fgets(buf, BIN_MAX_LEN+1, fin) != NULL) {
        buf[strlen(buf)-1] = '\0';
        p[i] = (char*) malloc(strlen(buf)+1);

        if (p[i] != NULL){
            strcpy(p[i], buf);
            i++;
        }
    }

    fclose(fin);
    printf("number of words: %d\n", i);

    for (j = 0; j < i; j++){
        printf("%s\n", p[j]);
    }

    printf("-------\n");

    while (fgets(buf, BIN_MAX_LEN+1, stdin) != NULL) {
        buf[strlen(buf)-1] = '\0';
        key = buf;
        np = bsearch(&key, p, i, sizeof(p[0]), cmpfunc);

        if (np != NULL){
            printf("> %s\n", *np);
            // printf("np is: %d\n", np);
            // printf("p is: %d\n", p);
            // printf("%d: %s\n", np-p, *np);
            // printf("-------\n");
        }
        else{
            printf("> Not found\n");
        } 
    }

    for (j = 0; j < i; j++){
        free(p[j]);
    }
    free(p);

    printf("DONE !!\n");
}

void array5(){
	int a[][4] = { {1,2,3,4}, {5,6}, {9,10,11,12} };
	int b[][4] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
    // int c[] = {1, 2, 3, 4, 5, 6, 9, 10, 11};

	int i, j;

    printf("a: %10d bytes\n", sizeof(a));
    printf("a[0]: %7d bytes\n", sizeof(a[0]));
    printf("a[0][0]: %4d bytes\n", sizeof(a[0][0]));

    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    printf("--------------------\n");

    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }
}

void array6(){
    char cdata[SIZE] = {'A', 'B', 'C', 'D'};
    char * ptc;
    int idatap[SIZE] = {1, 2, 3, 4};
    int * pti;
    int k;

    ptc = cdata;
    pti = idatap;

    for (k=0; k<SIZE; k++){
        printf("%p %c    %p %d\n", ptc+k, *(ptc+k), pti+k, *(pti+k)); 
        // printf("%c    %d", cdata[k], idatap[k]);
    }
}

void PtrNArr(){
    int idata[SIZE] = {1, 2, 3, 4};
    int * pti;
    int k;

    pti = idata; // pti = &idata[0];

    for (k=0; k<SIZE; k++){
        printf("%d ", idata[k]);
        printf("%d ", *(pti+k));

        printf("%d ", *(idata+k));
        printf("%d ", *(&idata[0]+k));

        printf("%d ", pti[k]); 
        // idata[k] => *(idata + k)
        // pti[k] => *(pti + k) => *(idata + k)

        printf("%d ", k[idata]);
        printf("%d ", k[pti]);
        // k[idata] => *(k + idata) => *(idata + k) => idata[k]
        // k[pti] => *(k + pti) => *(pti + k) => pti[k]

        printf("\n");
    }
}

int sum(int *ap, int size){
    // int sum(int a[], int size);
    int res = 0;

    for(int i = 0; i < size; i++){
        res += *(ap+i);
        // res = res + ap[i];
    }

    return res;
}

int adv_sum(int *startp, int *endp){
    int res = 0;

    printf("endp: %p\n", endp);

    while (startp < endp){
        res += *startp;
        startp++;
    }

    return res;
}

int _bsearch(int a[], int left, int right, int target){
    int mid = left + (right - left) / 2;

    if (left > right) { return -1; }

    if (a[mid] == target){
        return mid;
    }
    else if (a[mid] > target){
        return _bsearch(a, left, mid-1, target);
    }
    else if (a[mid] < target){
        return _bsearch(a, mid+1, right, target);
    }
}

void swap(char *x, char *y){
    char t;
    t = *x;
    *x = *y;
    *y = t;
}

void permute(char a[], int n){

    if(n == 1){
        printf("%s\n", a);
        permute_cnt++;
    }
    else{
        for (int i = n-1; i>=0; i--){
            swap(&a[i], &a[n-1]);
            permute(a, n-1);
            swap(&a[i], &a[n-1]);
        }
    }
}

void show_int_array(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
        // printf("%d ", *(a+i));
    }
    printf("\n");
}

void show_int_2d_array(int a[][2], int r){ // int a[][2] => int (*a)[2]
    for (int i = 0; i < r; i++){
        for (int j = 0; j < 2; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void basic_malloc(){
    double * ptd;
    int arr_size;

    scanf("%d", &arr_size);

    ptd = (double *)malloc(arr_size * sizeof(double));

    if (ptd == NULL){
        printf("malloc failed.\n");
        exit(EXIT_FAILURE); // end this program early
    }
    
    for(int i=0; i<arr_size; i++){
        ptd[i] = (double) rand() / RAND_MAX; // ptd[i] -> *(ptd+i)
    }

    for(int i=0; i<arr_size; i++){
        printf("%d: %f\n", i, ptd[i]);
    }

    free(ptd);
}

void malloc_two_star(){
    int *a;
    int * *b;
    int r, c; // r: row, c: column

    scanf("%d %d", &r, &c);

    a = (int *)malloc(r*c * sizeof(int));

    for (int i = 0; i < r*c; i++) a[i] = i;

    b = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++) b[i] = &a[c*i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }

    free(b);
    free(a);
}

void displayBits(unsigned int val){
    unsigned int mask = 1 << 31; // -> 1(0)*31 

    for (int i = 0; i < 32; i++){
        printf("%d", (mask&val) != 0); // 100 & 110 -> 100
        mask = mask >> 1;
    }

    printf("\n");
}

unsigned int getBits(unsigned int x, int p, int n){ // 取出 x 的第 p 位置算起 n 個 bits
    return ( (x >> (p-n)) & ~(~0 << n) ); // ~0 << n -> 1111...0000000...
}

unsigned int invert(unsigned int x, int p, int n){ // 將 x 第 p 位置算起 n 個 bits 由 0 -> 1, 1 -> 0
    return x ^ (~(~0 << n) << (p-n));
}

unsigned rightRotate(unsigned int x, int n){ // 傳回 x 向右 rotate n bits 之後的結果
    return ((x & ~(~0 << n)) << (sizeof(x) * 8 - n)) | (x >> n);
}

void test_get(){
    unsigned int num = 100;

    printf("getBits(num, 7, 5):   \n");
    displayBits( getBits(num, 7, 5) );
}

void test_invert(){
    unsigned int num = 100;

    printf("invert(num, 7, 5):    \n");
    displayBits( invert(num, 7, 5) );
}

void test_r_rotate(){
    unsigned int num = 100;

    printf("rightRotate(num, 5):  \n");
    displayBits( rightRotate(num, 5) );
}

void demo_bit_func(){
    unsigned int n = 100;

    // test_get();

    // test_invert();

    // test_r_rotate();
}

void bitBasic(){
    unsigned int n = 100;
    
    printf("n:        ");
    displayBits(n);

    printf("0x1F:     ");
    displayBits(0x1F);

    printf("------------------------------------------\n");

    printf("n & 0x1F: ");
    displayBits(n & 0x1F);

    printf("n | 0x1F: ");
    displayBits(n | 0x1F);

    printf("n ^ 0x1F: ");
    displayBits(n ^ 0x1F);

    printf("1's:      ");
    displayBits( ~n );
}

int cscmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void cs1(){
    // code
    int data[3];
    for(int i=0; i<3; i++){
        scanf("%d", &data[i]);
    }

    qsort(data, 3, sizeof(int), cscmp);

    printf("%d %d", data[0], data[2]);
}

void dp_fib_disp(long long int n[]){
    for(int i=1; i<=100; i++){
        printf("%d: %ld\n", i, n[i]);
    }
}

void dp_fib(){
    long long int dp[101] = {0};
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    dp_fib_disp(dp);
}

void anita(){
    // code
    int a = 83;
    int b = 0x6f; // '0x6f'
    int c = 114; // '0x72'
    int d = 121; // '0x79'

    printf("%c", (char)a);
    printf("%c", (char)b);
    printf("%c", (char)c);
    printf("%c", (char)c);
    printf("%c... \n", (char)d);
}

void cs2(){
    int n;
    int m = 10000;
    scanf("%d", &n); // 92626

    while(n > 0){
        printf("%d   ", n/m);
        n %= m;
        m /= 10;
    }
    printf("\n");

}

void _anita(){
    char op;
    int x, y;
    int ans;

    scanf("%c %d %d", &op, &x, &y);

    if (op == '+') ans = x + y;
    if (op == '-') ans = x - y;
    if (op == '*') ans = x * y;
    if (op == '/') ans = x / y;

    if(op == '+' && y < 0){
        op = '-';
        y = abs(y);
    }
    if (op == '-' && y < 0){
        op = '+';
        y = abs(y);
    }

    printf("%d %c %d = %d\n", x, op, y, ans);
}

int recursive_fib(int n){
    if (n <= 1){
        return n;
    }
    else{
        return recursive_fib(n-1) + recursive_fib(n-2);
    }
}

int gcd_recursive(int a, int b){
    if (b == 0) return a;
    return gcd_recursive(b, a%b);
}

void find_gcd_lcm(){
    int x, y;
    
    while(scanf("%d %d", &x, &y) != EOF){
        int n = x*y;
        while(y != 0){
            int t = y;
            y = x%y;
            x = t;
        }

        printf("%d %d\n", x, n/x);
    }
}

void isPrime(){
    int n;
    scanf("%d", &n);

    int flag = 1;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            flag = 0;
            break;
        }
    }

    if(flag){
        printf("Prime\n");
    }else{
        printf("Not prime\n");
    }
}

void bomb(){
    int row = 6, col = 6;
    char map[row][col];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col;){
            char c;
            scanf("%c", &c);
            if(c == '_' || c == 'x'){

            }
        }
    }
}

void carry(){
    char x[11];
    char y[11];

    while(scanf("%s %s", x, y)){
        if(strcmp(x, "0") == 0 && strcmp(y, "0") == 0) break;

        int carry = 0;
        int buffer = 0;
        for(int i=strlen(x)-1, j=strlen(y)-1; i>=0 || j>=0; i--, j--){
            int x_val = (i>=0) ? x[i] - '0' : 0;
            int y_val = (j>=0) ? y[j] - '0' : 0;

            int sum = x_val + y_val + carry;
            buffer = 0;
            if(sum >= 10){
                carry++;
                buffer = sum/10;
            }
        }
        
        if (carry == 0){
            printf("No carry operation.\n");
        }
        else if (carry == 1){
            printf("1 carry operation.\n");
        }
        else{
            printf("%d carry operations.\n", carry);
        }
    }
}

// void prime(){ // last one
//     printf("2\n");
//     for(int i=3; i<=100; i+=2){
//         int isPrime = 1;
//         for(int j=2; j<i; j++){
//             if(i % j == 0){
//                 isPrime = 0;
//                 break;
//             }
//         }
//         if(isPrime){
//             printf("%d\n", i);
//         }
//     }
// }

// print a diamond
void print_diamond(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        for(int j=1; j<=2*i-1; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        for(int j=1; j<=2*i-1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void printf_number(int d, int cnt){
    for(int i=3, j=0; j<cnt; i+=d, j++) printf("%d ", i);
    printf("\n");
}

bool isTriangle(double a, double b, double c){
    if(a+b > c && a+c > b && b+c > a){
        return true;
    }
    return false;
}

double slides(double x, double y, double z){
    return x + y + z;
}

void print_rectangle(int side1, int side2){
    for(int i=0; i<side1; i++){
        for(int j=0; j<side2; j++){
            printf("*");
        }
        printf("\n");
    }
}

bool isEven(int x){
    if(x % 2 == 0){
        return true;
    }
    return false;
}

char str_upper(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a' + 'A';
    }
    return c;
}

char str_lower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 'a';
    }
    return c;
}

int strrlen(char str[]){
    int length = 0;
    for(int i=0; str[i] != '\0'; i++){
        length++;
    }

    return length;
}

void nums_swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int cmp_char(const void* _a , const void* _b)
{
    char* a = (char*)_a;   
    char* b = (char*)_b;
    return *a - *b;
}

void generateNext(char num[], int length){
    int i, j;

    for(i=length-1; i>0; i--){
        if(num[i] > num[i-1]){
            break;
        }
    }

    if(i == 0) return;

    int x = num[i-1], smallest = i;
    for(j=i+1; j<length; j++){
        if(num[j] > x && num[j] < num[smallest]){
            smallest = j;
        }
    }

    nums_swap(&num[i-1], &num[smallest]);

    qsort(num+i, num+length, sizeof(char), cmp_char);

    printf("%s\n", num);

    return;
}

int _stack[100];
int _index = 0;

void _push(int val){
    _stack[_index] = val;
    _index++;
}

int _pop(){
    int i = _index;
    _index--;
    return _stack[i];
}

void _isEmpty(){
    if(_index == 0){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
}

int _size(){
    return _index;
}

int _top(){
    return _stack[_index-1];
}

void _print_stack(){
    for(int i=0; i<_index; i++){
        printf("%d ", _stack[i]);
    }
    printf("\n");
}

void insertion_sort(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void demo_stack(){
    _isEmpty();
    _push(1);
    _push(2);
    _push(3);
    _push(4);
    _push(5);
    _print_stack();
    _pop();
    _pop();
    _print_stack();
    _isEmpty();
    _push(0);
    _push(1);
    _push(2);
    _push(2);
    _push(0);
    _print_stack();
    printf("%d\n", _top());
    _pop();
    _pop();
    _pop();
    _pop();
}

void separate_num(int n){
    int arr[10];
    int i = 0;
    while(n > 0){
        arr[i] = n % 10;
        n /= 10;
        i++;
    }

    printf("%d\n", i);

    for(int j=i-1; j>=0; j--){
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void isPerfect(int n){
    int sum = 0;
    for(int i=1; i<n; i++){
        if(n % i == 0){
            sum += i;
        }
    }

    if(sum == n) printf("%d\n", n);
}

void lcm(int x, int y){
    int num = x*y;
    while(y != 0){
        int temp = y;
        y = x%y;
        x = temp;
    }

    printf("%d\n", num/x);
}

void toQualityPoints(int x){
    if(90 <= x && x <= 100){
        printf("4\n");
    }
    else if(80 <= x && x <= 89){
        printf("3\n");
    }
    else if(70 <= x && x <= 79){
        printf("2\n");
    }
    else if(60 <= x && x <= 69){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

int recursive_digitSum(int x){
    if (x == 0) return 0;
    return (x % 10) + recursive_digitSum(x / 10);
}

int recursive_gdc(int x, int y){
    if(y == 0) return x;
    return recursive_gdc(y, x%y);
}

int recursive_prime(int x, int y){
    if(x == y) return 1;
    if(x % y == 0) return 0;
    return recursive_prime(x, y+1);
}

int recursive_area_cude(int x){

}

void queeeeeeeen(){
    float x1, y1, x2, y2;

    while(scanf("%f %f %f %f", &x1, &y1, &x2, &y2) != EOF)
    {
        float n = (x2-x1)/(y2-y1);
        if(x1==0 && y1==0 && x2==0 && y2==0)
        {
            break;
        }
        else if(x1==x2 && y1==y2) // same spot
        {
            printf("0\n");
        }
        else if(x1==x2 || y1==y2) // row or col
        {
            printf("1\n");
        }
        else if( n==1 || n==(-1)) // slide
        {
            printf("1\n");
        }
        else
        {
            printf("2\n"); 
        }
    }
}

int recursive_pyramid_ball(int n){
    if(n == 1){
        return 1;
    }
    else{
        return recursive_pyramid_ball(n-1) + n*n;
    }
}

void dp_pyramid_ball(){
    int dp[101];
    dp[1] = 1;

    for(int i=2; i<=100; i++){
        dp[i] = dp[i-1] + i*i;
    }

    int n;
    while(scanf("%d", &n) && n != -1){
        printf("%d\n", dp[n]);
    }
}

int recursive_line_area(int n){
    if(n == 0){
        return 1;
    }
    else{
        return recursive_line_area(n-1) + n;
    }
}

void dp_line_area(){
    int dp[101];
    dp[0] = 1;

    for(int i=1; i<=100; i++){
        dp[i] = dp[i-1] + i;
    }

    int n;
    while(scanf("%d", &n) && n != -1){
        printf("%d\n", dp[n]);
    }
}

int recursive_circle_area(int n){
    if(n == 1){
        return 2;
    }
    else{
        return recursive_circle_area(n-1) + 2*(n-1);
    }
}

void dp_circle_area(){
    int dp[101];
    dp[1] = 2;

    for(int i=2; i<=100; i++){
        dp[i] = dp[i-1] + 2*(i-1);
    }

    int n;
    while(scanf("%d", &n) && n != -1){
        printf("%d\n", dp[n]);
    }
}

void Factorization(int input, int n, int i){
  for(i= 2; i<= input; i++){
    while(input% i== 0){
      input/= i;
      n++;
    }
    if(n== 1){
      printf("%d", i);
    }
    if(n> 1){
      printf("%d^%d", i, n);
    }
    if(input!= 1){
      printf("*");
    }

    n = 0;
  }
  printf("\n");
}

void repdigit(){
    unsigned long long int n;
    while(scanf("%llu", &n) && n != -1){
        int digit[10] = {0};

        while(n > 0){
            digit[n%10]++;
            n /= 10;
        }

        for(int i=0; i<10; i++){ printf("%llu ", i); }
        printf("\n");

        for(int i=0; i<10; i++){
            printf("%d ", digit[i]);
        }
    
        printf("\n");
    }
}

void tearApart(int integer){
    int n = integer;
    for(int i= 10000; i>= 1; i/= 10){
        if(integer%i != n){
            printf("%d  ", integer/i);
            integer %= i;
        }
    }
    printf("\n");
}

void box_of_bricks(){
    int n;
    int _case = 0;
    while(scanf("%d", &n) && n != 0){
        int blocks[n];
        int sum = 0;
        int moves = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &blocks[i]);
            sum += blocks[i];
        }
        sum /= n;

        for(int i=0; i<n; i++){
            if(blocks[i] > sum){
                moves += abs(blocks[i] - sum);
            }
        }
        _case++;

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", _case, moves);
    }
}

void sales_sales(){
    int n;
    scanf("%d", &n);
    int data[100][6] = {0};
    int price[5] = {12, 16, 10, 14, 15};
    int _max = -1;
    int _index_n = 0;
    int input;

    for(int i=0; i<n; i++){
        int _sum = 0;
        for(int j=0; j<5; j++){
            scanf("%d", &input);
            data[i][j] = input*price[j];
            _sum += data[i][j];
        }
        data[i][5] = _sum;

        if(_sum > _max){
            _max = _sum;
            _index_n = i;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d: ", i+1);
        printf("%d\n", data[i][5]);
    }

    int prod;
    int prod_max = -1;
    for(int i=0; i<5; i++){
        int _sum = 0;
        for(int j=0; j<n; j++){
            _sum += data[j][i];
        }
        printf("%d ", _sum);

        if(_sum > prod_max){
            prod_max = _sum;
            prod = i;
        }
    }
    printf("\n%d\n", _index_n+1);
    printf("%c\n", 'A'+prod);
}

void temp_temp(){
    int n;
    scanf("%d", &n);

    float tempt[10][5]; // n4->avg
    float day[4] = {0};
    int max_day;
    int max_time;
    int maxtd_temp = -1;
    int min_time;
    int mintd_temp = 400;

    for(int i=0; i<n; i++){
        double _sum = 0;
        for(int j=0; j<4; j++){
            scanf("%f", &tempt[i][j]);
            _sum += tempt[i][j];
            day[j] += tempt[i][j];
            if(tempt[i][j] > maxtd_temp){
                maxtd_temp = tempt[i][j];
                max_day = i;
                max_time = j;
            }
        }
        tempt[i][4] = _sum/4;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            printf("%.1lf ", tempt[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<4; i++){
        printf("%.1f ", day[i]/n);
        if(day[i]/n < mintd_temp){
            mintd_temp = day[i]/n;
            min_time = i;
        }
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("%.1f ", tempt[i][4]);
    }
    printf("\n");
    
    printf("%d %d\n", max_day+1, max_time+1);
    printf("%d\n", min_time+1);

}

void rec_bstr(char *str){
    if(*str == '\0'){
        printf("\n");
        return;
    }
    rec_bstr(str+1);
    printf("%c", *str);
}

void easy_bstr(char str[], int i){
    if(str[i] == '\0'){
        return;
    }
    easy_bstr(str, i+1);
    printf("%c", str[i]);
}

void dec_to_bin(int n){
    if(n == 0){
        return;
    }
    dec_to_bin(n/2);
    printf("%d", n%2);
}

void bin_to_dec(int n){
    int sum = 0;
    int i = 0;
    while(n > 0){
        sum += n%10 * pow(2, i);
        n /= 10;
        i++;
    }
    printf("%d", sum);
}

void union_of_set(){
    int n = 20;
    int index = 0;
    int input;
    int bool_set[100] = {0};
    int ans[20];

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        if(bool_set[input] == 0){
            bool_set[input] = 1;
            ans[index] = input;
            index++;
        }
    }

    for(int i=0; i<index; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void even_or_odd(){
    int n;
    int sum = 0;
    while(scanf("%d", &n) && n != -1){
        if(n%2 == 0) sum++;
    }

    printf("%d\n", sum);
}

void sales_commissions(){
    int ans[9] = {0};
    double gross;

    while(scanf("%lf", &gross)){
        if(gross == -1) break;

        double commission = 200 + (gross *0.09);

        if(200 <= commission && commission <= 299){
            ans[0]++;
        }
        else if(300 <= commission && commission <= 399){
            ans[1]++;
        }
        else if(400 < commission && commission <= 499){
            ans[2]++;
        }
        else if(500 < commission && commission <= 599){
            ans[3]++;
        }
        else if(600 < commission && commission <= 699){
            ans[4]++;
        }
        else if(700 < commission && commission <= 799){
            ans[5]++;
        }
        else if(800 < commission && commission <= 899){
            ans[6]++;
        }
        else if(900 < commission && commission <= 999){
            ans[7]++;
        }
        else {
            ans[8]++;
        }
    }

    for(int i=0; i<9; i++){
        printf("%d\n", ans[i]);
    }
}

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i]; 
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void count_factor(){
    int n;
    while(scanf("%d", &n) && n != 0){
        int _n = n;
        int cout = 0;
        int a = 2;
        while(n > 1){
            if(n%a == 0){
                cout++;
                while(n%a == 0){
                    n /= a;
                }
            }
            a++;
        }

        printf("%d : %d\n", _n, cout);
    }
}

int testPalindrome(char str[], int s, int e){
    if(!isalpha(str[s])) return testPalindrome(str, s+1, e);
    if(!isalpha(str[e])) return testPalindrome(str, s, e-1);
    
    if(s == e){
        return 1;
    }

    if(str[s] != str[e]){
        return 0;
    }
    
    if (s < e + 1){
        return testPalindrome(str, s+1, e-1);
    }

    return 1;
}

void array_flip(){
    int r, c;

    while(scanf("%d %d", &r, &c) && r != 0 && c != 0){
        int arr[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        for(int i=0; i<c; i++){
            for(int j=0; j<r; j++){
                printf("%d ", arr[j][i]);
            }
            printf("\n");
        }
    }
}

void lcs(){
    char a[256];
    char b[256];
    
}

void binary_search_recursive(int arr[], int n, int key){
    if(n == 0){
        return;
    }

    if(arr[n/2] == key){
        printf("%d\n", n/2);
        return;
    }
    else if(arr[n/2] > key){
        binary_search_recursive(arr, n/2, key);
    }
    else{
        binary_search_recursive(arr, n/2+n%2, key);
    }
}

void change(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void square_compare(int *a, int *b){
    if(*a > *b){
        *a = *a * *a;
        *b = *b * 2;
    }
    else if(*a < *b){
        *a = *a * 2;
        *b = *b * *b;
    }
}

void tototLower(char *a){
    *a = tolower(*a);
}

void append_string(char (*buf)[100], char (*ans)[100], char (*input)[100], int index){
    strncpy(*buf, *ans, index);
    strcat(*buf, *input);
    strcat(*buf, *ans+index);

    strcpy(*ans, *buf);
}

void remove_string(char (*buf)[100], char (*ans)[100], int index){
    strncpy(*buf, *ans, index);
    strcpy(*ans, *buf);
}

void find_position_string(char (*ans)[100], char (*input)[100]){
    char *p = strstr(*ans, *input);
    printf("index:%d\n", p-*ans);
}

void print_string(const char *a){
    while(*a != '\0'){
        printf("%c", *a);
        a++;
    }
    printf("\n");
}

void super_string(){
    int n;
    int index;
    char ans[100] = "";
    
    char input[100];
    while(scanf("%d", &n)){
        if(n == -1) break;

        char buf[100] = "";
        if(n == 1){
            scanf("%d", &index);
            getchar();
            scanf("%[^\n]", input);

            // strncpy(buf, ans, index);
            // strcat(buf, input);
            // strcat(buf, ans+index);

            // strcpy(ans, buf);   
            append_string(buf, ans, input, index);
        }
        else if(n == 2){
            scanf("%d", &index);
            getchar();
            // strncpy(buf, ans, index);
            // strcpy(ans, buf);
            remove_string(buf, ans, index);
        }
        else if(n == 3){
            getchar();
            scanf("%[^\n]", input);
            // char *p = strstr(ans, input);
            // printf("index:%d\n", p-ans);
            find_position_string(ans, input);
        }
        else if(n == 4){
            // printf("%s\n", ans);
            print_string(ans);
        }
    }
}

void ptr_memset(){
    int **arr;
    int rr = 8;
    int cc = 50;

    arr = (int**)malloc(sizeof(int*)*rr);
    for(int i=0; i<rr; i++){
        arr[i] = (int*)malloc(sizeof(int)*cc);
        memset(arr[i], 0, sizeof(*arr));
    }

    //print array
    for(int i=0; i<rr; i++){
        for(int j=0; j<cc; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    return;
}

void recrec_str(char *c){
    if(*c == '\0'){
        return;
    }
    recrec_str(c+1);
    printf("%c", *c);
}

void sum_avg_pointer(int *arr){
    double _sum = 0;
    for(int i=0; i<20; i++){
        _sum += arr[i];
    }
    printf("%d %.1lf\n", (int)_sum, _sum/20);
}

void array_sum_avg_ptr(){
    const int num[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    sum_avg_pointer(num);
}

int ptrptr_sum_array_sum(int * const ptr, int num){
    int _sum = 0;
    for(int i=0; i<num; i++){
        _sum += ptr[i];
    }
    return _sum;
}

void diagonal_array_sum(int *arr){
    int r = 3;
    int c = 3;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i == j){
                arr[i*c+j] += 2;
            }
        }
    }
    // print array
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%-3d", arr[i*c+j]);
        }
        printf("\n");
    }
}

void diagonal_array(){
    int arr[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    diagonal_array_sum(arr);
}

void ptr_array_sum_1228(){
    int data[100];
    int index = 0;
    int input;

    while(scanf("%d", &input)){
        if(input == -9999){
            break;
        }
        data[index] = input;
        index++;
    }

    printf("%d\n", ptrptr_sum_array_sum(data, index));
}

void politic_statistics(){
    char* topics[5] = { "police", "weather", "global", "social", "media"};
    int n;
    int responses[5][11];
    int input;
    memset(responses, 0, sizeof(responses[0][0]) * 11 * 5);

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &input);
            responses[j][input-1]++;
            responses[j][10] += input;
        }
    }

    int max_index = 0;
    int max_value = -9999999;
    int min_index = 0;
    int min_value = 9999999;
    for(int i=0; i<5; i++){
        if(responses[i][10] >= max_value){
            max_value = responses[i][10];
            max_index = i;
        }
        if(responses[i][10] <= min_value){
            min_value = responses[i][10];
            min_index = i;
        }
        responses[i][10] /= n;
    }

    printf("%10s ", " ");
    for(int i=0; i<10; i++){
        printf("%3d", i+1);
    }
    printf("\n");

    for(int i=0; i<5; i++){
        printf("%10s ", topics[i]);
        for(int j=0; j<11; j++){
            printf("%3d", responses[i][j]);
        }
        printf("\n");
    }

    printf("%s %d\n", topics[max_index], max_value);
    printf("%s %d\n", topics[min_index], min_value);
}

void circle_perimeter(int n){
    printf("%d\n", (int)(2*3.14*n));
}

void circle_area(int n){
    printf("%d\n", (int)(3.14*n*n));
}

void circle_volume(int n){
    printf("%d\n", (int)(4/3.0*3.14*n*n*n));
}

void ptrfunc_circle(){
    void (*circle[4])(int) = {circle_perimeter, circle_area, circle_volume};
    int n;
    int action;
    int p = 0;

    while(scanf("%d", &n)){
        while(scanf("%d", &action)){
            if(action == 3){
                puts("Program execution completed.");
                p = 1;
                break;
            }
            else{
                circle[action](n);
            }
        }
        if(p == 1){
            break;
        }
    }
}

void op_add(double x, double y){
    printf("%.1lf\n", x+y);
}

void op_sub(double x, double y){
    printf("%.1lf\n", x-y);
}

void op_mul(double x, double y){
    printf("%.1lf\n", x*y);
}

void op_div(double x, double y){
    printf("%.1lf\n", x/y);
}

void ptrfunc_two_number(){
    void (*calculate[4])(double, double) = {op_add, op_sub, op_mul, op_div};
    double a, b;
    int action;
    int p = 0;

    while(scanf("%lf %lf", &a, &b)){
        while(scanf("%d", &action)){
            if(action == 4){
                puts("Program execution completed.");
                p = 1;
                break;
            }
            else{
                calculate[action](a, b);
            }
        }
        if(p == 1){
            break;
        }
    }
}

void final_arr(){
    int nunms[10][10];
    int n;

    while(scanf("%d", &n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &nunms[i][j]);
                
                if(i == j){
                    nunms[i][j] += 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ", nunms[i][j]);
            }
            printf("\n");
        }
    }
}

void final_keyborad_decode(){
    char data[4][13] = {{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='}, // 13
                        {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\'}, // 13
                        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\''}, // 11
                        {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'}}; // 10

    int n;
    char str[1000];
    while(scanf("%d", &n)){
        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int i=0; i<strlen(str); i++){
                if(str[i] == ' '){
                    printf("%c", str[i]);
                }
                else{
                    for(int j=0; j<4; j++){
                        for(int k=0; k<13; k++){
                            if(tolower(str[i]) == data[j][k]){
                                if(j == 2){
                                    printf("%c", data[j][(k+11-2)%11]);
                                }
                                else if(j == 3){
                                    printf("%c", data[j][(k+10-2)%10]);
                                }
                                else{
                                    printf("%c", data[j][(k+13-2)%13]);
                                }
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
    }

    /*
        Input:               Output:
            2
            k[r dyt I[o          how are you
            j[[g .[y,p,j         good morning
    */

}

void primeNumber(){
    int n;

    while(scanf("%d", &n)){
        if(n == -1) break;

        if(n == 2 || n == 3){
            printf("True\n");
        }
        else if(n > 4){
            int m = n % 6;

            if(m!=1 && m!=5){
                printf("False\n");
                continue;
            }

            int s = (int)sqrt(n);
            for(int i=5; i<=s; s+=6){
                if(n%i==0 || n%(i+2)==0){
                    printf("False\n");
                }
            }

            printf("True\n");
        }
        else{
            printf("False\n");
        }
    }
}

void oddsum(){
    int n;

    while(scanf("%d", &n)){
        for(int cc=0; cc<n; cc++){
            int a, b;
            int ssum = 0;

            scanf("%d %d", &a, &b);
            for(int i=a; i<b+1; i++){
                if(i%2) ssum += i;
            }

            printf("Case %d: %d\n", cc+1, ssum);
        }
    }
}

void fn(){
    int n;

    while(scanf("%d", &n)){
        if(n == 0) break;

        while(n > 10){
            int sum = 0;
            
            while(n > 0){
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }

        printf("%d\n", n);
    }
}

int compNum(ANS *a, ANS*b){
    
    if(a->cnt == b->cnt){
        return a->ascii - b->ascii;
    }
    else{
        return b->cnt - a->cnt;
    }
}

void numberSeq(){ //  68.000000  ms 0.000068  sec
    int n=1;
    char str[1000];

    while(scanf("%d", &n)){
        int data[26] = {0};
        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int i=0; i<strlen(str); i++){
                if('a' <= tolower(str[i]) && tolower(str[i]) <= 'z'){
                    data[tolower(str[i])-97]++;
                }
            }
        }

        // for(int i=0; i<26; i++){
        //     printf("%d ", data[i]);
        // }
        // printf("\n");

        ANS asciiData[26];
        int buffer = 0;
        for(int i = 0; i < 26; i++){
            if(data[i] > 0){
                asciiData[buffer].ascii = i;
                asciiData[buffer].cnt = data[i];
                buffer++;
            }
        }
        qsort(asciiData, buffer, sizeof(ANS), compNum);

        for(int i=0; i<buffer; i++){
            printf("%c %d\n", asciiData[i].ascii+65, asciiData[i].cnt);
        }
    }
}

void numberSeq2(){ //  63.000000  ms 0.000063  sec
    int n;

    while(scanf("%d", &n)){
        if(n == -1) break;
        
        char ch;
        char str[1000];
        int data[26] = {0};
        int max = -1;
        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int idx=0; idx<strlen(str); idx++){
                ch = str[idx];

                if('a' <= tolower(ch) && tolower(ch) <= 'z'){
                    data[tolower(ch) - 'a']++;
                    
                    if(max < data[tolower(ch) - 'a']) max = data[tolower(ch) - 'a'];
                }
            }
        }

        for(int cnt = max; cnt > 0; cnt--){
            for(int i=0; i<26; i++){
                if(cnt == data[i]){
                    printf("%c %d\n", 'A'+i, data[i]);
                }
            }
        }
    }
}

void execution_time(){
    clock_t start, end;
   
    // Start Record the time
    start = clock();
   
    // Your program....
    numberSeq2();

    // Record the end time
    end = clock();

    double diff = end - start; // ms
    printf(" %f  ms" , diff);
    printf(" %f  sec\n", diff / CLOCKS_PER_SEC );
}

void score_guest(){
    int n, x, y;

    while(scanf("%d", &n)){
        for(int cc=0; cc<n; cc++){
            int isFind = 0;
            int i;

            scanf("%d %d", &x, &y);
            for(i=x; i>=0; i--){
                if(i-(x-i) == y){
                    isFind = 1;
                    break;
                }
            }

            if(isFind){
                printf("%d %d\n", i, x-i);
            }
            else{
                printf("Impossible\n");
            }
        }
    }
}

void cycle3n1(){
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

void square_find(){
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

void multSet(){
    int a_bool[10] = {0};
    int b_bool[10] = {0};
    int index = 0, ans[10];

    printf("Array A: ");
    for(int i=0; i<10; i++){
        int x = rand() % 10;

        a_bool[x] = 1;
        printf("%d ", x);
    }

    printf("\nArray B: ");
    for(int i=0; i<10; i++){
        int y = rand() % 10;

        b_bool[y] = 1;
        printf("%d ", y);

        if(a_bool[y] && b_bool[y]){
            ans[index] = y;
            index++;
            a_bool[y] = 0;
        }
    }
    printf("\n");

    for(int i=0; i<index; i++) printf("%d ", ans[i]);
    printf("\n");
}

void do_while_sumdigit(){
    int n;

    while(scanf("%d", &n) != EOF){
        if(n == -1) break;

        int _sum = 0;
        do{
            _sum += n%10;
            n /= 10;
        }while(n > 0);

        printf("%d\n", _sum);
    }
}

void comprsStr(){
    int n;
    int cc;
    char str[1000];

    // scanf("%d", &cc);
    // for(int cc=0; cc<n; cc++){
        scanf("%s", str);

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
    // }
}

void countingWords(){
    char str[200];

    while(scanf("%[^\n]s", str) != EOF){
        int cnt = 0;

        for(int i=0; i<strlen(str); i++){
            if(str[i]==' ' && str[i+1]!=' '){
                cnt++;
            }
        }

        printf("Number of words in given string: %d\n", cnt+1);
        getchar();
    }
}

// C Solution
void country(){
    int n;
    int i, j;
    int cnt, flag;
    char country[2001][76] = {0};
    char name[76] = {0};
    char temp[76] = {0};

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%s", country[i]);
        gets(name);

        if(strlen(name) > 75) i--;
    }

    // sort country
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(strcmp(country[j], country[j+1]) > 0){
                strcpy(temp, country[j]);
                strcpy(country[j], country[j+1]);
                strcpy(country[j+1], temp);
            }
        }
    }

    flag = false;
    cnt = 0;
    i = 0;

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

void hotel(){
    int s, end;

    while(scanf("%d %d", &s, &end)){
        if(s==0 && end==0) break;

        int count = 0;
        int i = s;
        while(1){
            count += i;
            if(count >= end){
                printf("%d\n", i);
                break;
            }
            i++;
        }
    }
}

void velocity(){
    int v, t;

    while(scanf("%d %d", &v, &t)){
        if(v == -1 && t == -1) break;

        printf("%d\n", v*t*2);
    }
}

void SumofArray(int arr[][100], int length, int *_sum){
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            *_sum += arr[i][j];
        }
    }
}

void aarraysum(){
    int n;
    int arr[100][100];

    while(scanf("%d", &n) != EOF){
        int _sum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        SumofArray(arr, n, &_sum);

        printf("Sum of Array is: %d\n", _sum);
    }
}

int productArray(const int *a, const int *b, int n){
    int _sum = 0;

    for(int i=0; i<n; i++){
        _sum += a[i] * b[i];
    }

    return _sum;
}

void prodarray(){
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;

    printf("%d\n", productArray(a, b, n));
}

void powdigit(){
    int n;

    while(scanf("%d", &n)){
        if(n == 0) break;

        long long int _sum = 0;
        for(int i=1; i<=n; i++){
            _sum += pow(i, i);
        }

        printf("%lld\n", _sum%10);
    }
}

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

void tr1(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j<=n; j++){
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");
}

void tr2(int n){
    for(int i=1; i<=n; i++){
        for(int j=n-i; j>0; j--){
            printf(" ");
        }
        for(int j=0; j<i; j++){
            printf("%d", i);
        }
        printf("\n");
    }
    printf("\n");
}

void tr3(int n){
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            printf("%d", i);
        }
        printf("\n");
    }
    printf("\n");
}

void parall(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j<n; j++){
            printf(" ");
        }
        for(int j=i; j>0; j--){
            printf("%d", j);
        }
        for(int j=i, k=2; j<n; j++, k++){
            printf("%d", k);
        }
        printf("\n");
    }
    printf("\n");
}

void invtTri(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int j=1; j<=n-i; j++){
            printf("%d", j);
        }
        for(int j=n-1-i; j>0; j--){
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");
}

void number_triangle(){
    int n;

    while(scanf("%d", &n) != EOF){
        tr1(n);
        tr2(n);
        tr3(n);
        parall(n);
        invtTri(n);
    }
}

void cntwords(){
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

void _lps(char str[], int n){
    int lps[256] = {0};
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while(i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    if(len > 0 && n%(n-len) == 0){ 
        printf("%d %d\n\n", len, n-len);
    }
    else{
        printf("%d %d\n\n", len, n);
    }
}

void find_smallest_period(){
    int n;
    char str[256];
    char c;
    
    while(scanf("%d", &n) != EOF){
        

        for(int ss = 0; ss < n; ss++){
            scanf("%c", &c);
            scanf("%s", str);

            _lps(str, strlen(str));
        }
    }
}

void compare_student(student *st, int index){
    for(int i=0; i<index; i++){
        
        for(int j=i+1; j<index; j++){
            if(st[i].score > st[j].score){
                student temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}

void strct_name_scr(){
    int index = 0;
    student st[100];
    while(scanf("%s %d", st[index].name, &st[index].score) != EOF){
        index++;
    }

    compare_student(st, index);

    for(int i=0; i<index; i++){
        printf("%s: %d\n", st[i].name, st[i].score);
    }
}

void str_decode(){
    int n;

    while(scanf("%d", &n)){
        char str[256];

        for(int ss=0; ss<n; ss++){
            scanf("%s", str);
            
            char c;
            int cnt = 0;
            for(int i=0; i<strlen(str); i++){
                if(isalpha(str[i])){
                    c = str[i];
                }
                else{
                    cnt *= 10;
                    cnt += str[i] - '0';

                    if(isalpha(str[i+1]) || i+1 == strlen(str)){
                        for(int j=0; j<cnt; j++){
                            printf("%c", c);
                        }
                        cnt = 0;
                    }
                }
            }

            printf("\n");
        }
    }
}

void nurse_time(){
    int h, m;
    int hh, mm;

    while(scanf("%d %d %d %d", &h, &m, &hh, &mm) != EOF){
        if(h == 0 && m == 0 && hh == 0 && mm == 0) break;

        m = h*60 + m;
        mm = hh*60 +mm;

        if(m > mm){
            m -= mm;
            m = DAY - m;
        }
        else{
            mm -= m;
            m = mm;
        }

        printf("%d\n", m);
    }
}

int check(int arr[], int i, int sum, int *N, int *K){
    if(i == *N) return abs(sum) % (*K);

    if(check(arr, i+1, sum+arr[i], N, K) == 0) return 0;
    if(check(arr, i+1, sum-arr[i], N, K) == 0) return 0;

    return 1;        
}

void dp_sequ_division(){
    int nn;
    int n, k;
    int num[100];
    int dp[1000][1000];

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

void sequ_division(){
    int nn;
    int n, k;
    int arr[10000];

    while(scanf("%d", &nn)){
        for(int ii=0; ii<nn; ii++){
            scanf("%d %d", &n, &k);
            
            for(int i=0; i<n; i++) scanf("%d", &arr[i]);

            if(check(arr, 0, 0, &n, &k) == 0) printf("Divisible\n");
            else printf("Not divisible\n");
        }
    }
}

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
        printf(" %d %d\n", alpha, hyphen);
    }
}

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



void fib_str_bfs(){
    long long f[48];
    // f[46] > 2^31 - 1
    
    f[0] = f[1] = 1;
    
    for(int i = 2;i <= 47;++i)
        f[i] = f[i - 1] + f[i - 2];
    
    int T;
    long long N,l,r;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld %lld",&N,&l,&r);
        if(N > 46) N -= (N - 46) / 2 * 2;
        
        for(long long i = l;i <= r;++i){
            long long pos = i;
            int n = N;
            
            while(n >= 2){
                if(pos >= f[n - 2]){
                    pos -= f[n - 2];
                    --n;
                }else n -= 2;
            }
            
            putchar('0' + n);
        }
        
        putchar('\n');
    }
}

void student_highest_score_sex(){
    sstudent st[4];
    int m_max;
    int m_max_val = -1;
    int f_max;
    int f_max_val = -1;
    int i = 0;

    while(scanf("%[^\t]", st[i].name) != EOF){
        scanf("%d %s\n", &st[i].score, st[i].sex);

        if(st[i].score > m_max_val && st[i].sex[0] == 'M'){
            if(st[i].score > m_max_val && st[i].sex[0] == 'M'){
                m_max = i;
                m_max_val = st[i].score;
            }  
        }
        if(st[i].score > f_max_val && st[i].sex[0] == 'F'){
            f_max = i;
            f_max_val = st[i].score;
        }
        i++;
        // getchar();
    }

    printf("%s %d %s\n", st[f_max].name, st[f_max].score, st[f_max].sex);
    printf("%s %d %s\n", st[m_max].name, st[m_max].score, st[m_max].sex);

    // scanf("%[^\t] %d %d", str , &a);
}

void oj_fcu(){
    // oddsum();
    // fn();
    
    // numberSeq();
    // score_guest();
    // cycle3n1();
    // square_find();
    // multSet();
    // do_while_sumdigit();
    // comprsStr();
    // countingWords();
    // velocity();
    // hotel();
    // country();
    // aarraysum();
    // prodarray();
    // powdigit();
    // abstractNames();
    // integerPalindrome();
    // number_triangle();
    // find_smallest_period();
    // brute_force_find_smallest_period();

    // strct_name_scr();
    // nurse_time();
    // str_decode();

    // sequ_division();
    // dp_sequ_division();

    // phone_number();
    // fib_str();
    // student_highest_score_sex();
    // judge();

    // cntwords();
    // student_score();
    // char str[50];
    // strcpy(str, "jill");
    // printf("%d\n", strlen(str));
}

// scanf("%d", &index);
// getchar();
// scanf("%[^\n]",ans);
// printf("%d\n", index);
// printf("%s\n", ans);

int main(){
    // diediedeanita();

    oj_fcu();
    // execution_time();
    // isPrime();

    // carry();
    // eric();

    // print_diamond(5);

    // cnt();

    // int value = 5;

    // switch(value){
    //     value %= 2;
    //     case 0:
    //         printf("Even\n");
    //         break;
    //     case 1:
    //         printf("Odd\n");
    //         break;
    // }

    
    // char c = '0';
    // printf("%c\n", c+1);

    // int x;
    // int *z;

    // z = &x;

    // scanf("%d", &x);

    // printf("%d\n", *z);

    // printf("--------------\n");
    // print_diamond(5);

    // int n;

    // while(scanf("%d", &n)){
    //     if(n == -1) break;

    //     int a, b, c, d;

    //     int nn = 626 / n % b;

    //     a = n / 1000 + 7;
    //     b = (n % 1000) / 100 + 7;
    //     c = (n % 100) / 10 + 7;
    //     d = n % 10 + 7;

    //     a %= 10;
    //     b %= 10;
    //     c %= 10;
    //     d %= 10;

    //     printf("%d%d%d%d\n", c, d, a, b);
    // }

    // int hour;
    // float salary;

    // while(scanf("%d", &hour) != EOF) {
    //     if (hour == -1) break;
    //     scanf("%f", &salary);

    //     if (hour <= 40){
    //         printf("Salary is $%.2f\n", salary * hour);
    //     }
    //     else{
    //         printf("Salary is $%.2f\n", salary * 40 + (hour - 40) * 1.5 * salary);
    //     }
    // }

    // int n;
    // int maxNum = -1;

    // for(int i=0; i<10; i++){ 
    //     scanf("%d", &n);
    //     if (n > maxNum) maxNum = n;
    // }

    // printf("Max: %d\n", maxNum);

    // int n;
    // while(scanf("%d", &n)){
    //     int isPrime = 1;
    //     for(int i=2; i<=sqrt(n); i++){
    //         if (! (n%i)){
    //             isPrime = 0;
    //             break;
    //         }
    //     }

    //     if (!isPrime || n == 1) 
    //         printf("False\n");
    //     else 
    //         printf("True\n");
    // }

    // cs1();
    // cs2();

    // int n;
    // scanf("%d", &n);

    // printf("%d", n);
    // dp_fib();
    // pos eva;
    // pos ch;

    // if(eva == ch){
    //     printf("eva == ch\n");
    // }

    // eva.x = 12;
    // eva.y = 20;

    // printf("eva.x: %d\n", eva.x);

    // strings();
    // advance_strings();

    // qsort_using();
    
    // functionPointers();

    // BinarySearch();

    // array5();
    // array6();
    // PtrNArr();

    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int ans;

    // // ans = sum(a, 10);
    // ans = adv_sum(a, a+10);

    // printf("%d\n", ans);

    // int a[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    // int target;
    // int ans;

    // scanf("%d", &target);

    // ans = _bsearch(a, 0, sizeof(a)/sizeof(int)-1, target);

    // if (ans < 0){
    //     printf("%d is not found. QQ\n", target);
    // }
    // else{
    //     printf("%d is found at a[%d]\n", a[ans], ans);
    // }

    // char a[] = "abcd"; // a[] = {'a', 'b', 'c', 'd', '\0'};
    // permute(a, 4);
    // printf("%d \n", permute_cnt);
    
    // int z[4][2] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };
    
    // for(int j = 0; j < 4; j++){
    //     show_int_array(z[j], 2);
    // }

    // show_int_2d_array(z, 4);

    // ptr_arr();

    // basic_malloc();
    // malloc_two_star();

    // struct_avia();
    // struct_rect();

    // linkedlist();
    // stack();
    // queue();

    // char s = 's'; // s -> 115
    // char o = 'o'; // o -> 111
    // char r = 'r'; // r -> 114
    // char y = 'y'; // y -> 121

    // printf("%d ", (int)s);
    // printf("%d ", (int)o);
    // printf("%d ", (int)r);
    // printf("%d \n", (int)y);

    // bitBasic();
    // demo_bit_func();

    // anita();

    // char str[100];
	// while(gets(str) && str != EOF){
	// 	rec_bstr(str);
	// 	printf("\n");
	// }

    // char str[100];
    // while(gets(str)){
    //   	if(str == EOF) break;
    //     int len = strlen(str);
    //     if(len == 0){
    //         printf("True\n");
    //     }
    //     else{
    //         if(testPalindrome(str, 0, len-1) == 1){
    //             printf("True\n");
    //         }
    //         else{
    //             printf("False\n");
    //         }
    //     }
    // }

    // easy_bstr("abcdefg", 0);
    // printf("\n");

    return 0;
}

// void _qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
