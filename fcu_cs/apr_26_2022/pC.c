#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

double _min(double a, double b){
    return a < b ? a : b;
}

int main(){
    int hh, mm;
    char cc;

    // find the angle between hour and minute hand
    // input format: hour:minute 
    while(scanf("%d%c%d", &hh, &cc, &mm)){
        if(hh == 0 && mm == 0){
            break;
        }
        
        double angle = (hh * 30 + mm * 0.5) - (mm * 6); 
        if(angle < 0){
            angle += 360;
        }
        printf("%.3f\n", _min(angle, 360-angle));
    }
}