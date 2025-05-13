#include "HeaderFile.h"
/*
 Description: This program simulates an ATM system, allowing users 
 to securely log in, manage their account balance, deposit and withdraw 
 funds, transfer money, change their PIN, pay bills, and view transaction 
 history.
 Programmed by: Paingan, Edriene James A. S23B
 Last modified: 24/11/2024
 Version: 4
 [Acknowledgements: GitHub, Reddit]
*/

/*******************************************************************************************************
This is to certify that this project is my own work, based on 
my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective 
algorithms and corresponding code by myself. The program was run, tested, 
and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work 
of other students and/or persons. 
Paingan, Edriene James, DLSU ID# 12413984
********************************************************************************************************/

/********************************************************************************************************
Utility Functions: 
Helper functions that are used by the main logic.
These helper functions enhance code readability, modularity, and maintainability. 
In this case, the functions assist with displaying visuals, logging date and time, 
and providing a user-friendly interface for an ATM system.
********************************************************************************************************/

/*  
	Function: atmlogo
	Description: Displays the ASCII art logo for the ATM system.
	Precondition: None.
	@param None
	@return void (prints the ATM logo to the console).
 */
void atmlogo() {
	
    system("chcp 65001 > nul"); // tp print blocks and >nul will prevent printing the output code 
	printf("\n");
    printf("\t\t\t\t    █████╗ ████████╗███╗   ███╗\n");
    printf("\t\t\t\t   ██╔══██╗╚══██╔══╝████╗ ████║\n");
    printf("\t\t\t\t   ███████║   ██║   ██╔████╔██║\n");
    printf("\t\t\t\t   ██╔══██║   ██║   ██║╚██╔╝██║\n");
    printf("\t\t\t\t   ██║  ██║   ██║   ██║ ╚═╝ ██║\n");
    printf("\t\t\t\t   ╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝\n");
    
}

/*  
	Function: dateandtime
	Description: Writes the current date and time to a specified file.
	Precondition: The file pointer (fptr) must be open and valid.
	@param fptr  (Pointer to the file where the date and time will be written.)
	@return void (writes the current date and time to the file).
*/
void dateandtime(FILE *fptr) {
    
    time_t t;
    // Get the current time
    time(&t);
    
    // Write the formatted date and time directly to the file
    fprintf(fptr, "%s", ctime(&t));
    
}

/*  
	Function: menuheader
	Description: Displays the ATM system's header brand.
	Precondition: None.
	@param None
	@return void (prints the header to the console).
 */
void menuheader() {
	
    printf(" ________________________________________________________________________________________________\n");
    printf("/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/\n");
    printf("\t\t\t   ___        _              ___            __    \n");
    printf("\t\t\t  / _ | ___  (_)_ _  ___    / _ )___ ____  / /__  \n");
    printf("\t\t\t / __ |/ _ \\/ /  ' \\/ _ \\  / _  / _ `/ _ \\/  '_/ \n");
    printf("\t\t\t/_/ |_/_//_/_/_/_/_/\\___/ /____/\\_,_/_//_/_/\\_\\ \n");
    printf(" ________________________________________________________________________________________________\n");
    printf("/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/\n");
    
}

/*  
	Function: accountloginmenu
	Description: Displays the login menu with instructions.
	Precondition: None.
	@param None
	@return void (prints the login menu to the console).
 */
void accountloginmenu() {
	
	printf("\n");
	printf("\t\t                       ------------------\n");
	printf("\t\t                      |  Account Log In  |\n");
	printf("\t\t                       ------------------\n");
	printf("\t\t                   Need help? Contact support.\n");
	printf("\t\t               ------------------------------------\n");	
	printf("\t\t              |        Press Enter to Log In      |\n");
	printf("\t\t              ------------------------------------\n\n");	
    
}

/*  
	Function: mainmenu
	Description: Displays the main menu with available ATM options.
	Precondition: None.
	 @param None
	@return void (prints the main menu to the console).
 */
void mainmenu(){
	
	system("chcp 65001 > nul"); // to print blocks and >nul will prevent printing the output code
	
	printf("\t\t     ______________________________________________________\n");
    printf("\t\t    |                                                      |\n");
    printf("\t\t    |                 MAIN MENU OPTIONS                    |\n");
    printf("\t\t    |______________________________________________________|\n");
    printf("\t\t    |                                                      |\n");
    printf("\t\t    |  [1]  Change PIN           [5]  Transfer Funds       |\n");
    printf("\t\t    |  [2]  Balance Inquiry      [6]  Pay Bills            |\n");
    printf("\t\t    |  [3]  Deposit              [7]  View Transactions    |\n");
    printf("\t\t    |  [4]  Withdraw             [0]  Logout               |\n");
    printf("\t\t    |______________________________________________________|\n");
}

/*  
	Function: denominationlist
	Description: Displays a list of available deposit denominations.
	Precondition: None.
	@param None
	@return void (prints the denomination list to the console).
 */
void denominationlist(){
	
	printf("\n\t\t\t     Choose your deposit denomination: \n");
	printf("\t\t\t   --------------------------------------\n");
	printf("\t\t\t   | [1] - P100                         |\n");
	printf("\t\t\t   | [2] - P200                         |\n");
	printf("\t\t\t   | [3] - P500                         |\n");
	printf("\t\t\t   | [4] - P1000                        |\n");
	printf("\t\t\t   | [0] - Cancel                       |\n");
	printf("\t\t\t   --------------------------------------\n\n");
	
}

/*  
	Function: billerlist
	Description: Displays a list of available billers for bill payment.
	Precondition: None.
	@param None
	@return void (prints the biller list to the console).
 */
void billerlist(){
	
        printf("\n\t\t\t\t   +-------------------------+\n");
        printf("\t\t\t\t   |      Billers List       |\n");
        printf("\t\t\t\t   +-------------------------+\n");
        printf("\t\t\t\t   |     [1] - Biller 1      |\n");
        printf("\t\t\t\t   |     [2] - Biller 2      |\n");
        printf("\t\t\t\t   |     [3] - Biller 3      |\n");
        printf("\t\t\t\t   |     [4] - Biller 4      |\n");
        printf("\t\t\t\t   |     [5] - Biller 5      |\n");
        printf("\t\t\t\t   |     [0] - Cancel        |\n");
        printf("\t\t\t\t   +-------------------------+\n");
        
}

/*  
	Function: loading
	Description: Displays a loading animation to simulate processing.
	Precondition: None.
	@param None
	@return void (prints a rotating character animation to the console).
 */  
void loading() {
	
	for (int j = 0; j<3; j++){//for loop to make it rotate twice
	
	    for (int i = 0; i<4; i++) { //for loop for each rotation character
	    
	        switch (i) { //switch case for each charcter
	        
	            case 0:
	                printf("\b|"); 
	                break;
	                
	            case 1:
	                printf("\b/"); 
	                break;
	                
	            case 2:
	                printf("\b-"); 
	                break;
	                
	            case 3:
	                printf("\b\\");
	                break;
	                
	        }
	        
	        //Sleep takes milliseconds as argument
	        Sleep(200); // Adjust delay as needed
	    }
	}
	
    // clear final character
    printf("\b \n");
    
}

/*******************************************************************************************************
Core Logic Functions: 
The provided code implements an ATM system wherein it allows user login, balance checks, deposits, 
withdrawals, transfers, bill payments, PIN changes, and transaction history viewing. It ensures secure 
authentication, validates inputs, and updates account details after each transaction.
********************************************************************************************************/

/*  
	Function: login
	Description: Authenticates the user by verifying the account number and PIN.
	Precondition: The system must have the correct account number and PIN to compare against.
	@param nAccountNumber - The correct account number for authentication.
	@param nAccountPin - Pointer to the correct account PIN for authentication.
	@return int - Returns 1 if the login is successful, or 2 if the login fails after 3 attempts.
 */
int login(const int nAccountNumber, int *nAccountPin) {
	
	//Variable Declarations
	int inputAccountNumber;
    int inputAccountPin;
    int loginstatus = 0; // 0 = Enter Loop, 1 = Successful, 2 = Failed/Cancelled
    int count = 0; //Initial number of tries

    //enters loop with initial login status of 0 and count 0
    while (loginstatus == 0 && count < 3) {
    	
    	//asks user to input account details
        printf("\t\t\t\t Enter Account Number: ");
        scanf("%d", &inputAccountNumber);
	
        printf("\t\t\t\t Enter PIN Number: ");
        scanf("%d", &inputAccountPin);

        // Check if account details match
        if (inputAccountNumber == nAccountNumber && inputAccountPin == *nAccountPin) {
        	
        	printf("\t\t\t\t\t\t  ");
			loading();
			system("cls");
			menuheader();
            printf("\n\t\t\t\t\tLog in Successful!\n"); // only for change pin since main menu will cls 
            
            //since successful already, it will now make loginstatus 1 thereby exiting the loop
            loginstatus = 1; 
            
        } 
		
		else {
        	
        	//user input is wrong so it will add to count until it reaches 2
            count++; 
            system("cls");
            menuheader ();
			accountloginmenu();
			system("chcp 65001 > nul");
            printf("\t\t   \u26A0  WARNING: Sorry, the account number and PIN did not match.\n");
            printf("\t\t\t      \u26A0  Please try again. %d attempts left.\n\n", 3 - count);
            
            // checks if the three attempts are used up, set loginstatus to 2 to indicate failure
            if (count >= 3) {
            	
                loginstatus = 2;
                printf("\t\t\t      Login failed. Please contact support.\n");
            }
        }
    }
	//returns status to see if it returns 1 or 2
    return loginstatus;
}

/*  
Function: displaymenu
Description: Displays the main menu to the user and captures their choice, ensuring it's within a valid range.
Precondition: None.
@param None
@return int  Returns the user's menu choice (0-7).
 */
int displaymenu(){
	
	// Variable to store the user's menu choice
	//-1 provides a safe, clear starting point that prevents errors
	int choice = -1; 
	
	// Print the decorative banner for the menu

 
 	// Print the menu options for the user
 	mainmenu();
    
	// Prompt the user for their input
    printf("\t\t\t\t\tYour choice: "); 
    scanf("%d", &choice ); 
    
    //Checks if the choice is a valid choice
    while ( choice < 0 || choice > 7){
    	system("cls");
    	menuheader ();
    	atmlogo();
    	mainmenu();
    	printf("\t\t\t\t   Please Enter a valid choice.\n");
    	printf("\t\t\t\t\tYour choice: "); 
    scanf("%d", &choice );
	}
    
    // Display the user's selected option
    printf("\t\t     ______________________________________________________ \n");
    printf("\t\t    |                   You selected: %d                    |\n", choice);
    printf("\t\t    |______________________________________________________|\n"); 
    printf("\t\t\t\t\t\t");
    loading();
    
    // function will return the choice of the user where to go
    return choice;
	
}

/*  
Function: changepin
Description: Allows the user to change their PIN with input validation and confirmation.
Precondition: The user must be logged in and have provided their current PIN.
@param currentpin - Pointer to the current PIN that will be updated if the change is successful.
@return int - Returns 1 if the PIN is successfully changed, or 2 if the operation is canceled.
 */
int changepin(int *currentpin) {
	
	int newpin;
    int confirmpin;
    int changepinstatus = 0;  
	// 0 = Enter Loop, 1 = Successful, 2 = Failed/Cancelled,
    
    // Loop until the PIN is successfully changed or the operation is canceled
    while (changepinstatus == 0) {
        // Prompt for a new PIN
        printf("\n\t\t\tEnter new PIN [100000 - 999999] or 0 to cancel: "); 
        scanf("%d", &newpin);

        // Check if user chose to cancel the operation
        if (newpin == 0) {
            
            changepinstatus = 2;  // Set the status to canceled, exit the loop
        }
        else if (newpin == *currentpin) {
            // Ensure the new PIN is different from the current PIN
            printf("\t\t\tThe new PIN must be different from the current PIN.\n");
        }
        else if (newpin < 100000 || newpin > 999999) {
            // Ensure the new PIN is within the valid range
            printf("\t\t\tThe new PIN must be between 100000 and 999999.\n");
        }
        else {
            // Ask the user to confirm the new PIN
            printf("\t\t\tConfirm new PIN: ");
            scanf("%d", &confirmpin);

            // Check if the confirmation PIN matches
            if (newpin != confirmpin) {
                printf("\t\t\tPINs do not match. Please try again.\n");
            } else {
                // Successfully update the current PIN
                *currentpin = newpin;

                // Set status to indicate success
                changepinstatus = 1;
            }
        }
    }

    return changepinstatus;  // Return 1 for success, 2 for cancellation
}

/*  
Function: balance
Description: Displays the current account balance along with the account number.
Precondition: The user must be logged in and the account details must be valid.
@param balance - pointer to the current account balance.
@param nAccountNumber - The account number associated with the user.
@return int - Returns 1 to indicate the balance was successfully displayed.
 */
int balance(float *balance, int nAccountNumber) {
	
    system("cls");
	menuheader ();
	//Shows user accountnumber and current balance
    printf("\n\t\t\t    +--------------------------------------+\n");

    // Print the account number and balance within the box
    printf("\t\t\t         Account Number: %d           \n", nAccountNumber);
    printf("\t\t\t         Your current balance is: %.2f  \n", *balance);

    // Create the bottom border of the box
    printf("\t\t\t    +--------------------------------------+\n\n");
    
    // function will return 1 to indicate success
    return 1;
}

/*  
Function: deposit
Description: Allows the user to deposit money into their account by specifying a denomination and number of bills.
Precondition: The user must be logged in, and the balance pointer must point to a valid account balance.
@param balance - Pointer to the user's current account balance, which will be updated after a successful deposit.
@return int - Returns 1 if the deposit is successful, or 2 if the deposit is canceled.
 */
int deposit(float *balance) {
	
	//Vartiable Declarations and Initial Values
    int denomination = 0;
    float denominationamount = 0.0;
    int numBills = 0;
    float currentdeposit = 0.0;
    float runningDeposit = 0.0;
    int depositresult = 0; // Flag for controlling loops, 0 for running, 1 for completed, 2 for cancelled
    char choice = 'Y'; // Set to 'Y' to start the loop

    system("cls");
    menuheader();

    // Outer loop, only runs until depositresult is set to 1 (completed) or 2 (cancelled)
    while (depositresult == 0) {
    	
        // Inner loop, runs while the user wants to keep depositing
        while (choice == 'Y' || choice == 'y') {
        	
            denominationlist(); // Display the list of available deposit denominations

            // Input for the denomination
            printf("\t\t\t   Enter Denomination or input '0' to exit: ");
            scanf("%d", &denomination);

            // Check if the user cancels (denomination is 0)
            if (denomination == 0) {
                depositresult = 2;  // Set flag to 2 (cancelled)
                choice = 'N';  // Force exit from the loop by setting choice to 'N'
                continue;
            }

            // Validate the denomination input
            while (denomination < 0 || denomination > 4) {
                system("cls");
                menuheader();
                denominationlist();
                printf("\t\t\t   Please enter a valid Denomination.\n");
                printf("\t\t\t   Enter Denomination or input '0' to exit: ");
                scanf("%d", &denomination);
            }
            
            // Handle user cancellation if user chooses to do so
            if (denomination == 0) {
                depositresult = 2;  // Set flag to 2 (cancelled)
                choice = 'N';  // Force exit from the loop by setting choice to 'N'
                continue;
            }

            // Prompt the user to enter the number of bills
			printf("\n\t\t\t   Number of bills (up to 10 bills only) or input '0' to exit: ");
			scanf("%d", &numBills);
			
			// Handle cancellation if user enters '0' for number of bills
			if (numBills == 0) {
			    depositresult = 2;  // Set flag to 2 (cancelled)
			    choice = 'N';  // Force exit from the loop by setting choice to 'N'
			    continue;
			}
			
			// If the number of bills is invalid (not in the range of 1 to 10), ask again
			while (numBills < 1 || numBills > 10) {
				
			    printf("\n\t\t\t   You can enter a maximum of 10 bills only.\n");
			    printf("\t\t\t   Number of bills (up to 10 bills only) or input '0' to exit: ");
			    scanf("%d", &numBills);
			    
			}
			    
			// Handle cancellation if user enters '0' for number of bills
			    if (numBills == 0) {
			    depositresult = 2;  // Set flag to 2 (cancelled)
			    choice = 'N';  // Force exit from the loop by setting choice to 'N'
			    continue;
			}

            // Determine the denomination amount based on user input
            switch (denomination) {
                case 1:
                    denominationamount = 100.00;
                    break;
                case 2:
                    denominationamount = 200.00;
                    break;
                case 3:
                    denominationamount = 500.00;
                    break;
                case 4:
                    denominationamount = 1000.00;
                    break;
                default:
                    // This case should never happen due to the earlier checks, but it ensures proper flow
                    printf("\t\t\t   Invalid denomination. Please try again.\n");
                    continue;  // Go back to the beginning of the loop
            }

            // Calculate the current deposit
            currentdeposit = denominationamount * numBills;
            printf("\t\t\t   Current deposit: %.2f\n", currentdeposit);

            // Update the running total
            runningDeposit += currentdeposit;
            printf("\t\t\t   Running Deposit: %.2f\n", runningDeposit);

            // Ask the user if they want to deposit more
            printf("\t\t\t   Do you want to deposit more? Y/N: ");
            scanf(" %c", &choice);

            // Handle invalid inputs for choice
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                printf("\t\t\t   WARNING: Invalid input. Please enter Y to continue or N to cancel: ");
                scanf(" %c", &choice);
            }

            // If user chooses 'N' or 'n', set depositresult to 1 to indicate completion
            if (choice == 'N' || choice == 'n') {
                depositresult = 1;  // Deposit completed
                system ("cls");
                menuheader();
                denominationlist();
            }
            
            //goes back to loop
            else{
            	system ("cls");
            	menuheader();
            	continue;
			}
            
        }

        // If deposit result is 1 (successful), continue processing
        if (depositresult == 1) {
            // Update the account balance with total deposits made
            *balance += runningDeposit;

            // Open the file to save transaction details
            FILE *fptr = fopen("TransactionHistory.txt", "a");

            // Record transaction details
            fprintf(fptr, "Deposit\t\t\t+P%8.2f\tP%8.2f\t", runningDeposit, *balance);
            dateandtime(fptr);

            // Close the file
            fclose(fptr);
        }
    }

    // Return the result of the deposit (1 for success, 2 for cancellation)
    return depositresult;
}

/*  
Function: withdrawal
Description: Allows the user to withdraw money from their account in intervals of P100, with input validation and confirmation.
Precondition: The user must be logged in, and the balance pointer must point to a valid account balance.
@param balance - Pointer to the user's current account balance, which will be updated after a successful withdrawal.
@return int - Returns 1 if the withdrawal is successful, or 2 if the withdrawal is canceled.
 */
int withdrawal(float *balance) {
	
	//Variable declalrations and Initial Values
    int amount;
    char confirm;
    int withdrawalstatus = 0; // Flag for controlling loops, 0 for running, 1 for completed, 2 for cancelled

    system("cls");
	menuheader();
	
    while (withdrawalstatus == 0) { 
    	
    	// Prompt the user to enter the withdrawal amount
        printf("\n\t\t   Enter amount to withdraw (P100 intervals) or '0' to cancel: ");
        scanf("%d", &amount);

        // Check for cancelation immediately
        if (amount == 0) {
            withdrawalstatus = 2;  // Set to 2 to exit loop naturally
        }
        
        // Validate that the amount is a positive multiple of 100
        else if (amount < 0 || amount % 100 != 0) {
        	system("cls");
        	menuheader();
            printf("\n\t\t\tYou can only withdraw in intervals of P100.00.\n");
            printf("\t\t\t--------------------------------------------------\n");
            continue;
        }
        
        // Check if the account has sufficient balance for the withdrawal
        else if (*balance < amount) {
        	system("cls");
        	menuheader();
            printf("\n\t\t\tSorry, your balance is insufficient.\n");
            printf("\t\t\tYour current balance is P%.2f.\n", *balance);
            printf("\t\t\t--------------------------------------------------\n");
            printf("\t\t\tPlease enter an amount within your balance.\n");
            continue;
        }
        
        
        else {
            // Confirm withdrawal if all checks are passed
            printf("\t\t\t\t   You will withdraw P%d.00. \n\n\t\t\t   Enter 'Y' to confirm and 'N' to cancel: ", amount);
            scanf(" %c", &confirm);
			
			 // Process the withdrawal if the user confirms
            if (confirm == 'Y' || confirm == 'y') {
                *balance -= amount; // Deduct the withdrawal amount from the balance
                printf("\n\t\t\tP%d.00 has been withdrawn successfully.\n\n", amount);
                
                // Open the file to save the transaction details
                FILE *fptr = fopen("TransactionHistory.txt", "a");
				
				// Record transaction details
			    fprintf(fptr, "Withdrawal\t\t-P%5d.00\tP%8.2f\t", amount, *balance);
   				dateandtime(fptr);
  			
  				// Close the file to save the transaction details
			    fclose(fptr);
                
                withdrawalstatus = 1; // Set status to indicate a successful withdrawal
            } 
            
            // Handle cancellation by the user
            else if (confirm == 'N' || confirm == 'n') {
                printf("\n\t\t\tWithdrawal canceled.\n");
                withdrawalstatus = 2; // User canceled
            } 
            
            // Handle invalid confirmation input
            else {
                printf("\n\t\t\tInvalid input.\n");
                printf("\t\t\t--------------------------------------------------\n");
                //goes back to ask again
            }
        }
    }
	
	// Return the result of the withdrawal (1 for success, 2 for cancellation)
    return withdrawalstatus;
}

/*  
Function: transferfunds
Description: Allows the user to transfer funds to another account with validation for the account number, transfer amount, and balance.
Precondition: The user must be logged in, and the balance pointer must point to a valid account balance.
@param balance - Pointer to the user's current account balance, which will be updated after a successful transfer.
@param accountnumber - The user's account number, which cannot be used for transfers.
@return int - Returns 1 if the transfer is successful, or 2 if the transfer is canceled.
 */
int transferfunds(float *balance, int accountnumber) {
	
    // Varaible Declaration and Initial Values
    int transferaccount;
    float transferamount;
    char confirm;
    int transactionStatus = 0; // Flag for controlling loops, 0 for running, 1 for completed, 2 for cancelled

    while (transactionStatus == 0) { // Loop until transaction is completed or canceled
    
        // Validate the account number for transfer (cannot transfer to own account)
        
        int validAccount = 0; // Flag for valid account input
        
        while (!validAccount) {
        	system("cls");
        	menuheader();
            printf("\n\t  Enter Account Number (Eight Digits [10000000 - 99999999]) or 0 to cancel: ");
            scanf("%d", &transferaccount);

            // If user enters own account number
            if (transferaccount == accountnumber) {
                printf("\n\t\t\tWARNING: You can't transfer funds into your own account!\n");
                printf("\t\t\t--------------------------------------------------\n");
                printf("\t\t\tPress any key to try again...\n");
                getch();  // Wait for user to press a key
                continue; // This will re-enter the loop and prompt again
            }

            // If user enters 0, cancel the transaction
            if (transferaccount == 0) {
                printf("\n\t\t\tAttempt to Transfer Funds has been cancelled.\n");
                transactionStatus = 2; // Set flag to indicate cancellation
                validAccount = 1; // Exit the loop
            }

            // Validate the account number is within range (10000000 - 99999999)
            else if (transferaccount >= 10000000 && transferaccount <= 99999999) {
                validAccount = 1;  // Valid account, exit loop
            } 
			
			else {
                // Account number out of range
                printf("\n\t\t\tWARNING: Account number must be within the prescribed range.\n");
                printf("\t\t\t--------------------------------------------------\n");
                printf("\t\t\tPress any key to try again...\n");
                getch();  // Wait for user to press a key
            }
        }

        // Check if the user cancelled
        if (transactionStatus == 2) {
            continue;
        }

        // Prompt for transfer amount
        printf("\n\t\t\tEnter amount to transfer or 0 to cancel: ");
        scanf("%f", &transferamount);

        // Checks if user input is zero for canceling the transfer
        if (transferamount == 0) {
            printf("\n\t\t\tAttempt to Transfer Funds has been cancelled.\n");
            transactionStatus = 2; // Set flag to indicate cancellation
            continue; // Skip further logic and re-enter the loop
        }

        // Validate the transfer amount (Check for negative values and range)
        int validAmount = 0; // Flag for valid transfer amount
        
        // Validate the transfer amount
        while (!validAmount) {
        	
        	
            if (transferamount > 1 && transferamount <= 50000) {
                validAmount = 1; // Valid amount, exit loop
            } 
            
            // Handle negative amounts
			else if (transferamount < 1) {
                printf("\n\t\t\tWARNING: Transfer amount cannot be less than one!\n");
                printf("\t\t\tPlease re-enter or 0 to cancel: ");
                scanf("%f", &transferamount);
            } 
			
			// Handle amounts outside the valid range
			else {
                printf("\n\t\t\tWARNING: Transfer amount must be a positive value between 1 and 50000!\n");
                printf("\t\t\tPlease re-enter or 0 to cancel: ");
                scanf("%f", &transferamount);
            }

            // If the user cancels by entering 0, exit the loop
            if (transferamount == 0) {
                printf("\n\t\t\tAttempt to Transfer Funds has been cancelled.\n");
                transactionStatus = 2;
                validAmount = 1; // Exit the loop
            }
        }

        // Check if the user cancelled
        if (transactionStatus == 2) {
            continue;
        }

        // Check if the user has sufficient balance for the transfer
        int validBalance = 0;  // Flag for sufficient balance
        while (!validBalance) {
        	
            if (transferamount <= *balance) {
                validBalance = 1;  // Sufficient balance, exit loop
            } 
            
			else {// Insufficient balance
                printf("\t\t\tWARNING! Current balance is insufficient to transfer that amount!\n");
                printf("\t\t\tYour current balance is P%.2f.\n", *balance);
                printf("\t\t\tPlease input an amount within your balance or 0 to cancel: ");
                scanf("%f", &transferamount);

                // If the user cancels by entering 0, exit the loop
                if (transferamount == 0) {
                    printf("\n\t\t\tAttempt to Transfer Funds has been cancelled.\n");
                    transactionStatus = 2;
                    validBalance = 1; // Exit the loop
                }
            }
        }

        // If transaction is canceled, skip to the next iteration
        if (transactionStatus == 2) {
            continue;
        }

        // Confirm transfer by inputting yes or no
        printf("\t\t\tYou are about to transfer P%.2f to Account Number: %d.\n", transferamount, transferaccount);
        printf("\t\t\tEnter 'Y' to confirm and 'N' to cancel: ");
        scanf(" %c", &confirm);
		
		// Process the transfer if confirmed
        if (confirm == 'Y' || confirm == 'y') {
            *balance -= transferamount;  // Correctly dereference the pointer to subtract the amount
            printf("\t\t\tTransfer of P%.2f has been sent to Account Number: %d.\n", transferamount, transferaccount);

            // Open the file to save transaction details
            FILE *fptr = fopen("TransactionHistory.txt", "a");
            // Input transaction details
            fprintf(fptr, "Transfer Funds\t\t-P%8.2f\tP%8.2f\t", transferamount, *balance);
            dateandtime(fptr);
            fclose(fptr);

            transactionStatus = 1; // Set flag to indicate success
        } 
        
        // Handle cancellation by the user
		else if (confirm == 'N' || confirm == 'n') {
            printf("\n\t\t\tTransfer canceled.\n");
            transactionStatus = 2; // Set flag to indicate cancellation
        } 
        
        // Handle invalid confirmation input
		else {
            printf("\t\t\tInvalid input. Transfer has not been processed.\n");
            transactionStatus = 2; // Set flag to indicate cancellation
        }
    }

    return transactionStatus; // Return the transaction status (1 for success, 2 for cancellation)
}

/*  
Function: paybills
Description: Allows the user to pay bills by selecting a biller and specifying the payment amount.
Precondition: The user must be logged in, and the balance pointer must point to a valid account balance.
@param balance - Pointer to the user's current account balance, which will be updated after a successful payment.
@return int - Returns 1 if the bill payment is successful, or 2 if the payment is canceled or failed.
 */
int paybills(float *balance) {
	
	//Variable Declaration and Initial Values
    int choice;
    char confirm;
    float amount = 0.0;
    int transactionStatus = 0; // Flag for controlling loops, 0 for running, 1 for completed, 2 for cancelled

    while (transactionStatus == 0) { // Loop until a successful transaction or failure
        system("cls"); // Clear the console (works on Windows)
        menuheader();  // Print the header/footer

        // Display biller options
        billerlist();
        
        // Get user choice
        printf("\n\t\t\t\t\tChoose Biller: ");
        scanf("%d", &choice);

        // Input validation for biller choice
        if (choice < 0 || choice > 5) {
            
            printf("\n\t\t\tWARNING: The chosen biller is not available. Please choose again.\n");
                printf("\t\t\t--------------------------------------------------\n");
                printf("\t\t\tPress any key to try again...\n");
                getch();  // Wait for user to press a key
                continue; // This will re-enter the loop and prompt again
        }

        // If the user selects 0, handle cancellation
        if (choice == 0) {
            printf("\n\t\t\t\tPayment canceled.\n");
            transactionStatus = 2; // Set flag to indicate cancellation (failure)
            
        } 
		
		else {
            // Prompt user for payment amount
            printf("\n\t\t\t\tEnter amount to pay for Biller %d: ", choice);
            scanf("%f", &amount);

            // Check if the payment amount is valid
            while (amount > *balance) {
                printf("\n\t\t\t\tInsufficient balance. Current balance is %.2f\n", *balance);
                printf("\n\t\t\t\tEnter an amount to pay or 0 to cancel: ");
                scanf("%f", &amount);

                // Allow the user to cancel
                if (amount == 0) {
                    printf("\n\t\t\t\tPayment canceled.\n");
                    transactionStatus = 2; // Set flag to indicate cancellation (failure)
                    break; // Exit the loop
                }
            }
			
			// If the amount is valid and the user has sufficient balance
            if (amount > 0 && amount <= *balance) {
                printf("\n\t\t\t\tYou are about to pay P%.2f to Biller %d.\n", amount, choice);
                printf("\t\t\t\tEnter 'Y' to confirm or 'N' to cancel: ");
                scanf(" %c", &confirm);

                if (confirm == 'Y' || confirm == 'y') {
                    *balance -= amount; // Deduct amount from balance
                    printf("\n\t\t\t\tPayment of P%.2f to Biller %d processed successfully.\n", amount, choice);

                    // Open the file to save transaction details
                    FILE *fptr = fopen("TransactionHistory.txt", "a");
                    fprintf(fptr, "Pay Bills\t\t-P%8.2f\tP%8.2f\t", amount, *balance);
                    dateandtime(fptr);
                    fclose(fptr); // Close the file

                    transactionStatus = 1; // Set flag to indicate success
                } 
				
				else {
                    printf("\n\t\t\t\tPayment canceled.\n");
                    transactionStatus = 2; // Set flag to indicate cancellation
                }
            }
        }
    }

    return transactionStatus; // Return the transaction status (1 for success, 2 for failure/cancellation)
}

/*  
Function: transactionhistory
Description: Displays the most recent 5 transactions from the transaction history file.
Precondition: The "TransactionHistory.txt" will contain transaction records.
@param None
@return void - This function doesn't return anything. It displays transaction history on the console.
*/
void transactionhistory() {
    // Print out layout
    system ("cls");
    menuheader();

    const int maxlinecount = 1000; // Maximum number of transactions (lines) to read
    const int numberoflines = 256;  // Size for each line (transaction string)

    FILE *file;
    char transactions[maxlinecount][numberoflines]; // Array to hold transactions
    int count = 0; // Initial count of lines inside transaction history

    // Open the file containing transactions
    file = fopen("TransactionHistory.txt", "r"); //r for read
    if (file == NULL) { // Check for file opening error
        printf("Error opening file.\n");
        return; // Exit if file cannot be opened
    }

    // Read all transactions from the file and counts it
    while (fgets(transactions[count], sizeof(transactions[count]), file) != NULL && count < maxlinecount) {
    	//adds to count per line that it reads
        count++; 
    }

    fclose(file); // Close the file after reading

 	//determines where to start and checks the amount of lines given in transaction history
    int start; 
    
    if (count > 5) {
        start = count - 5; // Start printing the 5th last transaction if more than 5 transactions exist
    } else {
        start = 0; // Start from 0 if there are 5 or fewer transactions
    }

    // Print the transactions in reverse order
    printf("\n\t\t\t\t\t   Transactions\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Transaction #\tTransaction Type\tAmount\t\tBalance\t\tDate and Time\n");

    // Print the transactions [i]
    //prints the transaction count as well [j]
   for (int i = count - 1, j = 1; i >= start && j <= 5; i--, j++) {
    printf("%d\t\t%s", j, transactions[i]);  // Print transaction number and transaction line
	}
	
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Press any key to go back to Main Menu...\n");
    getch();  // Wait for a key press
}

