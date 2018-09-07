//TEAM 9
//Kevin Thwe

#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

int main()
{
    char gameBoard[3][3] = {{'1','2','3'},
                            {'4','5','6'},
                            {'7','8','9'}};
    int i = 0;
    int row = 0;
    int col = 0;
    int player = 0;
    int win = 0;
    int location = 0;
    char piece = 'X';
    int lineCheck = 0;
    char choice;
    printf("TEAM 9's Tic-Tac-Toe\n Do you want to play? (Y/N): ");
    while ((scanf(" %c", &choice) == 1 && choice == 'Y') || choice == 'y')
    {
    for( i = 0; i < 9 && win == 0; i++)
    {

      puts("Welcome to Tic-Tac-Toe");
      printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
      player = i%2 + 1;
      do
      {
          if(player==1)
            {
            piece ='X';
            printf("Enter the square where you would like to play your piece");
            scanf("%d", &location);
            row = --location/3;
            col = location%3;
            }
          else
            {
            piece = 'O';
            location = rand() % 10;
            row = --location/3;
            col = location%3;
            }
      }
      while(location < 0 || location > 9 || gameBoard[row][col] > '9');
      if(player == 1)
        piece = 'X';
      else
        piece = 'O';
      gameBoard[row][col] = piece;
      //system("cls");

      if((gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) ||
         (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]))
         {
        win = player;
        if(player == 1)
                    piece = 'X';
                else
                    piece = 'O';
        gameBoard[0][0] = '1';
        gameBoard[0][1] = '2';
        printf("%c wins!\n", piece);
         }
      else
        for(lineCheck = 0; lineCheck <= 2; lineCheck ++)
          if((gameBoard[lineCheck][0] == gameBoard[lineCheck][1] && gameBoard[lineCheck][0] == gameBoard[lineCheck][2])||
             (gameBoard[0][lineCheck] == gameBoard[1][lineCheck] && gameBoard[0][lineCheck] == gameBoard[2][lineCheck]))
            {
                win = player;
                if(player == 1)
                    piece = 'X';
                else
                    piece = 'O';

                printf("%c wins!\n", piece);}
            }
        if(win != player)
            {
            printf("Tie!\n");
            }
            win = 0;
            gameBoard[0][0] = '1';
            gameBoard[0][1] = '2';
            gameBoard[0][2] = '3';
            gameBoard[1][0] = '4';
            gameBoard[1][1] = '5';
            gameBoard[1][2] = '6';
            gameBoard[2][0] = '7';
            gameBoard[2][1] = '8';
            gameBoard[2][2] = '9';
            printf("Do you want to play again? Y or N: ");
    }
    printf("Good Bye");
    return 0;
}


