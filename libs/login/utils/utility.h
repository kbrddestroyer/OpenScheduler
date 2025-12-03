#ifndef UTILITY_H
#define UTILITY_H

#include <openssl/evp.h>
#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif

#define HASH_FAIL_DIGEST_UPDATE 1
#define HASH_FAIL_DIGEST_FINALIZE 2
#define HASH_SUCCESS 0

    EVP_MD_CTX * get_context(bool);
    void free_context(EVP_MD_CTX *);

    uint8_t update_digest( const char * /* raw */, size_t /* size */ );
    size_t get_md_size();


    uint8_t hash_passwd(unsigned char *, uint32_t *);

#if __cplusplus
}
#endif

#endif //UTILITY_H
