#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
int  main(int argc, char **argv)
{

  argc = 2;
  char  *line = NULL;
  int   fd = open(argv[1], O_RDONLY);
  get_next_line(fd, &line);
  printf("%s\n", line);
  get_next_line(fd, &line);
  printf("%s\n", line);
  get_next_line(fd, &line);
  printf("%s\n", line);
  get_next_line(fd, &line);
  printf("%s", line);
  //close(fd);
  //sleep(15);
  return (0);
}
