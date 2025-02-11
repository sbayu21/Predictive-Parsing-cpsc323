

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// Read code from file
string readFile(fstream& file, string filePath) {

    // String to contain entire text
    string result = "";

    file.open(filePath, ios::in);

    char character;

    while (!file.eof()) {

        file.get(character);
        result += character; // Add read characters to result string
    }
    file.close();

    // Return entire text
    return result;
}

// Tokenize different strings
vector<string> tokenize(string file) {

    int len = file.length();
    vector<string> result;

    for (int i = 0; i < len; i++) {

        if (file[i] != '\n' && file[i] != ' ') { // If the character is not a white space
            string token = "";
            while (file[i] != '\n' && file[i] != ' ' && i < len) {
                token += file[i]; // Create token
                i++;
            }
            result.push_back(token); // Add token to result vector
        }
    }
    return result;
}

void ConvertToCPlusPlus(fstream& file, string filePath, vector<string> tokens) {

    bool foundVar = false; // True when we find "var"

    file.open(filePath, ios::out);

    // Add headers to C++ file
    file << "#include<iostream>\nusing namespace std;\n";

    for (int i = 0; i < tokens.size(); i++) {
        if (foundVar) {
            // Add code only after "var"
            if (tokens[i] == "begin") {
                // Begin main driver code in C++
                file << "int main()\n{\n";
            }
            else if (tokens[i] == ":" || tokens[i] == "integer") {
                // Skip "integer"
                continue;
            }

            else if (tokens[i] == "write") {
                // cout<< in place of write()
                file << "cout << ";
                // Skip '('
                i += 2;
                bool printedValue = false; // To track if "value=" has been printed
                while (tokens[i] != ")") {
                    if (tokens[i] == "\"value=") {
                        file << " << "; // Add <<
                        file << tokens[i]; // Add "value="
                        i++;
                        printedValue = true;
                        continue;
                    }
                    else if (printedValue && tokens[i] == ",") {
                        i++;
                        continue;
                    }
                    else if (tokens[i] == "pp") {
                        file << " << "; // Add <<
                        file << tokens[i]; // Add pp
                    }
                    else {
                        file << tokens[i];
                    }
                    file << ' ';
                    i++;
                }
            }
            else if (tokens[i] == "end.") {
                file << "}";
            }
            else if (tokens[i] == ";") {
                file << ';' << '\n';
            }
            else {
                file << tokens[i];
            }
            // Spaces between tokens
            file << ' ';
        }
        if (tokens[i] == "var") {
            // Declaring variables in C++ and begin main
            file << "int ";
            foundVar = true;
        }
    }
    file.close();
    return;
}

int main() {

    fstream file2, fileCpp;
    string file2Path = "C:\\Users\\bayu\\Desktop\\Final24.txt";
    string fileCppPath = "C:\\Users\\bayu\\Desktop\\finalproject3result.cpp";
    string cPlusPlus;

    string formattedCode = readFile(file2, file2Path); // Store entire code as string
    formattedCode.pop_back(); // Remove last character at end of file

    vector<string> tokens = tokenize(formattedCode);

    ConvertToCPlusPlus(fileCpp, fileCppPath, tokens);
    return 0;
}
