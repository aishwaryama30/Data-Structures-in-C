/*
Develop a Program in C for the following:
a) Declare a calendar as an array of 7 elements (A dynamically created array) to represent 7 days of a week. Each element of the array is a structure having three fields. The first field is the name of the Day (A dynamically allocated String), The second field is the date of the Day (An integer), the third field is the description of the activity for a particular day (A dynamically allocated String).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;
    int date;
    char *activity;
};

int main() {
    struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day)); // Dynamically allocated array of structures

    // Allocate memory for name and activity for each day
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char *)malloc(50 * sizeof(char));
        calendar[i].activity = (char *)malloc(100 * sizeof(char));
    }

    // Initialize the calendar data
    char *dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char *activities[] = {"Work", "Meeting", "Gym", "Shopping", "Movie", "Family Time", "Rest"};

    for (int i = 0; i < 7; i++) {
        strcpy(calendar[i].name, dayNames[i]);
        calendar[i].date = i + 1; // You can set the date as per your requirements
        strcpy(calendar[i].activity, activities[i]);
    }

    // Print the calendar
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].activity);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar); // Freeing the memory for the array of structures

    return 0;
}

