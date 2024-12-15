#include <stdio.h>

double calculate_parallel_resistance(int n, double resistors[]) {
    double reciprocal_sum = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (resistors[i] > 0) { // Avoid division by zero
            reciprocal_sum += 1.0 / resistors[i];
        } else {
            printf("Invalid resistor value at index %d. Skipping...\n", i);
        }
    }

    if (reciprocal_sum == 0.0) {
        return -1; // Return -1 to indicate infinite resistance
    }

    return 1.0 / reciprocal_sum;
}

int main() {
    int n,i;
    printf("Enter the number of resistors in parallel: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of resistors.\n");
        return 1;
    }

    double resistors[n];
    printf("Enter the resistance values (in ohms):\n");
    for (i = 0; i < n; i++) {
        printf("Resistor %d: ", i + 1);
        scanf("%lf", &resistors[i]);
    }

    double total_resistance = calculate_parallel_resistance(n, resistors);

    if (total_resistance == -1) {
        printf("The total resistance is infinite (no valid resistors).\n");
    } else {
        printf("The total resistance is: %.2f ohms\n", total_resistance);
    }

    return 0;
}
