#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"

struct Cipher::CipherCheshire {
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
};

struct KCipher::VectCheshire {
	vector<string> book;
	unsigned int page = 0;
	
};

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

VCipher :: VCipher() : KCipher() {};

VCipher :: VCipher(string key) {

	for (long unsigned int i = 0; i < key.length(); i++) {

		if (isupper(key[i]) || !(isalpha(key[i]))) {
			cout << "Error: not a valid Vigenere key word" << endl;
			exit(EXIT_FAILURE);
		}
	}

	string page;
	while (page.length() < MAX_LENGTH) {
		page += key;
	}
	
	v_smile->book.clear();
	v_smile->book.push_back(page);
};

VCipher::~VCipher() {};

     
