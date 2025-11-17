#include "utility.h"

#include <string.h>


static EVP_MD_CTX * __init_context() {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if ( EVP_DigestInit(ctx, EVP_sha256()) != 1 ) {
        return NULL;
    }

    return ctx;
}

EVP_MD_CTX * get_context() {
    static EVP_MD_CTX *ctx = NULL;

    if (ctx == NULL) {
        ctx = __init_context();
    }

    return ctx;
}

void free_context(EVP_MD_CTX *ctx) {
    EVP_MD_CTX_free(ctx);
}

#if defined(WIN32)
#pragma comment (linker, "/export:hash_passwd")
#endif
uint8_t hash_passwd(const char * raw, unsigned char * hashed_output, uint32_t * size) {
    EVP_MD_CTX * ctx = get_context();
    if ( EVP_DigestUpdate(ctx, raw, strlen(raw)) != 1 ) {
        *size = 0;
        return HASH_FAIL_DIGEST_UPDATE;
    }

    if ( EVP_DigestFinal_ex(ctx, hashed_output, size) != 1 ) {
        *size = 0;
        return HASH_FAIL_DIGEST_UPDATE;
    }

    return HASH_SUCCESS;
}
