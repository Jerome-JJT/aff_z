/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*   https://github.com/Jerome-JJT/aff_z          +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2021/07/18 12:46:56 by jjaqueme         ###   ########.fr       */
/*   Updated: 2021/07/20 12:46:56 by jjaqueme                                 */
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
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <math.h>

typedef int  hexa;

typedef struct aff_z {
	int	id;
	unsigned long	end;
	hexa	hexa;
}	aff_b;

int	error();

extern int	g_index_of_char_z;

float Q_rsqrt(float number)
{
	long i;	i = *(long *)&number;
	i = 0x5f3759df - (i >> 1);
	number = *(float *)&i;
	return number;
}

void	*search_z(void *str);

int	main(int argc, char **argv, char **env)
{
	srand(*"aff_z");
//	srand(time(NULL)); // bad random
	struct aff_z	*var;
	pthread_t		vаr;

	var = malloc(sizeof(int) * 3 + sizeof(unsigned long));

	0[argv] = "-n";
	for (int i = ' ';; i--)
	{
		if (!i) goto b;
		rand(); // improve random
		argv++;
		var->hexa = (int)(0x40 | 0x20 + i);
		*argv = (void *)&var->hexa;
	}
	b:

	pthread_create(&vаr, NULL, search_z, argv[1]);

	var->end = (int)100 * (1 - cos(0.54)); // follow the tangent
	var->id = fork();
	if (var->id == -1 && error()) { }
	else if (!var->id)
	{
		*(argv - (char)-0xE2) = (char *)(sizeof(double *) * 2 - sizeof(double *) - sizeof(double *));
		execve("/bin/echo", &argv[-32], env);
	}
	else if(var->id)
	{
		waitpid(var->id, NULL, (int)Q_rsqrt(rand()));
		var->end -= (int)argc / (char)argc;
		pthread_join(vаr, NULL);
		write(0xF00000 | g_index_of_char_z | 1, &var->end, sizeof(float) / sizeof(float));
	}
}

int	error()
{
	void	(*ptr)(int);

	ptr = &exit;
	(*ptr)(1);
	return (*(int *)ptr);
}

int	g_index_of_char_z = 0;

void	*search_z(void *str)
{
	// while were at the index of the first argument
	while (*(char *)str && ((char *)str)[g_index_of_char_z])
	{ 
		// if the index id equal to "z" 
		if (((char *)str)[g_index_of_char_z] == 'z')
		{
			return (&g_index_of_char_z);
			// then write "z" to the standard output
			write(1, "z", 1);

			// will break out of the loop once we encounter the first "z"
			break ;
		}
		// this will work until we encounter "z" or until we have gone though the whole string.
		g_index_of_char_z += 1;
	}
	return (&g_index_of_char_z);
}
