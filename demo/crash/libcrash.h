#ifndef LIBCRASH_H
#define LIBCRASH_H

namespace crash {

// Different crash scenarios for teaching purposes

// Scenario 1: NULL pointer dereference
void processUserData(const char* username);

// Scenario 2: Array out of bounds access
void calculateScore(int userId);

// Scenario 3: Stack corruption / bad memory access
void validateConfig();

} // namespace crash

#endif // LIBCRASH_H
