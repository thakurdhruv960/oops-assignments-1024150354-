//Lab assignment 9
//thakur dhruv singh(1024150354)

//PROGRAM 1
#include<iostream>

#include<fstream>

using namespace std;


int main() {

ofstream fout("NUM.TXT");

if (!fout) {

cout << "Error opening file!" << endl;

return 1;

}

for (int i = 1; i <= 200; i++) {

fout << i << "\n";

}

fout.close();

cout << "Numbers 1 to 200 written to NUM.TXT successfully." << endl;

return 0;

}

//PROGRAM 2
#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
 
void countAlphabets(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file!" << endl;
        return;
    }
    char ch;
    int count = 0;
    while (fin.get(ch)) {
        if (isalpha(ch))
            count++;
    }
    fin.close();
    cout << "Number of alphabets in NOTES.TXT: " << count << endl;
}
 
int main() {
    // First create a sample NOTES.TXT
    ofstream fout("NOTES.TXT");
    fout << "Hello World! 123 C++ is fun.";
    fout.close();
 
    countAlphabets("NOTES.TXT");
    return 0;
}

//PROGRAM 3
#include<iostream>
#include<fstream>
using namespace std;
 
int main() {
    // Create source file
    ofstream fout("source.txt");
    fout << "This is source file content.\nLine 2.\nLine 3.";
    fout.close();
 
    ifstream fin("source.txt");
    ofstream fdest("destination.txt");
 
    if (!fin || !fdest) {
        cout << "File error!" << endl;
        return 1;
    }
 
    char ch;
    while (fin.get(ch)) {
        fdest.put(ch);
    }
 
    fin.close();
    fdest.close();
    cout << "File copied successfully." << endl;
    return 0;
}

//PROGRAM 4
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
 
int main() {
    char str[200];
    cout << "Enter a string: ";
    cin.getline(str, 200);
 
    int len = strlen(str);
    cout << "Length of string: " << len << endl;
 
    // Write to file
    ofstream fout("chars.txt");
    fout << str;
    fout.close();
 
    // Read from file character by character
    ifstream fin("chars.txt");
    cout << "Characters fetched from file: ";
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << endl;
    fin.close();
    return 0;
}

//PROGRAM5
#include<iostream>
#include<fstream>
using namespace std;
 
int main() {
    // (a) Create file with A-Z and read 10th character using seekg()
    ofstream fout("AZ.txt");
    for (char c = 'A'; c <= 'Z'; c++) fout << c;
    fout.close();
 
    ifstream fin("AZ.txt");
    fin.seekg(9);  // 0-indexed, 10th char
    char ch;
    fin.get(ch);
    cout << "(a) 10th character: " << ch << endl;
    fin.close();
 
    // (b) Overwrite 5th character using seekp()
    fstream f("AZ.txt", ios::in | ios::out);
    f.seekp(4);  // 5th position (0-indexed)
    f.put('*');
    f.close();
    cout << "(b) Overwrote 5th character with '*'" << endl;
 
    // (c) Find file size using tellg()
    fin.open("AZ.txt");
    fin.seekg(0, ios::end);
    long size = fin.tellg();
    cout << "(c) File size: " << size << " bytes" << endl;
    fin.close();
 
    // (d) Read last character using seekg()
    fin.open("AZ.txt");
    fin.seekg(-1, ios::end);
    fin.get(ch);
    cout << "(d) Last character: " << ch << endl;
    fin.close();
 
    // (e) Create data.txt with multiple lines and demonstrate seekg/tellg
    ofstream fout2("data.txt");
    fout2 << "Hello World\nC++ File I/O\nSeek and Tell\n";
    fout2.close();
 
    ifstream fin2("data.txt");
    fin2.seekg(10);  // Move to 10th byte
    cout << "(e) Position after seekg(10): " << fin2.tellg() << endl;
    cout << "Remaining content: ";
    string line;
    while (getline(fin2, line))
        cout << line << endl;
    fin2.close();
 
    return 0;
}
//PROGRAM 6
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
 
int main() {
    // Create file and track put pointer after each character
    ofstream fout("hello.txt");
    const char* text = "Hello World";
    cout << "Writing characters and tracking put pointer:" << endl;
    for (int i = 0; text[i] != '\0'; i++) {
        fout.put(text[i]);
        cout << "Char: '" << text[i] << "'  tellp() = " << fout.tellp() << endl;
    }
    fout.close();
 
    // Replace 'World' with 'C++' using random access
    // 'World' starts at position 6
    fstream f("hello.txt", ios::in | ios::out);
    f.seekp(6);
    f << "C++  ";  // Overwrite 'World' (5 chars) with 'C++  '
    f.close();
 
    // Read and display final content
    ifstream fin("hello.txt");
    string result;
    getline(fin, result);
    cout << "\nFinal file content: " << result << endl;
    fin.close();
 
    return 0;
}


