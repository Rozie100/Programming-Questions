#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ofstream outFile;
//Function to print product array for a given array
//arr[] of size n
void productArray(unsigned long int arr[], int n)
{
    int i, j;


    for (i = 0; i < n; ++i)
    {
        int p = 1;
        for (j = 0; j < n; ++j)
            if (j != i)
            p *= arr[j];

        outFile << p <<( i== n-1?"":" ");

    }

    return;
}
// Driver code
int main(int argc, char *argv[])
{

    if ( argc != 2 ) // argc should be 2 for correct execution

    // We print argv[0] assuming it is the program name

    cout << "usage: " << argv[0] << " <filename>\n";

    else
    {
        ifstream inFile; //declaring a file stream object
        string fileName;
        unsigned long int arr[100];
        int count = 0;
        fileName = argv[1];
        inFile.open(fileName.c_str());
        outFile.open ("Question2.out");

        // Check whether the file was opened successfully:
        if( !inFile.is_open() )
        {
            // If the file couldn't be opened:
            cout << "File couldn't be opened successfully!" << endl;
            return 1;
        }

        // read the integers in the file into a vector
        while(inFile.good())
        {
            inFile >> arr[count++];

        }

        inFile.close();

        // call the product function

        productArray(arr, count);

    }

}


