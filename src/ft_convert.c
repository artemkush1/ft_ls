/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <cchadwic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:26:08 by cchadwic          #+#    #+#             */
/*   Updated: 2020/02/08 22:23:43 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*ft_short_name(char *path)
{
	int i;
	int k;

	i = 0;
	while (path[i])
		i++;
	i--;
	while (path[i] == '/' && i > 0)
		path[i--] = '\0';
	i = -1;
	k = 0;
	while (path[++i])
		if (path[i] == '/' && i > 0)
			k = i + 1;
	return (&(path[k]));
}

char		*convert_filename(char *s1, char *s2)
{
	int i;
	int k;

	i = -1;
	while (s1[++i])
		;
	k = -1;
	while (s2[++k])
		s1[i++] = s2[k];
	s1[i] = '\0';
	return (s1);
}

char		*prepare_path(char *s)
{
	char	*s1;
	int		i;
	int		k;
	int		sign;

	i = 0;
	k = 0;
	sign = 0;
	if (!(s1 = ft_strnew(PATH_MAX + 1000)))
		ERROR(1);
	while (s[i])
	{
		if (s[i] != '/' && !(sign = 0))
			s1[k++] = s[i++];
		else
		{
			if (sign == 0 && (sign = 1))
				s1[k++] = s[i++];
			else
				i++;
		}
	}
	if (sign == 0)
		s1[k] = '/';
	return (s1);
}
