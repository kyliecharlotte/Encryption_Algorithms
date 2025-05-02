#include <string>
#include <iostream>
#include "rcipher.h"

struct Cipher::CipherCheshire {
	string cipher_alpha;
};
// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------

RCipher::RCipher() : CCipher(13) {}

RCipher::~RCipher(){
};

