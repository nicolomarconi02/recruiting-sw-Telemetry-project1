#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class TyreData : public Data{
    public:
        int numTyres = 4;
        float tyreAge;
        vector<float> tyresTemperature;
        vector<float> tyresState;

        TyreData(){
            initializeData();
        }

        void initializeData();
};