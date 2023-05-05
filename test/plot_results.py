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
    input_file = "input/q1_example_input[516].txt"
    result_file = "results/q1_example_output[512].txt"
    main(input_file, result_file)
