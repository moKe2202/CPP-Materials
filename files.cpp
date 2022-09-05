#include <iostream>
#include <fstream> // NECESSARY INCLUDE
#include <string>

using namespace std;

int main(int argc, char** argv){
    
    ofstream myFile1; // Ofstream is for writing to files
    ifstream myFile2; // For reading files
    fstream myFile3; // For both

    // Example of writing to a file

    myFile1.open ("example.txt"); // Sets the file to a specific location
    myFile1 << "Writing this to a file.\n"; // Syntax the same as cout or cin
    myFile1.close(); // Best practice to close a file after you're done with it

    // Can also be used with constructors (ofstream, ifstream, etc. are classes)
    //Equivalent code to above

    ofstream constructorFile("example.txt");
    constructorFile << "Writing this to a file.\n";
    constructorFile.close();

    // Full syntax for opening a file is open (filename, mode), where filename is the location to a real or to-be-made file
    // and mode is an optional parameter or group of parameters

    /* LIST OF MODES AND THEIR FUNCTIONS
    ios::in	        Open for input operations.
    ios::out	    Open for output operations.
    ios::binary	    Open in binary mode.
    ios::ate	    Set the initial position at the end of the file. If this flag is not set, the initial position is the beginning of the file.
    ios::app	    All output operations are performed at the end of the file, appending the content to the current content of the file.
    ios::trunc	    If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
    */

    ofstream myfile;
    myfile.open ("example.bin", ios::out | ios::app | ios::binary);

    //To check if a file is open
    if(myfile.is_open()){ /* Do something */}

    // After a file is closed, the stream can be used to open another file (since the stream is a class and something like "myfile" is an object)
    fstream reopeningFile;
    reopeningFile.open ("example.bin", ios::out | ios::app | ios::binary);
    reopeningFile.close();
    reopeningFile.open ("secondExample.bin", ios::out | ios::app | ios::binary);

    // Reading a file
    string line;
    ifstream reading("someText.txt");
    if(reading.is_open()){
        while(getline(reading, line)){ //First getline parameter is the stream and the second one is the line string (getline returns true or false based on whether the stream is ready for more operations or has had an error)
            cout << line << endl;
        }
        reading.close();
    }

    else cout << "Unable to open file" << endl;
    /* FLAGS
    The following member functions exist to check for specific states of a stream (all of them return a bool value):

    bad()
        Returns true if a reading or writing operation fails. For example, in the case that we try to write to a file that is not open for writing or if the device where we try to write has no space left.
    fail()
        Returns true in the same cases as bad(), but also in the case that a format error happens, like when an alphabetical character is extracted when we are trying to read an integer number.
    eof()
        Returns true if a file open for reading has reached the end.
    good()
        It is the most generic state flag: it returns false in the same cases in which calling any of the previous functions would return true. Note that good and bad are not exact opposites (good checks more state flags at once).

    The member function clear() can be used to reset the state flags.

    */
    return 0;
}