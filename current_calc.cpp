#include <iostream>

int main() {
    double voltage = 0.0;
    double resistance =0.0;

    std::cout <<"Enter voltage (V): ";
    std::cin >> voltage;

    std::cout <<"Enter resistance (Ohms): ";
    std::cin >> resistance;

    double current = voltage / resistance;
    std::cout <<"Current (A): " << current << "A\n";

    return 0;
}
