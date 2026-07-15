#include <stdio.h>
#include <stdlib.h>   // For rand() and srand()
#include <time.h>     // For time(), localtime(), sleep()
#include <unistd.h>   // For sleep() function (POSIX)

// --- 3. Define a struct for the current time ---
struct Time {
    int hour;
    int minute;
    int second;
};

// --- 4. Function to print the time struct in "HH:MM:SS" format ---
void printTime(struct Time t) {
    // Print with leading zeros for two-digit format
    printf("%02d:%02d:%02d", t.hour, t.minute, t.second);
}

int main() {
    // --- 1. Sum of two integers (with user input challenge) ---
    int num1, num2;

    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    int sum = num1 + num2;
    // Print in the specified format
    printf("%d plus %d equals %d\n\n", num1, num2, sum);

    // --- 3. Create and initialize a time struct ---
    struct Time currentTime;

    currentTime.hour = 17;
    currentTime.minute = 31;
    currentTime.second = 0;
    printTime(currentTime);
    printf("\n\n");


    // --- 5 & 7. While loop that updates time every second for one minute ---
    printf("Starting a one-minute timer (updates every second):\n");
    int secondsElapsed = 0;

    // --- While loop stops after one minute (60 seconds) ---
    while (secondsElapsed < 60) {
        // Print the current time (overwrite the line for a cleaner effect)
        printf("\r");
        printTime(currentTime);
        fflush(stdout); // Force the output to be printed immediately

        // Wait for 1 second
        sleep(1);

        // Increment the time by one second
        currentTime.second++;
        if (currentTime.second >= 60) {
            currentTime.second = 0;
            currentTime.minute++;
            if (currentTime.minute >= 60) {
                currentTime.minute = 0;
                currentTime.hour++;
                if (currentTime.hour >= 24) {
                    currentTime.hour = 0;
                }
            }
        }

        secondsElapsed++;
    }

    // Print a newline after the loop finishes for a clean prompt
    printf("\nOne minute has passed. Timer stopped.\n");

    // --- Challenge: Replace the while loop logic with a for loop ---
    printf("\n--- Using a FOR loop for another minute ---\n");

    // For loop that runs exactly 60 times
    for (int i = 0; i < 60; i++) {
        printf("\r");
        printTime(currentTime);
        fflush(stdout);

        sleep(1);

        // Increment time
        currentTime.second++;
        if (currentTime.second >= 60) {
            currentTime.second = 0;
            currentTime.minute++;
            if (currentTime.minute >= 60) {
                currentTime.minute = 0;
                currentTime.hour++;
                if (currentTime.hour >= 24) {
                    currentTime.hour = 0;
                }
            }
        }
    }
    printf("\nFor loop timer finished.\n");

    return 0;
}
