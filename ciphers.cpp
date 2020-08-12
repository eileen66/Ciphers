#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;


char shiftChar(char c, int rshift){        
    if (isalpha(c) && (c >= 65 && c <= 90)) { 
        int ch = c;                         
        ch += rshift;                       
        while (isalpha(c) && ch > 90){      //uppercase letters
            int over = ch - 90;
            ch = 64 + over;
            
        }
        c = ch;
    }
    else if (isalpha(c) && c >= 97) {       // lowercase letters
        if (rshift > 25) {
            rshift = rshift % 26;
        }
        int ch = c;

        ch += rshift;
        if (ch > 122){
            int over = ch - 122;
            ch = 96 + over;
        }
        c = ch;
    }
    
    return c;

}

char backShiftChar(char c, int rshift){                 // reverse the shift
    if (isalpha(c) && (c >= 65 && c <= 90)) {           //lowercase letters
        c -= rshift;
        while (c < 65){
            int over = 65 - c;
            c = 91 - over;
            
        }
    }
    else if (isalpha(c) && (int(c) >= 97 && int(c) <= 122)) {   // uppercase letters
        if (rshift > 25) {
            rshift = rshift % 26;
        }
        c -= rshift;
        if (c < 97){
            int over = 97 - c;
            c = 123 - over;
        }
    }
    return c;
}

string encryptCaesar(string plaintext, int rshift){     
    string chipher;
    for (int i = 0; i < plaintext.length(); i++){       // loop through text
        chipher += shiftChar(plaintext[i], rshift);     
    }
    return chipher;
}

int shift(char c){
    return c - 97;
}

string encryptVigenere(string text,string key) {
    int count = 0;                                              // count position of key
    string chiphered = "";
    for (int i = 0; i < text.length(); i++){                    // loop through text
        chiphered += shiftChar(text[i], shift(key[count]));     
        
        if (isalpha(text[i])){                                  // keeo track of count
            if (count == key.length() - 1){                     
                count = 0;                             //reset count if its at the end of key
            }       
            else 
                count++;
        }        
    }
    return chiphered;
}

string decryptCaesar(string caesar, int shift){
    string chipher;
    for (int i = 0; i < caesar.length(); i++){              
        chipher += backShiftChar(caesar[i], shift);
    }
    return chipher;
}

string decryptVigenere(string vigenere, string key){
    int count = 0;
    string chiphered = "";
    for (int i = 0; i < vigenere.length(); i++){
        chiphered += backShiftChar(vigenere[i], shift(key[count]));
        
        if (isalpha(vigenere[i])){
            if (count == key.length() - 1){
                count = 0;
            }
            else 
                count++;
        }        
    }
    return chiphered;
}

int main(){

    string s;
    string key;
    int shift;
    cout << left << setw(15) <<  "Enter plaintext" << ": " ;
    getline(cin, s);
    cout << "= Caesar = \n" << left << setw(15) << "Enter shift" << ": " ;
    cin >> shift;

    string caesar = encryptCaesar(s, shift);
    cout << left << setw(15) << "Chipertext" << ": " << caesar << endl; 

    string decryptedC = decryptCaesar(caesar, shift);
    //if (decryptedC == s)
        cout << left << setw(15) << "Decrypted" << ": " << decryptedC << endl;
    
    
    cout << "= Vigenere = \n" << left << setw(15) << "Enter keyword" << ": " ;
    cin >> key; 

    string vigenere = encryptVigenere(s, key);
    cout << left << setw(15) << "Chipertext" << ": " << vigenere << endl; 
    
    string decryptedV = decryptVigenere(vigenere, key);
    //if (decryptedV == s)
        cout << left << setw(15) << "Decrypted" << ": " << decryptedV << endl;

    return 0;
}
