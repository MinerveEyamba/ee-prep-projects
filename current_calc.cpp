#include <iostream>
#include <limits>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

constexpr double maxLedCurrent = 0.02;  // 20 mA

double calcCurrent(double volts, double ohms)    { return volts / ohms; }
double calcVoltage(double amps, double ohms)     { return amps * ohms; }
double calcResistance(double volts, double amps) { return volts / amps; }
double calcPower(double volts, double amps)      { return volts * amps; }

// Reads a number into `value`. Returns true on success.
bool readNumber(const std::string& prompt, double& value) {
    std::cout << prompt;
    if (std::cin >> value) return true;

    std::cin.clear();  // reset the error state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard bad input
    std::cout << "That's not a number.\n";
    return false;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    while (true) {
        std::cout << "\n--- Ohm's Law Calculator ---\n"
                  << "1) Current    (I = V / R)\n"
                  << "2) Voltage    (V = I * R)\n"
                  << "3) Resistance (R = V / I)\n"
                  << "4) Power      (P = V * I)\n"
                  << "5) Quit\n"
                  << "Choose: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) return 0;  // input stream closed
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number from 1 to 5.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                double v = 0.0, r = 0.0;
                if (!readNumber("Voltage (V): ", v) || !readNumber("Resistance (Ω): ", r)) break;
                if (v < 0.0 || r <= 0.0) {
                    std::cout << "Voltage must be >= 0 and resistance > 0.\n";
                    break;
                }
                double i = calcCurrent(v, r);
                std::cout << "Current: " << i * 1000.0 << " mA\n";
                if (i > maxLedCurrent) {
                    std::cout << "Warning: current is above 20 mA!\n";
                }
                break;
            }
            case 2: {
                double i = 0.0, r = 0.0;
                if (!readNumber("Current (A): ", i) || !readNumber("Resistance (Ω): ", r)) break;
                if (i < 0.0 || r < 0.0) {
                    std::cout << "Values must be >= 0.\n";
                    break;
                }
                std::cout << "Voltage: " << calcVoltage(i, r) << " V\n";
                break;
            }
            case 3: {
                double v = 0.0, i = 0.0;
                if (!readNumber("Voltage (V): ", v) || !readNumber("Current (A): ", i)) break;
                if (v < 0.0 || i <= 0.0) {
                    std::cout << "Voltage must be >= 0 and current > 0.\n";
                    break;
                }
                std::cout << "Resistance: " << calcResistance(v, i) << " Ω\n";
                break;
            }
            case 4: {
                double v = 0.0, i = 0.0;
                if (!readNumber("Voltage (V): ", v) || !readNumber("Current (A): ", i)) break;
                if (v < 0.0 || i < 0.0) {
                    std::cout << "Values must be >= 0.\n";
                    break;
                }
                std::cout << "Power: " << calcPower(v, i) << " W\n";
                break;
            }
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Please enter a number from 1 to 5.\n";
        }
    }
}
