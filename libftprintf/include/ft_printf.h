/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:17:28 by jaimmart          #+#    #+#             */
/*   Updated: 2022/10/13 12:23:48 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include  <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);

int		ft_ptr_len(uintptr_t num);
int		ft_num_len(unsigned int num);
int		ft_hex_len(unsigned int num);

void	ft_put_hex(unsigned int num, const char format);
void	ft_put_ptr(uintptr_t num);
void	ft_putstr(char *str);

char	*ft_uitoa(unsigned int n);

#endif