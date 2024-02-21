#include "shared_array.h"

int main() {
    shared_array array("arr", 10);

    while (true) {
        for (int i = 0; i < 10; ++i) {
            std::cout << array[i] << std::endl;
        }
        sleep(2);
    }

    return 0;
}
