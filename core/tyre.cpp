#include "tyre.h"

using namespace std;

void TyreData::initializeData(){
    srand(time(NULL));
    for(int i = 0; i < numTyres; i++){
        float gen = generateRandomData(40, 150);
        tyresTemperature.push_back(gen);
        tyresState.push_back(generateRandomData(0,1));
    }
    tyreAge = generateRandomData(0, 40);
}