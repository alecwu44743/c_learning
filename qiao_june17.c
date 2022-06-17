#include <stdio.h>
#include <stdlib.h>


struct data{
    float time_stamp; 
    float ecg;
    float mcg[4];
};
typedef struct data _data;



int main(){
    FILE *fp;

    fp = fopen("MCG_in.txt", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    int rows = 0;
    while(!feof(fp)){
        char line[100];
        fgets(line, 100, fp);
        rows++;
    }
    fclose(fp);

    _data anly[rows];
    fp = fopen("MCG_out.txt", "r");
    

    int index = 0;
    while(!feof(fp)){
        fscanf(fp, "%f %f %f %f %f %f", &anly[index].time_stamp, &anly[index].ecg, &anly[index].mcg[0], &anly[index].mcg[1], &anly[index].mcg[2], &anly[index].mcg[3]);
        printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", anly[index].time_stamp, anly[index].ecg, anly[index].mcg[0], anly[index].mcg[1], anly[index].mcg[2], anly[index].mcg[3]);
        index++;

        printf("%d\n", index);
    }

    fclose(fp);


    FILE *wrt;
    fp = fopen("Statistics_out.txt", "w");

    float prev = anly[0].mcg[2];
    float curr = anly[1].mcg[2];

    int find_crest = 1;
    int wrtIndex = 1;
    int lineone = 1;

    _data prv;
    int add = 0;

    for(int i=2; i<1001; i++){
        // find crest and trough

        if(find_crest){
            if(prev < curr){
                prev = curr;
                curr = anly[i].mcg[2];
            }
            else{
                find_crest = 0;
                fprintf(fp, "%d: %.3f %.3f", wrtIndex, anly[i-2].time_stamp, anly[i-2].mcg[2]);
                prv = anly[i-2];
            }
        }
        else{
            if(prev > curr){
                prev = curr;
                curr = anly[i].mcg[2];
            }
            else{
                find_crest = 1;
                fprintf(fp, " %.3f %.3f\n", anly[i-2].time_stamp, anly[i-2].mcg[2]);
                wrtIndex++;

                prv = anly[i-2];

                if(add == 0){
                    fprintf(fp, "%d: %.3f %.3f", wrtIndex, prv.time_stamp, prv.mcg[2]);
                    add = 1;
                }
            }
        }

    }

}