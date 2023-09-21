#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// class VoltageData{
//     public:
//         vector<VoltageData> tableHVVoltage;
//         vector<VoltageData> tableLVVoltage;
//         VoltageData(){
//             generateData();
//         } 
        
//         VoltageData(float h, float l){
//             bmsHVVoltage = h;
//             bmsLVVoltage = l;
//         }
//         void generateData();
//         float getCellVoltage();
//     private:
//         float bmsHVVoltage;
//         float bmsLVVoltage;
// };

class VoltageData{
    public:
        int numCellHV = 108;
        int numCellLV = 4;
        vector<float> bmsHVVoltage;
        vector<float> bmsLVVoltage;

        VoltageData(){
            generateData();
        }

        void generateData();
};