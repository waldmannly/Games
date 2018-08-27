#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bettingList();
//int countSt

int main(void) {
    
    int bank = 100;
    int bet;
    int betChoice;
    int black[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    int red[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int single = -1;
    int bets [5][2];
    int numBets;
    int i, r, b, cont;
    char output[3000];
    int index =0;
    
    do{
        
        srand(time(NULL));
        r = rand() % 38;
        
        printf("You may bet up to five times.\nHow many bets would you like to make?");
        scanf("%d", &numBets);
        
        for(i = 0; i < numBets; i++)
        {
            bets[i][0] = -1;
            bets[i][1] = 0;
        }
        
        if(numBets < 1 || numBets >5)
        {
            numBets = 0;
            printf("Invalid entry. Try again.\n");
            printf
        }
        for (i = 0; i < numBets; i++)
        {
            bettingList();
            printf("Choose what you would like to bet on.");
            scanf("%d", &betChoice);
            
            while(betChoice <1 || betChoice > 14)
            {
                betChoice = -1;
                printf("Invalid entry. Try again.\nWhat would you like to bet on? ");
                scanf("%d", &betChoice);
            }
            
            if(betChoice == 13)
            {
                printf("What number would you like to bet on?\nIf you would like to bet on '00', enter '38'. ");
                scanf("%d", &single);
                if(single < 0 || single > 38)
                {
                    single = -1;
                    printf("Invalid entry. Try again.\n");
                   printf("What number would you like to bet on?\nIf you would like to bet on '00', enter '38'. ");
                    scanf("%d", &single);
                }
            }
            
            printf("How much would you like to bet? ($1 - $5) ");
            scanf("%d", &bet);
            while(bet < 1 || bet > 5)
            {
                bet = 0;
                printf( "Invalid entry. Try again.\nHow much would you like to bet? ");
                scanf("%d", &bet);
            }
            
            strcat(output, "%d\n", r);
            switch(betChoice)
            {
                case 1:
                    if(r >= 1 && r <= 18)
                    {
                        strcat(output, "You won your bet on low numbers!\n");
                        bank += bet;
                    }
                    else
                    {
                        strcat(output, "You lost your bet on low numbers.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 2:
                    if(r >= 19 && r <= 36)
                    {
                        strcat(output, "You won your bet on high numbers!\n");
                        bank += bet;
                    }
                    else
                    {
                        strcat(output, "You lost your bet on high numbers.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 3:
                    b = 0;
                    for(i = 0; i < 18; i++)
                    {
                        if(r == red[i])
                        {
                            b = 1;
                            strcat(output, "You won your bet on red numbers!\n");
                            bank += bet;
                        }
                        
                    }
                    
                    if(!b)
                    {
                        strcat(output, "You lost your bet on red numbers.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 4:
                    b = 0;
                    for(i = 0; i < 18; i++)
                    {
                        if(r == black[i])
                        {
                            b = 1;
                            strcat(output, "You won your bet on black numbers!\n");
                            bank += bet;
                        }
                        
                    }
                    
                    if(!b)
                    {
                        strcat(output, "You lost your bet on black numbers.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 5:
                        if(r % 2 == 0)
                        {
                            strcat(output, "You won your bet on even numbers!\n");
                            bank += bet;
                            
                        }
                        else
                        {
                            strcat(output, "You lose your bet on even numbers.\n");
                            bank-=bet;
                        }
                    break;
                    
                case 6: //Odd Numbers
                        if(r % 2 != 0)
                        {
                            strcat(output, "You won your bet on odd numbers!\n");
                            bank += bet;
                            
                        }
                        else
                        {
                            strcat(output, "You lose your bet on odd numbers.\n");
                            bank-=bet;
                        }
                    break;
                    
                case 7: //First Dozen
                    if(r <= 12)
                    {
                        strcat(output, "You won your bet on the First Dozen numbers!\n");
                        bank += (bet*2);
                    }
                    else
                    {
                        strcat(output, "You lose your bet on the First Dozen numbers.\n");
                        bank-=(bet*2);
                    }
                    break;
                case 8: //Second Dozen
                    if(r >= 13 && r <= 24)
                    {
                        strcat(output, "You won your bet on the Second Dozen numbers\n");
                        bank += (bet*2);
                    }
                    else
                    {
                        strcat(output, "You lose your bet on the Second Dozen numbers.\n");
                        bank-=(bet*2);
                    }
                    break;
                case 9: //Third Dozen
                    if(r >= 25 && r <= 36)
                    {
                        strcat(output, "You won your bet on the Third Dozen numbers!\n");
                        bank += (bet*2);
                    }
                    else
                    {
                        strcat(output, "You lose your bet on the Third Dozen numbers.\n");
                        bank-=(bet*2);
                    }
                    break;
                case 10: //First Column
                    if(r % 3 == 1)
                    {
                        strcat(output, "You won your bet on the First Column numbers!\n");
                        bank += (bet*2);
                    }
                    else
                    {
                        strcat(output, "You lose your bet on the Third Dozen numbers.\n");
                        bank-=(bet*2);
                    }
                    break;
                    
                case 11:
                    if(r % 3 == 2)
                    {
                        strcat(output, "You won your second column bet!\n");
                        bank += (2 * bet);
                    }
                    
                    else
                    {
                        strcat(output, "You lost your second column bet.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 12:
                    if(r % 3 == 0)
                    {
                        strcat(output, "You won your third column bet!\n");
                        bank += (2 * bet);
                    }
                    
                    else
                    {
                        strcat(output, "You lost your third coulmn bet.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 13:
                    if(r == single)
                    {
                        strcat(output, "You won your single bet!\n");
                        bank += (35 * bet);
                    }
                    
                    else
                    {
                        strcat(output, "You lost your single bet.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 14:
                    if (r == 0 || r == 1 || r == 2 || r ==3)
                    {
                        strcat(output, "You own your basket bet!");
                        bank += (11 * bet);
                    }
                    
                    else
                    {
                        strcat(output, "You lost your basket bet.\n");
                        bank -= bet;
                    }
                    break;
                    
                case 15:
                    if (r == 0 || r == 38 || r == 1 || r == 2 || r ==3)
                    {
                        strcat(output, "You won your top line bet!\n");
                        bank += (6 * bet);
                    }
                    
                    else
                    {
                        strcat(output, "You lost your top line bet.\n");
                        bank -= bet;
                    }
                    break;
                    
                default:
                    break;
            }
            printf( "your current bank amount is: %d\n", bank);
        }
        printf( "Do you want to play again?\nEnter 1 to play again and 0 to exit. ");
        scanf("%d", &cont);
    }while(cont);
    
    return 0;
}

void bettingList()
{
    printf( "===============\n");
   printf( "Betting Options\n");
    printf( "===============\n\n");
    printf( "============\n");
    printf("Outside Bets\n");
    printf( "============\n");
    printf( "1.  Low (1-18)\n");
    printf( "2.  High (19-36)\n");
    printf("3.  Red\n");
    printf( "4.  Black \n");
    printf( "5.  Even \n");
    printf( "6.  Odd \n");
   printf( "7.  First Dozen (1-12)\n");
   printf( "8.  Second Dozen (13-24)\n");
    printf( "9.  Third Dozen (25-36)\n");
    printf( "10.  First Column (1, 4, 7, ..., 34)\n");
    printf( "11. Second Column (2, 5, 8, ..., 35)\n");
   printf( "12. Third Column (3, 6, 9, ..., 36)\n\n");
   printf( "===========\n");
    printf( "Inside Bets\n");
    printf( "===========\n");
    printf( "13. Single\n");
    printf( "14. Basket (0, 1, 2, 3)\n");
    printf( "15. Top Line (0, 00, 1, 2, 3)\n");
    
}