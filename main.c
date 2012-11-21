#include <libgen.h> // for basename()

/** Print help and exit. */
static void help(char *name) {
  fprintf(stderr, "usage: %s [-dhqv] [files]\n\n", basename(name));
  fputs("-d      show debug logging messages\n", stderr);
  fputs("-h      print this help and exit\n", stderr);
  fputs("-q      quiet logging (errors only)\n", stderr);
  fputs("-v      verbose logging (default: warnings)\n", stderr);
  exit(0);
}

/** Default log handler does nothing. */
static void silent_handler(
    const gchar *log_domain,
    GLogLevelFlags log_level,
    const gchar *message,
    gpointer user_data) {
  return;
}

/** This log handler prints to STDERR. */
static void stderr_handler(
    const gchar *log_domain,
    GLogLevelFlags log_level,
    const gchar *message,
    gpointer user_data) {
  char buffer[20];
  time_t now = time(NULL);
  struct tm *now_p = localtime(&now);
  char *time_p = &buffer[0];
  char *level_p;

  switch (log_level & G_LOG_LEVEL_MASK)
  {
    case G_LOG_LEVEL_ERROR:    level_p = "ERRO"; break;
    case G_LOG_LEVEL_CRITICAL: level_p = "CRIT"; break;
    case G_LOG_LEVEL_WARNING:  level_p = "WARN"; break;
    case G_LOG_LEVEL_MESSAGE:  level_p = "MESG"; break;
    case G_LOG_LEVEL_INFO:     level_p = "INFO"; break;
    case G_LOG_LEVEL_DEBUG:    level_p = "DEBG"; break;
    default:                   level_p = "LVL?";
  }

  if (strftime(time_p, 20, "%Y-%M-%d %H:%M:%S", now_p) == 0)
    time_p = asctime(now_p);

  fprintf(stderr, "%s %s: %s: %s\n", level_p, time_p, log_domain, message);
}

int main(int argc, char **argv) {
  int verbosity = 1;
  int show_help = 0;
  int c;
  
  /* default logging: silence */
  g_log_set_default_handler(silent_handler, NULL);

  /* option parsing */
  while ((c = getopt(argc, argv, "hqvd")) != -1)
    switch (c)
    {
      case 'h': show_help = 1; break;
      case 'd': if (verbosity == 1) verbosity = 3; break;
      case 'v': if (verbosity == 1) verbosity = 2; break;
      case 'q': if (verbosity == 1) verbosity = 0; break;
      case '?': break; // getopt prints an error message
      default: abort();
    }

  /* logging setup */
  GLogLevelFlags log_level = G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_ERROR | G_LOG_FLAG_FATAL;
  if (verbosity > 0) log_level |= G_LOG_LEVEL_WARNING;
  if (verbosity > 1) log_level |= G_LOG_LEVEL_MESSAGE;
  if (verbosity > 2) log_level |= G_LOG_LEVEL_INFO | G_LOG_LEVEL_DEBUG;
  g_log_set_handler(G_LOG_DOMAIN, log_level, stderr_handler, NULL);

  /* print help and exit if requested */
  if (show_help) help (argv[0]);

  g_debug("%i arguments", argc - optind); // verbose logging example

  /* RUN PROGRAM */

  return EXIT_SUCCESS;
}
