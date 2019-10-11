/**
 * @file    dsa.h
 * @brief   Digital Signature Algorithm
 */

#ifndef CRY_DSA_H_
#define CRY_DSA_H_

#include <cry/mpi.h>

struct cry_dsa_ctx {
    cry_mpi g;
    cry_mpi p;
    cry_mpi q;
    cry_mpi pvt;  /**< Private signing key */
    cry_mpi pub;  /**< Public verification key */
};

typedef struct cry_dsa_ctx cry_dsa_ctx;

struct cry_dsa_signature {
    cry_mpi r;
    cry_mpi s;
};

typedef struct cry_dsa_signature cry_dsa_signature;

#ifdef __cplusplus
extern "C" {
#endif

int cry_dsa_init(cry_dsa_ctx *ctx);

void cry_dsa_clear(cry_dsa_ctx *ctx);

int cry_dsa_sign(cry_dsa_ctx *ctx, cry_dsa_signature *sign,
                 const unsigned char *in, size_t len);

int cry_dsa_verify(cry_dsa_ctx *ctx, const cry_dsa_signature *sign,
                   const unsigned char *in, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* CRY_DSA_H_ */
