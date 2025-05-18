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
  if (first == nullptr)
    return 0;
  first->light = true;
  countOp++;
  Car* curr = first->next;
  int steps = 1;
  while ( curr != first && !curr->light) {
    curr = curr->next;
    steps++;
    countOp++;
    countOp++;
  }
  return steps;
}

int Train::getOpCount() {
  return countOp;
}
