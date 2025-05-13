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

/******************************************************************
This is to certify that this project is my own work, based on 
my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective 
algorithms and corresponding code by myself. The program was run, tested, 
and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work 
of other students and/or persons. 
Paingan, Edriene James, DLSU ID# 12413984
******************************************************************/

int main (){

	//Setting up Variables and Initial Datas
	float accountbalance = 1000.00;
	const int accountnumber = 12413984;
	int pinnumber = 123456;
	int choices; //choice for user interface

	
	//variables for function result
	int loginresult;
	int changepinresult;
	int balanceresult;
	int depositresult;
	int withdrawalresult;
	int transferfundsresult;
	int paybillsresult;
	
	//loop so user will go back to account log in once user logouts
	while (1) {
		system("cls"); //clears screen
	    menuheader(); //display header menu
		accountloginmenu(); //display login menu
					
		// Attempt to log in
		loginresult = login(accountnumber, &pinnumber);
					
		if (loginresult == 1) {  // Successful login
		
			do { // This loop continues until the user chooses to log out (by selecting option 0)
				
				system("cls");
				menuheader();
				atmlogo();
				printf("\t\t\t    Login Successful! Welcome, User %d!\n", accountnumber);
				choices = displaymenu(); //makes sure that choice is only betwwen 0 and 7
				
					// Change PIN (Option 1)
					if (choices == 1) {
					    
					    system("cls");
					    menuheader();
					    accountloginmenu(); 
					    printf("\n\t      NOTE: To change your PIN, please log in again to verify your identity.\n\n");
					
					    loginresult = login(accountnumber, &pinnumber); // Additional authentication required for security
					
					    if (loginresult == 1) { // Successful re-login
					    
					        changepinresult = changepin(&pinnumber); // Call the change PIN function
					
					        if (changepinresult == 1) {
					        	printf("\n\t\t\tYour PIN has been successfully changed.\n");
								printf("\t\t\tFor security reasons, you will now be logged out.\n");
								printf("\t\t\t--------------------------------------------------\n");
					            printf("\t\t\tPress any key to continue...\n");
								getch();
					            choices = 0;
					        } else if (changepinresult == 2) {
					            printf("\t\t\t--------------------------------------------------\n");
					            printf("\t\t\tAttempt to Change Pin has been cancelled.\n");
					            printf("\t\t\tPress any key to go back to Main Menu...\n");
					            getch();
					        } else {
					            printf("Transaction did not complete.\n");
					            printf("--------------------------------------------------\n");
					            printf("Press any key to go back to Main Menu...\n");
					            getch();
					        }
					    }
					    
					    else{
					    	
					    	continue;
					    	
						}
					} 
					
					// Display Account Balance (Option 2)
					else if (choices == 2) {
				
					    menuheader();
					    balanceresult = balance(&accountbalance, accountnumber);
					
					    if (balanceresult == 1) {
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    }
					    
					} 
					
					// Deposit Money (Option 3)
					else if (choices == 3){
					
					    depositresult = deposit(&accountbalance);
					
					    if (depositresult == 1) {
					        printf("\t\t\t   --------------------------------------------------\n");
					        printf("\t\t\t   Successful Deposit!\n");
					        printf("\t\t\t   Total Balance after deposits: P%.2f\n", accountbalance);
					        printf("\t\t\t   Press any key to go back to Main Menu...\n");
					        getch();
					    } else if (depositresult == 2) {
					        printf("\t\t\t   --------------------------------------------------\n");
					        printf("\t\t\t   Attempt to Deposit has been cancelled.\n");
					        printf("\t\t\t   Press any key to go back to Main Menu...\n");
					        getch();
					    } else {
					        printf("\t\t\t   --------------------------------------------------\n");
					        printf("\t\t\t   Transaction did not complete.\n");
					        printf("\t\t\t   Press any key to go back to Main Menu...\n");
					        getch();
					    }
					} 
					
					// Withdrawal (Option 4)
					else if (choices == 4) {
					    
					    withdrawalresult = withdrawal(&accountbalance);
					
					    if (withdrawalresult == 1) {
					        printf("\t\t\tSuccessful Withdrawal!\n");
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tTotal Balance after Withdrawal: P%.2f\n", accountbalance);
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else if (withdrawalresult == 2) {
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tAttempt to Withdraw has been cancelled.\n");
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else {
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tTransaction did not complete.\n");
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    }
					} 
					
					// Transfer Funds (Option 5)
					else if (choices == 5) {
					    // Transfer Funds (Option 5)
					    transferfundsresult = transferfunds(&accountbalance, accountnumber);
					
					    if (transferfundsresult == 1) {
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tAttempt to Transfer Funds has been successful.\n");
					        printf("\t\t\tRemaining: P%.2f\n", accountbalance);
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else if (transferfundsresult == 2) {
					        printf("\t\t\t--------------------------------------------------\n");
					        printf("\t\t\tAttempt to Transfer Funds has been cancelled.\n");
					        printf("\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else {
					    
					        printf("\t\t\t   Transaction did not complete.\n");
					        printf("\t\t\t   Press any key to go back to Main Menu...\n");
					        getch();
					    }
					} 
					
					// Pay Bills (Option 6)
					else if (choices == 6) {
					    
					    paybillsresult = paybills(&accountbalance);
					
					    if (paybillsresult == 1) {
					    	printf("\t\t\t\t--------------------------------------------------\n");
					        printf("\t\t\t\tTransaction was successful.\n");
					        printf("\t\t\t\tRemaining balance: %.2f\n", accountbalance);
					        printf("\t\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else if (paybillsresult == 2) {
					    	printf("\t\t\t\t--------------------------------------------------\n");
					        printf("\t\t\t\tTransaction was canceled.\n");
					        printf("\t\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    } else {
					    	printf("\t\t\t\t--------------------------------------------------\n");
					        printf("\t\t\t\tTransaction did not complete.\n");
					        printf("\t\t\t\tPress any key to go back to Main Menu...\n");
					        getch();
					    }
					} 
					
					// Transfer Funds (Option 5)
					else if (choices == 7) {
					   
					    transactionhistory();
					    
					}
					
	    	} while (choices != 0); // Loop until the user chooses to logout
	    	
	    	//User Chooses 0 to logout and exits the loop that directs it here
	    	printf("\t\t\t--------------------------------------------------\n");
            printf("\t\t\t\t\t  Logging out  ");
            loading(); // Simulating a wait before logout
            continue; // Go back to loop
		}
		
		else if (loginresult == 2){ //2 means 3 attempts is done so failed to login
			
			printf("\t\t\t\t   Program will now terminate.\n");
			Sleep(3000);
			return 0;	
		
		}	   	
	}
}