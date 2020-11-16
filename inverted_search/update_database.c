#include "inverted_search.h"

//functionto update database
void update_database( Wlist *head[], Flist **f_head)
{
	char file_name[FNAME_SIZE];
	int status;

	//user-prompt
	printf("Enter the file name to be inserted:");
	scanf("%s", file_name);
	
	Flist * temp = *f_head;
	//iterating through the files to check if the new file name is repeated
	while (temp)
	{
		//printf("%s\n", temp->file_name);
		if (strcmp(temp->file_name, file_name) == 0)
		{
			printf("%s file is repeated so not added in file linked list\n", file_name);
			return;
		}
		//update link
		temp = temp->link;
		
	}
	//calling isFileEmpty function to check if function is empty or not
	status = isFileEmpty(file_name);
	if (status == -1 || status == -2)
	{
		return;
	}
	//if file is not empty then we need to create the file
	//soo calling create_files function
	status = to_create_list_of_files(f_head, file_name);
	//iterating through all the files
	while (*f_head)
	{
		//comparing added new file with the file name given in input
		//then add it to the database if match is found
		if (strcmp((*f_head)->file_name, file_name) == 0)
		{
			create_database(*f_head, head);
		}
		//updating link
		*f_head = (*f_head)->link;
	}
}