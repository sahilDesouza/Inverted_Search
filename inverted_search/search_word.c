#include "inverted_search.h"

void search(Wlist *head, char * word)
{
	//before searching check if head is empty or not
	if (head == NULL)
	{
		printf("Data base is empty\n");
		return;
	}
	
	Wlist * temp = head;
	//iterate throughout that Wlist(head) and
	while (temp)
	{
		//search for that word in that head list
		if (strcmp(temp->word, word) == 0)
		{
			//print that word
			printf("word '%s' is present in %d file/s\n", temp->word, temp->file_count);
			Ltable * temp_table = temp->Tlink;
			printf("In file:");
			//check number of times that word is occuring in that particular file
			while (temp_table)
			{
				printf("%s %d times/s  ", temp_table->file_name, temp_table->word_count);
				temp_table = temp_table->table_link;
				
			}
		}
		//update link
		temp = temp->link;
	}
}