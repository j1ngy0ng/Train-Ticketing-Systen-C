//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning(disable:4996)
//#define MAX_BOOKINGS 80 //From TicketBookingModule
//
//typedef struct { //Structure for storing date and time
//	char departureDate[12];
//	char departureTime[5];
//	char arrivalTime[5];
//}DateTime;
//
//
//typedef struct { //Structure for storing schedule information
//	int number;
//	char trainId[10];
//	char departureLocation[30];
//	char destination[30];
//	DateTime dateTime[200];
//	double fare;
//	int distance;
//	double duration;
//	int availableSeats;
//  char id[6];
//}Schedule;
//
//typedef struct { //From TicketBookingModule
//	char bookingID[10];
//	char memberID[10];
//	char trainID[10];
//	char bookingDate[12];
//	char departureDate[12];
//	int seatNumberRow[40];
//	int seatNumberColumn[40];
//	int quantity[10];
//	char paymentInfo[100];
//	double amount;
//	char staffID[7];
//} Booking;
//
//void TrainSchedulingAdd(Schedule schedule[], int* numOfSchedule, char id[]) { // Function to add a train schedule
//	int action;
//	FILE* add;
//	add = fopen("trainschedule.txt", "a"); //Open file for appending
//	if (add == NULL) {
//		printf("Unable to open file!!");
//		exit(-1);
//	}
//
//	do {  //Prompt and input data for each field of the schedule
//		printf("Enter Train ID :");
//		rewind(stdin);
//		scanf("%s", schedule[*numOfSchedule].trainId);
//		printf("Enter Departure Location :");
//		rewind(stdin);
//		scanf("%[^\n]", schedule[*numOfSchedule].departureLocation);
//		printf("Enter Destination :");
//		rewind(stdin);
//		scanf("%[^\n]", schedule[*numOfSchedule].destination);
//		printf("Enter Departure Date :");
//		rewind(stdin);
//		scanf("%s", schedule[*numOfSchedule].dateTime[*numOfSchedule].departureDate);
//		printf("Enter Departure Time :");
//		rewind(stdin);
//		scanf("%s", schedule[*numOfSchedule].dateTime[*numOfSchedule].departureTime);
//		printf("Enter Arrival Time :");
//		rewind(stdin);
//		scanf("%s", schedule[*numOfSchedule].dateTime[*numOfSchedule].arrivalTime);
//		printf("Enter Fare :");
//		rewind(stdin);
//		scanf("%lf", &schedule[*numOfSchedule].fare);
//		printf("Enter Distance(km) :");
//		rewind(stdin);
//		scanf("%d", &schedule[*numOfSchedule].distance);
//		printf("Enter Duration(hours) :");
//		rewind(stdin);
//		scanf("%lf", &schedule[*numOfSchedule].duration);
//		printf("Enter Available Seats :");
//		rewind(stdin);
//		scanf("%d", &schedule[*numOfSchedule].availableSeats);
//
//		 //Write schedule information to file
//		fprintf(add, "\n%d|%s|%s|%s|%s|%s|%s|%.2f|%d|%.2f|%d|%s", *numOfSchedule + 1, schedule[*numOfSchedule].trainId, schedule[*numOfSchedule].departureLocation,
//			schedule[*numOfSchedule].destination, schedule[*numOfSchedule].dateTime[*numOfSchedule].departureDate, schedule[*numOfSchedule].dateTime[*numOfSchedule].departureTime,
//			schedule[*numOfSchedule].dateTime[*numOfSchedule].arrivalTime, schedule[*numOfSchedule].fare, schedule[*numOfSchedule].distance, schedule[*numOfSchedule].duration,
//			schedule[*numOfSchedule].availableSeats, id);
//		printf("Schedule added succesfully!\n");
//
//		(*numOfSchedule)++;
//
//		printf("Select 1 to add another schedule (any character to go back to PREVIOUS SECTION) : ");
//		rewind(stdin);
//		scanf("%d", &action);
//	} while (action == 1);
//	fclose(add);
//}
//
//void TrainSchedulingSearch(Schedule schedule[], int* numOfSchedule, char id[]) { //Function to search for train schedules
//	char from[50], to[50];
//
//	printf("Enter Departure Destination : ");
//	rewind(stdin);
//	scanf("%[^\n]", from);
//	printf("Enter Arrival Destination : ");
//	rewind(stdin);
//	scanf("%[^\n]", to);
//
//	printf("%-5s\t%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-7s\t%-10s\t%-15s\t%-10s\t%s\n",
//		"No", "Train ID", "Departure Location", "Destination",
//		"Departure Date", "Departure Time", "Arrival Time", "Fare", "Distance",
//		"Duration", "Available Seats", "StaffID");
//	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//
//	for (int n = 0; n < *numOfSchedule; n++) { //Compare with data stored in structure array
//
//		if (strcmp(schedule[n].departureLocation, from) == 0 && strcmp(schedule[n].destination, to) == 0) {
//			printf("%-5d\t%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-7.2f\t%-10d\t%-15.2f\t%-10d\t%-5s\n",
//				schedule[n].number, schedule[n].trainId, schedule[n].departureLocation,
//				schedule[n].destination, schedule[n].dateTime[n].departureDate, schedule[n].dateTime[n].departureTime,
//				schedule[n].dateTime[n].arrivalTime, schedule[n].fare, schedule[n].distance,
//				schedule[n].duration, schedule[n].availableSeats, schedule[n].id);
//		}
//
//	}
//
//}
//
//void TrainSchedulingModify(Schedule schedule[], int* numOfSchedule, char id[]) { //Function to modify a train schedule
//	int no;
//	int foundIndex = -1;
//
//	printf("\nWhich NO of Schedule to modify? ");
//	rewind(stdin);
//	scanf("%d", &no);
//
//	for (int n = 0; n < *numOfSchedule; n++) { //Search for that particular schedule
//		if (schedule[n].number == no) {
//			foundIndex = n;
//			break;
//		}
//	}
//
//
//	if (foundIndex != -1) {
//		printf("Enter Train ID :");
//		rewind(stdin);
//		scanf("%s", schedule[foundIndex].trainId);
//		printf("Enter Departure Location :");
//		rewind(stdin);
//		scanf("%[^\n]", schedule[foundIndex].departureLocation);
//		printf("Enter Destination :");
//		rewind(stdin);
//		scanf("%[^\n]", schedule[foundIndex].destination);
//		printf("Enter Departure Date :");
//		rewind(stdin);
//		scanf("%s", schedule[foundIndex].dateTime[foundIndex].departureDate);
//		printf("Enter Departure Time :");
//		rewind(stdin);
//		scanf("%s", schedule[foundIndex].dateTime[foundIndex].departureTime);
//		printf("Enter Arrival Time :");
//		rewind(stdin);
//		scanf("%s", schedule[foundIndex].dateTime[foundIndex].arrivalTime);
//		printf("Enter Fare :");
//		rewind(stdin);
//		scanf("%lf", &schedule[foundIndex].fare);
//		printf("Enter Distance(km) :");
//		rewind(stdin);
//		scanf("%d", &schedule[foundIndex].distance);
//		printf("Enter Duration(hours) :");
//		rewind(stdin);
//		scanf("%lf", &schedule[foundIndex].duration);
//		printf("Enter Available Seats :");
//		rewind(stdin);
//		scanf("%d", &schedule[foundIndex].availableSeats);
//		strcmp(schedule[foundIndex].id, id);
//
//		printf("Schedule modified successfully!\n");
//	}
//	else {
//		printf("Schedule with number %d not found.\n", no);
//	}
//
//
//
//	FILE* modify;
//	modify = fopen("trainschedule.txt", "w");
//	if (modify == NULL) {
//		printf("Unable to open FILE!!\n");
//
//		exit(-1);
//	}
//
//	for (int n = 0; n < *numOfSchedule; n++) {
//
//		fprintf(modify, "%d|%s|%s|%s|%s|%s|%s|%.2f|%d|%.2f|%d|%s\n", schedule[n].number, schedule[n].trainId, schedule[n].departureLocation,
//			schedule[n].destination, schedule[n].dateTime[n].departureDate, schedule[n].dateTime[n].departureTime,
//			schedule[n].dateTime[n].arrivalTime, schedule[n].fare, schedule[n].distance, schedule[n].duration,
//			schedule[n].availableSeats, schedule[n].id);
//	}
//
//	fclose(modify);
//}
//
//void TrainSchedulingDisplay(Schedule schedule[], int* numOfSchedule, char id[]) { //Function to display all train schedules
//
//	printf("%-5s\t%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-7s\t%-10s\t%-15s\t%-10s\t%s\n",
//		"No", "Train ID", "Departure Location", "Destination",
//		"Departure Date", "Departure Time", "Arrival Time", "Fare", "Distance",
//		"Duration", "Available Seats", "StaffID");
//	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//
//	for (int n = 0; n < *numOfSchedule; n++) { //Print out all the data stored in structure array
//		printf("%-5d\t%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-7.2f\t%-10d\t%-15.2f\t%-10d\t%-5s\n",
//			schedule[n].number, schedule[n].trainId, schedule[n].departureLocation,
//			schedule[n].destination, schedule[n].dateTime[n].departureDate, schedule[n].dateTime[n].departureTime,
//			schedule[n].dateTime[n].arrivalTime, schedule[n].fare, schedule[n].distance,
//			schedule[n].duration, schedule[n].availableSeats, schedule[n].id);
//	}
//}
//
//void TrainSchedulingDelete(Schedule schedule[], int* numOfSchedule, char id[]) { //Function to delete a train schedule
//	Booking trainScheduleCompare[MAX_BOOKINGS];
//	FILE* file = fopen("bookings.bin", "rb");
//	if (file == NULL) {
//		printf("Error opening file\n");
//		return;
//	}
//
//	int index = 0;
//	while (fread(&trainScheduleCompare[index], sizeof(Booking), 1, file) == 1) {
//		index++;
//	}
//
//	int deleteNo;
//	printf("Enter the schedule number you want to delete: ");
//	scanf("%d", &deleteNo);
//
//	int foundIndex = -1;
//	for (int n = 0; n < *numOfSchedule; n++) {
//		if (schedule[n].number == deleteNo) {
//			foundIndex = n;
//			break;
//		}
//	}
//
//	// Check if the schedule has bookings
//	for (int i = 0; i < index; i++) {
//		if (strcmp(trainScheduleCompare[i].trainID, schedule[foundIndex].trainId) == 0) {
//			printf("Schedule has bookings. Cannot delete!\n");
//			return;
//		}
//	}
//
//	if (foundIndex != -1) {
//		for (int n = foundIndex; n < (*numOfSchedule - 1); n++) { //Move all the schedules one step forward after the deleted schedule  
//			strcpy(schedule[n].trainId, schedule[n + 1].trainId);
//			strcpy(schedule[n].departureLocation, schedule[n + 1].departureLocation);
//			strcpy(schedule[n].destination, schedule[n + 1].destination);
//			strcpy(schedule[n].dateTime[n].departureDate, schedule[n + 1].dateTime[n + 1].departureDate);
//			strcpy(schedule[n].dateTime[n].departureTime, schedule[n + 1].dateTime[n + 1].departureTime);
//			strcpy(schedule[n].dateTime[n].arrivalTime, schedule[n + 1].dateTime[n + 1].arrivalTime);
//			schedule[n].fare = schedule[n + 1].fare;
//			schedule[n].distance = schedule[n + 1].distance;
//			schedule[n].duration = schedule[n + 1].duration;
//			schedule[n].availableSeats = schedule[n + 1].availableSeats;
//			strcpy(schedule[n].id, schedule[n + 1].id);
//		}
//
//		(*numOfSchedule)--;
//
//		printf("Schedule %d deleted successfully.\n", deleteNo);
//
//		FILE* delete;
//		delete = fopen("trainschedule.txt", "w");
//		if (delete == NULL) {
//			printf("Unable to open FILE!!\n");
//			return;
//		}
//
//		for (int n = 0; n < *numOfSchedule; n++) { //Write the changed schedule information into file
//			fprintf(delete, "%d|%s|%s|%s|%s|%s|%s|%.2f|%d|%.2f|%d|%s\n", schedule[n].number, schedule[n].trainId, schedule[n].departureLocation,
//				schedule[n].destination, schedule[n].dateTime[n].departureDate, schedule[n].dateTime[n].departureTime,
//				schedule[n].dateTime[n].arrivalTime, schedule[n].fare, schedule[n].distance, schedule[n].duration,
//				schedule[n].availableSeats, schedule[n].id);
//		}
//
//		fclose(delete);
//	}
//	else {
//		printf("Schedule with number %d not found.\n", deleteNo);
//	}
//}
//
//void TrainSchedulingMaintenance(Schedule schedule[], int* numOfSchedule, char id[]) { //Function to perform maintenance on a train schedule
//
//	Booking trainScheduleCompare[MAX_BOOKINGS];
//	FILE* file = fopen("bookings.bin", "rb");
//	if (file == NULL) {
//		printf("Error opening file\n");
//		return;
//	}
//
//	int index = 0;
//	while (fread(&trainScheduleCompare[index], sizeof(Booking), 1, file) == 1) {
//		index++;
//	}
//
//	int action, no, foundIndex = -1;
//
//	printf("\n\n1. Under Maintenance\n");
//	printf("2. Maintenance Completed\n");
//	printf("Action to be taken :");
//	scanf("%d", &action);
//	while (action != 1 && action != 2) {
//		printf("Invalid action. Please Re-enter :");
//		scanf("%d", &action);
//	}
//
//	if (action == 1) {
//		printf("Enter Schedule Number :");
//		scanf("%d", &no);
//
//		for (int n = 0; n < *numOfSchedule; n++) {
//			if (schedule[n].number == no) {
//				foundIndex = n;
//				break;
//			}
//		}
//
//		// Check if the schedule has bookings
//		for (int i = 0; i < index; i++) {
//			if (strcmp(trainScheduleCompare[i].trainID, schedule[foundIndex].trainId) == 0) {
//				printf("Schedule has bookings. Cannot be under MAINTENANCE!\n");
//				return;
//			}
//		}
//
//		if (foundIndex != -1) {
//			strcpy(schedule[foundIndex].departureLocation, "Under Maintenance");
//			strcpy(schedule[foundIndex].destination, "Under Maintenance");
//			strcpy(schedule[foundIndex].id, id);
//			printf("Schedule Under Maintenance!\n");
//		}
//		else {
//			printf("Schedule with number %d not found.\n", no);
//		}
//	}
//
//	else {
//		printf("Enter Schedule Number :");
//		scanf("%d", &no);
//		for (int n = 0; n < *numOfSchedule; n++) {
//			if (schedule[n].number == no) {
//				foundIndex = n;
//				break;
//			}
//		}
//
//
//		if (foundIndex != -1) {
//			printf("Enter Departure Location :");
//			rewind(stdin);
//			scanf("%[^\n]", schedule[foundIndex].departureLocation);
//			printf("Enter Destination :");
//			rewind(stdin);
//			scanf("%[^\n]", schedule[foundIndex].destination);
//			strcpy(schedule[foundIndex].id, id);
//			printf("Schedule Maintenance Completed!\n");
//		}
//		else {
//			printf("Schedule with number %d not found.\n", no);
//		}
//	}
//
//	FILE* write;
//	write = fopen("trainschedule.txt", "w");
//	if (write == NULL) {
//		printf("Unable to open FILE!!\n");
//		exit(-1);
//	}
//
//	for (int n = 0; n < *numOfSchedule; n++) { //Write back the changed information into file
//
//		fprintf(write, "%d|%s|%s|%s|%s|%s|%s|%.2f|%d|%.2f|%d|%s\n", schedule[n].number, schedule[n].trainId, schedule[n].departureLocation,
//			schedule[n].destination, schedule[n].dateTime[n].departureDate, schedule[n].dateTime[n].departureTime,
//			schedule[n].dateTime[n].arrivalTime, schedule[n].fare, schedule[n].distance, schedule[n].duration,
//			schedule[n].availableSeats, schedule[n].id);
//	}
//
//	fclose(write);
//}
//
//void DisplaySeats() { //Function to display seats layout
//	int Seats[40][4] = { 0 };
//	int row, col;
//	printf("\t \t Seats\n");
//	printf("-----------------------------------------\n\n");
//	printf("\t  1  2  3  4\n");
//
//	for (row = 0; row < 40; row++)
//	{
//		printf("Rows %2d : ", row + 1);
//		for (col = 0; col < 4; col++)
//			printf("%d  ", Seats[row][col]);
//		printf("\n");
//	}
//	printf("\n");
//
//}
//
//int TrainSchedulingMenu(char id[]) { //Function for the train scheduling menu
//	int action;
//	do {
//	Schedule schedule[200] = { "" };
//	FILE* scan;
//	scan = fopen("trainschedule.txt", "r");
//	int numOfSchedule = 0;
//	if (scan == NULL) {
//		printf("Unable to open FILE!!");
//		exit(-1);
//	}
//
//	while (!feof(scan)) {
//		fscanf(scan, "%d|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%d|%lf|%d|%s\n", &schedule[numOfSchedule].number, schedule[numOfSchedule].trainId,
//			schedule[numOfSchedule].departureLocation, schedule[numOfSchedule].destination, schedule[numOfSchedule].dateTime[numOfSchedule].departureDate,
//			schedule[numOfSchedule].dateTime[numOfSchedule].departureTime, schedule[numOfSchedule].dateTime[numOfSchedule].arrivalTime,
//			&schedule[numOfSchedule].fare, &schedule[numOfSchedule].distance,
//			&schedule[numOfSchedule].duration, &schedule[numOfSchedule].availableSeats, schedule[numOfSchedule].id);
//
//		numOfSchedule++;
//	}
//
//	fclose(scan);
//	
//		printf("\n");
//		printf("\t***************************************\n");
//		printf("\t*                                     *\n");
//		printf("\t*           Train Scheduling          *\n");
//		printf("\t*                                     *\n");
//		printf("\t***************************************\n");
//		printf("\n");
//
//		printf("1. ADD schedule\n");
//		printf("2. SEARCH schedule\n");
//		printf("3. MODIFY schedule\n");
//		printf("4. DISPLAY schedule\n");
//		printf("5. DELETE schedule\n");
//		printf("6. MAINTENANCE schedule\n");
//		printf("7. DISPLAY SEATS\n");
//		printf("0. BACK TO PREVIOUS PAGE\n");
//		printf("\nSelect 0-7 : \n");
//		rewind(stdin);
//		scanf("%d", &action);
//		while (action < 0 || action > 7) {
//			printf("ERROR! Please Select 0-7 only : ");
//			scanf("%d", &action);
//		}
//
//		if (action == 1)
//			TrainSchedulingAdd(schedule, &numOfSchedule, id);
//		else if (action == 2)
//			TrainSchedulingSearch(schedule, &numOfSchedule, id);
//		else if (action == 3) {
//			TrainSchedulingDisplay(schedule, &numOfSchedule, id);
//			TrainSchedulingModify(schedule, &numOfSchedule, id);
//		}
//		else if (action == 4)
//			TrainSchedulingDisplay(schedule, &numOfSchedule, id);
//		else if (action == 5) {
//			TrainSchedulingDisplay(schedule, &numOfSchedule, id);
//			TrainSchedulingDelete(schedule, &numOfSchedule, id);
//		}
//		else if (action == 6) {
//			TrainSchedulingDisplay(schedule, &numOfSchedule, id);
//			TrainSchedulingMaintenance(schedule, &numOfSchedule, id);
//		}
//		else if (action == 7) {
//			DisplaySeats();
//		}
//		else
//			return 0;
//	} while (action != 0);
//}
//
//int main() { //Main function for the train scheduling system
//	char option;
//	char id[10] = { "STF005" }; // StaffID will be taken during login.
//
//	TrainSchedulingMenu(id);
//
//	return 0;
//}