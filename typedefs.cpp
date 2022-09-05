#include <iostream>

using namespace std;

// DEFINE DIRECTIVE
#define PI 3.14

//Define can also be used with #ifndef... for example
#ifndef PI
#define PI 3.14
#endif

// Define can also take parameters to form "small functions"

#define INCREMENT(x) ++x
#define MULTIPLY(a, b) a* b

//Typedef syntax
typedef long long int veryLongInt1; // Single declaration
typedef unsigned int unInt, alsoUnInt; // Two aliases
typedef int *intPtrByDefault; // Makes the type a pointer by default


//Using
using veryLongInt2 = long long int;

int main(int argc, char** argv){
    
    double pi = PI;

    int var = 5;

    INCREMENT(var);
    MULTIPLY(2, 3);

    veryLongInt1 var1;
    veryLongInt2 var2;

    unInt var3;
    alsoUnInt var4;

    int a = 5;
    intPtrByDefault var5 = &a;

    return 0;
}