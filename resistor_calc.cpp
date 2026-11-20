#include <iostream>

int main() {
    double supplyVoltage;
    double ledVoltage;
    double desiredCurrentMa;

    std::cout << "Supply voltage (e.g., 5 for Arduino): ";
    std::cin >> supplyVoltage;

    std::cout << "LED forward voltage (e.g., 2.0 for red, 3.2 for blue): ";
    std::cin >> ledVoltage;
    std::cout << "Desired current in mA (usually 15 to 20): ";
    std::cin >> desiredCurrentMa;

    if (ledVoltage >= supplyVoltage) {
        std::cout << "Warning: Supply voltage must be higher than the LED forward voltage!\n";
    } else if (desiredCurrentMa <= 0) {
        std::cout << "Warning: Current must be greater than 0 mA.\n";
    } else {
        double currentAmps = desiredCurrentMa / 1000.0;
        double resistance = (supplyVoltage - ledVoltage) / currentAmps;
        std::cout << "You need at least a " << resistance << " Ohm resistor!\n";
    }

    return 0;
}



 