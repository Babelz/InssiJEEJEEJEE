#include "Random.h"

Random::Random() {
}

int Random::next(int min, int max) {
	return min + (rand() % (int)(max - min + 1));
}

Random::~Random() {
}

