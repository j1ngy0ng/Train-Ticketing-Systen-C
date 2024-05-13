//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <stdbool.h>
//#pragma warning (disable:4996)
//
//#define MAX_SCHEDULES 30
//#define MAX_BOOKINGS 80
//#define MAX_RECORDS 100  
//#define MAX_MEMBER 100
//#define MAX_STAFFS 100
//#define MAX_SEATS 80
//
//
//typedef struct {
//    int birthDate;
//    int area;
//    int uniqueID;
//} IC;
//
//// Members Info
//struct Members {
//    char name[31];
//    char memberID[6];
//    char gender;
//    IC memberIC;
//    int contactNum;
//    char bookingID[6];
//    char password[9];
//    int passRecover;
//};
//
//typedef struct { //Structure for storing date and time
//    char departureDate[12];
//    char departureTime[5];
//    char arrivalTime[5];
//}DateTime;
//
//
//typedef struct { //Structure for storing schedule information
//    int number;
//    char trainId[10];
//    char departureLocation[30];
//    char destination[30];
//    DateTime dateTime[200];
//    double fare;
//    int distance;
//    double duration;
//    int availableSeats;
//    char id[6];
//}Schedule;
//
//typedef struct {
//    char bookingID[10];
//    char memberID[10];
//    char trainID[10];
//    char bookingDate[12];
//    char departureDate[12];
//    int seatNumberRow[40];
//    int seatNumberColumn[40];
//    int quantity[10];
//    char paymentInfo[100];
//    double amount;
//    char staffID[7];
//} Booking;
//
//typedef struct {
//    Booking bookings[MAX_BOOKINGS];
//    int numBookings;
//}BookingManager;
//
//typedef struct {
//    Schedule schedules[MAX_SCHEDULES];
//    int numSchedules;
//} ScheduleManager;
//
//void loadSchedules(ScheduleManager* manager, const char* schedulename) {
//
//    FILE* file = fopen(schedulename, "r");
//    if (file == NULL) {
//        printf("Error opening file %s\n", schedulename);
//        return;
//    }
//
//    int numSched = 0;
//
//    while (numSched < MAX_SCHEDULES) {
//        Schedule newSchedule;
//        DateTime dateTime;
//        int res = fscanf(file, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%lf|%d|%lf|%d|%s\n",
//            &newSchedule.number, newSchedule.trainId,
//            newSchedule.departureLocation, newSchedule.destination,
//            dateTime.departureDate, dateTime.departureTime,
//            dateTime.arrivalTime, &newSchedule.fare,
//            &newSchedule.distance, &newSchedule.duration,
//            &newSchedule.availableSeats, newSchedule.id);
//
//        if (res == EOF || res != 12) {
//            break;
//        }
//
//        (*manager).schedules[numSched] = newSchedule;
//        numSched++;
//    }
//
//    fclose(file);
//
//    (*manager).numSchedules = numSched;
//}
//
//
//int saveBookingsToFile(const char* bookingname, const BookingManager* bookingManager) {
//    FILE* file = fopen(bookingname, "wb");
//    if (file == NULL) {
//        printf("Error opening file %s\n", bookingname);
//        return -1;  // Return error code
//    }
//
//    size_t written = fwrite((*bookingManager).bookings, sizeof(Booking), (*bookingManager).numBookings, file);
//
//    if (written != (*bookingManager).numBookings) {
//        printf("Error writing data to file %s\n", bookingname);
//        fclose(file);
//        return -2;  // Return different error code
//    }
//
//    fclose(file);
//    return 0;  // Return 0 on success
//}
//
//
//int loadBookingsFromFile(const char* bookingname, BookingManager* bookingManager) {
//    FILE* file = fopen(bookingname, "rb");
//    if (file == NULL) {
//        printf("Error opening file %s\n", bookingname);
//        return -1;
//    }
//
//    int index = 0;
//    while (fread(&(*bookingManager).bookings[index], sizeof(Booking), 1, file) == 1) {
//        index++;
//    }
//
//
//    (*bookingManager).numBookings = index;
//
//    fclose(file);
//    return 0;
//}
//
//double getFare(const ScheduleManager* scheduleManager, const char* trainID) {
//    for (int i = 0; i < (*scheduleManager).numSchedules; i++) {
//        if (strcmp((*scheduleManager).schedules[i].trainId, trainID) == 0) {
//            return (*scheduleManager).schedules[i].fare;
//        }
//    }
//    return -1.0;
//}
//
//bool isSeatBooked(int row, int column, const char* trainID, const BookingManager* bookingManager) {
//    for (int i = 0; i < (*bookingManager).numBookings; i++) {
//        if (strcmp((*bookingManager).bookings[i].trainID, trainID) == 0) {
//            int quantity = (*bookingManager).bookings[i].quantity[0];
//            for (int j = 0; j < quantity; j++) {
//                if ((*bookingManager).bookings[i].seatNumberRow[j] == row && (*bookingManager).bookings[i].seatNumberColumn[j] == column) {
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//int is_leap_year(int year) {
//    if (year % 400 == 0) return 1;
//    if (year % 100 == 0) return 0;
//    if (year % 4 == 0) return 1;
//    return 0;
//}
//
//int is_valid_date(const char* date) {
//    int day, month, year;
//
//    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
//        return 0;
//    }
//
//    if (year < 1900 || year > 2100) {
//        return 0;
//    }
//
//    if (month < 1 || month > 12) {
//        return 0;
//    }
//
//    if (day < 1 || day > 31) {
//        return 0;
//    }
//
//    switch (month) {
//    case 2:
//        if (is_leap_year(year)) {
//            if (day > 29) {
//                return 0;
//            }
//        }
//        else {
//            if (day > 28) {
//                return 0;
//            }
//        }
//        break;
//    case 4:
//    case 6:
//    case 9:
//    case 11:
//        if (day > 30) {
//            return 0;
//        }
//        break;
//    default:
//        if (day > 31) {
//            return 0;
//        }
//        break;
//    }
//
//    return 1;
//}
//
//void DisplaySeats() { //Function to display seats layout
//    int Seats[40][4] = { 0 };
//    int row, col;
//    printf("\t \t Seats\n");
//    printf("-----------------------------------------\n\n");
//    printf("\t  1  2  3  4\n");
//
//    for (row = 0; row < 40; row++)
//    {
//        printf("Rows %2d : ", row + 1);
//        for (col = 0; col < 4; col++)
//            printf("%d  ", Seats[row][col]);
//        printf("\n");
//    }
//    printf("\n");
//
//}
//
//void TicketAdd(BookingManager* bookingManager, const ScheduleManager* scheduleManager) {
//    printf("Enter member ID: ");
//    scanf("%s", (*bookingManager).bookings[(*bookingManager).numBookings].memberID);
//
//    char trainID[10];
//    int found = 0;
//
//    do {
//        printf("Enter train ID: ");
//        scanf("%s", trainID);
//
//        double fare = getFare(scheduleManager, trainID);
//        if (fare == -1.0) {
//            printf("Train ID %s does not exist. Please try again.\n", trainID);
//        }
//        else {
//            found = 1;
//            strcpy((*bookingManager).bookings[(*bookingManager).numBookings].trainID, trainID);
//            printf("Fare for train ID %s is %.2f\n", trainID, fare);
//            (*bookingManager).bookings[(*bookingManager).numBookings].amount = fare;
//        }
//    } while (!found);
//
//    printf("Enter booking date (dd/mm/yyyy): ");
//    char bookingDate[12];
//    do {
//        scanf("%s", bookingDate);
//        if (!is_valid_date(bookingDate)) {
//            printf("Invalid date, please re-enter (dd/mm/yyyy): ");
//        }
//    } while (!is_valid_date(bookingDate));
//    strcpy((*bookingManager).bookings[(*bookingManager).numBookings].bookingDate, bookingDate);
//
//    printf("Enter departure date (dd/mm/yyyy): ");
//    char departureDate[12];
//    do {
//        scanf("%s", departureDate);
//        if (!is_valid_date(departureDate)) {
//            printf("Invalid date, please re-enter (dd/mm/yyyy): ");
//        }
//    } while (!is_valid_date(departureDate));
//    strcpy((*bookingManager).bookings[(*bookingManager).numBookings].departureDate, departureDate);
//
//    printf("Enter quantity: ");
//    int c;
//    while ((c = getchar()) != '\n' && c != EOF);
//    scanf("%d", &(*bookingManager).bookings[(*bookingManager).numBookings].quantity[0]);
//
//    printf("Enter payment type (CASH/PAYLATER): ");
//    while ((c = getchar()) != '\n' && c != EOF);
//    char paymentType[20];
//    do {
//        scanf("%s", paymentType);
//        if (strcmp(paymentType, "CASH") != 0 && strcmp(paymentType, "PAYLATER") != 0) {
//            printf("Invalid payment type. Please enter CASH or PAYLATER: ");
//        }
//    } while (strcmp(paymentType, "CASH") != 0 && strcmp(paymentType, "PAYLATER") != 0);
//    strcpy((*bookingManager).bookings[(*bookingManager).numBookings].paymentInfo, paymentType);
//
//    for (int i = 0; i < (*bookingManager).bookings[(*bookingManager).numBookings].quantity[0]; i++) {
//        int row, column;
//        bool seatAlreadyBooked;
//        DisplaySeats();
//        do {
//            printf("Enter seat number %d (row column): ", i + 1);
//            scanf("%d %d", &row, &column);
//            while (row > 40 || column > 4) {
//                printf("Invalid Seat. Please select again :");
//                scanf("%d %d", &row, &column);
//            }
//
//            seatAlreadyBooked = isSeatBooked(row, column, (*bookingManager).bookings[(*bookingManager).numBookings].trainID, bookingManager, (*bookingManager).numBookings);
//
//            if (seatAlreadyBooked) {
//                printf("Seat %d-%d is already booked for the same train ID. Please choose another seat.\n", row, column);
//            }
//        } while (seatAlreadyBooked);
//
//        (*bookingManager).bookings[(*bookingManager).numBookings].seatNumberRow[i] = row;
//        (*bookingManager).bookings[(*bookingManager).numBookings].seatNumberColumn[i] = column;
//    }
//
//    (*bookingManager).bookings[(*bookingManager).numBookings].amount *= (*bookingManager).bookings[(*bookingManager).numBookings].quantity[0];
//
//    int randomID;
//    do {
//        randomID = rand() % 9000 + 1000;
//        sprintf((*bookingManager).bookings[(*bookingManager).numBookings].bookingID, "B%d", randomID);
//    } while (!isUniqueID((*bookingManager).bookings[(*bookingManager).numBookings].bookingID, bookingManager, (*bookingManager).numBookings));
//
//    printf("\nBooking successful! Your booking ID is %s\n", (*bookingManager).bookings[(*bookingManager).numBookings].bookingID);
//
//    (*bookingManager).numBookings++;
//}
//
//int isUniqueID(const char* id, Booking* bookings, int numBookings) {
//    for (int i = 0; i < numBookings; i++) {
//        if (strcmp(id, bookings[i].bookingID) == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//void TicketDisplay(const char* memberID, BookingManager* bookingManager) {
//    printf("Displaying bookings for member ID: %s\n", memberID);
//    printf("Booking ID\tMember ID\tTrain ID\tBooking Date\tDeparture Date\tSeat\t\tQuantity\tPayment Info\tAmount\n");
//
//    int found = 0;
//
//    for (int i = 0; i < (*bookingManager).numBookings; i++) {
//        Booking currentBooking = (*bookingManager).bookings[i];
//        if (strcmp(currentBooking.memberID, memberID) == 0) {
//            printf("%s\t\t%s\t\t%s\t\t%s\t%s\t", currentBooking.bookingID, currentBooking.memberID, currentBooking.trainID,
//                currentBooking.bookingDate, currentBooking.departureDate);
//            printf("%d-%d", currentBooking.seatNumberRow[0], currentBooking.seatNumberColumn[0]);
//
//            for (int j = 1; j < currentBooking.quantity[0]; j++) {
//                printf(", %d-%d", currentBooking.seatNumberRow[j], currentBooking.seatNumberColumn[j]);
//            }
//
//            printf("\t%d \t\t%-8s \t%-10.2lf\n", currentBooking.quantity[0], currentBooking.paymentInfo, currentBooking.amount);
//            found = 1;
//        }
//    }
//
//    if (!found) {
//        printf("No bookings found for member ID: %s\n", memberID);
//    }
//}
//
//void TicketAskForDisplay(BookingManager* bookingManager) {
//    char memberID[20];
//    printf("Enter your member ID: ");
//    scanf("%19s", memberID);
//    TicketDisplay(memberID, bookingManager);
//
//}
//
////Ticket Search Function
//void TicketSearch(Booking* bookings, int numBookings, const char* bookingID) {
//    int found = 0;
//    for (int i = 0; i < numBookings; i++) {
//        if (strcmp(bookings[i].bookingID, bookingID) == 0) {
//            printf("==========================================\n");
//            printf("Booking ID: %s\n", bookings[i].bookingID);
//            printf("Member ID: %s\n", bookings[i].memberID);
//            printf("Train ID: %s\n", bookings[i].trainID);
//            printf("Booking Date: %s\n", bookings[i].bookingDate);
//            printf("Departure Date: %s\n", bookings[i].departureDate);
//            printf("Seat: ");
//            printf("%d-%d", bookings[i].seatNumberRow[0], bookings[i].seatNumberColumn[0]);
//            for (int j = 1; j < bookings[i].quantity[0]; j++) {
//                printf(", %d-%d", bookings[i].seatNumberRow[j], bookings[i].seatNumberColumn[j]);
//            }
//            printf("\n");
//            printf("Quantity: %d\n", bookings[i].quantity[0]);
//            printf("Payment Info: %s\n", bookings[i].paymentInfo);
//            printf("Amount: RM%.2lf\n", bookings[i].amount);
//            printf("==========================================\n");
//            found = 1;
//            break;
//        }
//    }
//    if (!found) {
//        printf("Booking with ID %s not found.\n", bookingID);
//    }
//}
//
//void TicketCancel(Booking* bookings, int* numBookings, const char* bookingID, ScheduleManager* scheduleManager) {
//    int found = 0;
//    for (int i = 0; i < *numBookings; i++) {
//        if (strcmp(bookings[i].bookingID, bookingID) == 0) {
//            found = 1;
//            printf("Booking ID: %s\n", bookings[i].bookingID);
//            printf("Current quantity: %d\n", bookings[i].quantity[0]);
//            printf("Enter the seat numbers you want to cancel : ");
//            int seatRow, seatColumn;
//            scanf("%d %d", &seatRow, &seatColumn);
//
//            int seatIndex = -1;
//            for (int j = 0; j < bookings[i].quantity[0]; j++) {
//                if (bookings[i].seatNumberRow[j] == seatRow && bookings[i].seatNumberColumn[j] == seatColumn) {
//                    seatIndex = j;
//                    break;
//                }
//            }
//
//            if (seatIndex == -1) {
//                printf("The seat number you entered does not exist in the booking.\n");
//                return;
//            }
//
//            for (int j = seatIndex; j < bookings[i].quantity[0] - 1; j++) {
//                bookings[i].seatNumberRow[j] = bookings[i].seatNumberRow[j + 1];
//                bookings[i].seatNumberColumn[j] = bookings[i].seatNumberColumn[j + 1];
//            }
//
//            bookings[i].quantity[0]--;
//
//            double fare = getFare(scheduleManager, bookings[i].trainID);
//            bookings[i].amount = bookings[i].quantity[0] * fare;
//
//            printf("Successfully cancelled seat at row %d, column %d. New quantity: %d\n", seatRow, seatColumn, bookings[i].quantity[0]);
//            printf("Please claim your refund at counter.\n");
//
//            if (bookings[i].quantity[0] == 0) {
//                for (int j = i; j < *numBookings - 1; j++) {
//                    bookings[j] = bookings[j + 1];
//                }
//                (*numBookings)--;
//                printf("Booking with ID %s has been fully cancelled.\n", bookingID);
//            }
//
//            break;
//        }
//    }
//    if (!found) {
//        printf("Booking with ID %s not found.\n", bookingID);
//    }
//}
//
////To find the booking id
//Booking* getBookingByID(Booking* bookings, int numBookings, const char* bookingID) {
//    for (int i = 0; i < numBookings; i++) {
//        if (strcmp(bookings[i].bookingID, bookingID) == 0) {
//            return &bookings[i];
//        }
//    }
//    return NULL;
//}
//
//// askForNewQuantity function
//void askForNewQuantity(Booking* booking, const ScheduleManager* scheduleManager) {
//    printf("Enter new quantity: ");
//    scanf("%d", &(*booking).quantity[0]);
//    (*booking).amount = getFare(scheduleManager, (*booking).trainID) * (*booking).quantity[0];
//}
//
//// askForNewSeatNumbers function
//void askForNewSeatNumbers(Booking* booking, const ScheduleManager* scheduleManager, Booking* bookings, int numBookings, bool (*isSeatBookedFunc)(int, int, const char*, Booking*, int)) {
//    for (int i = 0; i < (*booking).quantity[0]; i++) {
//        int row, column;
//        bool seatAlreadyBooked;
//
//        do {
//            printf("Enter seat number %d (row column): ", i + 1);
//            scanf("%d %d", &row, &column);
//            while (row > 40 || column > 4) {
//                printf("Invalid Seat. Please select again :");
//                scanf("%d %d", &row, &column);
//            }
//
//
//            seatAlreadyBooked = isSeatBookedFunc(row, column, (*booking).trainID, bookings, numBookings);
//
//            if (seatAlreadyBooked) {
//                printf("Seat %d-%d is already booked for the same train ID. Please choose another seat.\n", row, column);
//            }
//        } while (seatAlreadyBooked);
//
//        (*booking).seatNumberRow[i] = row;
//        (*booking).seatNumberColumn[i] = column;
//    }
//}
//
//void TicketModify(Booking* bookings, int numBookings, const char* bookingID, BookingManager* bookingManager, ScheduleManager* scheduleManager) {
//    Booking* booking = getBookingByID(bookings, numBookings, bookingID);
//    if (booking == NULL) {
//        printf("Booking with ID %s not found.\n", bookingID);
//        return;
//    }
//
//    char newTrainID[10];
//    double fare;
//    do {
//        printf("Enter new train ID: ");
//        scanf("%s", newTrainID);
//
//        fare = getFare(scheduleManager, newTrainID);
//        if (fare == -1.0) {
//            printf("Train ID %s does not exist. Please try again.\n", newTrainID);
//        }
//    } while (fare == -1.0);
//
//    strcpy((*booking).trainID, newTrainID);
//    printf("Fare for train ID %s is %.2f\n", newTrainID, fare);
//    (*booking).amount = fare * (*booking).quantity[0];
//
//    askForNewQuantity(booking, scheduleManager);
//    askForNewSeatNumbers(booking, scheduleManager, bookings, numBookings, isSeatBooked);
//
//    printf("Booking successfully modified for ID %s.\n", bookingID);
//}
//
//void TicketReceipt(const Booking* booking) {
//    printf("================================================================\n");
//    printf("                        Booking Receipt\n");
//    printf("================================================================\n");
//
//    if (strcmp((*booking).paymentInfo, "PAYLATER") == 0) {
//        printf("You have not paid RM%.2lf, please pay at the counter first.\n", (*booking).amount);
//    }
//    else if (strcmp((*booking).paymentInfo, "CASH") == 0) {
//        printf("Booking ID:        %s\n", (*booking).bookingID);
//        printf("Member ID:         %s\n", (*booking).memberID);
//        printf("Train ID:          %s\n", (*booking).trainID);
//        printf("Booking Date:      %s\n", (*booking).bookingDate);
//        printf("Departure Date:    %s\n", (*booking).departureDate);
//        printf("----------------------------------------------------------------\n");
//        printf("Seat Numbers:\n");
//        for (int i = 0; i < (*booking).quantity[0]; i++) {
//            printf("                   %d-%d\n", (*booking).seatNumberRow[i], (*booking).seatNumberColumn[i]);
//        }
//        printf("----------------------------------------------------------------\n");
//        printf("Quantity:          %d\n", (*booking).quantity[0]);
//        printf("Payment Info:      %s\n", (*booking).paymentInfo);
//        printf("Amount:            RM%.2lf\n", (*booking).amount);
//        printf("================================================================\n");
//        printf("Thank you for choosing our service!\n");
//    }
//    else {
//        printf("Invalid payment method detected.\n");
//    }
//
//    printf("================================================================\n");
//}
//
//int main() {
//    // Initialize managers
//    BookingManager bookingManager = { 0 };
//    ScheduleManager scheduleManager = { 0 };
//
//    // Load data
//    loadSchedules(&scheduleManager, "trainschedule.txt");
//    srand(time(NULL));
//
//    // Load bookings from file
//    int loadResult = loadBookingsFromFile("bookings.bin", &bookingManager);
//    if (loadResult != 0) {
//        printf("Error loading bookings from file\n");
//        return loadResult;
//    }
//
//    int choice = 0;
//    do {
//        printf("=====================\n");
//        printf("   Ticket Booking    \n");
//        printf("=====================\n");
//        printf("1. Add Booking\n");
//        printf("2. Display Bookings\n");
//        printf("3. Search Booking\n");
//        printf("4. Cancel Booking\n");
//        printf("5. Modify Booking\n");
//        printf("6. Generate Receipt\n");
//        printf("7. Exit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            TicketAdd(&bookingManager, &scheduleManager);
//            break;
//        case 2:
//            TicketAskForDisplay(&bookingManager);
//            break;
//        case 3:
//        {
//            char bookingID[10];
//            printf("Enter Booking ID: ");
//            scanf("%s", bookingID);
//            TicketSearch(bookingManager.bookings, bookingManager.numBookings, bookingID);
//
//        }
//        break;
//        case 4:
//        {
//            char bookingID[10];
//            printf("Enter Booking ID to cancel: ");
//            scanf("%s", bookingID);
//            TicketCancel(bookingManager.bookings, &bookingManager.numBookings, bookingID, &scheduleManager);
//
//        }
//        break;
//        case 5:
//        {
//            char bookingID[10];
//            printf("Enter Booking ID to modify: ");
//            scanf("%s", bookingID);
//            TicketModify(bookingManager.bookings, bookingManager.numBookings, bookingID, &bookingManager, &scheduleManager);
//
//        }
//        break;
//        case 6:
//        {
//            char bookingID[10];
//            printf("Enter Booking ID to generate receipt: ");
//            scanf("%s", bookingID);
//            Booking* booking = getBookingByID(bookingManager.bookings, bookingManager.numBookings, bookingID);
//            if (booking != NULL) {
//                TicketReceipt(booking);
//            }
//            else {
//                printf("Booking with ID %s not found.\n", bookingID);
//            }
//        }
//        break;
//        case 7:
//            saveBookingsToFile("bookings.bin", &bookingManager);
//            printf("Exiting...\n");
//            break;
//        default:
//            printf("Invalid choice. Please try again.\n");
//            break;
//        }
//    } while (choice != 7);
//
//    return 0;
//}
