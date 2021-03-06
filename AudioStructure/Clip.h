#pragma once
#ifndef _CLIP_H_
#define _CLIP_H_

#include <fstream>
#include <vector>

class Clip {
public:
    Clip(std::string clip_name, float start_time) {
        this->clip_name = clip_name;
        this->start_time = start_time;
    }

    void addSample(double sample) {
        audio_stream.push_back(sample);
    }

    void setName(std::string clip_name) { this->clip_name = clip_name; }
    void setStartTime(double start_time) {
        if (start_time > 0)
            this->start_time = start_time;
    }
    void setEndTime(double end_time) {
        if (end_time > start_time)
            this->end_time = end_time;
    }
    std::string getName() { return clip_name; }
    int getNumSamples() { return audio_stream.size(); }
    double getSample(int index) { return audio_stream[index]; }

private:
    float start_time, end_time, length;
    std::string clip_name;
    std::vector<double> audio_stream;
};

#endif