#include <stdio.h>

int main(void) {
    int selection;
    int days;

    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection:");
    scanf("%d", &selection);

    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    printf("Enter days:");
    scanf("%d", &days);

    if (days < 0) {
        printf("Invalid days.\n");
        return 0;
    }

    int first_day, daily, weekly_max;

    // TODO: assign rates based on selection (if / switch)

    int weeks = days / 7;
    int remaining = days % 7;
    int total = 0;

    int weekly_cost = first_day + 6 * daily;
    if (weekly_cost > weekly_max)
        weekly_cost = weekly_max;

    total += weeks * weekly_cost;

    int remaining_cost = 0;

    if (days <= 7) {
        if (days > 0) {
            remaining_cost = first_day + (days - 1) * daily;
            if (remaining_cost > weekly_max)
                remaining_cost = weekly_max;
        }
    } else {
        remaining_cost = remaining * daily;
    }

    total += remaining_cost;

    printf("Charge($): %d\n", total);

    return 0;
}
