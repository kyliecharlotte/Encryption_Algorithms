#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"

struct Cipher::CipherCheshire {
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
};

struct KCipher::VectCheshire {
	vector<string> book;
	unsigned int page = 0;
};

KCipher :: KCipher() {
	vector<string> book;

	string page;
	for (unsigned int i = 0; i < MAX_LENGTH; i++) {
		page += "a";
	};
	
	book.push_back(page);
	v_smile = new VectCheshire;
	v_smile->book = book;
};

KCipher :: KCipher(string page) {
	if (page.length() == 0) {
		cout << "Invalid Running key: " << endl;
		exit(EXIT_FAILURE);
	}
	for (char c : page) {
		if (isupper(c)) {
			cout << "Character is uppercase: " << c << endl;
			exit(EXIT_FAILURE);
		}
	}

	v_smile = new VectCheshire;
	v_smile->book.push_back(page);
};

void KCipher::add_key(string page) {
	if (page.length() == 0) {
                cout << "Nothing on the page" << endl;
	       	exit(EXIT_FAILURE);
        }
        for (char c : page) {
                if (isupper(c)) {
			cout << "Character is uppercase: " << c << endl;
                        exit(EXIT_FAILURE);
                }
        }

        v_smile->book.push_back(page);
};

void KCipher::set_id(unsigned int id) {
	unsigned int length = v_smile->book.size();
	if (id > length) {
		cout << "Warning: invalid id: " << id << endl; 
		exit(EXIT_FAILURE);
	}
	v_smile->page = id;
};

string KCipher::encrypt(string raw) {
	
	cout <<	"Encrypting...";
	
	string retStr;
	string alpha = smile->cipher_alpha;

	int length_space = raw.length();
	string encrypt_page = v_smile->book[v_smile->page];
		
	for (unsigned int i = 0; i < encrypt_page.length();i++){
		if (encrypt_page[i] == ' ') {
			encrypt_page.erase(encrypt_page.begin() + i);
		}
	}	

	vector<int> spaces;

	for (int i = 0; i < length_space; i++) {
		if (raw[i] == ' ') {
			spaces.push_back(i);
		}
	}
	
        for (unsigned int i = 0; i < raw.length();i++){
                if (raw[i] == ' ') {
                        raw.erase(raw.begin() + i);
                }
        }

	unsigned int total_char = raw.length();

	if (encrypt_page.length() < total_char) {
                cout << "Invalid Running key: " << endl;
		exit(EXIT_FAILURE);
        }

	int pos = 0;	
	
	for (unsigned int i = 0; i < total_char; i++) {
		char let = raw[i];
		char e = encrypt_page[i];
		pos = find_pos(alpha, tolower(let));
		if (isupper(raw[i])) {
			int pos_e = find_pos(alpha, tolower(e));
			rotate_string(alpha, pos);
			retStr += toupper(alpha[pos_e]);
		} else {
			int pos_e = find_pos(alpha, e);
			rotate_string(alpha, pos);
			retStr += alpha[pos_e];
		}
		rotate_string(alpha, ALPHABET_SIZE - pos);
	}

	for (unsigned int i = 0; i < spaces.size(); i++) {
		retStr.insert(spaces[i], " ");
	}

	cout << "Done" << endl;
	return retStr;

}

string KCipher::decrypt(string enc) {

        cout << "Decrypting...";

        string retStr;
        string alpha = smile->cipher_alpha;

        int length_space = enc.length();
        string encrypt_page = v_smile->book[v_smile->page];
        
	for (unsigned int i = 0; i < encrypt_page.length();i++){
                if (encrypt_page[i] == ' ') {
                        encrypt_page.erase(encrypt_page.begin() + i);
                }
        }
        vector<int> spaces;

        for (int i = 0; i < length_space; i++) {
                if (enc[i] == ' ') {
                        spaces.push_back(i);
                }
        }

        for (unsigned int i = 0; i < enc.length();i++){
                if (enc[i] == ' ') {
                        enc.erase(enc.begin() + i);
                }
        }

        unsigned int total_char = enc.length();

        int pos = 0;
        for (unsigned int i = 0; i < total_char; i++) {
                char let = enc[i];
                char e = encrypt_page[i];
                pos = find_pos(alpha, tolower(e));
                rotate_string(alpha, pos);

		if (isupper(enc[i])) {
                        int pos_e = find_pos(alpha, tolower(let));
                        rotate_string(alpha, ALPHABET_SIZE - pos);
                        retStr += toupper(alpha[pos_e]);
                } else {
                        int pos_e = find_pos(alpha, let);
                        rotate_string(alpha, ALPHABET_SIZE - pos);
                        retStr += alpha[pos_e];
                }
        }

        for (unsigned int i = 0; i < spaces.size(); i++) {
                retStr.insert(spaces[i], " ");
        }

        cout << "Done" << endl;
        return retStr;

};

KCipher::~KCipher() {
	delete v_smile;
};
/* Helper function definitions
 */

unsigned int find_pos(string alpha, char c)
{
    unsigned int pos = 0;

        pos = alpha.find(c);

    return pos;
        //TODO
}
// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------
