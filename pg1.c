#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;
    int date;
    char *activity;
};

// Function prototypes
void create(struct Day **calendar);
void read(struct Day *calendar);
void display(struct Day *calendar);

int main() {
    struct Day *calendar;

    // Create the calendar
    create(&calendar);

    // Read data from keyboard
    read(calendar);

    // Display the calendar
    display(calendar);

    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);

    return 0;
}

// Function to create the calendar
void create(struct Day **calendar) {
    // Dynamically allocate memory for the calendar array
    *calendar = (struct Day *)malloc(7 * sizeof(struct Day));

    // Names of the days of the week
    char *dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // Allocate memory for name and activity for each day and initialize names and dates
    for (int i = 0; i < 7; i++) {
        (*calendar)[i].name = (char *)malloc(50 * sizeof(char));
        strcpy((*calendar)[i].name, dayNames[i]);
        (*calendar)[i].date = i + 1; // Setting the date
        (*calendar)[i].activity = (char *)malloc(100 * sizeof(char));
    }
}

// Function to read data from the keyboard
void read(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        printf("Enter the activity for %s (Day %d): ", calendar[i].name, calendar[i].date);
        scanf("%s", calendar[i].activity);
    }
}

// Function to display the calendar
void display(struct Day *calendar) {
    printf("Calendar:\n");
    printf("Day\t\t\t Date\t\t\t Activity\n");
    for (int i = 0; i < 7; i++) {
        printf("%s\t\t\t%d\t\t\t%s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
} 
