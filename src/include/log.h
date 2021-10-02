#ifndef LOG_H
#define LOG_H

#include <stdio.h>

static const char LOG_NAME[]= "stack_log.html";

static const char HEADER[] = "<!DOCTYPE html>                      \n"
                                "<html>                            \n"
                                   "<head>                         \n"
                                      "<meta charset=\"utf-8\" />  \n"
                                      "<title>Stack log</title>    \n"
                                   "</head>                        \n"
                                "<body>                            \n"
                                   "<pre>                          \n"
                                             "<font color=\"navy\">\n"
                                                    "┈┏━╮╭━┓┈╭━━━━╮\n"
                                                    "┈┃┏┗┛┓┃╭┫MEOW┃\n"
                                                    "┈╰┓▋▋┏╯╯╰━━━━╯\n"
                                                    "╭━┻╮╲┗━━━━╮╭╮┈\n"
                                                    "┃▎▎┃╲╲╲╲╲╲┣━╯┈\n"
                                                    "╰━┳┻▅╯╲╲╲╲┃┈┈┈\n"
                                                    "┈┈╰━┳┓┏┳┓┏╯┈┈┈\n"
                                                    "┈┈┈┈┗┻┛┗┻┛┈┈┈┈\n"
                                                    "       </font>\n";  

static FILE *LOG = nullptr;

inline FILE *const get_log()
{
        return LOG;
}

inline void log_flush()
{
        fflush(LOG);
}

static inline void create_log()
{
        LOG = fopen(LOG_NAME, "w");
        fprintf(LOG, HEADER);
        fflush(LOG);
}

#define $(code) log("%s\n", #code); code

#ifdef NODEBUG
#define log_buf(fmt, ...) (void(0))
#else
#define log_buf(fmt, ...)                               \
        do {                                            \
                fprintf(get_log(), fmt, ##__VA_ARGS__); \
        } while (0)
#endif /* NODEBUG */

#ifdef NODEBUG
#define log(fmt, ...) (void(0))
#else
#define log(fmt, ...)                                                  \
        do {                                                           \
                fprintf(get_log(), "<font color=\"Chocolate\">>> At %s %s(%d): </font>" fmt,            \
                         __FILE__, __func__, __LINE__, ##__VA_ARGS__); \
                fflush(get_log());                                     \
        } while (0)
#endif /* NODEBUG */


#endif /* LOG_H */

