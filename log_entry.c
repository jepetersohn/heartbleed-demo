#include<stdlib.h>
#include<string.h>
#include "log_entry.h"

LogEntry *create_log_entry(char *ownerPtr, char *eventPtr, int ownerLen, int eventLen) {
  LogEntry *new = malloc(sizeof(LogEntry));
  new->owner =  malloc(ownerLen);
  new->event = malloc(eventLen);
  new->owner = strdup(ownerPtr);
  new->event = strdup(eventPtr);
  return new;
};
