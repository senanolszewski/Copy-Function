/*
 *        File: copy_file.cc
 *      Author: Nasseef Abukamail
 *        Date: March 04, 2019
 * Description: Demonstrate output streams
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
void copyFunction(ifstream &inStream,ofstream &outStream);

int main(int argc, char const *argv[]) {
    ifstream inStream;
    ofstream outStream;
    string inFileName, outFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName.c_str());
    if(inStream.fail()){
        cout << "Error: File does not exist!";
    } else{
        cout << "Enter the output file name: ";
        cin >> outFileName;
        outStream.open(outFileName.c_str());
        //check for failure
        if(inStream.fail()){
        cout << "Error: File does not exist!";
        } else{
        copyFunction(inStream, outStream);
    
        inStream.close();
        outStream.close();
        }
    }
    return 0;
}// main

void copyFunction(ifstream &inStream, ofstream &outStream){
    char ch;
    inStream.get(ch);
    while(!inStream.eof()){
        outStream << ch;
        inStream.get(ch);
    }
    cout << "Copied Successfully!" << endl;
}

/* Extra credit(Due: Tuesday 3/5/2019 11:59 PM):
 * Modify the copy program (above) by doing the copying in a function that takes an input
 * stream and an output stream as parameters. It should copy all the lines from the input stream to the
 * output stream. For example: copy(inStream, outStream);
 * The function must use the getline function to copy all the data.
 * Create a public repository on GitHub, push your code to the repository and
 * tag me (@nasseef) in the final commit message. Please make sure your program works
 * before you tag me.
 */
