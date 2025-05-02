#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"

struct Cipher::CipherCheshire {
	string cipher_alpha;	
};

// -------------------------------------------------------
// Caesar Cipher implementation
	
CCipher::CCipher()
{
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
	smile->cipher_alpha = cipher_alpha;
};

CCipher::CCipher(int shift)
{
	if (shift < 0) {
		cout << "Error: Caesar cipher is less than 0" << endl;
		exit(EXIT_FAILURE);
	} 

	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
	
	rotate_string(cipher_alpha, shift);
	
	smile->cipher_alpha = cipher_alpha;
	
};

CCipher::~CCipher()
{	
};
// -------------------------------------------------------


// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{

	// perform rot rotations
	while (rot > 0) {
		in_str[ALPHABET_SIZE] = in_str[0];
	for (unsigned int i = 0; i < ALPHABET_SIZE; i++) {
		in_str[i] = in_str[i+1];
	}
	
	rot = rot - 1; 
	}
};

int len(string& str) {
	return str.length();
}
