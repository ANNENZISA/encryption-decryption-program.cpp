#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& text, int shift) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            result += ch;
        }
    }
    return result;
}

string decrypt(const string& text, int shift) {
    // Decryption is the same as encryption with a negative shift
    return encrypt(text, -shift);
}

int main() {
    cout << "Enter text to encrypt: ";
    string inputText;
    getline(cin, inputText);

    int shift;
    cout << "Enter shift value: ";
    cin >> shift;

    string encryptedText = encrypt(inputText, shift);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, shift);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
