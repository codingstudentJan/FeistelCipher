// Feistel.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Main.h"
#include "Feistel-Cipher/FeistelCipher.h"

using namespace std;

int main()
{
	FeistelCipher feistel;
	std::uint64_t block = 1000000000000000000;
	std::uint64_t encryptedBlock = feistel.encrypt(block,10);
	std::uint64_t decryptedBlock = feistel.decrypt(encryptedBlock, 10);
	//feistel.viewBits(resultBlock);
	cout << block << "\n" << encryptedBlock << "\n" << decryptedBlock;
	return 0;
}
