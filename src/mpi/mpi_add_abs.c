#include "mpi_pvt.h"

int cry_mpi_add_abs(cry_mpi *r, const cry_mpi *a, const cry_mpi *b)
{
    size_t min, max, i;
    cry_mpi_digit t, l, c, *rp;
    const cry_mpi_digit *ap, *bp;
    int res;

    if (a->used < b->used) {
        const cry_mpi *swp = a;
        a = b;
        b = swp;
    }
    max = a->used;
    min = b->used;

    if (r->alloc < (max + 1)) {
        if ((res = cry_mpi_grow(r, max + 1)) < 0)
            return res;
    }
    r->used = max;
    r->sign = 0;

    ap = a->data;
    bp = b->data;
    rp = r->data;

    c = 0;
    for (i = 0; i < min; i++) {
        t = (*ap++ + c);
        c = (t < c);  /* check for wrap, on overflow t is 0 */
        l = (t + *bp++);
        c += (l < t); /* check for wrap, if t is 0 then l >= t */
        *rp++ = l;
    }

    for (; i < max && c; i++) {
        *rp = *ap++ + 1;
        c = (*rp++ == 0);
    }
    if (c) {
        *rp = 1;
        r->used++;
    } else {
        for (; i < max; i++)
            *rp++ = *ap++;
    }

    return 0;
}
