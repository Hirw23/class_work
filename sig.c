#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler for SIGTSTP (Ctrl+Z)
void handle_sigstp(int sig) {
    printf("\nReceived SIGTSTP (Ctrl+Z). Exiting gracefully...\n");
    exit(0);  // Gracefully terminate the program
}

int main() {
    // Register the signal handler
    signal(SIGTSTP, handle_sigstp);

    printf("Program running... Press Ctrl+Z to exit gracefully.\n");

    // Infinite loop to keep the program running
    while (1) {
        printf("Working...\n");
        sleep(2);  // Simulate work
    }

    return 0;
}
