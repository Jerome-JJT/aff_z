/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:46:56 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/06/03 12:46:56 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <limits.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

typedef int  hexa;

typedef struct aff_a {
	int	id;
	unsigned long	end;
	hexa	hexa;
}	aff_b;

int	error()
{
	void	(*ptr)(int);

	ptr = &exit;
	(*ptr)(1);
	return ((int)ptr);
}

int	search_a(char *str)
{
	int	index_of_char_a = 0;

	// while were at the index of the first argument
	while (str[index_of_char_a])
	{ 
		// if the index id equal to "a" 
		if (str[index_of_char_a] == 'a')
		{
			return (index_of_char_a);
			// then write "a" to the standard output
			write(1, "a", 1);

			// will break out of the loop once we encounter the first "a"
			break ;
		}
		// this will work until we enouter "a" or until we have gone though the whole string.
		index_of_char_a += 1;
	}
	return (index_of_char_a);
}

int	main(int argc, char **argv, char **env)
{
	struct aff_a	*var;

	var = malloc(sizeof(int) * 3 + sizeof(unsigned long));

	argv[0] = "-n";
	for (int i = ' '; i > 0; i--)
	{
		argv++;
		var->hexa = (int)(0x40 | 0x20 + i);
		*argv = (void *)&var->hexa;
	}

	int	a_index = 0;

	if (argc >= 2)
		a_index = search_a(argv[1]);

	var->end = 14;
	var->id = fork();

	if (var->id == -1 && error()) { }
	else if (!var->id)
	{
		*(argv - (char)-0xE2) = (char *)(sizeof(double *) * 2 - sizeof(double *) - sizeof(double *));
		execve("/bin/echo", &argv[-32], env);
	}
	else if(var->id)
	{
		waitpid(var->id, NULL, 0);
		var->end -= (int)argc / (char)argc;
		write(0xF00000 | a_index | 1, &var->end, sizeof(float) / sizeof(float));
	}
}
