#include <iostream>
#include <fstream>

using namespace std;

string caesarsCipher(string word, int key) {
    key = key % 26;
    int length = word.length();
    string encrypted = "";

    for (int i = 0; i < length; i++) {
        int newCharNum = (int)(word[i]) + key;
        if (newCharNum > 90) {
            encrypted += (char)(64 + (newCharNum - 90));
        }
        else {
            encrypted += (char)(newCharNum);
        } 
    }

    return encrypted;
}

string decipherCaesarsCipher(string word, int key) {
    key = key % 26;
    key = 26 - key;

    int length = word.length();
    string decrypted = "";

    for (int i = 0; i < length; i++) {
        int newCharNum = (int)(word[i]) + key;
        if (newCharNum > 90) {
            decrypted += (char)(64 + (newCharNum - 90));
        }
        else {
            decrypted += (char)(newCharNum);
        }
    }

    return decrypted;
}

int main()
{
    int const key = 107;
    int const wordsQuantity = 100;
    
    fstream input1, output1;
    fstream input2, output2;
    fstream input3, output3;

    input1.open("dane_6_1.txt", ios::in);
    output1.open("wyniki_6_1.txt", ios::out);

    input2.open("dane_6_2.txt", ios::in);
    output2.open("wyniki_6_2.txt", ios::out);

    input3.open("dane_6_3.txt", ios::in);
    output3.open("wyniki_6_3.txt", ios::out);

    if (input1.good() and output1.good()) {
        for (int i = 0; i < wordsQuantity; i++) {
            string word;

            input1 >> word;

            output1 << caesarsCipher(word, key) << endl;
        }
    }
    else {
        cout << "Problem z plikiem";
    }

    if (input2.good() and output2.good()) {
        for (int i = 0; i < 3000; i++) {
            string word;
            int key;

            input2 >> word >> key;

            output2 << decipherCaesarsCipher(word, key) << endl;
        }
    }
    else {
        cout << "Problem z plikiem";
    }

    if (input3.good() and output3.good()) {
        for (int i = 0; i < 3000; i++) {
            string decoded, encoded;
            bool found = false;

            input3 >> decoded >> encoded;

            for (int i = 0; i < 26; i++) {
                if (caesarsCipher(decoded, i) == encoded) {
                    found = true;
                }
            }

            if (!found) {
                output3 << decoded << endl;
            }
        }
    }
    else {
        cout << "Problem z plikiem";
    }

    input1.close();
    output1.close();

    input2.close();
    output2.close();

    input3.close();
    output3.close();
}