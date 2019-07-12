#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include<iomanip>
#include <bits/stdc++.h>
using namespace std;

// Function to check if a word (UniqueWord) is
// palindrome
int plain = 0;

bool checkPalin(string UniqueWord)
{
    int n = UniqueWord.length();
    transform(UniqueWord.begin(), UniqueWord.end(), UniqueWord.begin(), ::tolower);

    for (int i = 0; i < n; i++,n--)
    if (UniqueWord.at(i) != UniqueWord.at(n - 1))
    return false;
    return true;
}

// driver code//

int main(int argc, char *argv[])
{

    if ( argc != 2 ) // argc should be 2 for correct execution

    // print argv[0] assuming it is the program name

    cout << "usage: " << argv[0] << " <filename>\n";

    else
    {
        ifstream inFile; //declaring a file stream object
        ofstream outFile;
        string fileName;
        char character;
        char *tok;
        string word;
        string line;
        int count = 0, L = 0, ch = 0, unique = 0;

        map<string, int> mp; // Create a map to store count of all words

        fileName = argv[1];

        inFile.open(fileName.c_str());
        outFile.open ("Question1.out");

        // Check whether the file was opened successfully:
        if( !inFile.is_open() )
        {
            // If the file couldn't be opened:
            cout << "File couldn't be opened successfully!" << endl;
            return 1;
        }

        while (inFile >> character) ++ch;// Counting number of characters

        inFile.clear();
        inFile.seekg(0, ios::beg);

        while (getline(inFile, line)) ++L; // Counting number of lines

        inFile.clear();
        inFile.seekg(0, ios::beg);

        while(inFile >> word)  // Keep reading words while there are words to read
        {
            count++;

            // count the number of unique words
            if (!mp.count(word)) // If this is first occurrence of word
            mp.insert(make_pair(word,1));
            else
            mp[word]++;

        }

        // Traverse map and print all words whose count
        //is 1
        for (map<string, int> :: iterator p = mp.begin();
        p != mp.end(); p++)
        {
            if (p->second == 1)
            p->first;
            unique++;

            // call the chackPlain function to count the number of plaindrome words in unique words
            checkPalin(p->first);

            if (checkPalin(p->first))
            plain++;

        }

        outFile << count << " " << unique << " " << plain << " " << ch << " " << L;
        outFile.close();

    }

}
