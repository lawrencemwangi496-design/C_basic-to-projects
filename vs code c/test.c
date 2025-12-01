#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// ===========================
// FUNCTION DECLARATIONS
// ===========================
int read_pin(const char *filepath);
double read_balance(const char *filepath);
void send_money(double send, int pin, double balance, int epin, int number);

// ===========================
// FUNCTION DEFINITIONS
// ===========================

// Read PIN from last line
int read_pin(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char line[100];
    char last[100];

    while (fgets(line, sizeof(line), fp)) {
        strcpy(last, line);
    }

    fclose(fp);

    return atoi(last);
}

// Read balance from last line
double read_balance(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char line[100];
    char last[100];

    while (fgets(line, sizeof(line), fp)) {
        strcpy(last, line);
    }

    fclose(fp);

    return atof(last); // correct for double
}

// Send money
void send_money(double send, int pin, double balance, int epin, int number) {

    if (epin == pin) {

        if (balance >= send) {
            balance -= send;
            printf("You have sent ksh%.2lf to %d, your balance is ksh%.2lf\n",
                   send, number, balance);
        } else {
            printf("Insufficient funds.\n");
        }

    } else {
        printf("Transaction failed! Wrong pin.\n");
    }
}


// ===========================
// MAIN PROGRAM
// ===========================
int main() {

    double send, balance;
    int choice, number;
    int pin, epin;

    pin = read_pin("/home/lawrence-mwangi/Documents/mpesa/pin.txt");
    balance = read_balance("/home/lawrence-mwangi/Documents/mpesa/balance.txt");

    time_t current_time = time(NULL);
    char *time_string = ctime(&current_time);

    do {
        printf("=/ MPESA C PROGRAM =/\n");
        printf("CHOOSE THE SERVICE:\n");
        printf("1. Send money\n");
        printf("2. Withdraw cash\n");
        printf("3. Deposit amount\n");
        printf("4. Lipa na Mpesa\n");
        printf("5. Check balance\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nSEND MONEY\n");
            printf("Enter number of recipient: ");
            scanf("%d", &number);
            printf("Enter amount to send: ");
            scanf("%lf", &send);
            printf("Enter pin: ");
            scanf("%d", &epin);

            send_money(send, pin, balance, epin, number);
            printf("%s\n", time_string);

            break;
        }
    }
    while (choice != 6);

    return 0;
}
