#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void signal_handler(int signo);

int main() {

  if (signal(SIGINT, signal_handler)==SIG_ERR) {
    const char message[] = "Error: signal(SIGINT, signal_handler)\n";
    write(2, message, sizeof(message) - 1);
  }

  if (signal(SIGTERM, signal_handler)==SIG_ERR) {
    const char message[] = "Error: signal(SIGTERM, signal_handler)\n";
    write(2, message, sizeof(message) - 1);
  }

  if (signal(SIGHUP, SIG_IGN)==SIG_ERR) {
    const char message[] = "Error: signal(SIGHUP, SIG_IGN)\n";
    write(2, message, sizeof(message) - 1);
  }

  for (;;)
    pause();

  return 0;
}

void signal_handler(int signo) {
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);
  signal(SIGHUP, SIG_IGN);

  if (signo==SIGINT) {
    const char message[] = "SIGINT handler\n";
    write(1, message, sizeof(message) - 1);
  } else if (signo==SIGTERM) {
    const char message[] = "SIGTERM handler\n";
    write(1, message, sizeof(message) - 1);
  } else {
    const char message[] = "Error. Unexpected signal.\n";
    write(2, message, sizeof(message) - 1);
  }
}
