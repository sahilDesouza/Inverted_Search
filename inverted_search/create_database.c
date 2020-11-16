#include"inverted_search.h"

 void create_database(Flist *f_head, Wlist *head[])
{
	//Read till file_list is empty
	while (f_head)
	{
		read_datafile(f_head, head, f_head->file_name);
		//updating f_head to point to the next node
		f_head = f_head->link;
	}
	return;

}

