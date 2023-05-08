// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), last(nullptr), countOp(0) {}

void Train::addCage(bool light) {
  if (first == nullptr) {
    first = new Cage;
    first->next = first;
    first->prev = first;
    first->light = light;
    last = first;
  } else {
    last->next = new Cage;
    last->next->prev = last;
    last = last->next;
    last->next = first;
    first->prev = last;
    last->light = light;
  }
  countOp = 0;
}

int Train::getLength() {
  Cage* item = first;
  int count = 0;
  int rezult = 0;
  if (item->light == false) {
    item->light = true;
  }
  while (true) {
    item = item->next;
    countOp += 1;
    count += 1;
    while (item->light == false) {
      item = item->next;
      countOp += 1;
      count += 1;
    }
    item->light = false;
    rezult = count;
    while (count != 0) {
      countOp += 1;
      count -= 1;
      item = item->prev;
    }
    if (item->light == false) {
    return rezult;
    }
  }
}

int Train::getOpCount() {
  if (countOp == 0) {
    getOpCount();
  }
  return countOp;
}
