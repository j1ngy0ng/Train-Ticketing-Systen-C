//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//#pragma warning (disable:4996)
//
//typedef struct {
//    char staffID[7];
//    char name[20];
//    char gender;
//    char password[11];
//    char position[30];
//} staffInfo;
//
//typedef struct {
//    char passwordRecovery[5];
//    staffInfo info;
//}staffRecord;
//
//// Function
//int selectionStaff();
//void displayStaff();
//void addStaff();
//void searchStaff();
//void modifyStaff();
//void deleteeStaff();
//void forgotStaff();
//
////Function for validation Check
//int validateStaffId(const char* staffId);
//int validateGender(char gender);
//int validatePassword(const char* password);
//int validateName(const char* name);
//int validatePasswordRecovery(const char* recovery);
//int validatePosition(const char* position);
//
//int main() {
//    // Loop until the user chooses to exit the program
//    while (1) {
//        if (selectionStaff() == 0) {
//            break; // Exit the loop if selection returns 0
//        }
//    }
//    printf("\n=====You Have Already Exit. Have a great day!=====\n");
//    return 0;
//}
//
////This is a selection for staff when they enter staff mode
//int selectionStaff() {
//    int slt;
//
//    do {
//        printf("   ______________    ____________   _____   ____________  \n");
//        printf("  / ___/_  __/   |  / ____/ ____/  /  _/ | / / ____/ __ \\ \n");
//        printf(" \\___ \\ / / / /| | / /_  / /_      / //  |/ / /_  / / / / \n");
//        printf(" ___/ // / / ___ |/ __/ / __/    _/ // /|  / __/ / /_/ /  \n");
//        printf("/____//_/ /_/  |_/_/   /_/      /___/_/ |_/_/    \\____/   \n");
//
//        printf("\n");
//        printf("SELECT YOUR SERVE !!!\n");
//        printf("--------------------------------------------\n");
//
//        printf("1.Display\n");
//        printf("2.Add Information\n");
//        printf("3.Search Staff\n");
//        printf("4.Modify Information\n");
//        printf("5.Delete Information\n");
//        printf("6.Password Forgot\n");
//        printf("7.Exit\n");
//        printf("Enter your selection here >>>>");
//        rewind(stdin);
//        scanf("%d", &slt);
//
//        if (slt < 1 || slt > 7) {
//            printf("Invalid selection. Please enter a number between 1 and 7.\n\n");
//        }
//    } while (slt < 1 || slt > 7); // Continue looping until a valid selection is made
//
//    switch (slt) {
//    case 1:
//        system("cls");
//        displayStaff();
//        break;
//    case 2:
//        system("cls");
//        addStaff();
//        break;
//    case 3:
//        system("cls");
//        searchStaff();
//        break;
//    case 4:
//        system("cls");
//        modifyStaff();
//        break;
//    case 5:
//        system("cls");
//        deleteeStaff();
//        break;
//    case 6:
//        system("cls");
//        forgotStaff();
//        break;
//    case 7:
//        return 0;
//        break;
//    }
//}
//
////Below is the 6 different function
//void displayStaff() {
//    FILE* fptr = fopen("staff.txt", "r"); // Open the file in read mode
//    if (fptr == NULL) {
//        printf("Error opening file.\n");
//        selectionStaff(); // Return to the main loop
//        return;
//    }
//
//    staffRecord employee[100];
//
//    printf("------------------------------------------------------------------------------------------------------------------------\n");
//    printf("| %-8s | %-15s | %-2s | %-11s | %-17s | %-15s |\n", "Staff ID", "Name", "Gender", "Password", "Password Recovery", "Position");
//    printf("------------------------------------------------------------------------------------------------------------------------\n");
//
//    int i = 0;
//    while (fscanf(fptr, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^\n]\n", employee[i].info.staffID, employee[i].info.name, &employee[i].info.gender, employee[i].info.password, employee[i].passwordRecovery, employee[i].info.position) != EOF) {
//        printf("| %-8s | %-15s | %-6c | %-11s | %-17s | %-15s |\n", employee[i].info.staffID, employee[i].info.name, employee[i].info.gender, employee[i].info.password, employee[i].passwordRecovery, employee[i].info.position);
//        i++;
//    }
//
//    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
//    fclose(fptr);// Close the file
//    // Return to the main loop
//    selectionStaff();
//}
//
//void addStaff() {
//    FILE* fptr;
//    if ((fptr = fopen("staff.txt", "a")) == NULL) {
//        printf("Error opening file!");
//        exit(-1);
//    }
//
//    staffRecord new_staff;
//    char choice;
//
//    do {
//
//        // Input validation loop
//        do {
//            printf("Enter Staff Id: ");
//            scanf(" %7[^\n]", new_staff.info.staffID);
//        } while (!validateStaffId(new_staff.info.staffID)); // Repeat until valid staff ID is entered
//
//        do {
//            printf("Enter name: ");
//            scanf(" %19[^\n]", new_staff.info.name);
//        } while (!validateName(new_staff.info.name)); // Repeat until valid name is entered
//
//        do {
//            printf("Enter gender (M/F): ");
//            scanf(" %c", &new_staff.info.gender);
//        } while (!validateGender(new_staff.info.gender)); // Repeat until valid gender is entered
//
//        do {
//            printf("Enter password : ");
//            scanf("%11s", new_staff.info.password);
//        } while (!validatePassword(new_staff.info.password)); // Repeat until valid password is entered
//
//        do {
//            printf("Enter password recovery: ");
//            scanf("%5s", new_staff.passwordRecovery);
//        } while (!validatePasswordRecovery(new_staff.passwordRecovery)); // Repeat until valid recovery code is entered
//
//        do {
//            printf("Enter position: ");
//            scanf(" %29[^\n]", new_staff.info.position);
//        } while (!validatePosition(new_staff.info.position)); // Repeat until valid position is entered
//
//        // Write the new record to the file
//        fprintf(fptr, "\n%s|%s|%c|%s|%s|%s", new_staff.info.staffID, new_staff.info.name, new_staff.info.gender, new_staff.info.password, new_staff.passwordRecovery, new_staff.info.position);
//
//        printf("\nAdd another record? (Y/N): ");
//        scanf(" %c", &choice);
//
//        // Flush the input buffer to prevent issues with subsequent input
//        while (getchar() != '\n');
//
//    } while (toupper(choice) == 'Y');
//
//    fclose(fptr);
//
//    // Display the message only after all records are added
//    printf("Records added successfully.\n");
//
//    // Go back to the selection menu
//    selectionStaff();
//}
//
//void searchStaff() {
//    char idToSearch[10];
//    printf("Enter staff ID to search: ");
//    scanf("%9s", idToSearch);
//
//    FILE* fptr;
//    if ((fptr = fopen("staff.txt", "r")) == NULL) {
//        printf("Error opening file!\n");
//        return;
//    }
//
//    staffRecord employee;
//    printf("------------------------------------------------------------------------------------------------------------------------\n");
//    printf("| %-8s | %-15s | %-2s | %-7s | %-10s | %-15s |\n", "Staff ID", "Name", "Gender", "Password Recovery", "Password", "Position");
//    printf("------------------------------------------------------------------------------------------------------------------------\n");
//
//    int found = 0;
//    while (fscanf(fptr, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^\n]\n", employee.info.staffID, employee.info.name, &employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position) == 6) {
//        if (strcmp(employee.info.staffID, idToSearch) == 0) {
//            printf("| %-8s | %-15s | %-6c | %-17s | %-10s | %-15s |\n", employee.info.staffID, employee.info.name, employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position);
//            found = 1;
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("No record found with staff ID: %s\n", idToSearch);
//    }
//
//    printf("------------------------------------------------------------------------------------------------------------------------\n");
//    fclose(fptr);
//}
//
//void modifyStaff() {
//    char idToModify[10];
//    printf("Enter staff ID to modify: ");
//    scanf("%9s", idToModify);
//
//    FILE* fptr, * tempPtr;
//    if ((fptr = fopen("staff.txt", "r")) == NULL) {
//        printf("Error opening file!\n");
//        return;
//    }
//
//    if ((tempPtr = fopen("temp.txt", "w")) == NULL) {
//        printf("Error opening temporary file!\n");
//        fclose(fptr);
//        return;
//    }
//
//    staffRecord employee;
//    int found = 0;
//    while (fscanf(fptr, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^\n]\n", employee.info.staffID, employee.info.name, &employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position) == 6) {
//        if (strcmp(employee.info.staffID, idToModify) == 0) {
//
//            printf("Enter Staff Id: ");
//            scanf(" %7[^\n]", employee.info.staffID);
//            while (!validateStaffId(employee.info.staffID)) {
//                printf("Enter Staff Id: ");
//                scanf(" %7[^\n]", employee.info.staffID);
//            }
//
//            printf("Enter new name: ");
//            scanf(" %19[^\n]", employee.info.name);
//            while (!validateName(employee.info.name)) {
//                printf("Enter new name: ");
//                scanf(" %19[^\n]", employee.info.name);
//            }
//
//            printf("Enter new gender (M/F): ");
//            scanf(" %c", &employee.info.gender);
//            while (!validateGender(employee.info.gender)) {
//                printf("Enter new gender (M/F): ");
//                scanf(" %c", &employee.info.gender);
//            }
//
//            printf("Enter new password: ");
//            scanf("%19s", employee.info.password);
//            while (!validatePassword(employee.info.password)) {
//                printf("Enter new password: ");
//                scanf("%19s", employee.info.password);
//            }
//
//            printf("Enter new password recovery: ");
//            scanf("%10s", employee.passwordRecovery);
//            while (!validatePasswordRecovery(employee.passwordRecovery)) {
//                printf("Enter new password recovery: ");
//                scanf("%5s", employee.passwordRecovery);
//            }
//
//            printf("Enter new position: ");
//            scanf(" %29[^\n]", employee.info.position);
//            while (!validatePosition(employee.info.position)) {
//                printf("Enter new position: ");
//                scanf(" %29[^\n]", employee.info.position);
//            }
//
//            fprintf(tempPtr, "%s|%s|%c|%s|%s|%s\n", employee.info.staffID, employee.info.name, employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position);
//            found = 1;
//        }
//        else {
//            fprintf(tempPtr, "%s|%s|%c|%s|%s|%s\n", employee.info.staffID, employee.info.name, employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position);
//        }
//    }
//
//    fclose(fptr);
//    fclose(tempPtr);
//
//    if (found) {
//        printf("Record modified successfully.\n");
//    }
//    else {
//        printf("No record found with staff ID: %s\n", idToModify);
//    }
//
//    remove("staff.txt");
//    rename("temp.txt", "staff.txt");
//    selectionStaff();
//}
//
//void deleteeStaff() {
//    char idToDelete[10];
//    printf("Enter staff ID to delete: ");
//    scanf("%7s", idToDelete);
//
//    FILE* fptr, * tempPtr;
//    if ((fptr = fopen("staff.txt", "r")) == NULL) {
//        printf("Error opening file!\n");
//        return;
//    }
//
//    if ((tempPtr = fopen("temp.txt", "w")) == NULL) {
//        printf("Error opening temporary file!\n");
//        fclose(fptr);
//        return;
//    }
//
//    staffRecord employee;
//    int found = 0;
//    while (fscanf(fptr, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^\n]\n", employee.info.staffID, employee.info.name, &employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position) == 6) {
//        if (strcmp(employee.info.staffID, idToDelete) != 0) {
//            fprintf(tempPtr, "%s|%s|%c|%s|%s|%s\n", employee.info.staffID, employee.info.name, employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position);
//        }
//        else {
//            found = 1;
//        }
//    }
//
//    fclose(fptr);
//    fclose(tempPtr);
//
//    if (found) {
//        printf("Record deleted successfully.\n");
//    }
//    else {
//        printf("No record found with staff ID: %s\n", idToDelete);
//    }
//
//    remove("staff.txt");
//    rename("temp.txt", "staff.txt");
//}
//
//void forgotStaff() {
//    char passToForgot[5];
//    printf("Enter password recovery to get your password: ");
//    scanf("%5s", passToForgot);
//
//    FILE* fptr;
//    if ((fptr = fopen("staff.txt", "r")) == NULL) {
//        printf("Error opening file!\n");
//        return;
//    }
//
//    staffRecord employee;
//    int found = 0;
//    while (fscanf(fptr, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^\n]\n", employee.info.staffID, employee.info.name, &employee.info.gender, employee.info.password, employee.passwordRecovery, employee.info.position) == 6) {
//        if (strcmp(employee.passwordRecovery, passToForgot) == 0) {
//            printf("Your Password Is : %s\n\n", employee.info.password);
//            found = 1;
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("No record found with your Password Recovery: %s\n", passToForgot);
//    }
//
//    fclose(fptr);
//}
//
////validation check for staff detail input
//int validateStaffId(const char* staffId) {
//    // Check if the length is correct
//    if (strlen(staffId) != 6) {
//        printf("Invalid staff ID length. Staff ID must be 6 characters long.\n");
//        return 0; // Invalid staff ID
//    }
//
//    // Check if the first three characters are "STF"
//    if (strncmp(staffId, "STF", 3) != 0) {
//        printf("Invalid staff ID format. Staff ID must start with 'STF'.\n");
//        return 0; // Invalid staff ID
//    }
//
//    // Check if the last three characters are digits
//    for (int i = 3; i < 6; i++) {
//        if (!isdigit(staffId[i])) {
//            printf("Invalid staff ID format. Last three characters must be digits.\n");
//            return 0; // Invalid staff ID
//        }
//    }
//
//
//    return 1; // If all checks pass, staff ID is valid
//}
//
//int validateGender(char gender) {
//    if (gender == 'M' || gender == 'F') {
//        return 1; // Valid gender
//    }
//    else {
//        printf("Invalid gender. Please enter 'M' for male or 'F' for female.\n");
//        return 0; // Invalid gender
//    }
//}
//
//int validatePassword(const char* password) {
//    // Perform password validation here (e.g., minimum length, complexity requirements)
//    if (strlen(password) == 10) {
//        return 1; // Valid password
//    }
//    else {
//        printf("Invalid password. Password must be 10 characters long.\n");
//        return 0; // Invalid password
//    }
//}
//
//int validateName(const char* name) {
//    if (strlen(name) > 0) {
//        return 1; // Valid name
//    }
//    else {
//        printf("Invalid name. Name cannot be empty.\n");
//        return 0; // Invalid name
//    }
//}
//
//int validatePasswordRecovery(const char* recovery) {
//    if (strlen(recovery) == 4) {
//        return 1; // Valid recovery code
//    }
//    else {
//        printf("Invalid password recovery code.Password Recovery must be 4 characters long.\n");
//        return 0; // Invalid recovery code
//    }
//}
//
//int validatePosition(const char* position) {
//    if (strlen(position) > 0) {
//        return 1; // Valid position
//    }
//    else {
//        printf("Invalid position. Position cannot be empty.\n");
//        return 0; // Invalid position
//    }
//}