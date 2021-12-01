#include "./mandaw/mandaw.h"

int main() {
    Mandaw mandaw;

    initMandaw(mandaw, "Mandaw!", 800, 600);

    loop(mandaw);
}