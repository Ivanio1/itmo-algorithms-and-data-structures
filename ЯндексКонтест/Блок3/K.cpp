//
// Created by Asus on 23.03.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/* Сложность алгоритма O(n*log(n))
 */

struct memorySegment {
  bool freeStatus;
  int startIndex, endIndex;
  int length;
  struct memorySegment *left;
  struct memorySegment *right;

  memorySegment(int start, int end) {
    startIndex = start;
    endIndex = end;
    length = endIndex - startIndex + 1;
    freeStatus = true;
    left = nullptr;
    right = nullptr;
  }
};

auto compare = [](const struct memorySegment *a,
                  const struct memorySegment *b) {
  return a->length > b->length;
};

// Sorted by length
multiset<struct memorySegment *, decltype(compare)> freeSegments(compare);

// Allocate memory if it is possible
struct memorySegment *allocate(int operation, int i) {
  struct memorySegment *freeSegment = *freeSegments.begin();
  // Find first free region
  while (freeSegment) {
    if (freeSegment->freeStatus)
      break;
    freeSegments.erase(freeSegments.begin());
    freeSegment = *freeSegments.begin();
  }
  if (!freeSegment || !freeSegment->freeStatus ||
      freeSegment->length < operation) {
    cout << "-1\n";
    return nullptr;
  } else {
    freeSegments.erase(freeSegments.begin());
    cout << freeSegment->startIndex + 1 << endl;
    int new_addr = freeSegment->startIndex + operation - 1;
    if (operation != freeSegment->length) {
      auto *newSegment = new memorySegment(new_addr + 1, freeSegment->endIndex);
      newSegment->right = freeSegment->right;
      newSegment->left = freeSegment;
      freeSegments.insert(newSegment);
      freeSegment->right = newSegment;
    }
    freeSegment->freeStatus = false;
    freeSegment->endIndex = new_addr;
    freeSegment->length = freeSegment->endIndex - freeSegment->startIndex + 1;
    return freeSegment;
  }
}

// add next free block to current
struct memorySegment *addNext(struct memorySegment *currentSegment,
                              struct memorySegment *nextSegment) {
  nextSegment->freeStatus = false;
  currentSegment->right = nextSegment->right;
  if (nextSegment->right) {
    nextSegment->right->left = currentSegment;
  }
  currentSegment->endIndex = nextSegment->endIndex;
  currentSegment->length =
      currentSegment->endIndex - currentSegment->startIndex + 1;
  return currentSegment;
}

// add previous free block to current
struct memorySegment *addPrevious(struct memorySegment *previousSegment,
                                  struct memorySegment *currentSegment) {
  previousSegment->freeStatus = false;
  currentSegment->left = previousSegment->left;
  if (previousSegment->left) {
    previousSegment->left->right = currentSegment;
  }
  currentSegment->startIndex = previousSegment->startIndex;
  currentSegment->length =
      currentSegment->endIndex - currentSegment->startIndex + 1;
  return currentSegment;
}

void freeMemory(struct memorySegment *oldSegment) {
  if (oldSegment) {
    oldSegment->freeStatus = true;
    // Check next
    if (oldSegment->right && oldSegment->right->freeStatus) {
      struct memorySegment *nextSegment = oldSegment->right;
      oldSegment = addNext(oldSegment, nextSegment);
    }
    // Check previous
    if (oldSegment->left && oldSegment->left->freeStatus) {
      struct memorySegment *previousSegment = oldSegment->left;
      oldSegment = addPrevious(previousSegment, oldSegment);
    }
    freeSegments.insert(oldSegment);
  }
}

int main() {
  int memorySize;
  cin >> memorySize;

  int numberOfRequests;
  cin >> numberOfRequests;
  struct memorySegment *allocatedSegments[numberOfRequests];

  auto *firstSegment = new memorySegment(0, memorySize - 1);
  freeSegments.insert(firstSegment);

  for (int i = 0; i < numberOfRequests; i++) {
    int operation;
    cin >> operation;
    if (operation > 0) {
      allocatedSegments[i] = allocate(operation, i);
    } else {
      struct memorySegment *oldSegment = allocatedSegments[abs(operation) - 1];
      freeMemory(oldSegment);
    }
  }
  return 0;
}
