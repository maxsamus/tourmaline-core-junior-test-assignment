# tourmaline-core-junior-test-assignment

Change Calculation (1st Iteration)

by Maxim Samusenko

## How to Build and Run the Project

### Prerequisites

1. **CMake**
2. **Compiler**: A C++ compiler that supports C++17

### Steps to Build and Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/maxsamus/tourmaline-core-junior-test-assignment.git
   cd tourmaline-core-junior-test-assignment
   ```
2. Create a Build Directory:
   ```bash
   mkdir build
   cd build
   ```
3. Generate Build Files: Use CMake to generate the build files:
   ```bash
   cmake ..
   ```
4. Build the Project: Compile the project using the generated build files:
   ```bash
   cmake --build .
   ```
5. Run the Tests: After the build is complete, run the tests:
   ```bash
   ./test_change_calculator
   ```

## Project Structure

```
tourmaline-core-junior-test-assignment/
├── src/
│   ├── change_calculator.cpp      # Implementation of the change calculation logic
│   ├── change_calculator.h        # Header file for the change calculation function
├── tests/
│   ├── test_change_calculator.cpp # Unit tests for the change calculation function
├── task/
|   ├── Tourmaline_Core_Junior_Test_Assignment_–_Change_Calculation_1st.pdf # PDF with task
├── CMakeLists.txt                 # CMake configuration file
├── README.md                      # Instructions for building and running the project
```
