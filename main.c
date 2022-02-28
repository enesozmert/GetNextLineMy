/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:49:00 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/28 12:03:55 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int i;
    int fpointer;
    char *singleLine;

    i = 1;
    singleLine = malloc(1 * sizeof(char));
    fpointer = open("test.txt", O_RDONLY);
    while (i < 7)
    {
        free(singleLine);
        singleLine = get_next_line(fpointer);
        //printf("%s", singleLine);
        printf("line [%02d]: %s", i, singleLine);
        i++;
    }
    close(fpointer);
    return (0);
}