#include "utility.h"

#include <string.h>


static EVP_MD_CTX * init_context() {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if ( EVP_DigestInit(ctx, EVP_sha256()) != 1 ) {
        return NULL;
    }

    return ctx;
}

EVP_MD_CTX * get_context(bool force_reset) {
    static EVP_MD_CTX *ctx = NULL;

    if (force_reset && ctx != NULL) {
        free_context(ctx);
        ctx = NULL;
    }

    if (ctx == NULL) {
        ctx = init_context();
    }

    return ctx;
}

void free_context(EVP_MD_CTX* ctx) {
    EVP_MD_CTX_free(ctx);
}

#if defined(WIN32)
#pragma comment (linker, "/export:update_digest")
#endif
uint8_t update_digest(const char * raw, const size_t size) {
    EVP_MD_CTX * ctx = get_context(true);
    if ( EVP_DigestUpdate(ctx, raw, size) != 1 ) {
        return HASH_FAIL_DIGEST_UPDATE;
    }

    return HASH_SUCCESS;
}

#if defined(WIN32)
#pragma comment (linker, "/export:get_md_size")
#endif
size_t get_md_size() {
    return EVP_MD_size(EVP_sha3_256());
}

#if defined(WIN32)
#pragma comment (linker, "/export:hash_passwd")
#endif
uint8_t hash_passwd(void * hashed_output, uint32_t * size) {
    EVP_MD_CTX * ctx = get_context(false);

    if ( EVP_DigestFinal_ex(ctx, hashed_output, size) != 1 ) {
        *size = 0;
        return HASH_FAIL_DIGEST_UPDATE;
    }

    return HASH_SUCCESS;
}
