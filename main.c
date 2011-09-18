#include <stdio.h>
#include <stdlib.h>

#include "sudokuops.h"
// #include "ui.h"

int main ( int argc, char *argv[] )
{
// 	if ((*++argv)[0] == '-' && (*argv)[1] == 'X') {
// 		GtkWidget *mainwindow = make_main_window(argc, argv);
// 		gtk_widget_show (mainwindow);
// 		gtk_main ();
// 	}
// 	else if (argc == 3)
	sudoku_solve_from_file (*(argv + 1), *(argv + 2));
// 	else
// 		exit (1);

	return EXIT_SUCCESS;
}
