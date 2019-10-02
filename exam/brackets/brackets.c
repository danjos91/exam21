/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:02:02 by exam              #+#    #+#             */
/*   Updated: 2019/08/31 12:27:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int start(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return (1);
	return (0);
}

int	end(char c)
{
	if (c == ')' || c == ']' || c == '}')
			return (1);
	return (0);
}

int test(char s1, char s2)
{
	if ((s1 == '(' && s2 == ')') || (s1 == '[' && s2 == ']') || (s1 == '{' && s2 == '}'))
		return (1);
	return (0);
}

int brackets(char *s)
{
	int		i;
	int		j;
	char	c[4096];
	
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (start(s[i]))
		{
			j++;
			c[j] = s[i];
		}
		else if (end(s[i]))
		{
			if (!test(c[j], s[i]))
				return (0);
			else
			{
				c[j] = 0;
				j--;
			}
		}
		i++;
	}
	if (c[j] == 0)
		return (1);
	return (0);
}

int	main(int ac, char **ag)
{
	int	i;

	i = 1;
	if (ac == 1)
		write (1, "\n", 1);
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(ag[i]))
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			write(1 , "\n", 1);
			i++;
		}
	}
	return (0);
}
