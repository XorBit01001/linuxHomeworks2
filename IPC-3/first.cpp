#include "shared_array.h"

int main() {
    shared_array array("arr", 10);

    while (true) {
        for (int i = 0; i < 10; ++i) {
            array[i] = i;
        }
        sleep(1);
    }

    return 0;
}
