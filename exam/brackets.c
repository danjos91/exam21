/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:41:32 by exam              #+#    #+#             */
/*   Updated: 2019/09/21 14:05:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int start(char c)
{
	if (c == '(' || c == '[' ||c == '{')
		return (1);
	return (0);
}

int end(char c)
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
	int i;
	int j;
	char top[512];

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (start(s[i]))
		{
			top[++j] = s[i];
		}
		else if (end(s[i]))
		{
			if (!test(top[j], s[i]))
				return (0);
			else
				j--;
		}
		i++;
	}
	if (j != -1)
		return (0);
	return (1);
}

int main(int ac, char **ag)
{
	int i;

	i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while (i < ac)
		{
			if (brackets(ag[i]))
			{
				write(1, "OK\n", 3);
			}
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	return (0);
}
