#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define X 'x'
#define O 'o'
#define EMPTY ' '

void converter(char ch,int *row);

int check_win(char field[COLS][ROWS], char player);

int main(void)
{
    bool turn = false; // player 1(x): false, player 2(o): true

    char field[COLS][ROWS] = { 
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    };

    int col; //dikey
    int row; // yatay

    char input_row;

    char ltr[] = {'a','b','c'};

    while(1)
    {
        printf("  0 1 2\n");

        // drawing the field
        for(size_t i = 0; i<COLS;i++)
        {    
            printf("%c",ltr[i]); 

            for(size_t j = 0;j<ROWS;j++)
            {
                printf(" %c",field[i][j]);
            }

            printf("\n");
        }

        // checking for win
        if(check_win(field, X)){
            printf("X WINS!\n");
            break;
        }
        if(check_win(field, O)){
            printf("O WINS!\n");
            break;
        }
        // at first X plays.

        // in case player selects non empty field.
        do{
            printf(">>>");
            scanf(" %c%d",&input_row,&col);
            converter(input_row, &row);
        } while(col > 3 || row > 3 || col < 0 || row < 0 || field[row][col] != EMPTY);

        // turn converter and sign placer
        if(turn == false)
        {
            field[row][col] = X;
            turn = true;
        }    
        else{
            field[row][col] = O;
            turn = false;
        }  
    }

    return 0;
}

void converter(char ch,int *row)
{
    switch(ch){
        case 'a':
            *row = 0;
            break;
        case 'b':
            *row = 1;
            break;
        case 'c':
            *row = 2;
            break;
    }

}

int check_win(char field[COLS][ROWS], char player)
{
    // total 8 win situations (full verticals, full horizontals, crosses (2))

    //checking  horizontal and veritical
    for (int i = 0; i < 3; i++)
    {
        if(field[i][0] == player && field[i][1] == player && field[i][2] == player)
            return 1;
        if(field[0][i] == player && field[1][i] == player && field[2][i] == player)
            return 1;
    }
    
    // crosses left to right and right to left
    if(field[0][0] == player && field[1][1] == player && field[2][2] == player)
        return 1;
    if(field[0][2] == player && field[1][1] == player && field[2][0])
        return 1;
    

    return 0;

}


