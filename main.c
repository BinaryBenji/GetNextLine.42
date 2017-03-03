#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
int  main(int argc, char **argv)
{

  argc = 2;
  char  *line = NULL;
  int ret;
  int   fd = open(argv[1], O_RDONLY);
  
  ret = get_next_line(fd, &line);
  printf("ligne : %s#\n", line);
  printf("return : %d\n", ret);

  ret = get_next_line(fd, &line);
  printf("ligne : %s#\n", line);
  printf("return : %d\n", ret);

  ret = get_next_line(fd, &line);
  printf("ligne : %s#\n", line);
  printf("return : %d\n", ret);

  ret = get_next_line(fd, &line);
  printf("ligne : %s#\n", line);
  printf("return : %d\n", ret);

  ret = get_next_line(fd, &line);
  printf("ligne : %s#\n", line);
  printf("return : %d\n", ret);
  //close(fd);
  //sleep(15);
  // mouli : 3 5 6 7
  // basic : 
  return (0);
}
