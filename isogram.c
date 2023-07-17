/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isogram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42_Legin <Nige@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:10:34 by 42_Legin          #+#    #+#             */
/*   Updated: 2023/07/17 11:45:35 by 42_Legin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"isogram.h"

static bool	_is_valid_char(char current_char);
static char	_to_lowercase( char current_char);
static void	_to_initialize_alphabet_index(int *ptr);

/**
*	main function 
*	args : takes a string and return true or false if it is an isogram
*/

bool	is_isogram(const char phrase[])
{
	char		current_char;
	int			arr_alphabet_index[26];
	int			index;

	if (!phrase)
		return (false);
	if (phrase[0] == '\0')
		return (true);
	_to_initialize_alphabet_index(arr_alphabet_index);
	while (*phrase)
	{
		while ((*phrase == ' ') || (*phrase == '-'))
			phrase++;
		if (*phrase == '\0')
			break ;
		if (!_is_valid_char(*phrase))
			return (false);
		current_char = _to_lowercase(*phrase);
		index = (current_char - 97);
		arr_alphabet_index[index] = arr_alphabet_index[index] + 1;
		if (arr_alphabet_index[index] > 1)
			return (false);
		phrase++;
	}
	return (true);
}

static bool	_is_valid_char(char current_char)
{
	current_char = _to_lowercase(current_char);
	return ((current_char >= 'a') && (current_char <= 'z'));
}

static char	_to_lowercase( char current_char)
{
	if ((current_char >= 'A') && (current_char <= 'Z'))
		current_char = current_char + 32;
	return (current_char);
}

static void	_to_initialize_alphabet_index(int *ptr)
{
	int	alphabet;
	int	count;

	alphabet = 26;
	count = 0;
	while (count < alphabet)
	{
		*ptr = 0;
		ptr++;
		count++;
	}
}
