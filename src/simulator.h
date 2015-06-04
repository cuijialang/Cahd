/*
Copyright 2013 Elbert van de Put
*/
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <glib.h>
#include <gtk/gtk.h>

#include "logger.h"
#include "environment.h"

int
simulate(gchar *path);

int
start_gtkwave(gchar* path, gchar* file);
#endif
