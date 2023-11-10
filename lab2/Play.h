#pragma once
#include "Rating.h"

class Play {
public:
    Play(std::string name, std::string description);
    std::string ToString() const;
    void AddRating(float rating);
    float GetRating() const;
private:
    Rating rating;
    std::string name;
    std::string description;
};