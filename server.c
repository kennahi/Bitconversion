/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:28:59 by kennahi           #+#    #+#             */
/*   Updated: 2021/09/28 18:10:17 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	handler(int sig)
{
	static int 				i = 0;
	static unsigned char	c = 0;
	char					bit;

	if (sig == SIGUSR1)
		ft_putchar_fd('0', 1);
	else if (sig == SIGUSR2)
		ft_putchar_fd('1', 1);
	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	c = c | bit;
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd('\n', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
