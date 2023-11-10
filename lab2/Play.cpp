#include <string>
#include "Play.h"

Play::Play(std::string name, std::string description) : name(name), description(description) {}

std::string Play::ToString() const {
	return name + " (" + description + ")";
}

void Play::AddRating(float rating) {
	this->rating.AddRating(rating);
}

float Play::GetRating() const {
	return rating.GetRating();
}