#include <iostream>
#include <vector>
#include <string>

// Calculate the sum of numbers in a vector
int calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

// Calculate the average of numbers
double calculateAverage(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }
    int sum = calculateSum(numbers);
    return static_cast<double>(sum) / numbers.size();
}

// Find the maximum value in a vector
int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    int max = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// Print statistics about the numbers
void printStatistics(const std::vector<int>& numbers) {
    std::cout << "Number of elements: " << numbers.size() << std::endl;
    std::cout << "Sum: " << calculateSum(numbers) << std::endl;
    std::cout << "Average: " << calculateAverage(numbers) << std::endl;
    std::cout << "Maximum: " << findMax(numbers) << std::endl;
}

int main() {
    std::cout << "Welcome to GDB Basic Demo!" << std::endl;
    
    // Create a vector of numbers
    std::vector<int> numbers = {10, 25, 7, 42, 15, 33, 8};
    
    std::cout << "\nAnalyzing numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Calculate and print statistics
    printStatistics(numbers);
    
    std::cout << "\nDemo completed successfully!" << std::endl;
    return 0;
}
