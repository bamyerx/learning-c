/*
 * Project 8 from Chapter 9 of King: Write a program that simulates the game of
 * craps, which is played with two dice. On the first roll, the player wins if
 * the sum of the dice is 7 or 11. The player loses if the sum is 2, 3, or 12.
 * Any other roll is called the "point" and the game continues. On each
 * subsequent roll, the player wins if he or she rolls the point again. The
 * player loses by rolling 7. Any other roll is ignored and the game continues.
 * At the end of each game, the program will ask the user whether or not to play
 * again. When the user enters a response other than y or Y, the program will
 * display the number of wins and losses and then terminate.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
   bool is_win;
   int wins, losses;
   char play_again;

   while (true) {
      is_win = play_game();
      if (is_win) {
         wins++;
         printf("You win!\n");
      } else {
         losses++;
         printf("You lose!\n");
      }
      printf("\nPlay again? ");
      scanf(" %c", &play_again);
      printf("\n");
      if (play_again != 'Y' && play_again != 'y') {
         printf("Wins: %d  Losses: %d\n", wins, losses);
         return 0;
      }
   }

   return 0;
}

int roll_dice(void)
{
   int die1, die2;

   srand((unsigned) time(NULL));
   die1 = rand() % 6 + 1;
   die2 = rand() % 6 + 1;

   return die1 + die2;
}

bool play_game(void)
{
   int sum, point;
   sum = roll_dice();
   printf("You rolled: %d\n", sum);
   sleep(1);
   if (sum == 7 || sum == 11)
      return true;
   if (sum == 2 || sum == 3 || sum == 12)
      return false;
   point = sum;
   printf("Your point is %d\n", point);
   while (true) {
      sleep(1);
      sum = roll_dice();
      printf("You rolled: %d\n", sum);
      if (sum == point)
         return true;
      if (sum == 7)
         return false;
   }
}
