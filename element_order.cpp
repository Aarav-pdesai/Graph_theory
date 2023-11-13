#include <iostream>

// Function to find the order of an element in a group
int findOrder(int element, int groupSize) {
    int order = 1;
    int result = element;

    while (result != 1) {
        result = (result * element) % groupSize;
        order++;
    }

    return order;
}

int main() {
    // Example: Z_7 (integers modulo 7) under multiplication
    int element = 3;  // Element for which we want to find the order
    int groupSize = 7;  // Size of the group

    int order = findOrder(element, groupSize);

    std::cout << "The order of element " << element << " in the group Z_" << groupSize << " is: " << order << std::endl;

    return 0;
}
