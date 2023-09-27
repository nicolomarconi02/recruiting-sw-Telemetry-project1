#include "tyre.h"

using namespace std;

void TyreData::initializeData(){
    srand(time(NULL));
    for(int i = 0; i < numTyres; i++){
        float gen = generateRandomData(40, 150);
        tyresTemperature.push_back(gen);
        tyresState.push_back(generateRandomData(0,1));
    }
    setTyreAge(generateRandomData(0, 40));
}

void TyreData::setError(){
    string tyre;
    
    for(int i = 0; i < numTyres; i++){
        if(tyresTemperature[i] > 140){
            tyre = "CRITICAL HIGH TYRE TEMPERATURE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }
        else if(tyresTemperature[i] > 130 && tyresTemperature[i] <= 140){
            tyre = "WARNING HIGH TYRE TEMPERATURE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }
        else if(tyresTemperature[i] > 50 && tyresTemperature[i] <= 55){
            tyre = "WARNING LOW TYRE TEMPERATURE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }
        else if(tyresTemperature[i] <= 50){
            tyre = "CRITICAL LOW TYRE TEMPERATURE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }

        if(tyresState[i] <= 0.1f){
            tyre = "CRITICAL TYRE STATE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }
        else if(tyresState[i] > 0.1f && tyresState[i] <= 0.15f){
            tyre = "WARNING TYRE STATE " + getTyre(i);
            error.tyreErrorList.push_back(tyre);
        }
    }
}

string TyreData::getTyre(int n){
    string type;
    switch (n){
    case 0:
        type = "FRONT LEFT";
        break;
    case 1:
        type = "FRONT RIGHT";
        break;
    case 2:
        type = "REAR LEFT";
        break;
    case 3:
        type = "REAR RIGHT";
        break;
    default:
        break;
    }
    return type;
}

void TyreData::setNumTyres(int v){
    numTyres = v;
}
void TyreData::setTyreAge(float v){
    tyreAge = v;
}

int TyreData::getNumTyres(){
    return numTyres;
}
float TyreData::getTyreAge(){
    return tyreAge;
}