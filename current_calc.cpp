#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    double voltage = 0.0;
    double resistance = 0.0;

    std::cout << "Enter voltage (V): ";
    std::cin >> voltage;

    std::cout << "Enter resistance (\xCE\xA9): ";
    std::cin >> resistance;

    if (resistance <= 0.0) {
        std::cout << "Resistance must be greater than 0 \xCE\xA9.\n";
    }
    if (voltage < 0.0) {
        std::cout << "Voltage must be greater than or equal to 0 V.\n";
    }

    if (voltage >= 0.0 && resistance > 0.0) {
        double current = voltage / resistance;
        std::cout << "Current: " << current << " A\n";

        if (current > 0.02) {
            std::cout << "Warning: current is above 20 mA!\n";
        }
    }

    return 0;
}