#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void anotherTrans(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) {
    int userSelect;
    int userNum;
    printf("\n\nWould you like another transaction?\n0: Yes \n1: No\n");
    scanf("%d", &userSelect);
    system("cls");

    if (userSelect == 0) {
            printf("\nWhat would you like to do today?\n0: Account Info\n1: Pay Bills\n2: Withdraw Funds\n3: Deposit Funds\n4: Transfer Funds\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        checkAccountInfo(*cashBal, *savingAcct, *checkingAcct, *loanAcct, *creditAcct);
                        break;
                    case 1:
                        payBillsTrans(*cashBal, *savingAcct, *checkingAcct, *loanAcct, *creditAcct);
                        break;
                    case 2:
                        withdrawAcctTrans(*cashBal, *savingAcct, *checkingAcct, *loanAcct, *creditAcct);
                        break;
                    case 3:
                        depositAcctTrans(*cashBal, *savingAcct, *checkingAcct, *loanAcct, *creditAcct);
                        break;
                    case 4:
                        transferAcctTrans(*cashBal, *savingAcct, *checkingAcct, *loanAcct, *creditAcct);
                        break;
                    default:
                        printf("Please Select One Of The Options Provided\n");
                    }
    }
}

void checkForInsFunds (int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) {
    //check for insufficient funds, too sleepy, think about this later

}

void checkAccountInfo(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) { //function allows user to display acct info on screen
	int userSelect;
	int userNum;
	system("cls");
	printf("\nYour Account Info:\nCash Balance: %d\nCheckings: %d\nSavings: %d\nLoan Balance: %d\nCredit Balance: %d\n", *cashBal, *checkingAcct, *savingAcct, *loanAcct, *creditAcct);
    anotherTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
}

void payBillsTrans(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) {  //function allows user to pay bills
	int userSelect;
	int userNum;
	int electricBill = 100;
	int insuranceBill = 150;
	printf("\nWhich bill would you like to pay?\n0: Loan\n1: Credit Account\n2: Electric\n3: Insurance\n"); //Pay Loan, credit card, electric, insurance
	scanf("%d", &userSelect);
	system("cls");
	switch (userSelect) {
        case 0:
            printf("\nLoan Payment! How much would you like to pay?\n\nLoan Balance: %d\n", *loanAcct);
            scanf("%d", &userNum);
            printf("\nWhat are you paying with?\n0: Checking\n1: Saving\n2: Credit\n3: Cash\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        *checkingAcct = *checkingAcct - userNum;
                        *loanAcct = *loanAcct - userNum;
                        printf("Payment of %d was made on your loan with your checking account.", userNum);
                        break;
                    case 1:
                        *savingAcct = *savingAcct - userNum;
                        *loanAcct = *loanAcct - userNum;
                        printf("Payment of %d was made on your loan with your saving account.", userNum);
                        break;
                    case 2:
                        *creditAcct = *creditAcct - userNum;
                        *loanAcct = *loanAcct - userNum;
                        printf("Payment of %d was made on your loan with your credit account.", userNum);
                        break;
                    case 3:
                        *cashBal = *cashBal - userNum;
                        *loanAcct = *loanAcct - userNum;
                        printf("Payment of %d was made on your loan with cash.", userNum);
                        break;
                    default:
                        printf("Please Select One Of The Options Provided\n");
                }
            break;
        case 1:
            printf("\nCredit Payment! How much would you like to pay?\n\nCredit Balance: %d\n", *creditAcct);
            scanf("%d", &userNum);
            printf("\nWhat are you paying with?\n0: Checking\n1: Saving\n2: Cash\n");
            scanf("%d", userSelect);
                switch (userSelect) {
                    case 0:
                        *checkingAcct = *checkingAcct - userNum;
                        *creditAcct = *creditAcct + userNum;        //credit increase because it's credit
                        printf("Payment of %d was made on your credit account with your checking account.", userNum);
                        break;
                    case 1:
                        *savingAcct = *savingAcct - userNum;
                        *creditAcct = *creditAcct + userNum;
                        printf("Payment of %d was made on your credit account with your saving account.", userNum);
                        break;
                    case 2:
                        *cashBal = *cashBal - userNum;
                        *creditAcct = *creditAcct + userNum;
                        printf("Payment of %d was made on your credit account with cash.", userNum);
                        break;
                    default:
                        printf("Please Select One Of The Options Provided\n");
                }
            break;
        case 2:
            printf("\nElectric Bill Payment! How much would you like to pay?\n\nElectric Bill Balance: %d", electricBill);
            scanf("%d", &userNum);
            printf("\nWhat are you paying with?\n0: Checking\n1: Saving\n2: Credit\n3: Cash\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        *checkingAcct = *checkingAcct - userNum;
                        electricBill = electricBill - userNum;
                        printf("Payment of %d was made on your electric bill with your checking account.", userNum);
                        break;
                    case 1:
                        *savingAcct = *savingAcct - userNum;
                        electricBill = electricBill - userNum;
                        printf("Payment of %d was made on your electric bill with your saving account.", userNum);
                        break;
                    case 2:
                        *creditAcct = *creditAcct - userNum;
                        electricBill = electricBill - userNum;
                        printf("Payment of %d was made on your electric bill with your credit account.", userNum);
                        break;
                    case 3:
                        *cashBal = *cashBal - userNum;
                        electricBill = electricBill - userNum;
                        printf("Payment of %d was made on your electric bill with cash.", userNum);
                        break;
                    default:
                        printf("Please Select One Of The Options Provided\n");
                }
            break;
        case 3:
            printf("\nInsurance Bill Payment! How much would you like to pay?\n\nInsurance Bill Balance: $%d", insuranceBill);
            scanf("%d", &userNum);
            printf("\nWhat are you paying with?\n0: Checking\n1: Saving\n2: Credit\n3: Cash\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        *checkingAcct = *checkingAcct - userNum;
                        insuranceBill = insuranceBill - userNum;
                        printf("Payment of %d was made on your electric bill with your checking account.", userNum);
                        break;
                    case 1:
                        *savingAcct = *savingAcct - userNum;
                        insuranceBill = insuranceBill - userNum;
                        printf("Payment of %d was made on your electric bill with your saving account.", userNum);
                        break;
                    case 2:
                        *creditAcct = *creditAcct - userNum;
                        insuranceBill = insuranceBill - userNum;
                        printf("Payment of %d was made on your electric bill with your credit account.", userNum);
                        break;
                    case 3:
                        *cashBal = *cashBal - userNum;
                        insuranceBill = insuranceBill - userNum;
                        printf("Payment of %d was made on your electric bill with cash.", userNum);
                        break;
                    default:
                        printf("Please Select One Of The Options Provided\n");
                }
            break;
        default:
            printf("please select one of  our listed options.\n");
	}
    anotherTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
}

void withdrawAcctTrans(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) { //function allows user to withdraw funds
	int userSelect;
	int userNum;
	printf("\nWithdraw from which account?\n");
	printf("0: Checking\n1: Saving\n");
	scanf("%d", &userSelect);
	system("cls");

	switch (userSelect) {
        case 0:
            printf("Checking Account! How much would you like to withdraw? Must be divisible by 20.\n");
            printf(" 0: $20\n1: $40\n2: $60\n3: $80\n4: 100\n5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Dispensing $20**\n");
                        *checkingAcct = *checkingAcct - 20;
                        *cashBal = *cashBal + 20;
                        break;
                    case 1:
                        printf("**Dispensing $40**\n");
                        *checkingAcct = *checkingAcct - 40;
                        *cashBal = *cashBal + 40;
                        break;
                    case 2:
                        printf("**Dispensing $60**\n");
                        *checkingAcct = *checkingAcct - 60;
                        *cashBal = *cashBal + 60;
                        break;
                    case 3:
                        printf("**Dispensing $80**\n");
                        *checkingAcct = *checkingAcct - 80;
                        *cashBal = *cashBal + 80;
                        break;
                    case 4:
                        printf("**Dispensing $100**\n");
                        *checkingAcct = *checkingAcct - 100;
                        *cashBal = *cashBal + 100;
                        break;
                    case 5:
                        printf("What other amount would you like to withdraw? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum);
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Dispensing $%d**\n", userNum);
                        *checkingAcct = *checkingAcct - userNum;
                        *cashBal = *cashBal + userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        case 1:
            printf("Savings Account! How much would you like to withdraw?\n");
            printf("0: $20\n 1: $40\n 2: $60\n3: $80\n 4: 100\n 5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Dispensing $20**\n");
                        *savingAcct = *savingAcct - 20;
                        break;
                    case 1:
                        printf("**Dispensing $40**\n");
                        *savingAcct = *savingAcct - 40;
                        break;
                    case 2:
                        printf("**Dispensing $60**\n");
                        *savingAcct = *savingAcct - 60;
                        break;
                    case 3:
                        printf("**Dispensing $80**");
                        *savingAcct = *savingAcct - 80;
                        break;
                    case 4:
                        printf("**Dispensing $100**\n");
                        *savingAcct = *savingAcct - 100;
                        break;
                    case 5:
                        printf("What other amount would you like to withdraw? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum); //IMPORTANT: double check that amount is divisible by 20
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Dispensing $%d**\n", userNum);
                        *savingAcct = *savingAcct - userNum;
                        *cashBal = *cashBal + userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        default:
            printf("please select one of  our listed options.\n");
	}
    anotherTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
}

void depositAcctTrans(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) { //function allows user to add funds to checking or savings acct
	int userSelect;
	int userNum;
	printf("\Deposit into which account?\n");
	printf("0: Checking\n1: Saving\n");
	scanf("%d", &userSelect);
	system("cls");

	switch (userSelect) {
        case 0:
            printf("Checking Account! How much would you like to deposit?\n");
            printf(" 0: $20\n 1: $40\n 2: $60\n 3: $80\n 4: 100\n 5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Please Insert $20**\n");
                        *checkingAcct = *checkingAcct + 20;
                        *cashBal = *cashBal - 20;
                        break;
                    case 1:
                        printf("**Please Insert $40**\n");
                        *checkingAcct = *checkingAcct + 40;
                        *cashBal = *cashBal - 40;
                        break;
                    case 2:
                        printf("**Please Insert $60**\n");
                        *checkingAcct = *checkingAcct + 60;
                        *cashBal = *cashBal - 60;
                        break;
                    case 3:
                        printf("**Please Insert $80**\n");
                        *checkingAcct = *checkingAcct + 80;
                        *cashBal = *cashBal - 80;
                        break;
                    case 4:
                        printf("**Please Insert $100**\n");
                        *checkingAcct = *checkingAcct + 100;
                        *cashBal = *cashBal - 100;
                        break;
                    case 5:
                        printf("What other amount would you like to deposit? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum);
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Please Insert $%d**\n", userNum);
                        *checkingAcct = *checkingAcct + userNum;
                        *cashBal = *cashBal - userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        case 1:
            printf("Savings Account! How much would you like to deposit?\n");
            printf("0: $20\n 1: $40\n 2: $60\n3: $80\n 4: 100\n 5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Please Insert $20**\n");
                        *savingAcct = *savingAcct + 20;
                        *cashBal = *cashBal - 20;
                        break;
                    case 1:
                        printf("**Please Insert $40**\n");
                        *savingAcct = *savingAcct + 40;
                        *cashBal = *cashBal - 40;
                        break;
                    case 2:
                        printf("**Please Insert $60**\n");
                        *savingAcct = *savingAcct + 60;
                        *cashBal = *cashBal - 60;
                        break;
                    case 3:
                        printf("**Please Insert $80**\n");
                        *savingAcct = *savingAcct + 80;
                        *cashBal = *cashBal - 80;
                        break;
                    case 4:
                        printf("**Please Insert $100**\n");
                        *savingAcct = *savingAcct + 100;
                        *cashBal = *cashBal - 100;
                        break;
                    case 5:
                        printf("What other amount would you like to deposit? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum); //IMPORTANT: double check that amount is divisible by 20
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Please Insert $%d**\n", userNum);
                        *savingAcct = *savingAcct + userNum;
                        *cashBal = *cashBal - userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        default:
            printf("please select one of  our listed options.\n");
	}
    anotherTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
}

void transferAcctTrans(int* cashBal, int* savingAcct, int* checkingAcct, int* loanAcct, int* creditAcct) {
	int userSelect;
	int userNum;
	printf("\Select the transfer that you would like to make:\n");
	printf(" 0: Checking to Saving\n 1: Saving to Checking\n");
	scanf("%d", &userSelect);
	system("cls");

	switch (userSelect) {
        case 0:
            printf("Transferring from checking to saving! How much would you like to transfer?\n");
            printf("0: $20\n 1: $40\n 2: $60\n3: $80\n 4: 100\n 5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Transferring $20**\n");
                        *savingAcct = *savingAcct + 20;
                        *checkingAcct = *checkingAcct - 20;
                        break;
                    case 1:
                        printf("**Transferring $40**\n");
                        *savingAcct = *savingAcct + 40;
                        *checkingAcct = *checkingAcct - 40;
                        break;
                    case 2:
                        printf("**Transferring $60**\n");
                        *savingAcct = *savingAcct + 60;
                        *checkingAcct = *checkingAcct - 60;
                    case 3:
                        printf("**Transferring $80**\n");
                        *savingAcct = *savingAcct + 80;
                        *checkingAcct = *checkingAcct - 80;
                    case 4:
                        printf("**Transferring $100**\n");
                        *savingAcct = *savingAcct + 100;
                        *checkingAcct = *checkingAcct - 100;
                        break;
                    case 5:
                        printf("What other amount would you like to transfer? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum); //IMPORTANT: double check that amount is divisible by 20
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Transferring $%d**\n", userNum);
                        *savingAcct = *savingAcct + userNum;
                        *checkingAcct = *checkingAcct - userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        case 1:
            printf("Transferring from saving to checking! How much would you like to transfer?\n");
            printf("0: $20\n 1: $40\n 2: $60\n3: $80\n 4: 100\n 5: Other Amount\n");
            scanf("%d", &userSelect);
                switch (userSelect) {
                    case 0:
                        printf("**Transferring $20**\n");
                        *savingAcct = *savingAcct - 20;
                        *checkingAcct = *checkingAcct + 20;
                        break;
                    case 1:
                        printf("**Transferring $40**\n");
                        *savingAcct = *savingAcct - 40;
                        *checkingAcct = *checkingAcct + 40;
                        break;
                    case 2:
                        printf("**Transferring $60**\n");
                        *savingAcct = *savingAcct - 60;
                        *checkingAcct = *checkingAcct + 60;
                    case 3:
                        printf("**Transferring $80**\n");
                        *savingAcct = *savingAcct - 80;
                        *checkingAcct = *checkingAcct + 80;
                    case 4:
                        printf("**Transferring $100**\n");
                        *savingAcct = *savingAcct - 100;
                        *checkingAcct = *checkingAcct + 100;
                        break;
                    case 5:
                        printf("What other amount would you like to transfer? Amount must be divisible by 20.\n");
                        scanf("%d", &userNum); //IMPORTANT: double check that amount is divisible by 20
                        if (userNum % 20 != 0) {
                            while (userNum % 20 != 0) {
                                printf("\nPlease enter a number that is divisible by 20.\n");
                                scanf("%d", &userNum);
                            }
                        }
                        printf("**Transferring $%d**\n", userNum);
                        *savingAcct = *savingAcct - userNum;
                        *checkingAcct = *checkingAcct + userNum;
                        break;
                    default:
                        printf("please select one of  our listed options.\n");
                }
            break;
        default:
            printf("please select one of  our listed options.\n");
	}
    anotherTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
}

int main(void) {
	int checkingAcct = 250;     //checking account
	int savingAcct = 2750;      //saving account
	int loanAcct = 9000;        //loan balance
	int creditAcct = 500;       //credit card account
	int cashBal;                //cash on hand
	int userInput;
	printf("Welcome to FirstBanc!  Where people come to Banc First!\n\nHow much cash do you have?\n"); //
	scanf("%d", &cashBal);
	system("cls");
	printf("\nWhat would you like to do today?\n0: Account Info\n1: Pay Bills\n2: Withdraw Funds\n3: Deposit Funds\n4: Transfer Funds\n");
	scanf("%d", &userInput);
	//ACCOUNT INFO, PAY BILLS, WITHDRAW, DEPOSIT, TRANSFER
	switch (userInput) {
        case 0:
            checkAccountInfo(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
            break;
        case 1:
            payBillsTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
            break;
        case 2:
            withdrawAcctTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
            break;
        case 3:
            depositAcctTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
            break;
        case 4:
            transferAcctTrans(&cashBal, &savingAcct, &checkingAcct, &loanAcct, &creditAcct);
            break;
        default:
            printf("Please Select One Of The Options Provided");
	}
    printf("\n\n******Thank you for choosing FirstBanc!!******\n\n\n");
	return 0;
}

