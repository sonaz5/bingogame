#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void generate_board(int board[]) //function to generate a random bingo board
{  
  int i;
  int j;
    // Set the random seed
    srand(time(NULL));
    printf("---------------BINGO GAME!-----------------\n-------------------------------------------- \n");    
    
    for (i = 0; i < 8; i++) { // 8 unique random numbers between 1 and 100
        int num;
        bool is_unique;
        do {
            num = rand() % 100 + 1;
            is_unique = true;
            for (j = 0; j < i; j++) {
                if (board[j] == num) {
                    is_unique = false;
                    break;
                }
            }
        } while (!is_unique);
        board[i] = num;
    }  
}
// display the Bingo board to the user
void display_board(int board[])
{int i;
    for ( i = 0; i < 8; i++) {
        if (board[i] == 0) {
            printf("X ");
        } else {
            printf("%d ", board[i]);
        }
    }
    printf("\n");
}
    int main()
{
    int board[8] = {0}; 
    generate_board(board);// Generate a random Bingo board
    
    int num_tries = 0; //Initialize the number of tries 0
    
    while (true) {
        printf("\n");
        display_board(board);// Display the current bingo board
        int num;
        printf("Enter a number (or 0 for random number/ -1 to quit):");	
	    scanf("%d",&num);
        if (num == -1) {  //If the user types -1, quit the game
            break;
        } else if (num == 0) {  // If the user types 0, generate a random guess
            num = rand() % 100 + 1;
            printf(" %d\n", num);
        }
        
        // Mark the entered number on the Bingo board
        bool is_marked = false;
        int i;
        for ( i = 0; i < 8; i++) {
            if (board[i] == num) {
                board[i] = 0;
                is_marked = true;
                break;
            }
        }
        
        num_tries++;
        // Check if the user has won
        bool has_won = true;
        for ( i = 0; i < 8; i++) {
            if (board[i] != 0) {
                has_won = false;
                break;
            }
        }
        if (has_won) {
            printf("\nBINGO! YOU WON !\n Total number of tries:%d\n", num_tries);
            break;
        }
    }
    printf("Do you want to play again? (0-no/1-yes): ");
    int play_again;
                scanf("%d", &play_again);
                if (play_again == 1) {
                    
                 return main();
                } else {
                    printf("Goodbye!\n");
                    return 0;
                }
            
       
    }

	   
      



