/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:13:05 by exam              #+#    #+#             */
/*   Updated: 2019/09/21 13:38:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_simbol(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	operation(int a, int b, char simbol)
{
	if (simbol == '+')
	{
		return (a + b);
	}
	if (simbol == '-')
	{
		return (a - b);
	}
	if (simbol == '*')
	{
		return(a * b);
	}
	if (simbol == '/')
	{
		if (b == 0)
			return (99999);
		return (a / b);
	}
	if (simbol == '%')
	{
		if (b == 0)
			return (99999);
		return (a % b);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
int 	check_str(char *s)
{
	int i;
	char last;
	int pos_last;

	pos_last = ft_strlen(s) - 1;
	last = s[pos_last];
	i = 0;
	if (!is_simbol(last))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == s[pos_last])
		{
			if (!(s[i - 1] == ' '))
				return (0);
		}
		else if (is_simbol(s[i]))
		{
			if (!(s[i - 1] == ' ' && s[i + 1] == ' '))
				return (0);
		}
		i++;	
	}
	return (1);
}

int rpn_calc(char *s)
{
	int i;
	int j;
	int k;
	int num[500];
	int result;
	char *number;

	i = 0;
	j = -1;
	k = 0;
	number = (char*)malloc(sizeof(char) * 10);
	while (s[i] != '\0')
	{
		if (is_number(s[i]))
		{
			k = 0;
			while (is_number(s[i]))
			{
			number[k] = s[i];
				i++;
				k++;				
			}
			number[k] = '\0';
			num[++j] = atoi(number);
		}
		if (is_simbol(s[i]) && j > 0)
		{
			result = operation(num[j - 1], num[j], s[i]);
			num[j - 1] = result;
			j--;
		}
		i++;
	}
	if (j != 0)
		return (99999);		
	return (result);
}

int	main(int ac, char **ag)
{
	int result;

	result = 0;
	if (ac == 2)
	{
		if (!check_str(ag[1]))
		{
			printf("Error\n");
			return (0);
		}
		result = rpn_calc(ag[1]);
		if (result == 99999)
		{
			printf("Error\n");
			return (0);
		}
		printf("%d\n", result);
	}
	else
		printf("Error\n");
	return (0);
}
