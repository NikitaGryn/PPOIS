#include "Rating.h"

Rating::Rating() : total(0), count(0) {}

float Rating::GetRating() const {
	return total / count;
}

void Rating::AddRating(float rating) {
	count++;
	total += rating;
}