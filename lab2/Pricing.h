#pragma once

class Pricing {
public:
	Pricing(int defaultCost);
	int GetChildPricing() const;
	int GetDefaultPricing() const;
private:
	int cost;
};