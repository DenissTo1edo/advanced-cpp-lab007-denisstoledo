#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

namespace {
int factorialRecursive(int n) {
    if (n < 0) {
        throw std::logic_error("factorial: negative input");
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int fibonacciRecursive(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacci: negative input");
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int binarySearchRecursive(const std::vector<int>& array, int target, int left, int right) {
    if (left > right) {
        return -1;
    }

    const int mid = left + ((right - left) / 2);
    if (array[mid] == target) {
        return mid;
    }
    if (target < array[mid]) {
        return binarySearchRecursive(array, target, left, mid - 1);
    }
    return binarySearchRecursive(array, target, mid + 1, right);
}

int arraySumRecursive(const std::vector<int>& array, std::size_t index) {
    if (index >= array.size()) {
        return 0;
    }
    return array[index] + arraySumRecursive(array, index + 1);
}

void reverseArrayRecursive(std::vector<int>& array, std::size_t left, std::size_t right) {
    if (left >= right) {
        return;
    }

    std::swap(array[left], array[right]);
    reverseArrayRecursive(array, left + 1, right - 1);
}
}  // namespace

int factorial(int n) {
    return factorialRecursive(n);
}

int factorialIterative(int n) {
    if (n < 0) {
        throw std::logic_error("factorialIterative: negative input");
    }

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int fibonacci(int n) {
    return fibonacciRecursive(n);
}

int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacciIterative: negative input");
    }

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        const int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int binarySearch(const std::vector<int>& array, int target) {
    if (array.empty()) {
        return -1;
    }
    return binarySearchRecursive(array, target, 0, static_cast<int>(array.size()) - 1);
}

int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left <= right) {
        const int mid = left + ((right - left) / 2);
        if (array[mid] == target) {
            return mid;
        }
        if (target < array[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int arraySum(const std::vector<int>& array) {
    return arraySumRecursive(array, 0);
}

int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int value : array) {
        sum += value;
    }
    return sum;
}

void reverseArray(std::vector<int>& array) {
    if (array.size() <= 1) {
        return;
    }
    reverseArrayRecursive(array, 0, array.size() - 1);
}

void reverseArrayIterative(std::vector<int>& array) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
