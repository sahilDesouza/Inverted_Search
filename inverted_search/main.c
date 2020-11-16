/*
Author: Sahil Desouza
Date: 21/09/2020
Title: Inverted Search
*/


#include "inverted_search.h"

int main(int argc, char *argv[])
{
	
	//Create array of structure pointer
        //Declare head[27] : Outof 27, 26 are for 26 alphabets and 27th one other alphabets
	Wlist *head[27] = {NULL};
	
	//printf("\033[0;32m"); //Set the text to the color green

	//CLA validation
	if( argc <= 1)
	{
		printf("Enter valid number of arguments\n");
		printf("./Slist.exe f1.txt f2.txt ...\n");
		return 0;
	}

	//create a list of files passed through command line
	//declare a head pointer for file structure
	Flist * f_head = NULL, *temp_flist = NULL;

	//initialise the required variables
	int choice;
	char option;
	char word[WORD_SIZE];

	//Validate the file, If valid file is present then only add into file list
	file_validation_n_file_list(&f_head, argv);

	//If there is no valid file then list is empty
	if( f_head == NULL)
	{
		printf("No files available in the file list\n");
		printf("Hence process is terminating\n");
		return 1;

	}
	
	//printf("\033[0m"); //Resets the text to default color

	do
	{
		//prompt options to user
		printf("Select your choice among following options:\n");
		printf("1. Create DATABASE\n");
		printf("2. Display Database\n");
		printf("3. Update DATABASE\n");
		printf("4. Search\n");
		printf("5. Save Database\n");

		//Prompt user to enter choice
		printf("Enter your choice:"); 
		scanf("%d", &choice); 

		switch( choice)
		{
			case 1:
				//printf("\033[0;34m"); //Set the text to the color Blue
				//function call to create the database
				create_database(f_head, head);
				break;
			case 2: 
				//function call to display the data present in the database
				display_database(head);
				break;
			case 3:
				//printf("\033[0;34m"); //Set the text to the color Blue
				//storing f_head address in a temporary pointer
				temp_flist = f_head;
				//printf("%p", temp_flist);
				//function call to update the database provided its not empty
				update_database(head, &temp_flist);
				break;

			case 4:
				printf("Enter the word you want to search: ");
				scanf("%s", word);
				//function call to search for the prompted word
				search(head[tolower(word[0]) % 97], word);
				break;
				
			case 5:
				//printf("\033[0;34m"); //Set the text to the color Blue
				//function call to save data to the database
				save_database(head);
				break;
				
			default:
				printf("Entered invalid choice\nTry again.......\n");

		}
		//printf("\033[0m"); //Resets the text to default color

		printf("\n");
		//option whether you want to continue or not
		//if 'y' loop through again else break out
            	printf("Do you want to continue y/n:");
		scanf(" %c", &option);
		if (option == 'y' || option == 'Y')
            	{
                	continue;
            	}
            	else
            	{
                	break;
            	}
	} while(option);
	return 0;
}


