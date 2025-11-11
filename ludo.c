#include <stdio.h>
#include <stdlib.h>

// Function to simulate rolling one die (returns 1–6)
int roll_one_die() {
    return (rand() % 6) + 1;
}

int main() {
    int counts[13] = {0};  // counts for sums 2–12
    int ways[13] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1}; // theoretical ways to get each sum
    int total_ways = 36;   // total outcomes for 2 dice (6x6)
    int rolls;
    
    printf("Enter number of dice rolls to simulate: ");
    scanf("%d", &rolls);

    // Seed the random number generator
    srand(12345);  // fixed seed for reproducible results (can change or use time(NULL))

    // Simulation loop
    for (int i = 0; i < rolls; i++) {
        int die1 = roll_one_die();
        int die2 = roll_one_die();
        int sum = die1 + die2;
        counts[sum]++;
    }

    // Display header
    printf("\n-----------------------------------------------\n");
    printf("Ludo Dice Distribution Analyzer\n");
    printf("-----------------------------------------------\n");
    printf("Sum |  Count  | Simulated %% | Theoretical %% | Difference\n");
    printf("-----------------------------------------------\n");

    // Calculate and display comparison for each possible sum
    for (int sum = 2; sum <= 12; sum++) {
        float sim_pct = (counts[sum] * 100.0f) / rolls;
        float theo_pct = (ways[sum] * 100.0f) / total_ways;
        float diff = sim_pct - theo_pct;
        printf("%3d | %7d | %10.2f%% | %13.2f%% | %+8.2f%%\n",
               sum, counts[sum], sim_pct, theo_pct, diff);
    }

    printf("-----------------------------------------------\n");
    printf("Note: Difference = Simulated %% - Theoretical %%\n");
    printf("-----------------------------------------------\n");

    return 0;
}
