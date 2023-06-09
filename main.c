/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42_Legin <Nige@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:37:33 by 42_Legin          #+#    #+#             */
/*   Updated: 2023/06/09 10:41:27 by 42_Legin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include	"isogram.h"


void	ft_test_isogram (char *str);

typedef struct test_words
{
	char str_1[25];
	char str_2[20];
	char str_3[25];
	char str_4[25];
	char str_5[100];
	char str_6[100];
	char str_7[100];
	char str_8[100];
	char str_9[100];
	char str_10[100];
	char str_11[100];
	char str_12[100];
	char str_13[100];
	char str_14[100];

}Test;

int	main(void)
{
	struct test_words Test = 
	{
	"",
	"isogram",
	"eleven",
	"zzyzx",
	"subdermatoglyphic",
	"Alahabet",
	"alphAbet",
	"thumbscrew-japingly",
	"thumbsscrew-jappingly",
	"six-year-old",
	"Emily Jung Schwartzkopf",
	"accentor",
	"angola",
	"up-to-date"
	};

	printf("\n\n");
	printf("This function detects if a string is an isogram\n");
	printf("\n");
	ft_test_isogram (NULL);
	printf("\n");
	ft_test_isogram (Test.str_1);
	printf("\n");
	ft_test_isogram (Test.str_2);
	printf("\n");
	ft_test_isogram (Test.str_3);
	printf("\n");
	ft_test_isogram (Test.str_4);
	printf("\n");
	ft_test_isogram (Test.str_5);
	printf("\n");
	ft_test_isogram (Test.str_6);
	printf("\n");
	ft_test_isogram (Test.str_7);
	printf("\n");
	ft_test_isogram (Test.str_8);
	printf("\n");
	ft_test_isogram (Test.str_9);
	printf("\n");
	ft_test_isogram (Test.str_10);
	printf("\n");
	ft_test_isogram (Test.str_11);
	printf("\n");
	ft_test_isogram (Test.str_12);
	printf("\n");
	ft_test_isogram (Test.str_13);
	printf("\n");
	ft_test_isogram (Test.str_14);
	printf("\n\n");
	return (0);
}

void	ft_test_isogram (char *str)
{
	if(is_isogram(str))
		printf("\033[33mThis string : \"%s\" -> is an isogram \033[37m\n",str);
	else
		printf("This string : \"%s\" -> is NOT an isogram\n",str);
}
