/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:08:48 by exam              #+#    #+#             */
/*   Updated: 2019/08/29 14:59:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *s1, char *s2)
{
	int i;
	int size;

	size = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
}

void 	ft_rev_str(char *s1, char *tmp)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(s1);
	while(size--)
	{
		tmp[size] = s1[i];
		i++;
	}
	tmp[i] = '\0';
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == ft_strlen(s1))
			return (1);
	return (0);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
void ft_strncopy(char *s1, char *s2, int n)
{ 
	int i;

	i = 0;
	while (i < n)
	{
	   	s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0'; 
}

int main(int ac, char **ag)
{
	int i;
	int j;
	char str[BUFF];
	char str1[BUFF];
	char rev[BUFF];
	char answer[BUFF];
	int size;
	int size1;
	int size_pol;
	
	j = 1;
	i = 0;	
	size = 0;
	size1 = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{	
		ft_strcpy(ag[1], str1);
		size1 = ft_strlen(ag[1]);
		while (j <= size1 && ag[1][j - 1] != '\0')
		{
			ft_strncopy(str1, str, j);
			size = ft_strlen(str);
			ft_rev_str(str, rev);
			if (ft_strlen(str) > 1 && (ft_strcmp(str, rev)))
			{
				if (size_pol <= ft_strlen(str))
				{
					size_pol = ft_strlen(str);
					ft_strcpy(str, answer);
				}		
			}
			if (j == ft_strlen(ag[1]))
			{
				j = 0;
				ft_strcpy(++ag[1], str1);
			}
			j++;
		}
		ft_putstr(answer);
	}
	write(1, "\n", 1);
	return (0);
}
