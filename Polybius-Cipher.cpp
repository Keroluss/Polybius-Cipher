// Author :     Kerolus Akram Mady
// Purpose :    implement a Polybius Cipher Encryptor & Decryptor in C++ with customizable keys,
//              allowing users to encrypt and decrypt messages while providing a user-friendly interface through a main menu.
// Date :       6-3-2024 V 1.0
//
//              1  2  3  4  5
//            1 A  B  C  D  E
//            2 F  G  H I/J K
//            3 L  M  N  O  P
//            4 Q  R  S  T  U
//            5 V  W  X  Y  Z

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// Functions declaration
void main_menu6();
string insert_custom_key ();
void encryption6 (string key);
void decryption6 (string key);

int main (){
    main_menu6(); // Start the main menu
}

// Function to display the main menu
void main_menu6(){
    while (true){
        // Welcome message menu instructions
        cout << "\n\n** Welcome to the Polybius Cipher Encryptor & Decryptor! **\n";
        cout << "** Unveil hidden messages with Polybius Cipher! Customize your key for secure encryption & decryption. **\n";
        cout << "** The cipher didn't support symbols and numbers only alphabets. **\n\n";
        cout << "A) Encrypt a message.\n";
        cout << "B) Decrypt a message.\n";
        cout << "C) Bake to main menu.\n";
        cout << "E) Exit the program.\n";
        cout << "- Enter your choice: ";
        string menu1  ;
        getline (cin, menu1);
        // Check if user input is empty
        if (all_of(menu1.begin(), menu1.end(), ::isspace)) {
            cout << "Please input your choice." << endl;
            continue;
        }
        // Handle user choices
        if (menu1 == "A" || menu1 == "a"){
            string key = insert_custom_key();
            encryption6 (key);
        }
        else if (menu1 == "B" || menu1 == "b"){
            string key = insert_custom_key();
            decryption6 (key);
        }
        else if (menu1 == "c" || menu1 == "C"){
            cout << "in production mode\n";
            continue;

        }
        else if (menu1 == "e" || menu1 == "E") {
            cout << "exiting the program ....\n";
            exit(0);

        }

        else {
            cout << "* invalid input *\n\n";
        }
}}

// Function to get a custom key from the user with validation
string insert_custom_key (){
    while (true){
        // Key input instructions
        cout << "** The key must include (1, 2, 3, 4, 5). **\n";
        cout << "** Do not use a number that is not mentioned and do not repeat a number.  **\n";
        cout << "** You can use any order. **\n";

        string key ;
        cout << "- Enter the key : ";
        getline(cin, key);

        // Handle user empty inputs
        if (all_of(key.begin(), key.end(), ::isspace)) {
            cout << "Please input a key." << endl;
            continue;
        }
        // Key validation logic
        // Every variable must have value "1".
        int one, two ,three, four, five;
        one = two = three = four = five = 0;
        // Ensure the length of the key is 5
        if (key.size() == 5){
            for (char c : key){
                if (c == '1'){
                    one += 1;
                    // If number one repeated display erorr message and recall the function
                    if (one > 1){
                        cout << "Wrong key, you repeated number 1\n";
                        insert_custom_key();

                        }
                    }
                    else if (c == '2'){
                        two += 1;
                        // If number two repeated display erorr message and recall the function
                        if (two > 1){
                            cout << "Wrong key, you repeated number 2\n";
                            insert_custom_key();
                        }
                    }
                    else if (c == '3'){
                        three += 1;
                        // If number three repeated display erorr message and recall the function
                        if (three > 1){
                            cout << "Wrong key, you repeated number 3\n";
                            insert_custom_key();
                        }
                    }
                    else if (c == '4'){
                        four += 1;
                        // If number four repeated display erorr message and recall the function
                        if (four > 1){
                            cout << "Wrong key, you repeated number 4\n";
                            insert_custom_key();
                        }
                    }
                    else if (c == '5'){
                        five += 1;
                        // If number five repeated display erorr message and recall the function
                        if (five > 1){
                            cout << "Wrong key, you repeated number 5\n";
                            insert_custom_key();
                        }
                    }



                }
                // Final validation checks, if any number have value 0 so the number didn't exist in the key
                if (one == 0 || two == 0 || three == 0 || four == 0 || five == 0 ){
                    cout << "Wrong key. Ensure that each number (1, 2, 3, 4, 5) is used exactly once.\n";
                    continue;

                }
                return key;


            }else {
                cout << "Wrong key, the length of the key must be 5.\n";

            }

        }


    }

// Function to perform encryption using Polybius Cipher
void encryption6 (string key){
    while (true){
        // Define the Polybius Cipher grid
        char array[6][6] = {
                {'#', '#', '#', '#', '#', '#'},
                {'#', 'A', 'B', 'C', 'D', 'E'},
                {'#', 'F', 'G', 'H', 'I', 'K'},
                {'#', 'L', 'M', 'N', 'O', 'P'},
                {'#', 'Q', 'R', 'S', 'T', 'U'},
                {'#', 'V', 'W', 'X', 'Y', 'Z'}
        };
        string message ;
        // Prompt user to enter a message for encryption
        cout << "- Enter a message to encrypt: ";
        getline (cin, message);
        // Check if the message is empty
        if (all_of(message.begin(), message.end(), ::isspace)) {
            cout << "Please input a message." << endl;
            continue;
        }




        // Convert the message to uppercase and delete non-alphabet
        string upper;
        for (char c : message){
            upper += (char) toupper(c);

        }

        cout << "Encrypted message: ";
        for (char y : upper ){
            // Replace 'J' with 'I' in the message
            if (y == 'j' || y == 'J' ){
                y = 'I';
            }
            // Search for the position of the character in the Polybius grid
            for (int i = 0; i < 6; i++){

                for (int j = 0 ; j < 6; j++){
                    if(array[i][j] == y){
                        // The index [i][j] in the standard key (12345) if the user input custom key like 24513
                        // W if character index == [1][2] it in standard key we replace [1] to the first digit of the custom key and so on
                        // Explained in detailed in attached algorithms
                        if (i == 1){
                            cout << key[0];
                        }
                        else if (i == 2){
                            cout << key[1];
                        }
                        else if (i == 3){
                            cout << key[2];
                        }
                        else if (i == 4){
                            cout << key[3];
                        }
                        else if (i == 5){
                            cout << key[4];
                        }
                        if (j == 1){
                            cout << key[0];
                        }
                        else if (j == 2){
                            cout << key[1];
                        }
                        else if (j == 3){
                            cout << key[2];
                        }
                        else if (j == 4){
                            cout << key[3];
                        }
                        else if (j == 5){
                            cout << key[4];
                        }

                    }

                }

            }
        }main_menu6();



    }}

// Function to perform decryption using Polybius Cipher
void decryption6 (string key){
    while (true){
        char letters[6][6] = {
                {' ', ' ', ' ', ' ', ' ', ' '},
                {' ', 'a', 'b', 'c', 'd', 'e'},
                {' ', 'f', 'g', 'h', 'i', 'k'},
                {' ', 'l', 'm', 'n', 'o', 'p'},
                {' ', 'q', 'r', 's', 't', 'u'},
                {' ', 'v', 'w', 'x', 'y', 'z'}
        };
        string message ;
        // Prompt user to enter a message for decryption
        cout << "- Enter a message to decrypt: ";
        getline (cin, message);
        // Check if the message is empty
        if (all_of(message.begin(), message.end(), ::isspace)) {
            cout << "Please input a message." << endl;
            continue;
        }

        string encrypted_numes;
        for (char c : message){
            if (isdigit(c)){
                // Collect numbers only in variable (user can input symbols and alphabet but the code don't convert)
                encrypted_numes += c;
            }

        }
        // Ensure there are an even number of numerical representations
        if (encrypted_numes.length() %2 !=0){
            cout << "The numbers in the encrypted message must be an even number "
                    "\n(each character is represented by two numbers)." << endl;
            continue;

        }
        // Validate that the numerical representations are within the allowed range (1-5)
        for (char c : encrypted_numes){
            // Encrypted message must contain only 1, 2, 3, 4, 5
            if ( !(c >= '1' && c <= '5')){
                cout << "allowed numbers is (1, 2, 3, 4, 5) only."<< endl;
                continue;

            }}
        cout << "Decrypted message: ";
        // Iterate through pairs of numerical representations for decryption
        for (int o = 0 ; o < (encrypted_numes.length()-1); o+=2){
            // Subtracting '0' converts the ASCII value of a digit to its integer value
            char i = encrypted_numes[o]- '0';
            char j = encrypted_numes[o +1 ]- '0';

            // Get the index of the decrypted character
            // Explained in detailed in attached algorithms
            if (i == key[0]- '0'){
                i=1;
            }
            else if(i == key[1]- '0'){
                i=2;
            }
            else if(i ==key[2]- '0'){
                i=3;
            }
            else if(i ==key[3]- '0'){
                i=4;
            }
            else if(i ==key[4]- '0'){
                i=5;
            }
            if(j == key[0]- '0'){
                j=1;
            }
            else if(j == key[1]- '0'){
                j=2;
            }
            else if(j == key[2]- '0'){
                j=3;
            }
            else if(j == key[3]- '0'){
                j=4;
            }
            else if(j == key[4]- '0'){
                j=5;
            }

            cout << letters[i][j];

        }main_menu6();

}}