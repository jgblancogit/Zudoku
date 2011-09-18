#include "ui.h"

gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
	gtk_main_quit ();
	return FALSE;
}

GtkWidget *make_main_window (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkWidget *table;
	GtkWidget *spin[81];
	
	gtk_init (&argc, &argv);
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	button1 = gtk_button_new_with_label ("Solve");	
	button2 = gtk_button_new_from_stock (GTK_STOCK_CANCEL);	
	hbox = gtk_hbox_new (FALSE, 0);
	vbox = gtk_vbox_new (FALSE, 0);
	table = gtk_table_new (9, 9, TRUE);
	
	int i;
	for ( i = 0; i < 81; i++)
		spin[i] = gtk_spin_button_new_with_range (0, 9, 1);
	
	/*window*/
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_title (GTK_WINDOW (window), "Sudoku solver");
	g_signal_connect (G_OBJECT (window), "delete_event",
	                  G_CALLBACK (delete_event), NULL);	
	
	/*vbox*/
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_box_pack_end (GTK_BOX (vbox), hbox, FALSE, FALSE, 10);	
	gtk_box_pack_start (GTK_BOX (vbox), table, FALSE, FALSE, 10);
	
	/*table*/
	int j, k;
	int h, g;
	i = 0;
	for (j = 0, k = 1; k < 10; j++, k++)
		for (h = 0, g = 1; g < 10; h++, g++)
			gtk_table_attach (GTK_TABLE (table), spin[i++], j, k, h, g, GTK_SHRINK, GTK_SHRINK, 2, 2);
	
	/*hbox*/
	gtk_box_pack_start (GTK_BOX (hbox), button1, FALSE, FALSE, 10);
	gtk_box_pack_end (GTK_BOX (hbox), button2, FALSE, FALSE, 10);
	
	/*buttons*/
	g_signal_connect (G_OBJECT (button2), "clicked",
	                  G_CALLBACK (delete_event), NULL);
	
	
	gtk_widget_show (button1);
	gtk_widget_show (button2);
	
	for (i = 0; i < 81; i++)
		gtk_widget_show (spin[i]);
	
	gtk_widget_show (table);
	
	gtk_widget_show (hbox);
	gtk_widget_show (vbox);
	
	return window;
}