#include "inverted_search.h"

void display_database(Wlist *head[])
{
	int count = 0;
	//checking if hash table contains any word
	for (int i = 0; i < 27; i++)
	{
		//if it doesnt contain anything then count increments
		if (head[i] == NULL)
		{
			count++;
		}
	}
	//if the count is 27 it means that the hash table is empty
	if (count == 27)
	{
		printf("Database is empty\n");
		return;
	}
	
	printf("[index] [word]  file_count file/s: File: File_name  word_count\n");
	//iterating through the hash rable
	for (int i = 0; i < 27; i++)
	{
		//if hash table is contains elements
		if (head[i] != NULL)
		{
			//call the function to print the desired data
			print_word_count(head[i]);
		}	
	}
}

int print_word_count(Wlist *head)
{
	//checking if head is null or not
	if (head == NULL)
	{
		return 0;
	}
	//iterate through that particular node to get the respective data
	while (head != NULL)
	{
		printf("[%d]\t[%s]\t   %d\t   file/s:", (tolower(head->word[0])) % 97, head->word, head->file_count);
		//creating another pointer to print the data present in the Ltable node
		Ltable *Thead = head->Tlink;
		printf(" File:");
		//iterating through the Ltable node
		while (Thead)
		{
			printf(" %s\t%d\t", Thead->file_name, Thead->word_count);
			//updating Thead node to point to next node
			Thead = Thead->table_link;
		}
		//updating head node
		head = head->link;
		printf("\n");
	}
}