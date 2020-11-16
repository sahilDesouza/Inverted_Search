#include "inverted_search.h"

void save_database( Wlist *head[])
{
	//initialising file name array
	char file_name[FNAME_SIZE];
	printf("Enter file name where data is to be stored:");
	scanf("%s", file_name);

	//Use file pointers
	//opening the file in write mode
    	FILE *fptr = fopen(file_name, "w");
    	// Do Error handling
    	if (fptr == NULL)
    	{
    		perror("fopen");
    		fprintf(stderr, "ERROR: Unable to open file %s\n", file_name);
    		return;
    	}
	//iterating through the entire Wlist 
	for (int i = 0; i < 27; i++)
	{
		//calling the write_db function only when head is not null
		if (head[i] != NULL)
		{
			write_databasefile(head[i], fptr);
		}
		
	}
	printf("Data saved to the database file\n");
	//close the file
	fclose(fptr);
	    
}
void write_databasefile(Wlist *head, FILE * databasefile)
{
	//writing the index of the word to the file
	fprintf(databasefile, "#:%d", tolower(head->word[0])%97);
	fprintf(databasefile, "\n");
	//iterate through the entire link list
	while (head)
	{
		//fprintf(databasefile, "hello");
		//writing the word and file count to the destination file
		fprintf(databasefile, "%s:", head->word);
		fprintf(databasefile, "%d:", head->file_count);
		Ltable * temp = head->Tlink;
		while (temp)
		{
			//writing file name to the destination file 
			//along with the number of times that word occured in that file
			fprintf(databasefile, "%s:", temp->file_name);
			fprintf(databasefile, "%d:", temp->word_count);
			temp = temp->table_link;
		}
		fprintf(databasefile, "#");
		//update the head link
		head = head->link;
		fprintf(databasefile, "\n");
	}
	
}