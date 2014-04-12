#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log_entry.h"
#include "log_display.h"

#define LOG_MAX_SIZE 10
#define LOG_INIT_POST 0

LogEntry *LOG[LOG_MAX_SIZE];
int LOG_POSITION = LOG_INIT_POST;

void log_entry(LogEntry *l) {
  LOG[LOG_POSITION++] = l;
}

LogEntry *retrieve_entry(char name[]) {
  LogEntry *found = NULL;
  int i = 0;

  while(i < LOG_POSITION) {
    if (!strcmp(name, LOG[i]->owner)) {
      found = LOG[i];
      break;
    }
    i++;
  }

  if (found == NULL) {
    return NULL;
  } else {
    return found;
  }
}

char *retrieve_event(LogEntry *l, int size) {
  char *result = malloc(size);
  memcpy(result, l->event, size);
  return result;
}

void char_array_display(char char_array[], int size) {
  int i = 0;

  printf("'");
  while ( i < size ){
    printf("%c", char_array[i]);
    i++;
  }
  printf("'");
}

int check_entry(char *lookupName, char *heartbeatString, int nameLen, int hbStrLen) {
  LogEntry *eventForLookupName = retrieve_entry(lookupName);
  char *eventString = retrieve_event(eventForLookupName, hbStrLen);
  int strings_were_same = !strcmp(heartbeatString, eventString);

  if (strings_were_same) {
    printf("Heartbeat was valid! expected '%s' and found ", heartbeatString);
    char_array_display(eventString, hbStrLen);
  } else {
    printf("Heartbeat was invalid: expected '%s' but found ", heartbeatString);
    char_array_display(eventString, hbStrLen);
  }

  puts("");
  return 0;
}

int main(int argc, char *argv[]) {
  log_entry(create_log_entry("Alice", "Heartbeat Check: Monkey", 5, 23));
  log_entry(create_log_entry("Eve", "Heartbeat Check: Dog", 3, 20));
  log_entry(create_log_entry("Bob", "Update Password: s33krit", 3, 24));
  log_entry(create_log_entry("Dupe", "Update Password: superSwordfish222", 4, 24));

  check_entry("Alice", "Heartbeat Check: Monkey", 5, 23);

  check_entry("Eve", "hack", 3, 500);
}
