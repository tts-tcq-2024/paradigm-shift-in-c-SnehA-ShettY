#include <stdio.h>
#include <stdbool.h> // Use <stdbool.h> for clearer boolean handling

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool isOk = true;

    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        isOk = false;
    }
    if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        isOk = false;
    }
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        isOk = false;
    }

    return isOk; 
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0; // Added return 0 for completeness
}

