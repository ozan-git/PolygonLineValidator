# Polygon Line Validator

Polygon Line Validator is a C++ project that checks if a line segment can pass through a set of polygons without intersecting any of their edges. The project also includes test cases and a Python script for visualizing the results.

## Table of Contents

- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Testing](#testing)
- [Visualization](#visualization)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

These instructions will help you set up the project on your local machine for development and testing purposes.

### Prerequisites

- A C++ compiler with support for C++11 or later
- CMake (version 3.10 or later)
- Python 3.x (for visualization)

### Installation

1. Clone the repository:

```bash
git clone https://github.com/ozan-git/PolygonLineValidator.git
```

2. Create a build directory and navigate to it:

```bash
cd PolygonLineValidator
mkdir build
cd build
```

3. Run CMake:

```bash
cmake ..
```

4. Build the project:

```bash
cmake --build .
```

## Usage
After building the project, you can run the executable file with the following command:

```bash
./PolygonLineValidator
```

## File Structure

The project is organized into the following structure:
    
    ```
    .
    PolygonLineValidator/
    ├── CMakeLists.txt
    ├── README.md
    │
    ├── src/
    │   ├── main.cpp
    │   │
    │   ├── geometry/
    │   │   ├── LineSegment.cpp
    │   │   ├── LineSegment.h
    │   │   ├── Point.cpp
    │   │   ├── Point.h
    │   │   ├── Polygon.cpp
    │   │   └── Polygon.h
    │   │
    │   └── io/
    │       ├── Operations.cpp
    │       └── Operations.h
    │
    └── test/
    ├── input/
    │   ├── q1_example_input[516].txt
    │   └── q1_input[514].txt
    │
    ├── results/
    │   ├── q1_example_output[512].txt
    │   └── q1_first_output.txt
    │
    └── presentation/
    └── plot_results.py
  
    ```

## Testing

The project includes two test cases, which can be found in the `test/input` directory. The test cases are as follows:

- `q1_example_input[516].txt`: This test case is the example input given in the project description.
- `q1_input[514].txt`: This test case is a more complex input that includes polygons with more than 3 vertices.

The results of the test cases can be found in the `test/results` directory. The results are as follows:

- `q1_example_output[512].txt`: This result is the output of the example input given in the project description.
- `q1_first_output.txt`: This result is the output of the more complex input.

## Visualization

The project includes a Python script for visualizing the results. The script can be found in the `presentation` directory. The script uses the `matplotlib` library for plotting the polygons and the line segment. The script also uses the `shapely` library for checking if the line segment intersects with any of the polygons. The script can be run with the following command:

```bash
python3 plot_results.py
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.




 