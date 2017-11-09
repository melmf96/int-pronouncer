#include "translator.h"

// Constructor
Translator::Translator(int toPronounce){
    this -> numToPronounce = toPronounce;
    commaPlace = 0;

    onesPlace = new std::string[9]{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    tenValues = new std::string[10]{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    tensPlace = new std::string[10]{"ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    commaGroup = new std::string[5]{"", "thousand", "million", "billion", "trillion"};
}

// Wrapper for generatePronunciation
int Translator::generatePronunciation(std::vector<std::string> & pronunciation){
   return generatePronunciation(numToPronounce, 0, pronunciation, commaPlace);
}

/* generatePronunciation
 * Input:
 *  - number to pronounce
 *  - current power(n) to find current ten's place
 *  - vector to store translation
 *  - flag to determine whether any non-zero digit was found in a comma group
 * Output:
 *  - 1 if translation made, 0 if entered number was 0 (or made it to end of
 *  recursion)
 */
int Translator::generatePronunciation(int & numToPronounce, int power, std::vector<std::string> & pronunciation, int & commaPlace){
    if(numToPronounce < pow(10, power)){
        return 0;
    }
    generatePronunciation(numToPronounce, power + 1, pronunciation, commaPlace);
        //return 1;
    // looking at last one's place 
    if(!power){
        int value = (int) (numToPronounce/pow(10, power));
        if(value != 0){
            pronunciation.push_back(onesPlace[value - 1]);
        }
    }
    // comma group
    if(power % 3 == 0){
        if((int) power/3 != 0){
            int value = (int) (numToPronounce/pow(10, power));
            if(value != 0){
                commaPlace = 1;
                pronunciation.push_back(onesPlace[value - 1]);
            }
            if(commaPlace){
                pronunciation.push_back(commaGroup[(int) (power/3)]);
                commaPlace = 0;
            }
        }
    }
    // tens place
    if(power % 3 == 1){
        int value = (int) (numToPronounce/pow(10, power));
        if(value != 0){
            commaPlace = 1;
            if(value == 1){ // need to pull from special tenValues array
                // here, we need to know the next digit to determine which to
                // pull from tenValues
                int nextValue = (int) ((numToPronounce - (pow(10, power) * value)) / pow(10, power - 1));
                pronunciation.push_back(tenValues[nextValue]);
                numToPronounce -= (int) nextValue * pow(10, power - 1);
            } else {
                pronunciation.push_back(tensPlace[value - 1]);
            }
        }
    }
    // hundreds place
    if(power % 3 == 2){
        int value = (int) (numToPronounce/pow(10, power));
        if(value != 0){
            commaPlace = 1;
            pronunciation.push_back(onesPlace[value - 1]);
            pronunciation.push_back("hundred");
        }
    }
    int value = (int) (numToPronounce / pow(10, power)) * pow(10, power);
    numToPronounce -= value;    // subtract 10^n
    return 1;
}

// Destructor
Translator::~Translator(){
    delete [] onesPlace;
    delete [] tenValues;
    delete [] tensPlace;
    delete [] commaGroup;
}
