#ifndef __LOGGING__
#define __LOGGING__

void initialize_log(void);
void write_to_log(const char* message);
void write_line_to_log(const char* message);

#define LOG_WRITE(pref, msg) do { write_to_log(pref); write_line_to_log(msg); } while (0);
#define LOG_INFO(msg) LOG_WRITE("INF: ", msg)
#define LOG_ERR(msg) LOG_WRITE("ERR: ", msg)

#endif //__LOGGING__
