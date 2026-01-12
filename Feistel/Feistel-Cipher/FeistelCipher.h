#pragma once
#include <iostream>
#include <cstdint>
class FeistelCipher {
public:
	std::uint64_t encrypt(std::uint64_t block, int rounds);
	std::uint64_t swap(uint64_t block);
	std::uint64_t encryptRound(std::uint64_t block);
	std::uint64_t decrypt(std::uint64_t block, int rounds);
	void decryptRound(int rounds, uint64_t& block);
	void viewBits(uint64_t block);
private:
	std::uint32_t function_F(std::uint32_t r);
};