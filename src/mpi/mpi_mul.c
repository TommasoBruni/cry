#include "mpi_pvt.h"

int cry_mpi_mul(cry_mpi *r, const cry_mpi *a, const cry_mpi *b)
{
    int res, sign;

    sign = a->sign ^ b->sign;
    res = cry_mpi_mul_abs(r, a, b);
    if (res == 0 && !cry_mpi_is_zero(r))
        r->sign = sign;
    return res;
}


int cry_mpi_mul_dig(cry_mpi *r, const cry_mpi *a, cry_mpi_digit b)
{
    cry_mpi tmp;

    cry_mpi_static_init(&tmp, &b, 1);
    return cry_mpi_mul(r, a, &tmp);
}
