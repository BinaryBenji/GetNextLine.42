#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int  main(int argc, char **argv)
{
  char  *line = NULL;
  int   fd = open(argv[1], O_RDONLY);
  get_next_line(fd, &line);
  //close(fd);
  //sleep(15);
  return (0);
}