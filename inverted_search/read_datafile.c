#include"inverted_search.h"

Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{
	//Open file in read mode
	FILE *fptr = fopen(filename, "r");

	//Declare array to store extracted word from file
	char word[WORD_SIZE];
	int status;

	while(fscanf(fptr, "%s", word) != EOF)
	{
		//setting flag to 1
		int flag  = 1;

		//To get index of head
		int index = tolower(word[0]) % 97;

		if(!(index >= 0  && index <= 25))
		{
			//Other than alphabets
			index = 26;	
		}
		//check whether words are repeated
		if(head[index] != NULL) 
		{
			Wlist *temp = head[index];
			//Traverse through the list
			while(temp)
			{
				//Check If words are repeated
				if(!strcmp(temp->word, word))
				{
					//if repeated need to update word count
					update_word_count(&temp ,filename);
					//flag is 0 soo new node need not insert another node
					//because that word is repeated
					flag = 0 ;
					break;
				}
				temp = temp->link;
			}
		}
		//Call this function at start and if no words are repeated
		if(flag)
		{
			status = insert_at_last(&head[index], word, filename);			
		}
	}
	printf("Successful: Creation of database for file : %s\n",filename);
}

 int update_word_count(Wlist **head, char *file_name)
{
	//creating Ltable temp pointer
	Ltable *temp = (*head)->Tlink, *prev = NULL;
	
	//iterate through the Ltable
	while (temp)
	{
		//If Words are same && Filenames are also same then increment word count
		if (strcmp(temp->file_name, file_name) == 0)
		{
			//increment word count of the respective Ltable node
			temp->word_count = temp->word_count + 1;
			return SUCCESS;
		}
		//updating temp to point to next node and prev hold address of current node
		//soo if it becomes null that means match not found and we need to create a new node
		//prev will have the address of the last node
		prev = temp;
		temp = temp->table_link;
	}
	//if words are same && Filenames are different then increment file_count and allocate memory for table link
	//Create a node
	Ltable *new = malloc(sizeof(Ltable));
	new->word_count = 1;
	strcpy(new->file_name, file_name);
	new->table_link = NULL;
	
	//Check whether memory is allocated or not
	if (new == NULL)
	{
		return FAILURE;
	}
	//update last node address with the new node
	//and hence link created
	prev->table_link = new;

	//increment file count
	++((*head)->file_count);

	return SUCCESS;

}

