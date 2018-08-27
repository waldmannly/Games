/*
 NAME: Evan Waldmann
 CLASS: COP 3502H
 ASSIGNMENT: Assignment 6: Battleship
 DATE: 4/24/2016
 */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define  NORTH 'N'
#define  SOUTH 'S'
#define  WEST  'W'
#define  EAST  'E'
#define  MISS  '~'
#define  HIT   'X'
#define  BLANK ' '
#define  MAX 10
#define  CARRIER_LENGTH 5
#define  CARRIER 'C'
#define  BATTLESHIP_LENGTH 4
#define  BATTLESHIP 'B'
#define  SUB_LENGTH 3
#define  SUB 'S'
#define  DESTROYER_LENGTH 3
#define  DESTROYER 'D'
#define  PATROL_LENGTH 2
#define  PATROL 'P'
#define  NUM_SHIPS 5

//point struct definition
typedef struct point
{
    int x;
    int y;
} point1 ;

//ship struct definition
struct ship
{
    int length;
    char * start;
    char * stop;
    char * direction;
    int hits;
    int sunk;
    char *name;
};

//function that displays the board with ships, hits, and misses
void printBoard(char** grid)
{
    int r,c;
    printf("\n     1  2  3  4  5  6  7  8  9  10 (x)\n");
    printf("   |------------------------------|\n");
    for (r=0; r<MAX; r++)
    {
        for (c=0; c<MAX; c++)
        {
            if (c==0)
                printf("%3d|", r+1);
            
            printf(" %c ", grid[r][c]);
        }
        printf("|\n");
    }
    printf("(y)|------------------------------|\n");
}

//function that  displays the current state of the game with hits or misses
void specialPrintBoard(char** grid)
{
    int r,c;
    printf("\n     1  2  3  4  5  6  7  8  9  10 (x)\n");
    printf("   |------------------------------|\n");
    for (r=0; r<MAX; r++)
    {
        for (c=0; c<MAX; c++)
        {
            if (c==0)
                printf("%3d|", r+1);
            
            //the only difference between the special print and regular print is this, which makes sure that no ship will be printed
            if (grid[r][c] == CARRIER || grid[r][c] == SUB || grid[r][c] == DESTROYER || grid[r][c] == PATROL || grid[r][c] == BATTLESHIP)
                printf(" %c ", BLANK);
            else
                printf(" %c ", grid[r][c]);
        }
        printf("|\n");
    }
    printf("(y)|------------------------------|\n");
}

//function that populates board with blanks
char** popBoard(char** grid)
{
    int r,c;
    for (r=0; r<MAX; r++)
    {
        for (c=0; c<MAX; c++)
        {
            grid[r][c] = BLANK;
        }
    }
    return grid;
}

//converts a direction (N S E W) into a point that really is the basis vectors for the direction
point1* convertDirection (char dir)
{
    point1* point = malloc(sizeof(point1));
    if (dir == NORTH)
    {
        point->x = 0;
        point->y = -1;
    }
    else if (dir == SOUTH)
    {
        point->x = 0;
        point->y = 1;
    }
    else if (dir == WEST)
    {
        point->x = -1;
        point->y = 0;
    }
    else if (dir == EAST)
    {
        point->x = 1;
        point->y = 0;
    }
    else
        printf("error");
    
    return point;
}

//function to determine if ship will fit in selected position
//0 is false, any thing else is true
int isFit(int x, int y, char direction, int shipLength, char** grid)
{
    int i;
    //get point (basis vectors)
    point1* point = convertDirection(direction);
    //make the normal(unit) basis vector into the correct magnitude(ship length)
    int xmax = point->x * shipLength;
    int ymax = point->y * shipLength;
    
    //check the bounds
    if (x+xmax >= MAX|| x+xmax <0 || y+ymax >= MAX || y+ymax <0)
    {
        return 0;
    }
    
    //make sure there are not ships where the ship is going to be placed
    for (i=0; i<xmax; i++)
    {
        if (grid[y][x+i] != BLANK)
            return 0;
    }
    for (i=0; i>xmax; i--)
    {
        if (grid[y][x+i] != BLANK)
            return 0;
    }
    for(i=0; i<ymax; i++)
    {
        if (grid[y+i][x] != BLANK)
            return 0;
    }
    for(i=0; i>ymax; i--)
    {
        if (grid[y+i][x] != BLANK)
            return 0;
    }
    //returns true if there is a fit
    return 1;
}

//inserts the ship into the correct positions, does basically the same thing as the fit, except it doesn't check bounds
char** insertShip(char ship,int shipLength, int x, int y, char direction, char** grid)
{
    int i;
    x=x-1;
    y=y-1;
    point1* point = convertDirection(direction);
    int xmax = point->x * shipLength;
    int ymax = point->y * shipLength;
    
    for (i=0; i<xmax; i++)
    {
        grid[y][x+i] = ship;
    }
    
    for (i=0; i>xmax; i--)
    {
        grid[y][x+i] = ship;
    }
    
    for(i=0; i<ymax; i++)
    {
        grid[y+i][x] = ship;
    }
    
    for(i=0; i>ymax; i--)
    {
        grid[y+i][x] = ship;
    }
    return grid;
}


//function for human to place ship
char** placeHumanShips (char ** grid)
{
    int x, y;
    char dir;
    printf("\n");
    
    //each do while is taking in input and then inserting that input into the grid
    do
    {
    printf("Where do you want to place the start of your Carrier(length 5) and which direction do you want it to go? insert in format \"x y z\" where x and y in the bounds 1-10 and z is a char N, S, E, W");
    scanf("%d %d %c", &x, &y, &dir);
    }
    while(!(isFit(x-1,y-1,dir,5,grid)));
    grid = insertShip(CARRIER,CARRIER_LENGTH, x, y , dir, grid);
    
    printf("\n");
    do
    {
    printf("Where do you want to place the start of your BattleShip(length 4) and which direction do you want it to go? insert in format \"x y z\" where x and y in the bounds 1-10 and z is a char N, S, E, W");
     scanf("%d %d %c", &x, &y, &dir);
    }
    while(!(isFit(x-1,y-1,dir,4,grid)));
    grid = insertShip(BATTLESHIP,BATTLESHIP_LENGTH, x, y , dir, grid);
    
    printf("\n");
    do
    {
    printf("Where do you want to place the start of your Submarine(length 3) and which direction do you want it to go? insert in format \"x y z\" where x and y in the bounds 1-10 and z is a char N, S, E, W");
     scanf("%d %d %c", &x, &y, &dir);
    }
    while(!(isFit(x-1,y-1,dir,3,grid)));
    grid = insertShip(SUB,SUB_LENGTH, x, y , dir, grid);
    
    printf("\n");
    do
    {
    printf("Where do you want to place the start of your Destroyer(length 3) and which direction do you want it to go? insert in format \"x y z\" where x and y in the bounds 1-10 and z is a char N, S, E, W");
     scanf("%d %d %c", &x, &y, &dir);
    }
    while(!(isFit(x-1,y-1,dir,3,grid)));
    grid = insertShip(DESTROYER,DESTROYER_LENGTH, x, y , dir, grid);
    
    printf("\n");
    do
    {
    printf("Where do you want to place the start of your Patrol Boat(length 2) and which direction do you want it to go? insert in format \"x y z\" where x and y in the bounds 1-10 and z is a char N, S, E, W:  ");
     scanf("%d %d %c", &x, &y, &dir);
    }
    while(!(isFit(x-1,y-1,dir,2,grid)));
    grid = insertShip(PATROL,PATROL_LENGTH, x, y , dir, grid);
    
    return grid;
}

char** placeCompShips(char** grid)
{
    int x, y,z, count =0;
    char dir;
    
    //the computer randomly will pick spots for the 5 ships and insert them
    
    printf("\n");
    printf("\nComputer randomly picking 5 more spots... ");
    do
    {
        count++;
        srand(time(NULL));
        x = (rand() % 10)+1;
        y = (rand() % 10)+1;
        z=(rand() % 4) +1;
        
        if (z == 1)
            dir = 'N';
        else if (z == 2)
            dir = 'S';
        else if (z==3)
            dir = 'W';
        else
            dir = 'E';
    }
    while(!(isFit(x-1,y-1,dir,5,grid)));
//    printf("x:%d y:%d dir: %c\n", x,y,dir);
    grid = insertShip(CARRIER,CARRIER_LENGTH, x, y , dir, grid);
//    printBoard(grid);
    
    printf("\nComputer randomly picking 4 more spots... ");
    do
    {
        count++;
        srand(time(NULL));
        x = (rand() % 10)+1;
        y = (rand() % 10)+1;
        z=(rand() % 4) +1;
        
        if (z == 1)
            dir = 'N';
        else if (z == 2)
            dir = 'S';
        else if (z==3)
            dir = 'W';
        else
            dir = 'E';
    }
    while(!(isFit(x-1,y-1,dir,4,grid)));
//    printf("x:%d y:%d dir: %c\n", x,y,dir);
    grid = insertShip(BATTLESHIP,BATTLESHIP_LENGTH, x, y , dir, grid);
//    printBoard(grid);
    
    printf("\nComputer randomly picking 3 more spots... ");
    do
    {
        count++;
        srand(time(NULL));
        x = (rand() % 10)+1;
        y = (rand() % 10)+1;
        z=(rand() % 4) +1;
        
        if (z == 1)
            dir = 'N';
        else if (z == 2)
            dir = 'S';
        else if (z==3)
            dir = 'W';
        else
            dir = 'E';
    }
    while(!(isFit(x-1,y-1,dir,3,grid)));
//    printf("x:%d y:%d dir: %c\n", x,y,dir);
    grid = insertShip(SUB,SUB_LENGTH, x, y , dir, grid);
//    printBoard(grid);
    
    printf("\nComputer randomly picking 2 more spots... ");
    do
    {
        count++;
        srand(time(NULL));
        x = (rand() % 10)+1;
        y = (rand() % 10)+1;
        z=(rand() % 4) +1;
        
        if (z == 1)
            dir = 'N';
        else if (z == 2)
            dir = 'S';
        else if (z==3)
            dir = 'W';
        else
            dir = 'E';
    }
    while(!(isFit(x-1,y-1,dir,3,grid)));
//    printf("x:%d y:%d dir: %c\n", x,y,dir);
    grid = insertShip(DESTROYER,DESTROYER_LENGTH, x, y , dir, grid);
//    printBoard(grid);
    
    printf("\nComputer randomly picking 1 more spot... ");
    do
    {
        count++;
        srand(time(NULL));
        x = (rand() % 10)+1;
        y = (rand() % 10)+1;
        z=(rand() % 4) +1;
        
        if (z == 1)
            dir = 'N';
        else if (z == 2)
            dir = 'S';
        else if (z==3)
            dir = 'W';
        else
            dir = 'E';
    }
    while(!(isFit(x-1,y-1,dir,2,grid)));
//    printf("x:%d y:%d dir: %c\n", x,y,dir);
    grid = insertShip(PATROL,PATROL_LENGTH, x, y , dir, grid);
//    printBoard(grid);
    
    
    printf ("\nComputer finished placing ships!\nNumber of tries for the computer to randomly place its ships: %d\n", count);
    return grid;
}

//checks to see if the co-ordinates are in bounds
//0 if false, and 1 if true
int isInBound (int x, int y)
{
    if (x< MAX && x>=0 && y<MAX && y>=0)
        return 1;
    else
        return 0;
}

//check bounds and checks if the co-ordinate was picked by the user before, it alerts user if something went wrong
//0 if false, and 1 if true
int isPickedBeforeHuman(char** grid, int x, int y)
{
//    printf("CHECKING x:%d y:%d\n",x,y);
    if (!(isInBound(x, y)))
    {
        printf("Selection out of bounds. Try again\n");
        return 0;
    }
    
    if (grid[x][y] == MISS || grid[x][y] == HIT)
    {
        printf("Selection has been picked before. Try again\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

//computer will always pick a point in bounds so this only checks picked before. it doesnt know display anything
//0 if false, and 1 if true
int isPickedBeforeComputer(char** grid, int x, int y)
{
    //    printf("CHECKING x:%d y:%d\n",x,y);
    if (grid[x][y] == MISS || grid[x][y] == HIT)
        return 0;
    else
        return 1;
}

//generates a random move for the computer and makes sure that the move is do able
void getViableMove(char** grid, int *x, int* y)
{
    do
    {
        srand(time(NULL));
        *x = (rand() % 10);
        *y = (rand() % 10);
    }
    while(!(isPickedBeforeComputer(grid, *x, *y)));
}


//function to determine if a ship is sunk
//0 is false, any thing else is true
int isShipSunken( char ** grid, int x, int y)
{
    int r, c,count=0;
    //gets the ship char
    char shipHit = grid[x][y];
//    printf("%c   ", shipHit);
    for (r=0; r<MAX; r++)
    {
        for(c=0; c<MAX;c++)
        {
            if (grid[r][c] == shipHit) // counts the amount of those chars in the grid
                count++;
        }
    }
//    printf("count: %d\n", count);
    if (count-1 ==0) //returns the shipHit, which is also a true value if there is only the one ship char left. this means that type of ship was sunken
        return shipHit;
    else //otherwise the ship was no sunken
        return 0;
}

//function to determine if the selected cell is a hit or miss
//0 is false, any thing else is true
int isHit(int x, int y, char** grid)
{
    if (grid[x][y] == BLANK) //only need to check if the space holds a BLANK char because you cant pick the same spot. thus if it is not blank it is a ship
        return 0;
    else
        return grid[x][y];
}

//function to determine if the game is over
//0 is false, any thing else is true
int isGameOver(char** grid)
{
    //check for C,B,P,D,S
    int r,c;
    for (r=0; r<MAX; r++)
    {
        for (c=0; c<MAX; c++)
        {
            //make sure there are no ships left
            if (grid[r][c] == CARRIER || grid[r][c] == SUB || grid[r][c] == DESTROYER || grid[r][c] == PATROL || grid[r][c] == BATTLESHIP)
                return 0;
        }
    }
    return 1;
}

//function to manage switching play between human and computer
//returns 1 if computer wins, 2 if human wins, and 0 is no one wins
int switchTurns(char** uGrid, char** cGrid)
{
    int x,y;
    int shipHit;
    
    //human turn
    
    //give the User the boards
    printf("Hits and Misses on computer:\n");
    specialPrintBoard(cGrid);
    printf("\nYour ships with computer's Hits and Misses: \n");
    printBoard(uGrid);
    
    //prompt user for input and make sure it was not repeated input(picked before)
    do
    {
        printf("What position would you like to shoot? insert in format \"x y\" where x and y in the bounds 1-10: ");
        scanf("%d %d", &x,&y);
        x=x-1;
        y=y-1;
        int temp = x;
        x=y;
        y=temp;
        printf("\n");
    }
    while (!(isPickedBeforeHuman(cGrid,x,y)));
    
    //check to see if the input was a hit
    if (isHit(x,y,cGrid))
    {
        //if hit check to see if ship was sunken
        if((shipHit = isShipSunken(cGrid, x,y)))
        {
            printf("You have SUNKEN an enemy ship(%c) with your HIT at %d %d.\n", shipHit,y+1, x+1);
        }
        else
        {
            printf("You HIT an enemy ship at %d %d.\n", y+1, x+1);
        }
        
        //mark hit
        cGrid[x][y]= HIT;
        
        //after each hit check to see if game is over
        if (isGameOver(cGrid))
        {
            printf("\nGAME IS OVER!\n");
            return 2;
        }
    }
    else
    {
        //mark miss
        cGrid[x][y]= MISS;
        printf("%d %d was a MISS.\n",y+1, x+1 );
    }
    printf("\n");

    
    //computer turn
    
    //get computer's move
    getViableMove(uGrid, &x, &y);
    
//    printf("x:%d, y:%d\n", x,y);
    
    //check to see if the computer hit
    if (isHit(x,y,uGrid))
    {
         //if hit check to see if ship was sunken
        if((shipHit =isShipSunken(uGrid,x,y)))
        {
            printf("One of your ships(%c) was SUNKEN by the computer's HIT at %d %d.\n", shipHit, y+1, x+1);
        }
        else
        {
            printf("One of your ships was HIT by the computer's shot at %d %d.\n", y+1, x+1);
        }
        
        //mark hit
        uGrid[x][y]= HIT;
        
        //after each hit check to see if game is over
        if (isGameOver(uGrid))
        {
            return 1;
        }
    }
    else
    {
        printf("The computer fired at %d %d and MISSED.\n", y+1, x+1);
        //mark miss
        uGrid[x][y]= MISS;
    }
    
    return 0;
}



int main(void)
{
    int i, turn, count=0;
    
    // allocate memory for each of the grids
    char** userGrid = malloc(sizeof(char*)*10);
    for (i=0; i<MAX; i++)
        userGrid[i] = malloc(sizeof(char)*10);
    
    char** compGrid = malloc(sizeof(char*)*10);
    for (i=0; i<MAX; i++)
        compGrid[i] = malloc(sizeof(char)*10);
    
    //fill each grid with blanks
    userGrid = popBoard(userGrid);
    compGrid = popBoard(compGrid);
    
    //place the ships
    placeHumanShips(userGrid);
    placeCompShips(compGrid);
    
    //game begins
    
    //game loop
    do
    {
        count++;
        printf("\n\n---------------------------------------\n");
        printf("|              Turn %2d                |\n", count);
        printf("---------------------------------------\n");
        
        //method that allows user and computer to take turns
        turn = switchTurns(userGrid, compGrid);
    }
    while (turn == 0);
  
    //end game print out
    printf("The boards after %d turns were: \n", count);
    printf("\nUser's board: ");
    printBoard(userGrid);
    printf("\nComputer's board:");
    printBoard(compGrid);
    
    if (turn == 1)
    {
        printf("\nThe computer has won!\n");
    }
    else if (turn ==2)
    {
        printf("\nYou have won!\n");
    }
    else
        printf("Error");
    
    printf("\nThe game will now close.\n");

    return 0;
}


/*

 1 1 S
 2 1 S
 3 1 S
 4 1 S
 5 1 S

*/