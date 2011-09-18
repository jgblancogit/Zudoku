#include "framework.h"

mini_square * mini_square_cons ( mini_square *a )
{
	a->info.length = 9;
	a->info.from_square = 0;
	a->info.from_column = 0;
	a->info.from_row = 0;

	list *b = malloc ( sizeof ( list ) );
	a->first = b;

	int i;
	for ( i = 1; i < 9; i++ )
	{
		b->n = i;
		b->next = malloc ( sizeof ( list ) );
		b = b->next;
	}
	b->n = i;
	b->next = NULL;

	return a;
}

mini_square * mini_square_cons_filled ( mini_square *a, int n )
{
	a->info.length = 1;
	a->info.from_square = 0;
	a->info.from_column = 0;
	a->info.from_row = 0;

	list *b = malloc ( sizeof ( list ) );
	a->first = b;
	b->n = n;
	b->next = NULL;

	return a;
}

void mini_square_remove ( mini_square *a, int n )
{
	list *temp_1 = a->first;
	list *temp_2 = NULL;

	if ( a->first->n == n )
	{
		a->first = a->first->next;
		free ( temp_1 );
	}
	else
	{
		temp_1 = a->first->next;
		temp_2 = a->first;
		while ( temp_1->n != n )
		{
			temp_1 = temp_1->next;
			temp_2 = temp_2->next;
		}
		temp_2->next = temp_1->next;
		free ( temp_1 );
	}
	a->info.length--;
}

void mini_square_fill ( mini_square *a, int index, int n )
{
	int i;
	for (i = 1; i < 10; i++)
		if (has_no ((a + index), i) && i != n)
			mini_square_remove (a + index, i);
}

int has_no ( mini_square *a, int n )
{
	list *temp = a->first;
	while ( temp->n != n && temp->next != NULL )
		temp = temp->next;
	if ( temp->n == n )
		return 1;
	else
		return 0;
}