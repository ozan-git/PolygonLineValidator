"""

@file plot_results.py
@brief This file contains code to visualize the results of a passability test using the visibility graph algorithm.
@date 2023-05-01
@author ozan-git

@detail This file contains code to read the input and result files of a passability test, and then visualize the
polygons, passages, and test points using Matplotlib. The result of each test point is shown with a green line
if it is passable and a red line if it is not. The input file is assumed to be in the format specified in the
assignment.

@technical_details Open-Closed Principle: The DrawingContext class is open for extension and closed for modification.
The DrawingContext class is open for the extension because it can be extended with new drawing strategies.
The DrawingContext class is closed for modification because it does not need to be modified when new drawing strategies
are added.
Single Responsibility Principle: The DrawingContext class has a single responsibility which is to draw all the drawing
strategies it contains.

"""

from typing import List, Tuple
import matplotlib.pyplot as plt


class DrawingStrategy:
    def draw(self, ax):
        pass


class PolygonDrawingStrategy(DrawingStrategy):
    def __init__(self, polygon):
        self.polygon = polygon

    def draw(self, ax):
        self.polygon.append(self.polygon[0])  # Connect last vertex to first
        x, y = zip(*self.polygon)
        ax.plot(x, y, 'k-')


class PassageDrawingStrategy(DrawingStrategy):
    def __init__(self, passage):
        self.passage = passage

    def draw(self, ax):
        x, y = zip(*self.passage)
        ax.plot(x, y, 'b--')


class TestPointsDrawingStrategy(DrawingStrategy):
    def __init__(self, start, end, result):
        self.start = start
        self.end = end
        self.result = result

    def draw(self, ax):
        color = 'g' if self.result else 'r'
        x, y = zip(self.start, self.end)
        ax.plot(x, y, color=color)


class DrawingContext:
    def __init__(self):
        self.strategies = []

    def add_strategy(self, strategy):
        self.strategies.append(strategy)

    def draw_all(self, ax):
        for strategy in self.strategies:
            strategy.draw(ax)


def read_input_file(file_path: str) -> Tuple[
    List[List[Tuple[float, float]]], List[Tuple[Tuple[float, float], Tuple[float, float]]], List[
        Tuple[Tuple[float, float], Tuple[float, float]]]]:
    polygons, passages, test_points = [], [], []

    with open(file_path, 'r') as file:
        sections = [polygons, passages, test_points]
        section_idx = 0

        for line in file:
            line = line.strip()

            if not line:
                section_idx += 1
                continue

            sections[section_idx].append([tuple(map(float, point.split(','))) for point in line.split(';')])

    return polygons, passages, test_points


def read_result_file(file_path: str) -> List[int]:
    with open(file_path, 'r') as file:
        results = [int(line.strip()) for line in file]

    return results


def main(input_file: str, result_file: str):
    polygons, passages, test_points = read_input_file(input_file)
    results = read_result_file(result_file)

    drawing_context = DrawingContext()

    # Add drawing strategies for polygons
    for polygon in polygons:
        drawing_context.add_strategy(PolygonDrawingStrategy(polygon))

    # Add drawing strategies for passages
    for passage in passages:
        drawing_context.add_strategy(PassageDrawingStrategy(passage))

    # Add drawing strategies for test points
    for i, (start, end) in enumerate(test_points):
        result = results[i]
        drawing_context.add_strategy(TestPointsDrawingStrategy(start, end, result))

    # Draw everything
    fig, ax = plt.subplots()
    drawing_context.draw_all(ax)
    plt.show()


if __name__ == "__main__":
    input_file = "../test/input/q1_example_input[516].txt"
    result_file = "../test/results/q1_example_output[512].txt"
    main(input_file, result_file)



# Here function and class class's functions list of this file
# 1. DrawingStrategy.draw(self, ax)
# 2. PolygonDrawingStrategy.__init__(self, polygon)
# 3. PolygonDrawingStrategy.draw(self, ax)
# 4. PassageDrawingStrategy.__init__(self, passage)
# 5. PassageDrawingStrategy.draw(self, ax)
# 6. TestPointsDrawingStrategy.__init__(self, start, end, result)
# 7. TestPointsDrawingStrategy.draw(self, ax)
# 8. DrawingContext.__init__(self)
# 9. DrawingContext.add_strategy(self, strategy)
# 10. DrawingContext.draw_all(self, ax)
# 11. read_input_file(file_path: str) -> Tuple[List[List[Tuple[float, float]]], List[Tuple[Tuple[float, float], Tuple[float, float]]], List[Tuple[Tuple[float, float], Tuple[float, float]]]]
# 12. read_result_file(file_path: str) -> List[int]
# 13. main(input_file: str, result_file: str)



