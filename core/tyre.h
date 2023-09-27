#include <iostream>
#include <vector>
#include <string>
#include "data.h"

using namespace std;

class TyreData : public Data{
    public:
        vector<float> tyresTemperature;
        vector<float> tyresState;

        TyreData(){
            initializeData();
            setError();
        }

        void initializeData();
        void setError();
        string getTyre(int);

        void setNumTyres(int);
        void setTyreAge(float);
        
        int getNumTyres();
        float getTyreAge();

    private:
        int numTyres = 4;
        float tyreAge;

};