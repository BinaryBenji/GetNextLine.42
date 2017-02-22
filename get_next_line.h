#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# define BUFF_SIZE 6
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);


#endif