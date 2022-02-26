/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:49:00 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/26 17:24:52 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fpointer;
    char *singleLine;

    singleLine = malloc(1 * sizeof(char));
    fpointer = open("test.txt", O_RDONLY);
    while (singleLine != NULL)
    {
        free(singleLine);
        singleLine = get_next_line(fpointer);
        //printf("%s", singleLine);
    }
    return (0);
}