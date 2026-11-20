#include <iostream>

int main() {
    double voltage = 0.0;
    double resistance =0.0;

    std::cout <<"Enter voltage (V): ";
    std::cin >> voltage;

    std::cout <<"Enter resistance (Ohms): ";
    std::cin >> resistance;

    if (resistance <= 0.0) {
        std::cout <<"Resistance must be greater than 0 ohm.\n";
    } else {

    double current = voltage / resistance;
    std::cout <<"Current (A): " << current << "A\n";

    if (current > 0.02) {
        std::cout <<"Warning: current is above 20mA !\n";
    }
    }

    return 0;
}

