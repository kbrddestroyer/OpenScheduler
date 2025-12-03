#include <gtest/gtest.h>
#include <login/Login.hpp>
#include <login/utils/utility.h>

#include <vector>


TEST(TEST_LOGIN, TEST_HASH_EXPECTED) {
    const std::string raw_password = "testpassword";
    const std::string expected_passwd = "9f735e0df9a1ddc702bf0a1a7b83033f9f7153a00c29de82cedadc9957289b05";  // Hand-hashed "testpassword" string, no salt, no bullshit
    const std::string username = "dummy";

    uint32_t size;
    update_digest(raw_password.c_str(), raw_password.length());

    const size_t precalc_size = get_md_size();

    std::vector<unsigned char> hashed(precalc_size);

    hash_passwd(hashed.data(), &size);

    std::stringstream ss;
    for (unsigned int i = 0; i < size; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hashed[i]);
    }
    const std::string checksum_hex = ss.str();
    ASSERT_STREQ(checksum_hex.c_str(), expected_passwd.c_str());
}

TEST(TEST_LOGIN, TEST_LOGIN_HASH_CPP_IMPL) {
    const std::string raw_password = "testpassword";
    const std::string expected_passwd = "9f735e0df9a1ddc702bf0a1a7b83033f9f7153a00c29de82cedadc9957289b05";  // Hand-hashed "testpassword" string, no salt, no bullshit
    const std::string username = "dummy";

    std::string data;
    Login::Login::doHashPassword(
        raw_password,
        data
    );

    ASSERT_STREQ(data.c_str(), expected_passwd.c_str());
}