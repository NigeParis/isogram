/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isogram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42_Legin <Nige@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:10:34 by 42_Legin          #+#    #+#             */
/*   Updated: 2023/06/12 10:11:47 by 42_Legin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include	"isogram.h"

static int	ft_strlen(const char *str);
static int	ft_strcopy(const char *src, char *str, int str_len);
static bool	ft_is_compared_char_valid(char c, char *str2);
static bool	ft_is_string_valid_isogram(char *ptr1_to_str, char *ptr2_to_str);

/**
*	main function 
*	args : takes a string and return true or false if it is an isogram
*/

bool	is_isogram(const char phrase[])
{
	char	*ptr_copy_phrase;
	int		str_len;
	int		reponse;

	if (phrase == NULL)
		return (false);
	str_len = ft_strlen(phrase);
	if (!str_len)
		return (false);
	ptr_copy_phrase = (void *) malloc((str_len + 1) * sizeof(char));
	if (ptr_copy_phrase == NULL)
	{
		free(ptr_copy_phrase);
		return (false);
	}
	ft_strcopy(phrase, ptr_copy_phrase, str_len);
	reponse = ft_is_string_valid_isogram(ptr_copy_phrase, ptr_copy_phrase);
	free(ptr_copy_phrase);
	return (reponse);
}

/**
*	string length function
*	args : takes a pointer to a string
*	returns the length less the '\0' caracter.
*/

static int	ft_strlen(const char *str)
{
	int	str_len;

	str_len = 0;
	if (*str == '\0')
		return (!str_len);
	while (*(str++) != '\0')
	{
		str_len++;
	}
	return (str_len);
}

/**
*	copy string - returns nbr chars copied
*/

static int	ft_strcopy(const char *src, char *str, int str_len)
{
	int	count;

	count = 0;
	while (count < str_len)
	{
		str[count] = src[count];
		count++;
	}
	str[count] = '\0';
	return (count);
}

/**
*	validates if the string is an isogram
*/

static bool	ft_is_string_valid_isogram(char *ptr1_to_str, char *ptr2_to_str)
{
	bool	valid;

	while (*ptr1_to_str != '\0')
	{
		while (*ptr2_to_str != *ptr1_to_str)
			ptr2_to_str++;
		valid = ft_is_compared_char_valid(*ptr1_to_str, ptr2_to_str);
		if (!valid)
			return (false);
		ptr1_to_str++;
	}
	return (true);
}

/**
*	compares caracters in the string to look for exceptions and doubles.
*/

static bool	ft_is_compared_char_valid(char c, char *ptr)
{
	int		nbr_of_occurance;
	char	test_char;

	nbr_of_occurance = 0;
	if ((c == ' ') || (c == '-'))
		return (true);
	while (*ptr != '\0')
	{
		test_char = *ptr;
		if ((c >= 'A') && (c <= 'Z'))
			c = c + 32;
		if ((*ptr >= 'A') && (*ptr <= 'Z'))
			test_char = *ptr + 32;
		if ((c < 'a') || (c > 'z'))
			return (false);
		if (c == test_char)
		{
			nbr_of_occurance++;
			if (nbr_of_occurance > 1)
				return (false);
		}
		ptr++;
	}
	return (true);
}
