/**
 * @file    rsa.h
 * @brief   RSA cipher.
 */

#ifndef CRY_RSA_H_
#define CRY_RSA_H_

#include <cry/mpi.h>

/** Schoolbook RSA */
#define CRY_RSA_PADDING_NONE        0
/** PKCS#1 v1.5 padding */
#define CRY_RSA_PADDING_PKCS_V15    1
/** PKCS#1 v2.0 padding */
#define CRY_RSA_PADDING_PKCS_V21    2

/**
 * Structure used for both private and public key.
 */
struct cry_rsa_ctx {
    cry_mpi n;      /**< Modulus */
    cry_mpi e;      /**< Public exponent */
    cry_mpi d;      /**< Private exponent */
    char padding;   /**< Padding mode */
};

typedef struct cry_rsa_ctx cry_rsa_ctx;

#ifdef __cplusplus
extern "C" {
#endif

int cry_rsa_init(cry_rsa_ctx *ctc, int padding);

int cry_rsa_encrypt(cry_rsa_ctx *ctx, unsigned char **out, size_t *outlen,
                    const unsigned char *in, size_t inlen);

int cry_rsa_decrypt(cry_rsa_ctx *ctx, unsigned char **out, size_t *outlen,
                    const unsigned char *in, size_t inlen);

int cry_rsa_sign(cry_rsa_ctx *ctx, unsigned char **out, size_t *outlen,
                 const unsigned char *in, size_t inlen);

int cry_rsa_verify(cry_rsa_ctx *ctx, const unsigned char *sig, size_t siglen,
                   const unsigned char *in, size_t inlen);

int cry_rsa_keygen(cry_rsa_ctx *ctx, size_t bits);


#ifdef __cplusplus
}
#endif

#endif /* CRY_RSA_H_ */
