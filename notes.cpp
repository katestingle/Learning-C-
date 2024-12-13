
// preprocessor: scans the file from top to bottom, looking for liens that begins with a hash #
// each hash # is a preprocessor directive: directs the preprocessor to modify the file in some way before compilation continues

// for example, #include <iostream> directs the preprocessor to get iostream directory functions and objects
#include <iostream>

/* #include <stdfile> -- A filename in angle brackets causes the preprocessor to look in the system's standard library folder/directory. 
   Programmers typically use angle brackets only for standard library files, using quotes for all other include files. */
// Header files that are part of the standard C++ library do not have a .h extension.
#include <iomanip>
//Items that were originally part of the C standard library have a "c" prepended, as in cmath.
#include <cmath>

// A filename in quotes: directs preprocessor to look for the file in the same folder/directory as the including file.
#include "notes.h"
/*	
Good practice is to use a.h suffix for any file that will be included in another file.
The h is short for header, to indicate that the file is intended to be included at
the top (or header) of other files. Although any file can be included in any other file,
convention is to only include .h files. 
*/
using namespace std;

int myGlobalInt = 0;
int main() {
	doSmnToInt(myGlobalInt);
	return 0;
}