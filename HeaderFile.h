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
algorithms
and corresponding code by myself. The program was run, tested, 
and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work 
of other students and/or persons. 
Paingan, Edriene James, DLSU ID# 12413984
******************************************************************/

#ifndef HEADERFILE_H  
#define HEADERFILE_H  

// Libraries used
#include <stdio.h>    // for Basic Functions: printf() and scanf()
#include <conio.h>    // for getch() 
#include <stdlib.h>   // for system("cls") and system("chcp 65001");
#include <windows.h>  // for Sleep()
#include <time.h>     // for time function

// Function Declarations
int displaymenu();                          // Function to display menu options
int login(const int nAccountNumber, int *nAccountPin);   // Function for login
int changepin(int *currentpin);             // Function to change the pin
int balance(float *balance, int nAccountNumber);   // Function to check balance
int deposit(float *balance);               // Function to deposit money
int withdrawal(float *balance);            // Function to withdraw money
int transferfunds(float *balance, int accountnumber);  // Function for fund transfer
int paybills(float *balance);              // Function to pay bills
void transactionhistory();                 // Function to view transaction history

// Display function declarations
void atmlogo();                            // Function to display ATM logo
void dateandtime(FILE *fptr);              // Function to get current date and time
void menuheader();                         // Function to display menu header
void mainmenu();                           // Function to add Menu Choices
void denominationlist();                   // Function to add Denomination List
void billerlist();                         // Function to add Biller List
void accountloginmenu();                   // Function to display account login menu
void loading();                            // Function to simulate a loading animation

#include "FunctionFile.c"

#endif 