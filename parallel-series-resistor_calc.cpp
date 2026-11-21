#include <iostream>
#include <vector>

int main() {
    std::vector<double> resistors;   // an empty list of doubles

    resistors.push_back(100.0);      // like .append() in Python
    resistors.push_back(200.0);
    resistors.push_back(300.0);

    std::cout << "I have " << resistors.size() << " resistors:\n";

    for (double r : resistors) {     // like: for r in resistors:
        std::cout << r << " ohms\n";
    }

    return 0;
}
