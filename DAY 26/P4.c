#include <stdio.h>

int main() {
    int choice, score = 0;

    printf(" Welcome to the Quiz Application!\n");
    printf("Answer the following questions:\n\n");

    // Question 1
    printf("Q1. Which is the capital of India?\n");
    printf("1. Mumbai\n2. Delhi\n3. Kolkata\n4. Chennai\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 2) {
        printf(" Correct!\n");
        score++;
    } else {
        printf(" Wrong! Correct answer is Delhi.\n");
    }

    // Question 2
    printf("\nQ2. Who is known as the Father of C language?\n");
    printf("1. Dennis Ritchie\n2. James Gosling\n3. Bjarne Stroustrup\n4. Guido van Rossum\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf(" Correct!\n");
        score++;
    } else {
        printf(" Wrong! Correct answer is Dennis Ritchie.\n");
    }

    // Question 3
    printf("\nQ3. Which planet is known as the Red Planet?\n");
    printf("1. Earth\n2. Mars\n3. Jupiter\n4. Venus\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 2) {
        printf(" Correct!\n");
        score++;
    } else {
        printf("Wrong! Correct answer is Mars.\n");
    }

    // Final Score
    printf("\n Your final score is: %d/3\n", score);

    if(score == 3) {
        printf(" Excellent! You got all correct.\n");
    } else if(score == 2) {
        printf(" Good job! Keep practicing.\n");
    } else {
        printf(" Better luck next time.\n");
    }

    return 0;
}
