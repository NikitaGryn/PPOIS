#include "Pricing.h"

Pricing::Pricing(int defaultCost) : cost(defaultCost) { }


int Pricing::GetChildPricing() const {
	return cost / 2;
}

int Pricing::GetDefaultPricing() const {
	return cost;
}