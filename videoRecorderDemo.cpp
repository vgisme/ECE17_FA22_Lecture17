#include <iostream>
#include "VideoRecorder.hpp"


int main() {
    VideoRecorder vr;

    vr.printState();

    vr.play();
    vr.printState();

    vr.pause();
    vr.stop();

    vr.printState();

    return 0;
}
