#include <stdio.h>
#include <stdbool.h> // Use <stdbool.h> for clearer boolean handling

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool isTemperatureOk = temperature >= 0 && temperature <= 45;
    bool isSocOk = soc >= 20 && soc <= 80;
    bool isChargeRateOk = chargeRate <= 0.8;

    if (!isTemperatureOk || !isSocOk || !isChargeRateOk) {
        if (!isTemperatureOk) {
            printf("Temperature out of range!\n");
        } 
        if (!isSocOk) {
            printf("State of Charge out of range!\n");
        } 
        if (!isChargeRateOk) {
            printf("Charge Rate out of range!\n");
        }
        return 0;
    }

    return 1; 
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0; // Add return 0 for completeness
}

