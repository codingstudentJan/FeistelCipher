#include "FeistelCipher.h"

std::uint64_t FeistelCipher::encrypt(std::uint64_t block, int rounds) {
    for (int i = 0; i < rounds; i++) {
        block = encryptRound(block);
        viewBits(block);
    }
    return swap(block);
}

std::uint64_t FeistelCipher::decrypt(std::uint64_t block, int rounds) {
    block = swap(block);

    decryptRound(rounds, block);

    return block;
}

void FeistelCipher::decryptRound(int rounds, uint64_t& block)
{
    for (int i = 0; i < rounds; ++i) {
        std::uint32_t originalLeft = static_cast<std::uint32_t>(block >> 32);
        std::uint32_t originalRight = static_cast<std::uint32_t>(block & 0xFFFFFFFFULL);
        std::uint32_t right = originalLeft;
        std::uint32_t left = originalRight ^ function_F(originalLeft);

        block = (static_cast<std::uint64_t>(left) << 32) | static_cast<std::uint64_t>(right);
    }
}


std::uint64_t FeistelCipher::swap(std::uint64_t block) {
    return (block << 32) | (block >> 32);
}


std::uint64_t FeistelCipher::encryptRound(std::uint64_t block) {
    std::uint32_t right = static_cast<std::uint32_t>(block & 0xFFFFFFFFULL);
    std::uint32_t originalLeft = static_cast<std::uint32_t>(block >> 32);
    std::uint32_t left = right;
    right = originalLeft ^ function_F(right);
    std::uint64_t resultBlock = (static_cast<std::uint64_t>(left) << 32) | static_cast<std::uint64_t>(right);
    return resultBlock;
}

void FeistelCipher::viewBits(std::uint64_t block)
{
    for (int i = 63; i >= 0; --i) {
        std::uint64_t bit = (block >> i) & 1ULL;
        std::cout << bit;
    }
    std::cout << '\n';
}

std::uint32_t FeistelCipher::function_F(std::uint32_t r) {
    r ^= (r << 5) | (r >> 27);   
    r ^= 0xA5A5A5A5;             // XOR with Constant
    return r;
}

