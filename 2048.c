/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:49:10 by tponark           #+#    #+#             */
/*   Updated: 2022/09/24 15:23:48 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 100

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start > strlen(s))
	{
		ptr = (char *)calloc(1, 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (len > (strlen(s) - (int)start))
		len = (strlen(s) - (int)start);
	ptr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static size_t	ft_total(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static size_t	ft_word(const char *s, char c, size_t word_l)
{
	if (!strchr(s, c))
		word_l = strlen(s);
	else
		word_l = strchr(s, c) - s;
	return (word_l);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	word_l;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_l = strlen(s);
	array = malloc((ft_total(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_l = ft_word(s, c, word_l);
			array[i++] = ft_substr(s, 0, word_l);
			s += word_l;
		}
	}
	array[i] = NULL;
	return (array);
}

void	ft_grid_input(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\033[1;35m");
	printf("\nPlease enter the elements of the grid  :\n");
	printf("\033[0m");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			scanf("%d%*c", &grid[i][j]);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int		i;
	int		j;
	char	str[100];
	int		grid[4][4];
	int		result[4][4];
	char	**sequence;

	ft_grid_input(grid);
	//printing stuffs
	printf("\033[1;35m");
	printf("\nThe grid :\n");
	printf("\033[0m");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%-6d", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	//inputting moving sequences
	printf("\nPlease input your move sequence : ");
	i = 0;
	fgets(str, STR_SIZE, stdin);
	str[strcspn(str, "\n")] = 0;
	//scanf("%s\n", str);
	sequence = ft_split(str, ' ');
	while (sequence[i])
	{
		printf("%s, \n", sequence[i]);
		i++;
	}

	return (0);
}
