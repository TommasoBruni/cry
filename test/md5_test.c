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

#include "test.h"
#include <cry/md5.h>

static char *ar[] = {
    "HelloWorld",
    "Davy",
    NULL
};

void md5_test(void)
{
    char **asc = ar;
    unsigned int len;
    struct cry_md5_ctx md5;
    unsigned char md[16];
    int i;

    cry_md5_init(&md5);
    for (i = 0; asc[i] != NULL; i++) {
        len = strlen(asc[i]);
        cry_md5_update(&md5, asc[i], len);
    }
    cry_md5_digest(&md5, md);

    TRACE("MD5: ");
    for (i = 0; i < sizeof(md); i++)
        TRACE("%x", md[i]);
    TRACE("\n");
}

