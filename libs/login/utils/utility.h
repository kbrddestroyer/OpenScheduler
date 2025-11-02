#ifndef UTILITY_H
#define UTILITY_H

#include <openssl/evp.h>

#if __cplusplus
extern "C" {
#endif

#define HASH_FAIL_DIGEST_UPDATE 1
#define HASH_FAIL_DIGEST_FINALIZE 2
#define HASH_SUCCESS 0

    EVP_MD_CTX * get_context();
    void free_context(EVP_MD_CTX *);
    uint8_t hash_passwd(const char *, unsigned char *, uint32_t *);

#if __cplusplus
}
#endif

#endif //UTILITY_H
