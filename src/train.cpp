// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{ light, nullptr, nullptr };
  if (first == nullptr) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}
int Train::getLength() {
	countOp = 0;
	int steps = 0;
	Car* curr = first;
	curr->light = true;
	while (++steps) {
		curr = curr->next;
		++countOp;
		if (curr->light) {
			curr->light = false;
			for (int i = 0; i < steps; ++i) {
				curr = curr->prev;
				++countOp;
			}
			if (!curr->light) return steps;
			steps = 0;
		}
	}
	return 0;
}

int Train::getOpCount() {
  return countOp;
}
