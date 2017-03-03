# GetNextLine.42

Reads a line on a file descriptor.

<h3> Return cases : </h3>
<li> -1 : An error occurs : verify that you have entered good arguments (valid FD, opened file ...) </li> 
<li> 0 : All has been read. </li>
<li> 1 : A line has been read </li>

<h3> Run the project : </h3>
Compile libft : <code> make -C libft </code><br/>
Compile whole project : <code> gcc -g get_next_line.c get_next_line.h libft/libft.h libft/libft.a main.c </code>
