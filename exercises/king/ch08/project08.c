/*
 * Project 8 from Chapter 8 of King: Modify Programming Project 7 so that it
 * prompts for five quiz grade for each of five students, then compares the
 * total score and average score for each student, and the average score, high
 * score, and low score for each quiz.
 */

#include <stdio.h>

#define N_STUDENTS 5
#define N_QUIZZES 5

int main(void)
{
   int grades[N_STUDENTS][N_QUIZZES] = {0};
   int student, quiz, sum, low, high;

   for (student = 0; student < N_STUDENTS; student++) {
      printf("Enter student %d's scores: ", student + 1);
      for (quiz = 0; quiz < N_QUIZZES; quiz++) {
         scanf("%d", &grades[student][quiz]);
      }
   }
   printf("\nStudent  Total  Average\n");
   for (student = 0; student < N_STUDENTS; student++) {
      sum = 0;
      for (quiz = 0; quiz < N_QUIZZES; quiz++) {
         sum += grades[student][quiz];
      }
      printf("%7d  %5d  %7.1f\n", student + 1, sum, ((float) sum) / N_QUIZZES);
   }
   printf("\nQuiz  Average  High  Low\n");
   for (quiz = 0; quiz < N_QUIZZES; quiz++) {
      sum = 0;
      low = 100;
      high = 0;
      for (student = 0; student < N_STUDENTS; student++) {
         if (grades[student][quiz] < low)
            low = grades[student][quiz];
         if (grades[student][quiz] > high)
            high = grades[student][quiz];
         sum += grades[student][quiz];
      }
      printf("%4d  %7.1f  %4d  %3d\n", quiz + 1, ((float) sum) / N_STUDENTS, high, low);
   }

   return 0;
}
