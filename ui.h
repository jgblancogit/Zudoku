#include "gtk/gtk.h"

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data );

GtkWidget * make_main_window (int, char *[]);