#include "mpi_pvt.h"

int cry_mpi_sub_abs(cry_mpi *r, const cry_mpi *a, const cry_mpi *b)
{
    size_t min, max, i;
    cry_mpi_digit c, t1, t2, *rp;
    const cry_mpi_digit *ap, *bp;
    int res;

    if (cry_mpi_cmp_abs(a, b) < 0)
        return CRY_ERROR_BAD_DATA; /* negative results are not allowed */

    max = a->used;
    min = b->used;

    if (r->alloc < max) {
        if ((res = cry_mpi_grow(r, max)) < 0)
            return res;
    }
    r->used = max;
    r->sign = 0;

    ap = a->data;
    bp = b->data;
    rp = r->data;
    c = 0;
    for (i = 0; i < min; i++) {
        t1 = *ap++;
        t2 = *bp++;
        *rp++ = (t1 - t2 - c);
        if (t1 != t2) /* if are equal the carry is unchanged */
            c = (t1 < t2);
    }

    /*
     * If there is a borrow, decrease blocks until one does not
     * reverse rollover
     */
    for (; i < max && c; i++) {
        c = (*ap == 0);
        *rp++ = *ap++ - 1;
    }
    if (c)
        return CRY_ERROR_BAD_DATA; /* negative result not allowed */
    for (; i < max; i++)
        *rp++ = *ap++;
    cry_mpi_adjust(r); /* Adjust used counter */

    return 0;
}
