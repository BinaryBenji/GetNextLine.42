#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int  main(int argc, char **argv)
{
  char  *line = NULL;
  int   ret;
  int   fd = open(argv[1], O_RDONLY);

  argc++; // Used to ignore -Werror

  while((ret = get_next_line(fd, &line) == 1))
  {
    printf("Lign : %s#\n", line);
    printf("Return value : %d\n\n", ret);
  }
  return (0);
}
