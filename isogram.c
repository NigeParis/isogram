/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isogram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42_Legin <Nige@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:10:34 by 42_Legin          #+#    #+#             */
/*   Updated: 2023/06/16 09:06:05 by 42_Legin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"isogram.h"

static bool	_valid_char(char current_char);
static char	_to_lowercase( char current_char);
static bool	_found_double_char(const char *char_in_string, char current_char);

/**
*	main function 
*	args : takes a string and return true or false if it is an isogram
*/

bool	is_isogram(const char phrase[])
{
	const char	*position_in_phrase;
	char		current_char;

	position_in_phrase = phrase;
	if (!phrase)
		return (false);
	while (*position_in_phrase)
	{
		while ((*position_in_phrase == ' ') || (*position_in_phrase == '-'))
			position_in_phrase++;
		if (!_valid_char(*position_in_phrase))
			return (false);
		current_char = _to_lowercase(*position_in_phrase);
		if (_found_double_char((position_in_phrase + 1), current_char))
			return (false);
		position_in_phrase++;
	}
	return (true);
}

static bool	_found_double_char(const char *char_in_string, char current_char)
{
	char	c;
	int		count;

	count = 0;
	while (*char_in_string)
	{
		c = *char_in_string;
		c = _to_lowercase(*char_in_string);
		count += (current_char == c);
		if (count > 0)
			return (true);
		char_in_string++;
	}
	return (false);
}

static bool	_valid_char(char current_char)
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
