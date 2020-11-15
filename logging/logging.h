#ifndef __LOGGING__
#define __LOGGING__

void initialize_log(void);
void write_to_log(const char* message);
void write_line_to_log(const char* message);

#define LOG_INFO(msg) do { write_to_log("INF: "); write_line_to_log(msg); } while (0);

#endif //__LOGGING__
