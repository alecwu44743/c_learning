#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



void create_map(int *row, int *col){ // pass
  printf("Input the number of row and column for the map:\n");
  scanf("%d %d", row, col);
}


int check_boundary(int row, int col, int a, int b){ // pass
  if(a>=row || b>=col || a<0 || b<0){
    printf("the location is outside the map\n");
    return 1;
  }
  else 
    return 0;
}

int check_availability(char* arr, int row, int col, int a, int b){  // pass
  if (*((arr+col*a)+b)!='.'){
    printf("the location is occupied\n");
    return 1;
  }
  else 
    return 0;
}

void setup_village(char* arr, int row, int col,int a, int b){ // pass
  do {printf("Input the row and column for the village location:\n");
  scanf("%d %d", &a, &b);    
  }while(check_boundary(row, col,a,b));
  *((arr+col*a)+b)='v';
}

void setup_monster(int amo_mons, char* arr, int row, int col, int a, int b){ // pass
  for(int i=0; i<amo_mons; i++){
    do {
      printf("Input the row and column for monster %d:\n", i);
      scanf("%d %d", &a, &b);
    }while(check_boundary(row, col, a, b)||check_availability(arr, row, col, a, b));
    *((arr+col*a)+ b)='m';
  }
}

void setup_trap(int amo_trap, char* arr, int row, int col, int a, int b){ // pass
  for(int i=0; i<amo_trap; i++){
    do {
      printf("Input the row and column for trap %d:\n", i);
      scanf("%d %d", &a, &b);
    }while(check_boundary(row, col, a, b)||check_availability(arr, row, col,a,b));
    *((arr+col*a)+b)='t';
  }
}


int check_pvmtg(int a, int b, char* arr, int row, int col){ // pass
  int _check = *((arr+col*a)+b);
  if (_check=='p'|| _check=='v'|| _check=='m'|| _check=='t' || _check=='G') return 1;
  else return 0;
}


void print_map(char **arr, int row, int col){ // pass
  printf("=== MAP === \n");
  for ( int row_f = 0; row_f < row; row_f++){
    for ( int col_f = 0; col_f <col; col_f++){
      printf("%c ", arr[row_f][col_f]);
    }
    printf("\n");
  }
  printf("=== MAP ===\n");
}

void setup_player(char* arr, int row, int col, int a, int b){ // pass
 do{
    printf("Input the row and column for player:\n");
    scanf("%d %d", &a, &b);
  } while(check_availability(arr, row, col, a, b)||check_boundary(row, col, a, b));
  *((arr+col*a)+b)='p';
}

void met_mons(char* arr, int a, int b, int* blood, int* strength, int MonsterNumber,int will_p, int win){ // pass

  printf("You are fighting Monster %d!\n", MonsterNumber);
  if(*strength-MonsterNumber>0){//血量設定
      *blood = *blood;
      *strength += 1;
      printf("You Win!\nDo you want to go on your adventure (1:Yes; 0: No)?: ");
      scanf("%d", &will_p);
      if(will_p==0){
        printf("We will miss you. Bye!");
        exit (0);
      }
      else win =1;
  }
  else{//血量設定
      *blood-=MonsterNumber;
      if (*blood>0){//輸了但還有血
        printf("You Lose!\nDo you want to go on your adventure (1:Yes; 0: No)?: ");
        scanf("%d", &will_p);

        if(will_p==0){
          printf("We will miss you. Bye!");
          exit(0);
        }

        else win = 1;
      }

      else{
        printf("You Lose!\nDo you want to go on your adventure (1:Yes; 0: No)?: ");
        scanf("%d", &will_p);
        printf("You Dead. Bye!");
        exit(0);
      }
    }
}

void met_vil(char* arr, int a, int b, int* strength, int* blood, int village, int Q_v){//村莊設定 pass
  if(village==1){
    if(Q_v==0){
      *strength+=1;
      printf("Nice sword! Now you have %d strength!\n", *strength);
      Q_v=1; 
    }
    else{
      printf("You already brought a sword.\n");
    }
  }
  else if(village==2){
    if(*blood<10){
      *blood+=1;
      printf("Nice beer! Now you have %d blood!\n", *blood);
    }
    else{
      printf("Your blood is full. You don't need a beer.\n");
    }
  }      
  else if(village==3){
    printf("You are welcome to come back anytime\n");
  } 
}


int check_move(char* arr, int a, int b, int row, int col){ // pass
  if(a>row-1||b>col-1||a<0||b<0){
    printf("you can't go there\n");
    return 1;
  }
  else return 0;
}



void go_up(char* arr, int* strength, int* blood, int win, int will_p, int row, int col, int a, int b){ // pass
  if (*((arr+col*(a-1))+b)=='m'){
    int MonsterNumber=0;
    int willingness = 1;
    printf("You have %d blood and %d strength.\n", *blood, *strength);
    do {
      printf("Please choose which monster (1 to 4) you want to fight: ");
      scanf("%d", &MonsterNumber);
      if (MonsterNumber>4||MonsterNumber<1){
        printf("No such monster, please enter 1 to 4 to choose the monster.\nDo you want to go on your adventure (1: Yes; 0: No) ?:");
        scanf("%d", &willingness);
        if (willingness==1) continue;
        else if (willingness==0) {
          printf("We will miss you. Bye!\n");
          exit(0); 
        }
      }
      else break;
    } while(willingness==1);
    met_mons(arr, a, b, blood, strength, MonsterNumber, will_p, win);
  }
  
  if (*((arr+col*(a-1))+b)=='v'){
    int village =0;
    int Q_v=0;
    do{
      printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)?");
      scanf("%d", &village);
      while(village!=1 && village!=2 && village!=3){
        printf("Invalid action!\n1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
        break;
      }
      met_vil(arr, a, b, strength, blood, village, Q_v);
    }while (village != 3);
  }
  if (*((arr+col*(a-1))+b)=='G'){
    *strength+=1;
    printf("You got a gun! Now you have %d strength!\n", *strength);
  }

  if (*((arr+col*(a-1))+b)=='t'){
    *blood-=1;
    printf("You fall into trap... Now you have %d health\n", *blood);
  }

  if (*((arr+col*(a-1))+b)=='X'){
    int k;
    srand(time(NULL));
    k = rand()%3;
    if(k==0){
      if (*blood<10){
        *blood+=1;
        printf("You find a beer! Now you have %d health\n", *blood);
      }
      else printf("You find a beer! However your blood is full");
    }
    else if(k==1){
      *strength+=1;
      printf("You find a sword! Now you have %d strength\n", *strength);
    }
    else {
      if (*blood<10){
        *blood+=1;
      }
      *strength+=1;
      printf("You are so lucky! You find the best treature! Now you have %d health and %d strength\n", *blood, *strength);
    }
  }
  if (win == 1){
    *((arr+col*a)+b)='.';
    *((arr+col*(a-1))+b)='p';
    a--;
  }
}

void go_down(char* arr, int* strength, int* blood, int win, int will_p, int row, int col, int a, int b){ // pass
  if (*((arr+col*(a+1))+b)=='m'){
    int MonsterNumber=0;
    int willingness = 1;
    printf("You have %d blood and %d strength.\n", *blood, *strength);
    do {
      printf("Please choose which monster (1 to 4) you want to fight: ");
      scanf("%d", &MonsterNumber);
      if (MonsterNumber>4||MonsterNumber<1){
        printf("No such monster, please enter 1 to 4 to choose the monster.\nDo you want to go on your adventure (1: Yes; 0: No) ?:");
        scanf("%d", &willingness);
        if (willingness==1) continue;
        else if (willingness==0) {
          printf("We will miss you. Bye!\n");
          exit(0); 
        }
      }
      else break;
    } while(willingness==1);
    met_mons(arr, a, b, blood, strength, MonsterNumber, will_p, win);
  }

  if (*((arr+col*(a+1))+b)=='v'){
    int village =0;
    int Q_v=0;
    do{
      printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)?");
      scanf("%d", &village);
      while(village!=1 && village!=2 && village!=3){
        printf("Invalid action!\n1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
        break;
      }
      met_vil(arr, a, b, strength, blood, village, Q_v);
    }while (village != 3);
  }
  if (*((arr+col*(a+1))+b)=='G'){
    *strength+=1;
    printf("You got a gun! Now you have %d strength!\n", *strength);
  }

  if (*((arr+col*(a+1))+b)=='t'){
    *blood-=1;
    printf("You fall into trap... Now you have %d health\n", *blood);
  }

  if (*((arr+col*(a+1))+b)=='X'){
    int k;
    srand(time(NULL));
    k = rand()%3;
    if(k==0){
      if (*blood<10){
        *blood+=1;
        printf("You find a beer! Now you have %d health\n", *blood);
      }
      else printf("You find a beer! However your blood is full");
    }
    else if(k==1){
      *strength+=1;
      printf("You find a sword! Now you have %d strength\n", *strength);
    }
    else {
      if (*blood<10){
        *blood+=1;
      }
      *strength+=1;
      printf("You are so lucky! You find the best treature! Now you have %d health and %d strength\n", *blood, *strength);
    }
  }
  if (win == 1){
    *((arr+col*a)+b)='.';
    *((arr+col*(a+1))+b)='p';
    a++;
  }
}

void go_right(char* arr, int *strength, int *blood, int win, int will_p, int row, int col, int a, int b){ // pass
  if (*((arr+col*a)+(b+1))=='m'){
    int MonsterNumber=0;
    int willingness = 1;
    printf("You have %d blood and %d strength.\n", *blood, *strength);
    do {
      printf("Please choose which monster (1 to 4) you want to fight: ");
      scanf("%d", &MonsterNumber);
      if (MonsterNumber>4||MonsterNumber<1){
        printf("No such monster, please enter 1 to 4 to choose the monster.\nDo you want to go on your adventure (1: Yes; 0: No) ?:");
        scanf("%d", &willingness);
        if (willingness==1) continue;
        else if (willingness==0) {
          printf("We will miss you. Bye!\n");
          exit(0); 
        }
      }
      else break;
    } while(willingness==1);
    met_mons(arr, a, b, blood, strength, MonsterNumber, will_p, win);
  }

  if (*((arr+col*a)+b+1)=='v'){
    int village =0;
    int Q_v=0;
    do{
      printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)?");
      scanf("%d", &village);
      while(village!=1 && village!=2 && village!=3){
        printf("Invalid action!\n1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
        break;
      }
      met_vil(arr, a, b, strength, blood, village, Q_v);
    }while (village != 3);
  }
  if (*((arr+col*a)+b+1)=='G'){
    *strength+=1;
    printf("You got a gun! Now you have %d strength!\n", *strength);
  }

  if (*((arr+col*a)+b+1)=='t'){
    *blood-=1;
    printf("You fall into trap... Now you have %d health\n", *blood);
  }

  if (*((arr+col*a)+b+1)=='X'){
    int k;
    srand(time(NULL));
    k = rand()%3;
    if(k==0){
      if (*blood<10){
        *blood+=1;
        printf("You find a beer! Now you have %d health\n", *blood);
      }
      else printf("You find a beer! However your blood is full");
    }
    else if(k==1){
      *strength+=1;
      printf("You find a sword! Now you have %d strength\n", *strength);
    }
    else {
      if (*blood<10){
        *blood+=1;
      }
      *strength+=1;
      printf("You are so lucky! You find the best treature! Now you have %d health and %d strength\n", *blood, *strength);
    }
  }
  if (win == 1){
    *((arr+col*a)+b)='.';
    *((arr+col*a)+b+1)='p';
    b++;
  }
}

void go_left(char* arr, int *strength, int *blood, int win, int will_p, int row, int col, int a, int b){
  if (*((arr+col*a)+b-1)=='m'){
    int MonsterNumber=0;
    int willingness = 1;
    printf("You have %d blood and %d strength.\n", *blood, *strength);
    do {
      printf("Please choose which monster (1 to 4) you want to fight: ");
      scanf("%d", &MonsterNumber);
      if (MonsterNumber>4||MonsterNumber<1){
        printf("No such monster, please enter 1 to 4 to choose the monster.\nDo you want to go on your adventure (1: Yes; 0: No) ?:");
        scanf("%d", &willingness);
        if (willingness==1) continue;
        else if (willingness==0) {
          printf("We will miss you. Bye!\n");
          exit(0); 
        }
      }
      else break;
    } while(willingness==1);
    met_mons(arr, a, b, blood, strength, MonsterNumber, will_p, win);
  }

  if (*((arr+col*a)+b-1)=='v'){
    int village =0;
    int Q_v=0;
    do{
      printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)?");
      scanf("%d", &village);
      while(village!=1 && village!=2 && village!=3){
        printf("Invalid action!\n1: buy a magical sword; 2: go to the bar; 3: leave the village\n");
        break;
      }
      met_vil(arr, a, b, strength, blood, village, Q_v);
      if (village==1) Q_v=1;
    }while (village != 3);
  }

  if (*((arr+col*a)+b-1)=='G'){
    *strength+=1;
    printf("You got a gun! Now you have %d strength!\n", *strength);
  }

  if (*((arr+col*a)+b-1)=='t'){
    *blood-=1;
    printf("You fall into trap... Now you have %d health\n", *blood);
  }

  if (*((arr+col*a)+b-1)=='X'){
    int k;
    srand(time(NULL));
    k = rand()%3;
    if(k==0){
      if (*blood<10){
        *blood+=1;
        printf("You find a beer! Now you have %d health\n", *blood);
      }
      else printf("You find a beer! However your blood is full");
    }
    else if(k==1){
      *strength+=1;
      printf("You find a sword! Now you have %d strength\n", *strength);
    }
    else {
      if (*blood<10){
        *blood+=1;
      }
      *strength+=1;
      printf("You are so lucky! You find the best treature! Now you have %d health and %d strength\n", *blood, *strength);
    }
  }
  if (win == 1){
    *((arr+col*a)+b)='.';
    *((arr+col*a)+b-1)='p';
    b--;
  }
}



int main() {
  char **arr;
  int a, b;
  int row, col;
  int will=1;
  int blood=10, strength=2; 
  while (will==1){ //一開始的意願是1
    int gun_x=0, gun_y=0;
    int tre_x=0, tre_y=0;
    int win = 1;
    int will_p=1;
    int amo_mons;
    int Q=0;
    
    create_map(&row, &col);

    char **arr = (char **)malloc(sizeof(char *) * row);
    for(int i = 0; i < row; i++){
        arr[i] = (char *)malloc(sizeof(char) * col);
        memset(arr[i], '.', sizeof(char *));
    }

    print_map(arr, row, col);

    int amo_trap = row/2;

    setup_village(arr[0], row, col, a, b);
    
    amo_mons= (row/10) + (row % 10) - 1;//怪獸數

    printf("You need to assign location for %d monsters in total\n",amo_mons);

    setup_monster(amo_mons,arr[0], row, col, a, b);

    printf("You need to assign location for %d traps in total\n",amo_trap);

    setup_trap(amo_trap,arr[0], row, col, a, b);
    
    if (row>=3||col>=3) {
      srand(time(NULL));
      do{
        gun_x=rand()%row;
        gun_y=rand()%col;
				//printf("do while507: %d %d\n", gun_x, gun_y);
      } while (check_pvmtg(gun_x, gun_y, arr[0], row, col));
			//printf("507: %d %d\n", gun_x, gun_y);
      arr[gun_x][gun_y] = 'G'; 
    }

    if (row>=3||col>=3) {
      srand(time(NULL));
      do{
        tre_x=rand()%row;
        tre_y=rand()%col;
				//printf("do while517: %d %d\n", tre_x, tre_y);
      } while (check_pvmtg(tre_x, tre_y, arr[0], row, col));
			//printf("516: %d %d\n", tre_x, tre_y);
      arr[tre_x][tre_y] = 'X'; 
    }

    print_map(arr[0], row, col);
    
    while (Q==0){ //一開始還沒填，Q等於零
      printf("[1] Create a new map [2] Start travel the map: ");
      scanf("%d", &will);
      if (will==1) Q=1;
      else if (will==2) Q=2;
      else Q=0;
    }
    if (Q==1) {
      Q=0;
      continue;
    }
    if (Q==2) {setup_player(arr[0], row, col, a, b);}
    print_map(*arr, row, col);
    while (Q==2){
      int sum = 0;
      for (int k=0; k<row; k++){
        for (int f=0; f<col+1; f++){
          if (arr[k][f]=='m')
            sum++;
        }
      }
      if (sum==0){
        printf("You finish this game!");
        exit(0);
      }
      int move;
      printf("[1] go up [2] go down [3] go right [4] go left [5] exit: ");
      scanf("%d", &move);
      switch (move){
        case 1:
          if(check_move(arr[0], a-1, b, row, col)) continue;
          go_up(arr[0],&strength,&blood,win,will_p, row, col, a, b);
          break;
        case 2:
          if(check_move(arr[0], a+1, b, row, col)) continue;
          go_down(arr[0],&strength,&blood,win,will_p, row, col, a, b);
          break;
        case 3:
          if(check_move(arr[0], a, b+1, row, col)) continue;
          go_right(arr[0],&strength,&blood,win,will_p, row, col, a, b);
          break;
        case 4:
          if(check_move(arr[0], a, b-1, row, col)) continue;
          go_left(arr[0],&strength,&blood,win,will_p, row, col, a, b);
          break;
        case 5: return 0;
        default:
          continue;
      }
      print_map(arr[0], row, col);
    }
  }

  for(int i=0; i<row; i++){
    free(arr[i]);
    free (*arr);
  }  
  return 0;
}
