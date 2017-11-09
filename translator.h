#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>


class Translator {
    public:
        Translator(int numToPronounce);
        ~Translator();
        int generatePronunciation(std::vector<std::string> & pronunciation);
        int generatePronunciation(int & numToPronounce, int power, std::vector<std::string> & pronunciation, int & commaPlace);
    private:
        std::string * onesPlace;
        std::string * tenValues;
        std::string * tensPlace;
        std::string * commaGroup; 

        int numToPronounce;
        int commaPlace;
};
