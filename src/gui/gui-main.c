#include "gui-main.h"

void gui_init(int argc, char **argv, char *builderFile)
{
    GtkBuilder *builder;
    GtkWidget  *window;
    GError *error = NULL;

    gtk_init(&argc, &argv);
    
    if( !g_file_test(builderFile, G_FILE_TEST_EXISTS))
    {
        printf("Could not locate glade file at: %s\n", builderFile);
        return;
    }

    builder = gtk_builder_new();
    if( !gtk_builder_add_from_file(builder, builderFile, &error))
    {
        g_warning("%s", error->message);
        g_free(error);
        return;
    }

    //window declaration
    window = GTK_WIDGET( gtk_builder_get_object(builder, "main-window"));

    gtk_builder_connect_signals(builder , NULL);

    g_object_unref( G_OBJECT(builder));

    gtk_widget_show_all(window);

    gtk_main();
    
    return;
}
