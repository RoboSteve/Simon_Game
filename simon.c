#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define guesses2win 100
int main(){
    srand(time(NULL));
    int i,j,guessnumber,choice,number,input[50],inputlength,counter,matches,timer,timer1,eraser;
    char yn;
    int array[guesses2win];
    //int r = (rand()%4);
Menu:
    printf("Welcome to Simon!\n");
    printf("Made by Steven Cotton\n");
    printf("Choose your mode!\n"
            "[1]     How to Play\n"
            "[2]	Classic Mode\n"
            "[3]	Regular Mode\n"
            "[4]     Winnable Mode\n"
            "[5]	Quit\n");
    printf(" ");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            printf("\nHow to Play\n"
                    "-----------\n"
                    "Simon is a game that tests your memory.\n"
                    "It will show you a number sequence, then quickly replace it with an 'X'.\n"
                    "The game will ask you for your guess. You put in the number(s) it showed you.\n"
                    "If you are correct, the game will show you a sequence of numbers, one larger than the previous.\n"
                    "***You MUST input the numbers EXACTLY as shown!\n"
                    "For example: 0 2 1 cannot be input as 021 or it will break!!\n"
                    "(I'm not that good yet :P)\n"
                    "If you are wrong, the game will give you the correct sequence and exit.\n\n"
                    "Modes\n"
                    "-----\n"
                    "[2] Classic Mode gives you numbers sequentially like the real game!\n"
                    "[3] Regular Mode gives you all the numbers at once!\n"
                    "[4] Winnable Mode lets you choose how long you play before you win!\n"
                    "Have fun!!!\n"
                    "\n");
            goto Menu;
        case 2:
            goto Classic;
        case 3:
            goto Regular;
        case 4:
            goto Win;
        case 5:
            printf("See you again soon!\n");
            return 0;
        default:
            printf("Invalid choice, you big dummy!\n");
            goto Menu;
    }
Classic:
    printf("Welcome to Classic Mode!\n");
    //printf("How many guesses would you like to make? "); //replaced with #define
    //scanf("%d",&guesses2win);
    for (i=0;i<guesses2win;i++) //makes random array, adds on to each round
        array[i] = (rand()%4);
    for (guessnumber=1;guessnumber<=guesses2win;guessnumber++){
        for(i=0;i<guessnumber;i++){  //prints values in array until guess number
            printf("%d ",array[i]);
            for (j=0;j<999999;j++)
                printf("\b ");
        }
        printf("\b");
        for(timer1=0;timer1<500;timer1++){
            for(timer=0;timer<4000*guessnumber+1;timer++) //timer before erase
                printf("\b");
        }
        while(i<guessnumber*2){  //erasing
            printf("X ");
            i++;
        }
        printf("\n");

        if(guessnumber==1)
            printf("%dst guess: ",guessnumber);
        else if(guessnumber==2)
            printf("%dnd guess: ",guessnumber);
        else if(guessnumber==3)
            printf("%drd guess: ",guessnumber);
        else
            printf("%dth guess: ",guessnumber);
        for(i=0;i<guessnumber;i++){
            scanf("%d",&input[i]);
        }
        for (j=0;j<guessnumber;j++){    //check if guess is correct
            //printf("%d vs. %d\n",array[j],input[j]); //debug print input vs actual
            if(array[j]!=input[j]){
                printf("Wrong! You lost after %d tries!\n",guessnumber);
                printf("Correct answer was: ");
                for(i=0;i<guessnumber;i++)
                    printf("%d ",array[i]);
                printf("\nTo play again, type ./simon.out and hit enter\n");
                return 0;
            }
        }    
        for (i=0;i<35;i++)  //moves screen down
            printf("\n");    
        printf("Correct!\n");
        if (guessnumber==guesses2win)
            printf("You Win!!!\n");
    }
    goto Menu;
Regular:
    printf("Welcome to Regular Mode!\n");
    //guesses2win=100; //replaced with #define
    int arrayinf[guesses2win];
    for (i=5;i>0;i--){  //countdown delay to start
        for(j=0;j<999999;j++)
            printf("\b");
        printf("%d",i);
        for (j=0;j<999999;j++)
            printf("\b");
    }
    for (i=0;i<guesses2win;i++) //makes random array, adds on to each round
        arrayinf[i] = (rand()%4);
    for (guessnumber=1;guessnumber<=guesses2win;guessnumber++){
        for(i=0;i<guessnumber;i++)  //prints values in array until guess number
            printf("%d ",arrayinf[i]);
        printf("\b");
        for(timer1=0;timer1<500;timer1++){
            for(timer=0;timer<6001*guessnumber+1;timer++) //timer before erase
                printf("\b");
        }
        while(i<guessnumber*2){  //erasing
            printf("X ");
            i++;
        }
        printf("\n");

        if(guessnumber==1)
            printf("%dst guess: ",guessnumber);
        else if(guessnumber==2)
            printf("%dnd guess: ",guessnumber);
        else if(guessnumber==3)
            printf("%drd guess: ",guessnumber);
        else
            printf("%dth guess: ",guessnumber);
        for(i=0;i<guessnumber;i++){

            scanf("%d",&input[i]);
        }
        for (j=0;j<guessnumber;j++){    //check if guess is correct
            //printf("%d vs. %d\n",array[j],input[j]); //debug print input vs actual
            if(arrayinf[j]!=input[j]){
                printf("Wrong! You lost after %d tries! Well done!\n",guessnumber);
                printf("Correct answer was: ");
                for(i=0;i<guessnumber;i++)
                    printf("%d ",arrayinf[i]);
                printf("\nTo play again, type ./simon.out and hit enter\n");

                return 0;
            }
        }
        for (i=0;i<35;i++)  //moves screen down
            printf("\n");
        printf("Correct!\n");
    }
}
Win:
printf("Welcome to Regular Mode!\n");
printf("How many guesses would you like to make? "); //replaced with #define
scanf("%d",&guess2win);
int arrayinf[guess2win];
for (i=5;i>0;i--){  //countdown delay to start
    for(j=0;j<999999;j++)
        printf("\b");
    printf("%d",i);
    for (j=0;j<999999;j++)
        printf("\b");
}
for (i=0;i<guess2win;i++) //makes random array, adds on to each round
arrayinf[i] = (rand()%4);
for (guessnumber=1;guessnumber<=guess2win;guessnumber++){
    for(i=0;i<guessnumber;i++)  //prints values in array until guess number
        printf("%d ",arrayinf[i]);
    printf("\b");
    for(timer1=0;timer1<500;timer1++){
        for(timer=0;timer<6001*guessnumber+1;timer++) //timer before erase
            printf("\b");
    }
    while(i<guessnumber*2){  //erasing
        printf("X ");
        i++;
    }
    printf("\n");

    if(guessnumber==1)
        printf("%dst guess: ",guessnumber);
    else if(guessnumber==2)
        printf("%dnd guess: ",guessnumber);
    else if(guessnumber==3)
        printf("%drd guess: ",guessnumber);
    else
        printf("%dth guess: ",guessnumber);
    for(i=0;i<guessnumber;i++){

        scanf("%d",&input[i]);
    }
    for (j=0;j<guessnumber;j++){    //check if guess is correct
        //printf("%d vs. %d\n",array[j],input[j]); //debug print input vs actual
        if(arrayinf[j]!=input[j]){
            printf("Wrong! You lost after %d tries! Well done!\n",guessnumber);
            printf("Correct answer was: ");
            for(i=0;i<guessnumber;i++)
                printf("%d ",arrayinf[i]);
            printf("\nTo play again, type ./simon.out and hit enter\n");

            return 0;
        }
    }
    for (i=0;i<35;i++)  //moves screen down
        printf("\n");
    printf("Correct!\n");
    if (guessnumber==guesses2win)
        printf("You Win!!!\n");
}
}
