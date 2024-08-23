#include <stdio.h>
#include <assert.h>

int range_check(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 1;
    }
    return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temp_range_check;
    int soc_range_check;
    int charge_rate_check;
    temp_range_check = range_check(temperature, 0, 45, "Temperature out of range!");
    soc_range_check = range_check(soc, 20, 80, "State of Charge out of range!");
    charge_rate_check = range_check(chargeRate, 0, 0.8, "Charge Rate out of range!");

    return !(temp_range_check || soc_range_check || charge_rate_check);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}



 
