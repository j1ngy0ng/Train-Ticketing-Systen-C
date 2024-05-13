//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdbool.h>
//#pragma warning (disable: 4996)
//#define MAX_MEMBER 100
//
//// Structure variable for storing IC
//typedef struct {
//	int birthDate;
//	int area;
//	int uniqueID;
//} IC;
//
//// Members Info
//struct Members {
//	char name[31];
//	char memberID[6];
//	char gender;
//	IC memberIC;
//	int contactNum;
//	char bookingID[6];
//	char password[9];
//	int passRecover;
//};
//
//// Modules
//void MemberInfoAdd();
//void MemberInfoSearch(struct Members member[], int* count);
//void MemberInfoModify(struct Members member[], int* count);
//void MemberInfoDisplay(struct Members member[], int* count);
//void MemberInfoDelete(struct Members member[], int* count);
//void MemberInfoForgotPassword(struct Members member[], int* count);
//
//
//void main() {
//	FILE* readBinary;
//	readBinary = fopen("memberdata.bin", "rb");
//	if (readBinary == NULL) {
//		printf("File not exist!\n");
//		exit(-1);
//	}
//
//	struct Members member[MAX_MEMBER];
//	int count = 0;
//	while (fread(&member[count], sizeof(struct Members), 1, readBinary))
//		count++;
//
//	int option; // Variables for selecting modules
//
//	// Menu for selecting modules
//	printf("MEMBER INFORMATION\n"
//		"Select your option:\n"
//		"(1) Add\n"
//		"(2) Search\n"
//		"(3) Modify\n"
//		"(4) Display\n"
//		"(5) Delete\n"
//		"(6) Exit\n");
//
//	do
//	{
//		printf("> ");
//		rewind(stdin);
//		scanf("%d", &option);
//
//		// Error handling
//		if (option < 1 || option > 6) {
//			printf("Invalid option! Please try again.\n\n");
//		}
//	} while (option < 1 || option > 6);
//
//	// Switch to the option entered
//	switch (option) {
//	case 1: MemberInfoAdd(); break;
//	case 2: MemberInfoSearch(member, &count); break;
//	case 3: MemberInfoModify(member, &count); break;
//	case 4: MemberInfoDisplay(member, &count); break;
//	case 5: MemberInfoDelete(member, &count); break;
//	case 6: return;
//	}
//}
//
//// Add new members info
//void MemberInfoAdd() {
//	struct Members newMember;
//
//	printf("\n|| %-15s ADD MEMBERS %-15s ||\n", " ", " ");
//
//	int keepLoop = 1; // Boolean variable for entering multiple members info
//
//	while (keepLoop == 1) {
//		printf("Name			: "); // Name
//		rewind(stdin);
//		scanf("%[^\n]", newMember.name);
//
//		do {
//			printf("Member ID		: "); // Member ID
//			rewind(stdin);
//			scanf("%s", newMember.memberID);
//
//			// Check whether the array size is too much
//			if (strlen(newMember.memberID) > 5)
//				printf("\nMember ID is too long. Please enter again!\n");
//		} while (strlen(newMember.memberID) > 5);
//
//		do {
//			printf("Gender (M/F)		: "); // Gender
//			rewind(stdin);
//			scanf(" %c", &newMember.gender);
//
//			// Check the gender input only receive 'M' or 'F'
//			if (newMember.gender != 'M' && newMember.gender != 'F')
//				printf("\nYou could only enter \'M\' or \'F\'. Please enter again!\n");
//
//		} while (newMember.gender != 'M' && newMember.gender != 'F');
//
//		printf("IC Number		: "); // IC Number, must follow the format
//		rewind(stdin); // The IC Number is formatted to receive limited digit numbers
//		scanf("%06d-%02d-%04d", &newMember.memberIC.birthDate, &newMember.memberIC.area, &newMember.memberIC.uniqueID);
//
//		printf("Contact Number		: "); // Contact Number
//		rewind(stdin);
//		scanf(" %011d", &newMember.contactNum); // The contact number is formatted to receive limited digit numbers
//
//		do {
//			printf("Booking ID		: "); // Booking ID
//			rewind(stdin);
//			scanf("%s", newMember.bookingID);
//
//			// Check the array size is over
//			if (strlen(newMember.bookingID) > 5)
//				printf("\nBooking ID is too long. Please enter again!\n");
//		} while (strlen(newMember.bookingID) > 5);
//
//		do {
//			printf("Password		: "); // Enter password
//			rewind(stdin);
//			scanf("%s", newMember.password);
//
//			// Check whether the array size is over
//			if (strlen(newMember.password) > 8)
//				printf("\nPassword is too long. Please change another password.\n");
//		} while (strlen(newMember.password) > 8);
//
//
//
//		printf("Password Recovery	: "); // Enter password recovery
//		rewind(stdin);
//		scanf("%4d", &newMember.passRecover); // Formatted to receive 4 digits of number
//
//		// Write data into the binary file
//		FILE* fptr; // Open file and error handling
//		fptr = fopen("memberdata.bin", "ab");
//		if (fptr == NULL) {
//			printf("File not exist!\n");
//			exit(-1);
//		}
//		fwrite(&newMember, sizeof(struct Members), 1, fptr);
//		fclose(fptr);
//
//
//		do {
//			printf("\nContinue adding member info?\n"
//				"(1) Yes\n"
//				"(2) No\n"
//				"> ");
//			rewind(stdin);
//			scanf("%d", &keepLoop);
//
//			// Error handling
//			if (keepLoop != 1 && keepLoop != 2) {
//				printf("Wrong input! Enter again!\n\n");
//			}
//		} while (keepLoop != 1 && keepLoop != 2);
//
//		printf("\n");
//
//		// If choose 2, which is no, exit the loop
//	}
//
//	printf("\n\n");
//	main(); // Back to the main menu
//}
//
//void MemberInfoSearch(struct Members member[], int* count) {
//	char searchID[6] = "";
//	int found = -1;
//
//	// Enter the member ID that wishes to search
//	printf("Enter Member ID		: ");
//	rewind(stdin);
//	scanf("%s", searchID);
//
//	for (int i = 0; i < *count; i++) {
//		if (strcmp(member[i].memberID, searchID) == 0)
//			found = i;
//	}
//
//
//	printf("\n\n");
//
//	// If not found, display "no", if found, display the info
//	if (found == -1) {
//		printf("No member found.\n");
//	}
//	else {
//		printf("Name			: %s\n", member[found].name);
//		printf("Member ID		: %s\n", member[found].memberID);
//		printf("Gender			: %c\n", member[found].gender);
//		printf("IC Number		: %06d-%02d-%04d\n", member[found].memberIC.birthDate, member[found].memberIC.area, member[found].memberIC.uniqueID);
//		printf("Contact Number		: %010d\n", member[found].contactNum);
//		printf("Booking ID		: %s\n", member[found].bookingID);
//		printf("Password		: %s\n", member[found].password);
//		printf("Password Recovery	: %d\n", member[found].passRecover);
//	}
//
//	printf("\n\n");
//	main();
//}
//
//void MemberInfoModify(struct Members member[], int* count) {
//	// Search the member ID that wishes to modify
//	char modifyMember[6] = "";
//	printf("Enter Member ID		: ");
//	rewind(stdin);
//	scanf("%s", modifyMember);
//
//	int found = -1;
//
//	for (int i = 0; i < *count; i++) {
//		if (strcmp(modifyMember, member[i].memberID) == 0) {
//			found = i;
//			break;
//		}
//	}
//
//	// If not found, display "no", if found, enter the input for the member
//	if (found == -1) {
//		printf("The Member ID does not exist.\n");
//	}
//	else {
//		int confirmModify;
//		do {
//			confirmModify = 2;
//
//			printf("\n\n");
//			printf("Name			: "); // Enter Name
//			rewind(stdin);
//			scanf("%[^\n]", member[found].name);
//
//			do {
//				printf("Gender			: "); // Enter Gender
//				rewind(stdin);
//				scanf("%c", &member[found].gender);
//
//				// Check the gender input
//				if (member[found].gender != 'M' && member[found].gender != 'F')
//					printf("\nYou could only enter \'M\' or \'F\'. Please try again!\n");
//
//			} while (member[found].gender != 'M' && member[found].gender != 'F');
//
//
//			printf("IC Number		: "); // Enter IC Number
//			rewind(stdin);
//			scanf("%06d-%02d-%04d", &member[found].memberIC.birthDate, &member[found].memberIC.area, &member[found].memberIC.uniqueID);
//
//			printf("Contact Number		: "); // Enter contact number
//			rewind(stdin);
//			scanf("%011d", &member[found].contactNum);
//
//			do {
//				printf("Booking ID		: "); // Enter Booking ID
//				rewind(stdin);
//				scanf("%s", member[found].bookingID);
//
//				// Check Booking ID array size is over or not
//				if (strlen(member[found].bookingID) > 5)
//					printf("\nBooking ID is too long. Please enter again!\n");
//			} while (strlen(member[found].bookingID) > 5);
//
//			do {
//				printf("Password		: ");
//				rewind(stdin);
//				scanf("%s", member[found].password);
//
//				// Check the password array size is over or not
//				if (strlen(member[found].password) > 8)
//					printf("\nPassword maximum could only have 8 characters, try again!\n");
//			} while (strlen(member[found].password) > 8);
//
//			printf("Password Recovery	: ");
//			rewind(stdin);
//			scanf("%04d", &member[found].passRecover);
//
//
//			do {
//				printf("\nConfirm Modification?\n"
//					"(1) Yes\n"
//					"(2) No\n"
//					"> ");
//				rewind(stdin);
//				scanf("%d", &confirmModify);
//
//				if (confirmModify != 1 && confirmModify != 2)
//					printf("\nInvalid option. Try again!\n");
//			} while (confirmModify != 1 && confirmModify != 2);
//
//		} while (confirmModify == 2);
//
//
//		// Open the file again to overwrite data into the binary file
//		FILE* modify;
//		modify = fopen("memberdata.bin", "wb");
//		if (modify == NULL) {
//			printf("File not exist.\n");
//			exit(-1);
//		}
//
//		for (int i = 0; i < *count; i++)
//			fwrite(&member[i], sizeof(struct Members), 1, modify);
//
//		fclose(modify);
//	}
//
//	printf("\n\n");
//	main();
//}
//
//void MemberInfoDisplay(struct Members member[], int* count) {
//	for (int i = 0; i < 121; i++)
//		printf("-");
//
//	printf("\n%-30s  %-10s  %-6s  %-14s  %-11s  %-11s  %-8s  %-17s\n",
//		"Name", "Member ID", "Gender", "Member IC",
//		"Contact Num", "Booking ID", "Password", "Password Recovery");
//
//	for (int i = 0; i < 121; i++)
//		printf("-");
//
//	printf("\n");
//
//	// Display all the record in the binary file
//	for (int i = 0; i < *count; i++) {
//		printf("%-30s  %-10s  %-6c  %06d-%02d-%04d  %011d  %-11s  %-8s  %-17d\n",
//			member[i].name, member[i].memberID, member[i].gender, member[i].memberIC.birthDate,
//			member[i].memberIC.area, member[i].memberIC.uniqueID, member[i].contactNum,
//			member[i].bookingID, member[i].password, member[i].passRecover);
//	}
//
//	printf("\n < %d Details Listed >\n", *count);
//
//	printf("\n\n");
//	main();
//}
//
//void MemberInfoDelete(struct Members member[], int* count) {
//	char deleteMember[6] = ""; // Variable for intended deleted Member ID
//	int found = -1;
//
//	printf("\n");
//
//	do {
//		printf("Enter ID	: "); // Enter Member ID
//		rewind(stdin);
//		scanf("%s", deleteMember);
//
//		if (strlen(deleteMember) > 5)
//			printf("\nYou could only enter 5 characters for the Member ID, try again!\n");
//	} while (strlen(deleteMember) > 5);
//
//
//	for (int i = 0; i < *count; i++) {
//		if (strcmp(member[i].memberID, deleteMember) == 0) {
//			found = i;
//			break;
//		}
//	}
//
//	if (found == -1) {
//		printf("Member not found.\n");
//	}
//	else {
//		while (found != *count) {
//			if (found == *count)
//				break;
//
//			member[found] = member[found + 1];
//			found++;
//		}
//
//		*count -= 1;
//
//		// Open File
//		FILE* delete;
//		delete = fopen("memberdata.bin", "wb");
//		if (delete == NULL) {
//			printf("File not exist!\n");
//			exit(-1);
//		}
//
//		for (int i = 0; i < *count; i++) {
//			fwrite(&member[i], sizeof(struct Members), 1, delete);
//		}
//
//		fclose(delete);
//
//		printf("Record of Member %s has deleted.\n", deleteMember);
//	}
//
//	printf("\n\n");
//	main();
//}
//
//
//void MemberInfoForgotPassword(struct Members member[], int* count) {
//	char findMember[6] = ""; // Variable for the intended search Member ID
//	int matchPassRecover;
//	int found;
//	do {
//		found = -1;
//
//		printf("Enter your Member ID		: "); // Enter Member ID
//		rewind(stdin);
//		scanf("%s", findMember);
//
//		printf("Enter your Password Recovery	: "); // Enter Password Recovery
//		rewind(stdin);
//		scanf("%d", &matchPassRecover);
//
//		// Loop for searching the Member ID in the file with the inputted Member ID
//		for (int i = 0; i < *count; i++) {
//			if (strcmp(member[i].memberID, findMember) == 0)
//				found = i;
//		}
//
//		if (found != -1 && member[found].passRecover == matchPassRecover)
//			printf("\nYour password is %s.\n", member[found].password);
//		else // If not found, loop again
//			printf("\nYour Member ID or Password Recovery is incorrect!\n");
//	} while (!(found != -1 && member[found].passRecover == matchPassRecover));
//
//	// Section for changing the passwordd
//	int option;
//	do {
//		printf("\nDo you want to change your password?\n"
//			"(1) Yes\n"
//			"(2) No\n"
//			"> ");
//		rewind(stdin);
//		scanf("%d", &option);
//
//		// If yes, proceed the code, if no, exit the function
//		if (option < 1 || option > 2)
//			printf("Invalid option. Try again!\n");
//	} while (option < 1 || option > 2);
//
//	int confirm;
//
//	if (option == 1) {
//		confirm = 2;
//		do {
//			do {
//				printf("\nEnter New Password	: "); // Enter new password
//				rewind(stdin);
//				scanf("%s", member[found].password);
//
//				if (strlen(member[found].password) > 8)
//					printf("The new password could only have maximum 8 characters. Try again!\n");
//			} while (strlen(member[found].password) > 8);
//
//			do { // Confirm modification
//				printf("\nDo you confirm your changes?\n"
//					"(1) Yes\n"
//					"(2) No\n"
//					"> ");
//				rewind(stdin);
//				scanf("%d", &confirm);
//
//				if (confirm < 1 || confirm > 2)
//					printf("Invalid option. Try again!\n");
//			} while (confirm < 1 || confirm > 2);
//		} while (confirm == 2);
//
//		printf("\nYour password has been changed.\n");
//	}
//
//	// Open file for overwrite the binary file
//	FILE* changePassword;
//	changePassword = fopen("memberdata.bin", "wb");
//	if (changePassword == NULL) {
//		printf("File not exist.\n");
//		exit(-1);
//	}
//
//	for (int i = 0; i < *count; i++)
//		fwrite(&member[i], sizeof(struct Members), 1, changePassword);
//
//	fclose(changePassword);
//
//	printf("\n\n");
//	main();
//}
//
//
////int main() {
////	FILE* fptr;
////	fptr = fopen("memberdata.bin", "wb");
////	if (fptr == NULL) {
////		printf("File not exist.\n");
////		exit(-1);
////	}
////
////	struct Members members[20] = {
////		{"John Doe", "M1001", 'M', {900101, 3, 101}, 1234567890, "BK001", "john0101", 1234},
////		{"Jane Smith", "M1002", 'F', {851203, 9, 202}, 1987654321, "BK002", "jane0202", 5678},
////		{"Michael Johnson", "M1003", 'M', {780415, 6, 303}, 1654321987, "BK003", "micj0303", 9012},
////		{"Emily Davis", "M1004", 'F', {001120, 7, 404}, 1237894560, "BK004", "davi0404", 3456},
////		{"David Brown", "M1005", 'M', {930506, 3, 505}, 1456789012, "BK005", "brow0505", 7890},
////		{"Jessica Wilson", "M1006", 'F', {870630, 8, 606}, 1789012345, "BK006", "jess0606", 1234},
////		{"Daniel Taylor", "M1007", 'M', {760918, 6, 707}, 1234567897, "BK007", "tayl0707", 5678},
////		{"Sarah Martinez", "M1008", 'F', {021025, 3, 808}, 1890123456, "BK008", "sara0808", 9012},
////		{"Matthew Anderson", "M1009", 'M', {901210, 7, 909}, 1345678901, "BK009", "matt0909", 3456},
////		{"Olivia Garcia", "M1010", 'F', {840503, 4, 1010}, 1901234567, "BK010", "oliv1010", 7890},
////		{"Christopher Rodriguez", "M1011", 'M', {980815, 3, 1111}, 1456789012, "BK011", "chris011", 1234},
////		{"Ava Hernandez", "M1012", 'F', {771127, 7, 1212}, 1123456789, "BK012", "avah1212", 5678},
////		{"Andrew Lee", "M1013", 'M', {10409, 1, 1313}, 1234567899, "BK013", "andl1313", 9012},
////		{"Sophia Nguyen", "M1014", 'F', {890214, 7, 1414}, 1345678921, "BK014", "soph1414", 3456},
////		{"James Kim", "M1015", 'M', {960701, 6, 1515}, 1901234567, "BK015", "james155", 7890},
////		{"Isabella Wong", "M1016", 'F', {720818, 3, 1616}, 1123456442, "BK016", "isaw1616", 1234},
////		{"Ryan Chan", "M1017", 'M', {031205, 9, 1717}, 1234567880, "BK017", "ryan1717", 5678},
////		{"Mia Patel", "M1018", 'F', {921230, 1, 1818}, 1321678901, "BK018", "miap1818", 9012},
////		{"Jacob Liu", "M1019", 'M', {860723, 7, 1919}, 1921034567, "BK019", "jaco1919", 3456},
////		{"Emma Smith", "M1020", 'F', {001017, 6, 2020}, 1123456791, "BK020", "emma2020", 7890}
////	};
////
////	for (int i = 0; i < 20; i++)
////		fwrite(&members[i], sizeof(struct Members), 1, fptr);
////
////	fclose(fptr);
////}
