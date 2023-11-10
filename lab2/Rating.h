#pragma once
class Rating {
public:
	Rating();
	void AddRating(float rating);
	float GetRating() const;
private:
	float total;
	int count;
};