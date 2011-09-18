#include "sudokuops.h"

int solved ( mini_square *s )
{
	mini_square *r = s;
	int i;
	for ( i = 0; i < 81; i++ )
	{
		if ( r->info.length != 1 )
			return 0;
		else
			++r;
	}
	return 1;
}

int square_find ( mini_square *s, int no, int *column, int *row )
{
	int i, j;
	switch ( no )
	{
case 0 : case 1 : case 2 :
			for ( i = no * 3 ; i < no * 3 + 19; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i + no * 3;
						*row = j - ( j - i ) - no * 3;
						return ( s + j )->first->n;
					}
			break;
		case 3 :
			for ( i = 27 ; i < 46; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i;
						*row = i;
						return ( s + j )->first->n;
					}
			break;
		case 4 :
			for ( i = 30 ; i < 49; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i + 3;
						*row = i - 3;
						return ( s + j )->first->n;
					}
			break;
		case 5 :
			for ( i = 33 ; i < 52; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i + 6;
						*row = i - 6;
						return ( s + j )->first->n;
					}
			break;
		case 6 :
			for ( i = 54 ; i < 73; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i;
						*row = i;
						return ( s + j )->first->n;
					}
			break;
		case 7 :
			for ( i = 57 ; i < 76; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i + 3;
						*row = i - 3;
						return ( s + j )->first->n;
					}
			break;
		case 8 :
			for ( i = 60 ; i < 79; i += 9 )
				for ( j = i; j < i + 3; j++ )
					if ( ( s + j )->info.length == 1 &&
					        ( s + j )->info.from_square == 0 &&
					        ( s + j )->info.from_column == 0 &&
					        ( s + j )->info.from_row == 0 )
					{
						*column = j - i + 6;
						*row = i - 6;
						return ( s + j )->first->n;
					}
			break;
		default :
			break;
	}
	return -1;
}

void square_remove ( mini_square *a, int no, int n )
{
	int i, j, h;
	i = j = h = 0;

	switch ( no )
	{
case 0 : case 1 : case 2 :
			i = no * 3;
			h = no * 3 + 19;
			break;
		case 3 :
			i = 27;
			h = 46;
			break;
		case 4 :
			i = 30;
			h = 49;
			break;
		case 5 :
			i = 33;
			h = 52;
			break;
		case 6 :
			i = 54;
			h = 73;
			break;
		case 7 :
			i = 57;
			h = 76;
			break;
		case 8 :
			i = 60;
			h = 79;
			break;
		default :
			break;
	}

	for ( ; i < h; i += 9 )
		for ( j = i; j < i + 3; j++ )
		{
			if ( ( a + j )->info.length > 1 &&
			        has_no ( a + j, n ) )
				mini_square_remove ( a + j, n );

			else if ( ( a + j )->info.length == 1 && has_no ( a + j, n ) )
				( a + j )->info.from_square = 1;
		}
}

void column_remove ( mini_square *a, int no, int n )
{
	int i;
	for ( i = no; i < no + 73; i += 9 )
	{
		if ( ( a + i )->info.length > 1 &&
		        has_no ( a + i, n ) )
			mini_square_remove ( a + i, n );
		else if ( ( a + i )->info.length == 1 && has_no ( ( a + i ), n ) )
			( a + i )->info.from_column = 1;
	}
}

void row_remove ( mini_square *a, int no, int n )
{
	int i;
	for ( i = no; i < no + 9; i++ )
	{
		if ( ( a + i )->info.length > 1 && has_no ( ( a + i ), n ) )
			mini_square_remove ( a + i, n );
		else if ( ( a + i )->info.length == 1 && has_no ( ( a + i ), n ) )
			( a + i )->info.from_row = 1;
	}
}

int square_occurences ( mini_square *a, int no, int n, int *index )
{
	int occ = 0;
	int i, j, h;
	i = j = h = 0;

	switch ( no )
	{
case 0 : case 1 : case 2 :
			i = no * 3;
			h = no * 3 + 19;
			break;
		case 3 :
			i = 27;
			h = 46;
			break;
		case 4 :
			i = 30;
			h = 49;
			break;
		case 5 :
			i = 33;
			h = 52;
			break;
		case 6 :
			i = 54;
			h = 73;
			break;
		case 7 :
			i = 57;
			h = 76;
			break;
		case 8 :
			i = 60;
			h = 79;
			break;
		default :
			break;
	}

	for ( ; i < h; i += 9 )
		for ( j = i; j < i + 3; j++ )
			if ( has_no ( ( a + j ), n ) && ( a + j )->info.from_square == 0 && ( a + j )->info.from_column == 0 && ( a + j )->info.from_row == 0 )
			{
				*index = j;
				occ++;
			}
	return occ;
}

int square_isolated ( mini_square *a, int no, int *index )
{
	int i;
	for ( i = 1; i < 10; i++ )
		if ( square_occurences ( a, no, i , index ) == 1 )
			if ( ( a + *index )->info.length > 1 )
				return i;
	return -1;
}

int column_occurences ( mini_square *a, int no, int n, int *index )
{
	int occ = 0;
	int i;
	for ( i = no; i < no + 73; i += 9 )
		if ( has_no ( ( a + i ), n ) && ( a + i )->info.from_square == 0 && ( a + i )->info.from_column == 0 && ( a + i )->info.from_row == 0 )
		{
			*index = i;
			occ++;
		}
	return occ;
}

int column_isolated ( mini_square *a, int no, int *index )
{
	int i;
	for ( i = 1; i < 10; i++ )
		if ( column_occurences ( a, no, i, index ) == 1 )
			if ( ( a + *index )->info.length > 1 )
				return i;
	return -1;
}

int row_occurences ( mini_square *a, int no, int n, int *index )
{
	int occ = 0;
	int i;
	for ( i = no; i < no + 9; i++ )
		if ( has_no ( ( a + i ), n ) && ( a + i )->info.from_square == 0 && ( a + i )->info.from_column == 0 && ( a + i )->info.from_row == 0 )
		{
			*index = i;
			occ++;
		}
	return occ;
}

int row_isolated ( mini_square *a, int no, int *index )
{
	int i;
	for ( i = 1; i < 10; i++ )
		if ( row_occurences ( a, no, i, index ) == 1 )
			if ( ( a + *index )->info.length > 1 )
				return i;
	return -1;
}

void sudoku_clean ( mini_square *a )
{
	int square, n;
	int *columnf, *rowf;
	columnf = malloc ( sizeof ( int ) );
	rowf = malloc ( sizeof ( int ) );

	for ( square = 0; square < 9; square++ )
		while ( ( n = square_find ( a, square, columnf, rowf ) ) > 0 )
		{
			square_remove ( a, square, n );
			column_remove ( a, *columnf, n );
			row_remove ( a, *rowf, n );
		}
}

void squares_clean ( mini_square *a )
{
	int i, n;
	int *indexf = malloc ( sizeof ( int ) );

	for ( i = 0; i < 9; i++ )
		while ( ( n = square_isolated ( a, i, indexf ) ) > 0 )
			mini_square_fill ( a, *indexf, n );
}

void columns_clean ( mini_square *a )
{
	int i, n;
	int *indexf = malloc ( sizeof ( int ) );

	for ( i = 0; i < 9; i++ )
		while ( ( n = column_isolated ( a, i, indexf ) ) > 0 )
			mini_square_fill ( a, *indexf, n );
}

void rows_clean ( mini_square *a )
{
	int i, n;
	int *indexf = malloc ( sizeof ( int ) );

	for ( i = 0; i < 73; i += 9 )
		while ( ( n = row_isolated ( a, i, indexf ) ) > 0 )
			mini_square_fill ( a, *indexf, n );
}

mini_square * sudoku_cons ( fill a[], int n )
{
	int i, j;
	i = j = 0;
	mini_square *s = malloc ( 81 * sizeof ( mini_square ) );
	mini_square *r = s;

	while ( i < 81 )
	{
		if ( a[j].index == i )
		{
			s = mini_square_cons_filled ( s, a[j].n );
			j++;
		}
		else
			s = mini_square_cons ( s );
		s++;
		i++;
	}
	return r;
}

mini_square * sudoku_cons_from_file ( char *filename )
{
	fill temp[MAXSOLVED];
	FILE *fp;
	fp = fopen ( filename, "r" );

	int i, j, c;
	j = 0;

	for ( i = 0; i < 81 &&	( c = getc ( fp ) ) != EOF; )
	{
		if ( c == ' ' || c == '\n' )
			;
		else if ( c == 'X' )
			i++;
		else
		{
			temp[j].index = i;
			temp[j].n = c - '0';
			j++;
			i++;
		}
	}
	fclose ( fp );

	fill *a = malloc ( j * sizeof ( fill ) );
	fill *r = a;
	for ( i = 0; i < j; i++ )
	{
		r->index = temp[i].index;
		r->n = temp[i].n;
		r++;
	}

	mini_square *curr = sudoku_cons ( a, j );
	free ( a );
	return curr;
}

void sudoku_print ( mini_square *a )
{
	int i, j;
	for ( i = 0; i < 81; i += 9 )
	{
		for ( j = i; j < i + 9; j++ )
			printf ( "%d%s", ( a + j )->first->n, ( ( j == i + 2 ) || ( j == i + 5 ) ? " | " : "   " ) );
		printf ( "\n----------------------------------\n" );
	}
}

void sudoku_print_in_file ( mini_square *a, char *filename )
{
	FILE *fp;
	fp = fopen ( filename, "w" );

	int i, j;
	for ( i = 0; i < 81; i += 9 )
	{
		for ( j = i; j < i + 9; j++ )
			fprintf ( fp, "%d%s", ( a + j )->first->n, ( ( j == i + 2 ) || ( j == i + 5 ) ? " | " : "   " ) );
		fprintf ( fp, "\n----------------------------------\n" );
	}
	fclose ( fp );
}

void sudoku_solve_from_file ( char *infile, char *outfile )
{
	mini_square *current = sudoku_cons_from_file ( infile );

	int square, column, row;
	square = column = row = 0;

	while ( !solved ( current ) )
	{
		sudoku_clean ( current );

		squares_clean ( current );

		columns_clean ( current );

		rows_clean ( current );

	}

	sudoku_print ( current );
	sudoku_print_in_file ( current, outfile );
}
