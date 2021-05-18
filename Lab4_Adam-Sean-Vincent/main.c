//lab4.c
#include "linklist.h"


int main() //add on to menu
{
    puts("Welcome to the FedEx delivery database"); //we are FedEx
    ItemPtr startPtr,tempPtr;
    char number[SIZE];

    int value, choice;
    startPtr = NULL;
    
    menu();
    fgets(number, SIZE-1, stdin);
    choice = (int) strtol(number,NULL,10);   
    while (choice != 6){
      switch (choice){
        case 1: printf("\nEnter a new delivery ID: "); //making a new delivery item
                fgets(number,SIZE-1,stdin);
                value = (int) strtol(number,NULL,10);
        	startPtr = addItem(startPtr, value);
                tempPtr = startPtr;
                puts("The present ID's are:");
                while (tempPtr != NULL)
	        {
	        printf ("%d   ", tempPtr->id);
	        tempPtr = tempPtr->next;
	        }
                puts("");
                break;

        case 2: printf("\nEnter delivery ID for deletion : "); //getting rid of someone's work
                fgets(number,SIZE-1,stdin);
                value = (int) strtol(number,NULL,10);
                startPtr = removeItem(startPtr, value);
                tempPtr = startPtr;
                puts("The present ID's are:");
                while (tempPtr != NULL)
	        {
	        printf ("%d   ", tempPtr->id);
	        tempPtr = tempPtr->next;
	        }
                puts("");
                break;

        case 4: printf("\nEnter delivery ID to View : "); //see who is paying what
                fgets(number,SIZE-1,stdin);
                value = (int) strtol(number,NULL,10);
                viewItem(startPtr, value);
                printf("\n");
                break;

        case 5: puts("Do you want to print to screen or to a text file (1 for screen, 2 for text file)?"); //get the whole list
                fgets(number,SIZE-1,stdin);
                if (number[0] == '1')
		   printList(startPtr);
                else if (number[0] == '2')
                   printFile(startPtr);
                else
                   puts("That was not a valid option");
                printf("\n");
                break;

	case 3: puts("\nEnter a delivery ID to update : "); //change... something
		fgets(number,SIZE-1,stdin);
                value = (int) strtol(number,NULL,10);
		updateItem(startPtr, value);
		puts("");
		break;

        default: printf ("Invalid Option... Please Try Again \n"); //when people can't follow directions
                break;
      }
      menu();
      fgets(number, SIZE-1, stdin);
      choice = (int) strtol(number,NULL,10);      
    }
    puts("Have fun running delivery's");

    return 0;
}




