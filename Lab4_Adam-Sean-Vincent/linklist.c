#include "linklist.h"



void menu () //MENUUUUUUUUUUUUUUUUUUUU

{
  
puts("\t1: Insert a new delivery ID");

puts("\t2: Remove a specific delivery ID from the list");
  
puts("\t3: Update a specific delivery ID");
  
puts("\t4: View a specific delivery ID");
  
puts("\t5: Print all information to (the screen or a text file)");
  
puts("\t6: Exit");
  printf ("\tEnter Choice: ");

} 
 

ItemPtr makeItem (int value) //creation of the delivery object

{
  
   char adr[SIZE];
  
   char num[SIZE];
  
   ItemPtr np = (ItemPtr) malloc (sizeof (Item));
  
   np->id = value;
  
   puts("Please enter the address to deliver the product");
  
   fgets(adr,SIZE-1,stdin);
  
   strtok(adr,"\n");
  
   strcpy(np->address,adr);
  
   puts("Please enter the cost of the product");
  
   fgets(num,SIZE-1,stdin);
  
   np->cost = strtof(num,NULL);
  
   np->next = NULL;
  
   return np;

}


void printList (ItemPtr sPtr) //print information to the screen

{
  
   if (sPtr == NULL)
  
   {
      printf ("\nThere are no Items to be Printed\n");
   }
   else  
   {      
      printf ("The Items in the List Are As Follows: \n");
      while (sPtr != NULL)
      {
         printf ("%d\t%s\t$%.2f\n", sPtr->id, sPtr->address, sPtr->cost);  
         sPtr = sPtr->next;
	
      }

   }


}
void printFile (ItemPtr sPtr) //Print information to a file

{
  
  FILE *outPtr;
  char name[25];
  
  if (sPtr == NULL)
  
  {

  printf ("\nThere are no delivery information printed\n");
  
  }
  
  else
     
  {
        
    puts("Name the file you wish to output to");
        
    fgets(name,19,stdin);
        
    strtok(name,"\n");
        
    strcat(name,".txt");
        
    if((outPtr = fopen(name,"w"))==NULL) //make sure writing permissions on the output file are there
        
    {
      puts("Output File could not be opened");

    }
    else
    {
      while (sPtr != NULL)
      {
        fprintf (outPtr, "%d\t%s\t$%.2f\n",sPtr->id, sPtr->address, sPtr->cost);

        sPtr = sPtr->next;

      }
      fclose(0outPtr);
    }
  }

}





ItemPtr addItem (ItemPtr sPtr, int value) //Add a new delivery item
{
  ItemPtr newPtr, currPtr, prevPtr;
  prevPtr = NULL;
  currPtr = sPtr;
  while (currPtr != NULL && value != currPtr->id)

  {
    currPtr = currPtr->next;
  }
  if (currPtr == NULL)
  {
    newPtr = makeItem (value);
    currPtr = sPtr;

    while (currPtr != NULL && value > currPtr->id)
    {
      prevPtr = currPtr;
      currPtr = currPtr->next;
    }
    if (prevPtr == NULL)
    {// inserting at the start of the list
      newPtr->next = sPtr;
      sPtr = newPtr;		// start of list has now changed

    }
    else
    {
    newPtr->next = currPtr;
    prevPtr->next = newPtr;
    }
    return sPtr;

    }
    else
    {
    puts("That id already exists, please make a new id");
    return sPtr;
}
}


ItemPtr updateItem (ItemPtr sPtr, int value) //Update an existing delivery
{
ItemPtr newPtr, currPtr, prevPtr, tempPtr;
prevPtr = NULL;
currPtr = sPtr;
while (currPtr != NULL && value != currPtr->id)
{
currPtr = currPtr->next;
}
if (currPtr != NULL)
{
tempPtr = sPtr;
sPtr = sPtr->next;// start of list has been changed
printf ("\nItem ( %d ) was deleted \n", tempPtr->id);
free (tempPtr);
newPtr = makeItem (value);
currPtr = sPtr;
while (currPtr != NULL && value > currPtr->id)
{
prevPtr = currPtr;
currPtr = currPtr->next;
}
if (prevPtr == NULL)
{			// inserting at the start of the list
      newPtr->next = sPtr;
      sPtr = newPtr;		// start of list has now changed
    }
    else
       {
         newPtr->next = currPtr;
         prevPtr->next = newPtr;
       }

    return sPtr;
  }
  else
  {
    puts("That ID doesn't exist, please choose an existing ID");
    return sPtr;
  }
}




ItemPtr removeItem (ItemPtr sPtr, int value) //Remove an existing delivery from the list
{
  ItemPtr previousPtr, currentPtr, tempPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
   
  if (sPtr == NULL)
  {
    printf ("\nThe List is empty... No delivery's to be Removed\n");
    return sPtr;
  }
  
  while (currentPtr != NULL && currentPtr->id != value)
  {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }
  
  if (currentPtr == NULL)
  {
    printf ("\nID ( %d ) was not found \n", value);
  }
  else if (previousPtr == NULL)
    {				// if node to be deleted is the first node
      tempPtr = sPtr;
      sPtr = sPtr->next;	// start of list has been changed
      printf ("\nID ( %d ) was deleted \n", tempPtr->id);
      free (tempPtr);
    }
    else
     {
       tempPtr = currentPtr;
       previousPtr->next = currentPtr->next;
       printf ("\nID ( %d ) was deleted \n", tempPtr->id);
       free (tempPtr);
     }
  
  return sPtr;
}

void viewItem (ItemPtr sPtr, int value) //View a specific delivery
{
  ItemPtr previousPtr, currentPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  int position = 0;
  
  if (sPtr == NULL)
  {
    printf ("\nThe List is empty... No delivery's to View\n");
    return;
  }
  
  while (currentPtr != NULL && currentPtr->id != value)
  {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
    position++;
  }
  
  if (currentPtr == NULL)
  {
     printf ("\nID ( %d ) was not found \n", value);
  }
  else
     {
        printf ("\n%d\t%s\t$%.2f\n", currentPtr->id, currentPtr->address, currentPtr->cost);
     }
}

