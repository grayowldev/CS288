/* Kwasi Nsiah
 * Homework 1
 * */





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int MoveTortoise(int tortPos,int randNum){
    if (randNum >= 0 && randNum <= 5 ){
        tortPos += 3;
    } else if (randNum > 5 && randNum <= 7){
        tortPos -= 6;
        if (tortPos < 1){
            tortPos = 1;
        }
    } else {
        tortPos++;
    }
    return tortPos;
}

int MoveHare(int harePos, int randNum){
    if (randNum >= 0 && randNum <= 2 ){
        harePos += 0;
    } else if (randNum > 2 && randNum <= 4){
        harePos += 9;
    } else if (randNum > 4 && randNum <= 5){
        harePos -= 12;
        if (harePos < 1){
            harePos = 1;
        }
    } else if (randNum > 5 && randNum <= 8){
        harePos++;
    } else {
        harePos -= 2;
        if (harePos < 1){
            harePos = 1;
        }
    }
    return harePos;
}

void PrintCurrentPositions(int tortoisePosition, int harePosition){
    printf("---------------------------------------------------------------------||\n");
    int h = 1;
    int t = 1;
    while(t != tortoisePosition) {
        printf(" ");
        t++;
    }
    printf("T\n");
    while(h != harePosition) {
        printf(" ");
        h++;
    }
    printf("H\n");

    printf("---------------------------------------------------------------------||\n");
}

int main() {
    int tortoisePosition = 1;
    int harePosition = 1;
    int timer = 0;

    printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n\n");
    while (!(tortoisePosition >=70) && !(harePosition >= 70) ){
        printf("\n\n\n\n\n\n\n\n\n\n");
        int randNum = rand() % 11;
        timer++;
        tortoisePosition = MoveTortoise(tortoisePosition,randNum);
        harePosition = MoveHare(harePosition,randNum);
        PrintCurrentPositions(tortoisePosition,harePosition);
        usleep(100000);

    }

    if (tortoisePosition >= 70 && harePosition >= 70){
        printf("IT'S A TIE.\n");
    } else if (tortoisePosition > 70){
        printf("TORTOISE WINS!!! YAY!!!");
    } else {
        printf("HARE WINS. YUCH.");
    }



    return 0;
}