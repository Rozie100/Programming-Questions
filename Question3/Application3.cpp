#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const string APP1 = "Application1.exe";
const string APP2 = "Application2.exe";

const string APP1_OUTPUT = "Question1.out";
const string APP2_OUTPUT = "Question2.out";
const string APP2_INPUT  = "input.in";

int main(int argc, char *argv[])
{

    if ( argc == 1 ) // argc should be 2 for correct execution

    // print argv[0] assuming it is the program name

    cout << "usage: " << argv[0] << " <filename>[ <filename>,...]\n";

    else {

        ofstream app2_input;

        ifstream inFile; //declaring a file stream object
        string fileName, line, concatenates = "";

        for (int i = 1; i < argc; i++)
        {
            fileName = argv[i];

            ifstream ifile(fileName.c_str());

            if (!ifile) {

                // file could not be opened
                cout << "file " << fileName << " could't be openned!";

                } else {

                inFile.close();
                // 1 - execute first app with current fileName

                string command;
                command = APP1;
                command.append(" ");
                command.append(fileName);

                system(command.c_str());

                inFile.open(APP1_OUTPUT.c_str());
                getline(inFile, line);
                inFile.close();

                concatenates += line + (i == argc-1 ? "" : " ");

            }
        }

        // 2 - write concatenated integer arrays
        app2_input.open(APP2_INPUT.c_str());
        app2_input << concatenates;
        app2_input.close();

        // 3 - run second application
        string command;
        command = APP2;
        command.append(" ");
        command.append(APP2_INPUT);
        system(command.c_str());

        // 4 - show the results on the screen
        inFile.open(APP2_OUTPUT.c_str());
        getline(inFile, line);
        inFile.close();
        cout << line << "\n";

    }

}
