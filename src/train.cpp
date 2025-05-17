// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  if (first == nullptr) {
    first = new Car{ light, nullptr, nullptr };
    first->next = first;
    first->prev = first;
  }
  else {
    Car* last = first->prev;
    Car* newCar = new Car{ light, nullptr, nullptr };
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr)
    return 0;
  Car* curr = first;
  int steps = 0;
  curr->light = true;
  do {
    curr = curr->next;
    steps++;
    countOp++;
  } while (!curr->light && curr != first);
  if (curr->light) {
    curr->light = false;
    for (int i = 0; i < steps; i++) {
      curr = curr->prev;
      countOp++;
    }
    if (curr->light) {
      return steps;
    }
    else {
      return getLength();
    }
  }
  return steps;
}

int Train::getOpCount() {
  return countOp;
}
