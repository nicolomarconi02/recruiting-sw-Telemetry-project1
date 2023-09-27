#include <iostream>
#include <vector>
#include <string>
#include "data.h"

using namespace std;

class TyreData : public Data{
    public:
        vector<float> tyresTemperature; // Vector to store tyre temperatures
        vector<float> tyresState;       // Vector to store tyre states

        TyreData(){
            initializeData(); // Initialize tyre data
            setError();      // Check and set error conditions for the tyres
        }

        void initializeData(); // Function to initialize tyre data
        void setError();      // Function to check and set error conditions for the tyres
        string getTyre(int);  // Function to get a string representation of a tyre based on its index

        void setNumTyres(int);   // Setter function to set the number of tyres
        void setTyreAge(float);  // Setter function to set the age of the tyres
        
        int getNumTyres();   // Getter function to retrieve the number of tyres
        float getTyreAge(); // Getter function to retrieve the age of the tyres

    private:
        int numTyres = 4;   // Default number of tyres is set to 4
        float tyreAge;     // Variable to store the age of the tyres
};