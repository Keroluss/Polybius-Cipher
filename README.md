# Polybius-Cipher
implement a Polybius Cipher Encryptor &amp; Decryptor in C++ with customizable keys, allowing users to encrypt and decrypt messages while providing a user-friendly interface through a main menu.
# Polybius Square Cipher Algorithms:  
## 1) Import necessary libraries:  
- "iostream" for input/output operations.  
- "algorithm" for using functions like all_of.  
- "cctype" for using functions like  toupper and isdigit.
## 2) Define functions:  
### A) Main_menu6 ():  
- Displays a welcome message and menu options.
- Gets user input for their choice.
- Validates the user input.
- Calls the appropriate function based on user input:
  - "A" or "a": Calls insert_custom_key() and then encryption() with the returned key.
  - "B" or "b": Calls insert_custom_key() and then decryption() with the returned key.
  - "C" or "c": Does nothing (commented out "in production mode").
  - "E" or "e": Exits the program.
  - Invalid input: Displays an error message.  
### B) Insert_custom_key ():
- Prompts the user to enter a custom key.
- Validates the key:
  - Ensures the key is not empty.
  - Ensures the key length is 5.
  - Ensures the key contains only the digits "1", "2", "3", "4", and "5".
  - Ensures each digit appears only once in the key.
- If the key is valid, returns the key. Otherwise, prompts the user to enter a new key.
### C) Encryption (string key):
- Defines a Polybius Cipher grid (filled with letters), this grid is made for use with the standard key 12345.
- Prompts the user to enter a message to encrypt.
- Validates the message:
  - Ensures the message is not empty.
- Converts the message to uppercase.
- Iterates through each character in the message:
  - If the character is 'J' or 'j', replaces it with 'I'.
  - Finds the character's position in the Polybius Cipher grid.
  - The character representation made with the standard key 12345.
  - Uses the character's position and the custom key to generate the encrypted representation (convert encrypted message form standard key to inserted custom key steps below).
  - Prints the encrypted representation.
- Calls main_menu6() to return to the main menu.
### D) Decryption (string key):
- Defines a Polybius Cipher grid (filled with letters), this grid is made for use with the standard key 12345.
- Prompts the user to enter a message to decrypt.
- Validates the message:
  - Ensures the message is not empty.
- Extracts the numerical representations from the message (ignoring non-digits).
- Validates the extracted representation:
  - Ensures there are an even number of digits.
  - Ensures each digit is within the range 1-5.
- Iterates through pairs of digits in the extracted representation:
  - Uses the digits and the custom key to find the corresponding position in the Polybius Cipher grid (convert encrypted message made with custom key to standard key steps below).
  - Prints the letter at that position.
- Calls main_menu6() to return to the main menu.
## 3) Overall:
- The program starts by calling main_menu6().
- main_menu6() handles user interaction and calls the appropriate functions based on user input.
- The encryption and decryption functions use the custom key provided by the user.
- The program performs basic input validation to ensure the user enters valid data.
## 4)  Encryption steps:
- **Purpose:**
  - Convert a message to encrypted message with standard key then convert it to encrypted message with custom key.
- **Inputs:**
  - **Decrypted_message:**  A string containing the decrypted message represented by alphabets (e.g., “CODE”).
  - **Key:** A string containing the key numbers used for encryption		 (e.g., "23541").
- **Steps:**
  - Iterate by Pairs:  The code iterates through the encrypted_message in pairs of digits (e.g., "C").
  - Get letter representation: The code search letter index in the grid, for letter “C” is (1, 3).
  - **Converting section:**
    - First, we  replace the digit ‘1’ with the number that exist in the first place in key (e.g., "23541"). Let’s say that is ‘2’.
    - second , we replace the second digit in pair ‘3’ with the number in the third place in key (e.g., "23541"). Let’s say it is ‘5’.
- **Example:  **
  - **Input:**
    - **Original message:** “CODE"
    - **Key:** "23541"
  - **Process:**
    - Character “C”: From the grid, ’C’ representation is (1,3). The first place in key is ‘2’. The third is “5”.  The secret guide says (2, 5) means 'C'.
    - Character "O": From the grid, ’C’ representation is (3,4). The third place in key is ‘5’. The fourth  is “4”.  The secret guide says (5, 4) means 'O'.
    - (This continues for each charachter)
  - **Output:**
    - **Decrypted message:** "25542421".


## 5) Decryption steps:
- **Purpose:**
  - Convert encrypted message with custom key to encrypted message with standard key.
- **Inputs:**
  - **Encrypted_message:** A string containing the encrypted message represented by numbers (e.g., "25542421").
  - **Key:** A string containing the key numbers used for decryption		 (e.g., "23541").
- **Steps:**
  - Iterate by Pairs: The code iterates through the encrypted_message in pairs of digits (e.g., "25").
  - **Converting section:**
    - **First digit investigation:**
      - First, we check where the first digit of the pair (e.g., "2") is in our special key (e.g., "23541"). Let's say it's at position 1 in our secret key.
    - **Second digit investigation:**
      - Next, we explore the second digit of the pair (e.g., "5"). We look in our key again to find its position. Let's say it's at position 3 in our secret key.
  - **Uncovering the Code's Meaning**:
    - The positions we find in the key give us clues about the hidden letters in the code. For example, if '2' is at position 1 and '5' is at position 3, our secret guide might say this combination (1, 3) means the letter 'C'.
- **Example:**  
  **- Input:**
    - **Encrypted message:** "25542421"
    - **Key:** "23541"
  - Process:
    - **Pair "25":** In the key, '2' is at position 1, and '5' is at position 3. The secret guide says (1, 3) means 'C'.
    - **Pair "54":** In the key, '5' is at position 3, and '4' is at position 4. The secret guide says (3, 4) means 'O'.
    - (This continues for each pair)
  - **Output:**
    - **Decrypted message:** "CODE".
## 6) Note:
- The pseudocode focuses on the high-level logic of the program and does not include details like variable names or specific loop conditions.
