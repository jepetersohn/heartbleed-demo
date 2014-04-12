typedef struct LogEntry {
  char *owner;
  char *event;
} LogEntry;

LogEntry *create_log_entry(char *ownerPtr, char *eventPtr, int ownerLen, int eventLen);
