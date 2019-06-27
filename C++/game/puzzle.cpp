/*
    ***********************************************************
                            :Question:
            1. Play the puzzle game after running this code.
            2. First run the code put some number for the level.

                             :Output:
             then arrage should be(as a output)
                              __________________
                              |  1  | 2  |  3  |
                              |_____|____|_____|
                              |  4  |  5 |  6  |
                              |_____|____|_____|
                              |  7  |  8 |     |
                              |_____|____|_____|
    
    ***********************************************************
*/


#include <stdio.h>
#include <conio.h>
#include <time.h>
 //#include <ncurses.h>	
void puzzleRearrange();
int count = 0;
char a[9], ch;
void test();
clock_t start, end;
int main() {

    int j, k, flag, m, p;
    int i, n;
    printf("enter the lable::");
    scanf("%d", & p);
    for (i = 876543210; i >= 123456780; i--) {
        n = i;
        a[0] = n % 10 + 48;
        n = n / 10;
        a[1] = n % 10 + 48;
        n = n / 10;
        a[2] = n % 10 + 48;
        n = n / 10;
        a[3] = n % 10 + 48;
        n = n / 10;
        a[4] = n % 10 + 48;
        n = n / 10;
        a[5] = n % 10 + 48;
        n = n / 10;
        a[6] = n % 10 + 48;
        n = n / 10;
        a[7] = n % 10 + 48;
        n = n / 10;
        a[8] = n + 48;
        flag = 0;
        for (k = 0; k < 8; k++) {
            for (j = k + 1; j < 9; j++) {
                if (a[j] == a[k] || a[j] == '9' || a[k] == '9') {
                    flag = 1;
                    break;
                }
            }

        }
        if (flag == 0) {
            count++;
            if (p == count) {
                //printf("%d",i);
                break;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (a[i] == '0') {
            a[i] = ' ';
            break;
        }
    }
    test();
}

void test() {

    printf("\n************MAGIC PUZZLE*********\n");
    printf("\t****time is start****");
    start = time(NULL);
    while (1) {

        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 187);
        printf("%c     %c     %c     %c\n%c  %c  %c  %c  %c  %c  %c\n%c     %c     %c     %c\n", 186, 186, 186, 186, 186, a[0], 186, a[1], 186, a[2], 186, 186, 186, 186, 186);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
        printf("%c     %c     %c     %c\n%c  %c  %c  %c  %c  %c  %c\n%c     %c     %c     %c\n", 186, 186, 186, 186, 186, a[3], 186, a[4], 186, a[5], 186, 186, 186, 186, 186);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
        printf("%c     %c     %c     %c\n%c  %c  %c  %c  %c  %c  %c\n%c     %c     %c     %c\n", 186, 186, 186, 186, 186, a[6], 186, a[7], 186, a[8], 186, 186, 186, 186, 186);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 188);
        if (a[0] == '1' && a[1] == '2' && a[2] == '3' && a[3] == '4' && a[4] == '5' && a[5] == '6' && a[6] == '7' && a[7] == '8' && a[8] == ' ')
            break;
        else {
            puzzleRearrange();
        }
    }
    printf("\n**********puzzle is complite*********\n");
    end = time(NULL);
    int t = difftime(end, start);
    printf("\n total time= %d minute %d sec", t / 60, t % 60);
    printf("\n*********GAME IS SOLVED**************\n");
}
void puzzleRearrange() {
    printf("\n enter the move element::");
    int i, j;
    ch = getche();
    if (ch == 'M' || ch == 'K' || ch == 'H' || ch == 'P') {

        for (i = 0; i < 9; i++) {
            if (a[i] == ' ' && ch == 'K') {

                if (((i >= 0 && i < 2) || (i >= 3 && i < 5) || (i >= 6 && i < 8))) {
                    j = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = j;
                    break;
                } else {
                    printf("\n wrong enter,plz try again::\n");
                    break;
                }
            } else if (a[i] == ' ' && ch == 'H') {
                if (((i >= 0 && i <= 5))) {
                    j = a[i];
                    a[i] = a[i + 3];
                    a[i + 3] = j;
                    break;
                } else {
                    printf("\n wrong enter,plz try again::\n");
                    break;
                }
            } else if (a[i] == ' ' && ch == 'P')

            {
                if ((i >= 3 && i <= 8)) {
                    j = a[i];
                    a[i] = a[i - 3];
                    a[i - 3] = j;
                    break;
                } else {
                    printf("\n wrong enter,plz try again::\n");
                    break;
                }
            } else if (a[i] == ' ' && ch == 'M') {
                if (((i <= 2 && i > 0) || (i <= 5 && i > 3) || (i <= 8 && i > 6))) {
                    j = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = j;
                    break;
                } else {
                    printf("\n wrong enter,plz try again::\n");
                    break;
                }
            }
        }
    }

}
