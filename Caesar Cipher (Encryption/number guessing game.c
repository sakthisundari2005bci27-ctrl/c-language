#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_num, guess, attempts = 0;
    srand(time(0)); // Seed the random number generator
    secret_num = rand() % 100 + 1; // Number between 1 and 100

    printf("--- Welcome to the Number Guessing Game! ---\n");
    printf("I have picked a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }
        attempts++;

        if (guess > secret_num) printf("Too high! Try again.\n");
        else if (guess < secret_num) printf("Too low! Try again.\n");
        else printf("Correct! You found it in %d attempts.\n", attempts);

    } while (guess != secret_num);

    return 0;
}
