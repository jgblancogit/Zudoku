#include <stdio.h>
#include <stdlib.h>
#include "sudokuops.h"

int main (int argc, char *argv[])
{	
// 	FILE *fp;
// 	fp = fopen ("table.txt", "r");
// 	int c = getc (fp);
// 	putchar (c);
// 	c = getc (fp);
// 	putchar (c);
// 	
// 	while (( c = getc (fp)) != '\n')
// 		putchar (c);
	
	mini_square *current = sudoku_read_from_file("table.txt");
	
	printf ("%d\n", current->info.length);
	
	return EXIT_SUCCESS;
}