#include <stdio.h>
#include <string.h>

struct Ticket {
    int id;
    char name[50];
    char movie[50];
    int seats;
};

struct Ticket tickets[100];
int count = 0;

void bookTicket() {
    tickets[count].id = count + 1;
    printf("Enter customer name: ");
    scanf(" %[^\n]", tickets[count].name);
    printf("Enter movie name: ");
    scanf(" %[^\n]", tickets[count].movie);
    printf("Enter number of seats: ");
    scanf("%d", &tickets[count].seats);
    count++;
    printf("Ticket booked successfully!\n");
}

void displayTickets() {
    if (count == 0) {
        printf("No tickets booked.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Movie: %s | Seats: %d\n",
               tickets[i].id, tickets[i].name, tickets[i].movie, tickets[i].seats);
    }
}

void searchTicket() {
    int id;
    printf("Enter ticket ID to search: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Ticket not found.\n");
        return;
    }
    printf("Ticket Found: Name: %s | Movie: %s | Seats: %d\n",
           tickets[id - 1].name, tickets[id - 1].movie, tickets[id - 1].seats);
}

void cancelTicket() {
    int id;
    printf("Enter ticket ID to cancel: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid ticket ID.\n");
        return;
    }
    for (int i = id - 1; i < count - 1; i++) {
        tickets[i] = tickets[i + 1];
    }
    count--;
    printf("Ticket cancelled successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Ticket Booking System ---\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: displayTickets(); break;
            case 3: searchTicket(); break;
            case 4: cancelTicket(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
