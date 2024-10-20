// #include <iostream>

// int main() {
//     int rows = 5;

//     for (int i = rows; i >= 1; --i) {
//         for (int j = 1; j <= i; ++j) {
//             std::cout << "* ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }
#include <iostream>

int main() {
    int rows = 5;

    for (int i = rows; i >= 1; --i) {
        // Add spaces before the stars
        for (int j = 1; j <= rows - i; ++j) {
            std::cout << "  ";
        }
        // Print stars
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}


