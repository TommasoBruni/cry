#include "mpi_pvt.h"
#include "cry/prng.h"

/*
 * Generate a random integer with a given number of bits.
 */
int cry_mpi_rand(cry_mpi *r, unsigned int bits)
{
    unsigned int digs, res;
    unsigned long msb;

    digs = CRY_MPI_BITS_TO_DIGS(bits);
    if (digs == 0) {
        cry_mpi_zero(r);
        return 0;
    }
    if (r->alloc < digs) {
        if ((res = cry_mpi_grow(r, digs)) != 0)
            return res;
    }
    r->used = digs;

    if ((res = cry_prng_rand((unsigned char *)r->data,
                    digs * sizeof(cry_mpi_digit))) != 0)
        return res;

    msb = bits - CRY_MPI_DIGIT_BITS * (digs - 1);
    if (msb < CRY_MPI_DIGIT_BITS)
        r->data[digs-1] &= (1UL << msb)-1; /* Clean extra bits */
    r->data[digs-1] |= (1UL << (msb-1));   /* Set the msb */
    return 0;
}

int cry_mpi_rand_range(cry_mpi *a, const cry_mpi *max)
{
    int n, ret;

    n = cry_mpi_count_bits(max);
    if ((ret = cry_mpi_rand(a, n)) != 0)
        return ret;
    if (cry_mpi_cmp_abs(a, max) >= 0)
        ret = cry_mpi_mod(a, a, max);
    return 0;
}

