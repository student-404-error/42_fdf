/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:12:48 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 15:16:28 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hex_char_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 10);
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

unsigned int	hex_to_int(char *hex_str)
{
	unsigned int	result;
	int				value;

	result = 0;
	while (*hex_str)
	{
		value = hex_char_to_int(*hex_str++);
		result = (result << 4) | value;
	}
	return (result);
}

int	main(void)
{
	printf("%d\n", hex_to_int("FFEEFF"));
	printf("%d\n", hex_to_int("FFFFFF"));
}
