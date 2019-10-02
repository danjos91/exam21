/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:01:37 by exam              #+#    #+#             */
/*   Updated: 2019/08/22 13:16:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int c)
{
	char hex[] = "0123456789abcdef";

	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	print_char(int c)
{
	if (c >= 32 && c <= 126)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t j;
	unsigned char *ptr;

	i = 0;
	j = 0;
	ptr = (unsigned char *)addr;
	while(i < size)
	{
		j = 0;
		while((j < 16) && (i + j < size))
		{
			print_hex(ptr[i + j]);
			if (j % 2)
				ft_putchar(' ');
			j++;
		}
		while(j < 16)
		{
			write(1, "  ", 2);
		   	if (j % 2)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while((j < 16) && (i + j < size))
		{
			print_char(ptr[i + j]);
			j++;
		}
		i = i + 16;
		ft_putchar('\n');
	}
}
