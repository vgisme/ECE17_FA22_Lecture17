//
// Created by Vikash Gilja on 11/17/22.
//

#ifndef ECE17_FA22_LECTURE17_VIDEORECORDER2_HPP
#define ECE17_FA22_LECTURE17_VIDEORECORDER2_HPP

#include <iostream>
#include <map>

class VideoRecorder {
    enum class State { Stopped, Recording, Playing, Paused};
    enum class Action { Stop, Record, Play, Pause};
    std::map<State, std::string> stateStrings= {
            {State::Stopped, "Stopped"},
            {State::Recording, "Recording"},
            {State::Playing, "Playing"},
            {State::Paused, "Paused"}};

    std::map<std::pair<State, Action>, State> transitionTable = {
            {std::make_pair(State::Stopped, Action::Record), State::Recording},
            {std::make_pair(State::Stopped, Action::Play), State::Playing},
            {std::make_pair(State::Recording, Action::Stop), State::Stopped},
            {std::make_pair(State::Playing, Action::Stop), State::Stopped}};

public:
    VideoRecorder() { state = State::Stopped;}
    void stop() {
        if (tryAction(Action::Stop)) std::cout << "I stopped\n";
        else std::cout << "Stop action does nothing\n";
    }

    void record() {
        if (tryAction(Action::Record)) std::cout << "I'm recording now\n";
        else std::cout << "Record action does nothing\n";
    }

    void play() {
        if (tryAction(Action::Play)) std::cout << "I'm playing now\n";
        else std::cout << "Play action does nothing\n";
    }

    void pause() {
        if (tryAction(Action::Pause)) std::cout << "I'm paused now\n";
        else std::cout << "Pause action does nothing\n";
    }


    void printState() {
        std::cout << "Current State: " << stateStrings[state] << std::endl;
    }

private:
    State state;

    bool tryAction(Action action) {
        if( 0 == transitionTable.count(std::make_pair(state, action)) ) return false;
        state = transitionTable[std::make_pair(state, action)];
        return true;
    }
};

#endif //ECE17_FA22_LECTURE17_VIDEORECORDER2_HPP
