//
// Created by Vikash Gilja on 11/17/22.
//

#ifndef ECE17_FA22_LECTURE17_VIDEORECORDER_HPP
#define ECE17_FA22_LECTURE17_VIDEORECORDER_HPP

#include <iostream>
#include <map>

class VideoRecorder {
    enum class State { Stopped, Recording, Playing, Paused};
    std::map<State, std::string> stateStrings= {
            {State::Stopped, "Stopped"},
            {State::Recording, "Recording"},
            {State::Playing, "Playing"},
            {State::Paused, "Paused"}};

public:
    VideoRecorder() { state = State::Stopped;}
    void stop() {
        switch (state) {
            case State::Recording:
            case State::Playing:
            case State::Paused:
                state = State::Stopped;
                std::cout << "I stopped\n";
                break;
            case State::Stopped:
                std::cout << "Stop action does nothing\n";
        }
    }

    void record() {
        if (State::Stopped == state) {
            state = State::Recording;
            std::cout << "I'm recording now\n";
        }
        else {
            std::cout << "Record action does nothing \n";
        }
    }

    void play() {
        if (State::Stopped == state || State::Paused == state) {
            state = State::Playing;
            std::cout << "I'm playing now\n";
        }
        else {
            std::cout << "Play action does nothing \n";
        }
    }

    void pause() {
        if (State::Playing == state) {
            state = State::Paused;
            std::cout << "I'm paused now\n";
        }
        else {
            std::cout << "Pause action does nothing \n";
        }
    }

    void printState() {
        std::cout << "Current State: " << stateStrings[state] << std::endl;
    }

private:
    State state;
};

#endif //ECE17_FA22_LECTURE17_VIDEORECORDER_HPP
