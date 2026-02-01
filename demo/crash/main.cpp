#include "libcrash.h"
#include <iostream>
#include <cstdlib>

void displayMenu() {
    std::cout << "\n=== Core Dump Demo Program ===" << std::endl;
    std::cout << "Select a crash scenario:" << std::endl;
    std::cout << "1. NULL pointer dereference" << std::endl;
    std::cout << "2. Array out of bounds" << std::endl;
    std::cout << "3. Buffer overflow / Stack corruption" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

int main(int argc, char* argv[]) {
    std::cout << "Core Dump Teaching Demo" << std::endl;
    std::cout << "This program demonstrates different crash scenarios." << std::endl;
    
    // If a scenario is provided as command line argument, run it directly
    if (argc > 1) {
        int choice = std::atoi(argv[1]);
        std::cout << "\nRunning scenario " << choice << "..." << std::endl;
        
        switch (choice) {
            case 1:
                std::cout << "Triggering NULL pointer dereference..." << std::endl;
                crash::processUserData(nullptr);
                break;
            case 2:
                std::cout << "Triggering array out of bounds..." << std::endl;
                crash::calculateScore(150);  // High userId triggers crash
                break;
            case 3:
                std::cout << "Triggering buffer overflow..." << std::endl;
                crash::validateConfig();
                break;
            default:
                std::cerr << "Invalid scenario number: " << choice << std::endl;
                std::cerr << "Valid options: 1, 2, or 3" << std::endl;
                return 1;
        }
        
        std::cout << "If you see this, the crash didn't happen!" << std::endl;
        return 0;
    }
    
    // Interactive mode
    while (true) {
        displayMenu();
        
        int choice;
        std::cin >> choice;
        
        if (choice == 0) {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        
        switch (choice) {
            case 1:
                std::cout << "\nTriggering NULL pointer dereference..." << std::endl;
                crash::processUserData(nullptr);
                break;
            case 2:
                std::cout << "\nTriggering array out of bounds..." << std::endl;
                crash::calculateScore(150);  // High userId triggers crash
                break;
            case 3:
                std::cout << "\nTriggering buffer overflow..." << std::endl;
                crash::validateConfig();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }
        
        std::cout << "If you see this, the crash didn't happen!" << std::endl;
    }
    
    return 0;
}
