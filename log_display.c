#include <stdlib.h>
#include <stdio.h>
#include "log_entry.h"


void display_log_entry(LogEntry *l) {
  puts(l->owner);
  puts(l->event);
}

