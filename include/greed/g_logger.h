#pragma once

#include "../../src/defines.h"
#include <stdio.h>
#include <time.h>

typedef enum
{
  LOG_DBG,
  LOG_SCS,
  LOG_WRN,
  LOG_ERR,
  LOG_LVL_LEN
} LOG_LEVEL;

const char *DEFAULT_COLOR = "\x1b[0m";

char *type[LOG_LVL_LEN] = {"DEBUG", "SUCCESS", "WARNING", "ERROR"};
char *colors[LOG_LVL_LEN] = {
    "\x1b[34m", /* blue */
    "\x1b[32m", /* green */
    "\x1b[33m", /* yellow */
    "\x1b[31m"  /* red */
};
time_t current_time;
struct tm *m_time;

/* --- GREED LOGGER --- */

void get_time()
{
  time(&current_time);
  m_time = localtime(&current_time);
}

void g_logger(LOG_LEVEL lvl, const char *msg, char *file, u32 line)
{
  get_time();

  printf("%s", colors[lvl]);

  printf("[%s]", type[lvl]);

  printf("[%d/%d/%d -> %d:%d:%d]--", m_time->tm_mday, m_time->tm_mon,
         m_time->tm_year + 1900, m_time->tm_hour, m_time->tm_min,
         m_time->tm_sec);

  printf("[%s on line %u in file %s]\n%s", msg, line, file, DEFAULT_COLOR);
}

#define g_log_trace(msg) g_logger(LOG_TRACE, msg, __FILE__, __LINE__);

#define g_log_debug(msg) g_logger(LOG_DEBUG, msg, __FILE__, __LINE__);

#define g_log_info(msg) g_logger(LOG_INFO, msg, __FILE__, __LINE__);

#define g_log_warning(msg) g_logger(LOG_WARNING, msg, __FILE__, __LINE__);

#define g_log_error(msg) g_logger(LOG_ERROR, msg, __FILE__, __LINE__);

#define g_log_success(msg) g_logger(LOG_SUCCESS, msg, __FILE__, __LINE__);

#define g_log_fatal(msg) g_logger(LOG_FATAL, msg, __FILE__, __LINE__);