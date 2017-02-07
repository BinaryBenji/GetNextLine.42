/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:23:25 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/17 15:24:10 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*char 	*ft_end_copy(char *buf)
{
	int begin;
	int i;
	char *s;
	int len;
	char *buf;

	i = 0;
	begin = where_to_stop(buf,'\n');
	len = ft_strlen(buf) - begin;
	if (!(s = (char *)malloc(len * sizeof(char))))
		return (NULL);
	while(buf[begin])
	{	
		s[i] = buf[begin];
		begin++;
		i++;
	}
	free(buf);
	if (!(buf = (char *)malloc(len - begin + 1 * sizeof(char))))
		return (NULL);
	while()
	{


	}
	return (buf);
}*/

int		where_to_stop(char *str,char stop)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == stop)
			return (i);
		i++;
	}
	return (i);
}  

char 	*ft_strjoin_stop(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	int 	stopper;

	if (!s1 || !s2)
		return (NULL);
	stopper = where_to_stop(s2,'\n');
	if (!(s = ft_strnew(ft_strlen(s1) + j + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while ((s2[i] != '\0') && (i < stopper))
	{
		s[j] = s2[i];
		j++;
		i++;
	}  
	s[j] = '\0';
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	static char	bufr[BUFF_SIZE + 1]; // RIP
	char 		*buf; // Buffer
	int 		ret; // Stop
	int i;

	i = 0;
	//bufr doit stocker le reste
	//line, la ligne
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (fd < 0 || !line || buf[0] == '\0') // Validity check
			return (-1);
		if (where_to_stop(buf, '\n') != ft_strlen(buf)) // Case line.
		{
			line = ft_strjoin_stop(line, buf);
			printf("\n Baque dans le buf \n");
			printf("Ligne : %s", line);
			//free(buf);
			//bufr = ft_end_copy(buf);
			return (1);
		}
		else // Case no line
		{
			line = ft_strjoin(line,buf);
			printf("Pas encore a la fin de la ligne \n");
		}
	}
	return (0);	
}