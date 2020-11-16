#include"inverted_search.h"

//data is the word
//each time we insert at that for that wlist node we have to create 1 List node
int insert_at_last(Wlist **head, data_t * data, char *fileName)
{
	//Create a node
	Wlist *new = malloc(sizeof(Wlist));
	Wlist *temp = *head;

	//Check whether memory is allocated or not
	if (new == NULL)
	{
		return FAILURE;
	}
	//Update the values
	new->file_count = 1;
	new->link = NULL;
	new->Tlink = NULL;
	strcpy(new->word, data);

	//Check whether list is empty or not
	//this condition is if the head is empty
	if (*head == NULL)
	{
		*head = new;
		//for each wlist node we create we need to create a node Ltable and update the Tlink 
		update_link_table(&new, fileName);
		return SUCCESS;
	}
	//List non empty
	//mutiple nodes present
	else
	{
		//iterate till the last
		while(temp->link)
		{
			temp = temp->link;
		}
		//establish link between last + new Node and update tail 
		temp->link = new;
		//Call function to update link table
		update_link_table(&new, fileName);
		return SUCCESS;
	}
	
}

int update_link_table(Wlist **head, char * fileName)
{
	//Create a node 
	Ltable *new = malloc(sizeof(Ltable));
	//Check whether memory is allocated or not
	if (new == NULL)
	{
		return FAILURE;
	}

	//Update the values
	new->word_count = 1;
	new->table_link = NULL;
	(*head)->Tlink = new;
	strcpy(new->file_name, fileName);
	return SUCCESS;

}

