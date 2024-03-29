#include "test.h"
#include <cry/ecdh.h>

void secret_exchange(void)
{
    cry_ecdh_ctx dh1, dh2;
    cry_ecp q1, q2;

    ASSERT_OK(cry_ecp_init(&q1));
    ASSERT_OK(cry_ecp_init(&q2));

    /* Alice */

    ASSERT_OK(cry_ecdh_init(&dh1, CRY_ECP_GRP_SECP256R1));
    ASSERT_OK(cry_mpi_rand(&dh1.d, 256));
    ASSERT_OK(cry_ecdh_agree(&dh1)); /* gen pub key */
    ASSERT_OK(cry_ecp_copy(&q1, &dh1.q));

    /* Bob */

    ASSERT_OK(cry_ecdh_init(&dh2, CRY_ECP_GRP_SECP256R1));
    ASSERT_OK(cry_mpi_rand(&dh2.d, 256));
    ASSERT_OK(cry_ecdh_agree(&dh2)); /* gen pub key */
    ASSERT_OK(cry_ecp_copy(&q2, &dh2.q));

    /* Public keys exchange takes place */
    ASSERT_OK(cry_ecp_copy(&dh1.q, &q2));
    ASSERT_OK(cry_ecp_copy(&dh2.q, &q1));

    /* Final step */
    ASSERT_OK(cry_ecdh_final(&dh1));
    ASSERT_OK(cry_ecdh_final(&dh2));

    /* Final checks */

    ASSERT_EQ(cry_mpi_cmp(&dh1.z.x, &dh2.z.x), 0);
    ASSERT_EQ(cry_mpi_cmp(&dh1.z.y, &dh2.z.y), 0);

    cry_ecdh_clear(&dh1);
    cry_ecdh_clear(&dh2);
    cry_ecp_clear(&q1);
    cry_ecp_clear(&q2);
}

#define MYRUN(name, test) run(name, test, NULL, NULL)

void ecdh_test(void)
{
    TRACE("* ECDH\n");
    MYRUN("Secret exchange", secret_exchange);
    TRACE("\n");
}
