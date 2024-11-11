#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 10 // Total seats in the train

typedef struct {
    int pnr_number;
    char name[50];
    int age;
    int seat_number;
    int is_booked;
} Passenger;

Passenger train[TOTAL_SEATS];
int pnr_counter = 1;

// Function prototypes
void initializeTrain();
void bookTicket();
void cancelTicket();
void printTicket();
void printChart();
int findAvailableSeat(int age);

int main() {
    int choice;
    initializeTrain();

    while (1) {
        printf("\nRailway Reservation System\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Print Ticket\n");
        printf("4. Print Chart\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                printTicket();
                break;
            case 4:
                printChart();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Initialize train seats
void initializeTrain() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        train[i].is_booked = 0;  // 0 means seat is available
        train[i].seat_number = i + 1;
    }
}

// Book a ticket
void bookTicket() {
    char name[50];
    int age;
    
    printf("Enter your name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter your age: ");
    scanf("%d", &age);

    int seat_index = findAvailableSeat(age);
    if (seat_index == -1) {
        printf("Sorry, no seats available.\n");
        return;
    }

    // Book the seat
    train[seat_index].is_booked = 1;
    train[seat_index].pnr_number = pnr_counter++;
    strcpy(train[seat_index].name, name);
    train[seat_index].age = age;

    printf("Ticket booked successfully! Your PNR number is: %d, Seat number is: %d\n", train[seat_index].pnr_number, train[seat_index].seat_number);
}

// Find an available seat, prioritizing lower berths for senior citizens
int findAvailableSeat(int age) {
    if (age > 60) {
        for (int i = 0; i < TOTAL_SEATS; i++) {
            if (train[i].is_booked == 0 && train[i].seat_number % 3 == 0) {
                return i;
            }
        }
    }
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (train[i].is_booked == 0) {
            return i;
        }
    }
    return -1;
}

// Cancel a ticket
void cancelTicket() {
    int pnr;
    printf("Enter your PNR number to cancel the ticket: ");
    scanf("%d", &pnr);

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (train[i].is_booked && train[i].pnr_number == pnr) {
            train[i].is_booked = 0;
            printf("Ticket with PNR number %d cancelled successfully.\n", pnr);
            return;
        }
    }
    printf("Ticket with PNR number %d not found.\n", pnr);
}

// Print ticket details
void printTicket() {
    int pnr;
    printf("Enter your PNR number to print the ticket: ");
    scanf("%d", &pnr);

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (train[i].is_booked && train[i].pnr_number == pnr) {
            printf("\nTicket Details:\n");
            printf("PNR Number: %d\n", train[i].pnr_number);
            printf("Name: %s\n", train[i].name);
            printf("Age: %d\n", train[i].age);
            printf("Seat Number: %d\n", train[i].seat_number);
            return;
        }
    }
    printf("Ticket with PNR number %d not found.\n", pnr);
}

// Print the reservation chart
void printChart() {
    printf("\nReservation Chart:\n");
    printf("PNR Number\tName\t\tAge\tSeat Number\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (train[i].is_booked) {
            printf("%d\t\t%s\t\t%d\t%d\n", train[i].pnr_number, train[i].name, train[i].age, train[i].seat_number);
        }
    }
}
