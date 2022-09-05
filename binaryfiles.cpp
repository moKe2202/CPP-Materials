#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

    streampos size;
    char * memblock;

    ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg(); // Tellg returns the current position of the stream. By putting ios::ate we make it positioned at the end of the file, which makes it the size of the file at the same time.
        memblock = new char [size]; // Initialize the char array to contain as many characters there are in the file
        file.seekg (0, ios::beg); // Set the position to the start. seekg(offset , direction(eg. ios::beg, ios::end))
        file.read (memblock, size); // .read(memory block, and the size of the array) -> parameters in general
        file.close();

        cout << "the entire file content is in memory";
        for(int i = 0; i < size; i++){
            cout << *(memblock + 1);
        }
        delete[] memblock;
    }
    else cout << "Unable to open file";
    return 0;
}