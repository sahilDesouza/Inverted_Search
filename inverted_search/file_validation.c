#include"inverted_search.h"

//function for file validation
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
	int i = 1, ret_val, status;

	//gets the ith argument from the command line
	//iterates till null
	while(argv[i] != NULL)
	{
		//Check whether file is available or not, also check whther file is empty
		status = isFileEmpty(argv[i]);
	
		//condition for Failure or file empty
		if (status == -1 || status == -2)
		{
			i++;
			continue;
		}
		//if file is not empty/exits
		else
		{
			//(*count)++;
			ret_val = to_create_list_of_files(f_head, argv[i]);
			//If file is valid
			if(ret_val == SUCCESS)
			{
				printf("Successfull: inserting file name : %s into file linked list\n",argv[i]);
			}
			//condition if file is repeated
			else if(ret_val == REPEATATION)
			{
				printf("Failure: %s file is repeated so do not add in file linked list\n", argv[i]);
			}	
			else
			{
				printf("Failure");
			}
		}
		//increment to get the next CLA argument
		i++;
	}
	
		
}
//function to check if file is empty
int isFileEmpty(char *filename)
{
	//Use file pointers
    	FILE *fptr = fopen(filename, "r");
    	// Do Error handling
    	if (fptr == NULL)
    	{
    		perror("fopen");
    		fprintf(stderr, "Failure: Unable to open file %s\n", filename);
    		return FAILURE;
    	}
	//seek the end of the file
	fseek (fptr, 0, SEEK_END);
    	int size = ftell(fptr);
	//if ftell points to 0 it means that the file is empty
	if (size == 0)
	{
		printf("Failure: File %s is empty soo not added into the linked list\n", filename);
		return FILE_EMPTY;
	}
	return SUCCESS;

}
//Function is to create a file linked list
int to_create_list_of_files(Flist **f_head, char *name)
{
	//Check whether any file is repeated
	Flist * temp = *f_head;

	//iterating through FList
	//if temp is null it means that initially no file is present
	while (temp)
	{
		//if file it already present then compare file name in Flist with the inputted name
		if(strcmp(temp->file_name, name) == 0)
		{
			//if matches it means file name is repeated
			return REPEATATION;
		}
		temp = temp->link;
	}
	
	//if file name is not repeated or initial node is not created then create a node
	//and allocate the memory
	Flist * new = malloc(sizeof(Flist));
	if (new == NULL)
	{
		return FAILURE;
	}
	//copy the name into the Flist node
	strcpy(new->file_name, name);
	new->link = NULL;

	//if head is null
	if (*f_head == NULL)
	{
		*f_head = new;
		//printf("%p\n", f_head);
		return SUCCESS;
	}
	//if more than 1 node is present
	//take a temp pointer
	temp = *f_head;
	
	//continuosly add the values at last
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	//update last node address to the new node
	//hence link established
	temp->link = new;	
	return SUCCESS;
	
}






