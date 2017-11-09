#include "translator.h"

/*
 * This program takes in a positive integer (maximum input is: 2147483647), as a command-line argument, and outputs
 * the pronunciation of the integer in English. A primary goal of this program
 * was to utilize a recursive implementation with only a single traversal.
*/

// MAIN
int main(int argc, char ** argv) {
    if(argc == 1){
        std::cout << "No number was entered.\n";
        return 0;
    }
    int numToPronounce = atoi(argv[1]);
    if(numToPronounce < 0){
        std::cout << "That number is either too large to be an int, or is negative. Please enter a valid integer.\n";
        return 0;
    }
    int commaPlace = 0;
    Translator recognizor(numToPronounce);
    std::cout << numToPronounce << std::endl;

    //string * pronunciation;
    std::vector <std::string> pronunciation;
    //pronunciation = new string[countPower(numToPronounce, 1, pronunciation)];
    if(!recognizor.generatePronunciation(pronunciation)){
        std::cout << "zero" << std::endl;
    }

    for(std::vector<std::string>::iterator it = pronunciation.begin(); it != pronunciation.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

