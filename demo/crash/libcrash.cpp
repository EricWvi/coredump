#include "libcrash.h"
#include <iostream>
#include <cstring>

namespace crash {

// Helper function for scenario 1 - gets user info from database
static const char* getUserInfo(int userId) {
    // Simulate database lookup that might return NULL
    if (userId == 999) {
        return nullptr;  // Simulate user not found
    }
    return "John Doe";
}

// Helper function for scenario 1 - formats the username
static void formatUsername(const char* name) {
    // This will crash if name is NULL
    char buffer[100];
    strcpy(buffer, name);  // CRASH: null pointer dereference when name is NULL
    std::cout << "Formatted name: " << buffer << std::endl;
}

// Scenario 1: NULL pointer dereference through function call chain
void processUserData(const char* username) {
    std::cout << "Processing user data..." << std::endl;
    
    // If username is NULL, this chain will crash in formatUsername
    formatUsername(username);
    
    std::cout << "User data processed successfully" << std::endl;
}

// Helper function for scenario 2 - calculates bonus
static int calculateBonus(int scores[], int index) {
    // This will crash when index is out of bounds
    return scores[index] * 2;  // CRASH: array out of bounds
}

// Helper function for scenario 2 - processes scores
static void processScores(int userId) {
    int scores[5] = {10, 20, 30, 40, 50};
    
    // Intentionally use a bad index when userId is high
    int index = userId > 100 ? 10 : userId % 5;  // index 10 is out of bounds
    
    int bonus = calculateBonus(scores, index);
    std::cout << "Bonus calculated: " << bonus << std::endl;
}

// Scenario 2: Array out of bounds access
void calculateScore(int userId) {
    std::cout << "Calculating score for user " << userId << std::endl;
    processScores(userId);
    std::cout << "Score calculation complete" << std::endl;
}

// Helper function for scenario 3 - validates a single setting
static bool validateSetting(const char* setting) {
    // Create a pointer to a local variable (will be invalid after return)
    int localValue = 42;
    int* ptr = &localValue;
    
    // Simulate some work
    if (setting == nullptr) {
        return false;
    }
    
    return true;
}

// Helper function for scenario 3 - applies config
static void applyConfiguration(int* configPtr) {
    // Dereference a potentially bad pointer
    *configPtr = 123;  // CRASH: accessing invalid memory
    std::cout << "Configuration applied: " << *configPtr << std::endl;
}

// Scenario 3: Stack corruption / bad memory access
void validateConfig() {
    std::cout << "Validating configuration..." << std::endl;
    
    // Get a pointer to stack memory that will become invalid
    int localConfig = 0;
    int* badPtr = &localConfig;
    
    validateSetting("test");
    
    // Simulate some operations that corrupt the stack
    char buffer[10];
    const char* longString = "This is a very long string that will overflow the buffer";
    strcpy(buffer, longString);  // CRASH: buffer overflow / stack corruption
    
    applyConfiguration(badPtr);
    
    std::cout << "Configuration validated" << std::endl;
}

} // namespace crash
