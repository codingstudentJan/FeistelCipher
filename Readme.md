# Feistel Cipher (Educational / Toy)

Educational implementation of a Feistel cipher in C++.

⚠️ **Not cryptographically secure. Do NOT use in production.**  
This project exists solely to study block cipher construction principles.

## Purpose
This project demonstrates:
- Feistel network structure
- Round functions and key scheduling
- Reversibility of Feistel ciphers
- Basic cryptographic engineering considerations
- How modern block ciphers are constructed on an abstract, algorithmic level

## Implemented Features
- Configurable number of rounds
- Custom round function
- Simple key schedule
- Encrypt / Decrypt symmetry
- Deterministic output for testability

## What This Is NOT
- ❌ No resistance against cryptanalysis
- ❌ No authentication (no MAC / AEAD)
- ❌ No side-channel protection
- ❌ No secure randomness
- ❌ No claim of security

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./feistel
