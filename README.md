# Encryption_Algorithms
### Some helper files were created by Professor Jee Choi for CS 330 at the University of Oregon
Encryption and decryption algorithms are a cornerstone of cybersecurity, even as technology gets more advanced. Encrypting a message is the process of modifying the exterior content to conceal the true meaning underneath, and decryption is the process of "solving" an encryption. Here, I have five encryption and decryption algorithms.

1. Substitution Cipher: Each letter in a message is replaced with another letter or symbol

2. Caesar Cipher: Shifts the alphabet by a specified number and applies this shifted alphabet to the message.

3. ROT13: A Caesar Cipher, but only shifts the alphabet by 13.

4. Running Key: Uses a long key that is often a string of words, like a sentence, and uses this as the alphabet.

5. Vigenere: Our implementation of a Vigenere cipher is as a shortened Running Key, where a (typically) shorter phrase is used and repeated, acting as the new alphabet for the message.

To run any of these with a specified file:

./cipher -m (letter code) -i (input file) -o (name of output file)

Letter Code: s: Substitution
    c: Caesar
    r: ROT13
    k: Running Key
    v: Vigenere

ex:./cipher -m s -i test1/subs/substitution.txt -o output.txt 

The input file can be one found in test{1,2,3}, or another one added to the folder. The output file can exist or be the name of a file you wish to create with the results.










