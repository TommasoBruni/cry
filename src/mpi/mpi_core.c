/*
 * Copyright (c) 2013-2014, Davide Galassi. All rights reserved.
 *
 * This file is part of CRY software.
 *
 * CRY is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with CRY; if not, see <http://www.gnu/licenses/>.
 */

#include "mpi_pvt.h"
#include <stdlib.h>
#include <stdio.h>


/* Digits allocation quantum */
#define MPI_PREC    8

int cry_mpi_grow(cry_mpi *a, unsigned int digs)
{
    cry_mpi_digit *tmp;

    if (digs <= a->alloc)
        return 0;

    /* ensure there are always at least MPI_PREC digits extra on top */
    digs += (MPI_PREC * 2) - (digs % MPI_PREC);
    /* reallocate the array */
    tmp = (cry_mpi_digit *) realloc(a->data, sizeof(cry_mpi_digit) * digs);
    if (tmp == NULL)
        return -1;
    a->data = tmp;

    /* zero excess digits */
    a->alloc = digs;

    return 0;
}

int cry_mpi_init(cry_mpi *a)
{
    /* allocate required memory and clear it */
    a->data = (cry_mpi_digit *) malloc(sizeof(cry_mpi_digit) * MPI_PREC);
    if (a->data == NULL)
        return -1;

    /* finalize the initialization */
    a->used = 0;
    a->alloc = MPI_PREC;
    a->sign = 0;
    return 0;
}

/*
 * Init an cry_mpi for a given size
 */
int cry_mpi_init_size(cry_mpi *a, unsigned int size)
{
    a->data = malloc(sizeof(cry_mpi_digit) * size);
    if (a->data == NULL)
        return -1;

    a->used = 0;
    a->alloc = size;
    a->sign = 0;
    return 0;
}

/*
 * Initialize a big number and assign it an integer value.
 */
int cry_mpi_init_int(cry_mpi *a, long i)
{
    int res;

    if ((res = cry_mpi_init(a)) != 0)
        return res;
    cry_mpi_set_int(a, i);
    return 0;
}

void cry_mpi_set_int(cry_mpi *a, long i)
{
    if (i < 0) {
        a->sign = 1;
        i = -i;
    } else {
        a->sign = 0;
    }

    while (i != 0) {
        a->data[a->used++] = (unsigned char) i;
        i >>= 8;
    }
}

void cry_mpi_clear(cry_mpi *a)
{
    if (a->data != NULL)
        free(a->data);
    /* reset the members to make debugging easier */
    a->data = NULL;
    a->alloc = 0;
    a->used = 0;
    a->sign = 0;
}

int cry_mpi_copy(cry_mpi *d, const cry_mpi *s)
{
    int res;
    unsigned int i;

    /* if dst == src do nothing */
    if (d == s)
        return 0;

    /* grow dest */
    if (d->alloc < s->used) {
        res = cry_mpi_grow(d, s->used);
        if (res != 0)
            return res;
    }

    /* zero dest and copy the parameters over */
    for (i = 0; i < s->used; i++)
        d->data[i] = s->data[i];
    d->used = s->used;
    d->sign = s->sign;
    return 0;
}

int cry_mpi_init_copy(cry_mpi *d, const cry_mpi *s)
{
    int res;

    if ((res = cry_mpi_init(d)) != 0)
        return res;
    if ((res = cry_mpi_copy(d, s)) != 0)
        cry_mpi_clear(d);
    return res;
}

/*
 * Quick way to get number of bits in a word
 */
static size_t word_size_bits(unsigned long l)
{
    static const unsigned char bits[256] = {
        0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    };

#if __WORDSIZE == 64
    if (l & 0xffffffff00000000L) {
        if (l & 0xffff000000000000L) {
            if (l & 0xff00000000000000L)
                return (bits[(int)(l >> 56)] + 56);
            else
                return (bits[(int)(l >> 48)] + 48);
        } else {
            if (l & 0x0000ff0000000000L)
                return (bits[(int)(l >> 40)] + 40);
            else
                return (bits[(int)(l >> 32)] + 32);
        }
    } else {
#endif
        if (l & 0xffff0000L) {
            if (l & 0xff000000L)
                return (bits[(int)(l >> 24L)] + 24);
            else
                return (bits[(int)(l >> 16L)] + 16);
        } else {
            if (l & 0xff00L)
                return (bits[(int)(l >> 8)] + 8);
            else
                return (bits[(int)(l)]);
        }
#if __WORDSIZE == 64
    }
#endif
}

/*
 * Big number size in bits
 */
size_t cry_mpi_count_bits(const cry_mpi *a)
{
    if (a->used == 0)
        return 0;
    return ((a->used-1) * MPI_DIGIT_BITS) +
            word_size_bits(a->data[a->used-1]);
}

void cry_mpi_print(const cry_mpi *a)
{
    int i;

    if (a->used == 0) {
        printf("00\n");
        return;
    }    

    i = a->used;
    while (i-- > 0)
        printf("%02x", a->data[i]);
    printf("\n");
}
