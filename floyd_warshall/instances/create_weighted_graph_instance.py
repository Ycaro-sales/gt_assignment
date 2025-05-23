# 125 6963
# 45 918
# 200 14834
# 200 9876
# 6 8
# 64 1824
# 64 704
# 28 210
# 70 1855
# 120 5460
# 171 9435
import itertools
import random
from typing import List, Tuple, NewType

edge = NewType("edge", Tuple[int, int, int])


def generate_weight():
    weight = random.randint(-5, 5)
    while weight == 0:
        weight = random.randint(-5, 5)
    return weight


def create_graph_intances(num_vertices: int) -> List[edge]:
    edges: List[edge] = []
    for i, j in itertools.product(
        range(1, num_vertices + 1), range(1, num_vertices + 1)
    ):
        if i != j:
            edges.append(edge((i, j, generate_weight())))

    return edges


def output_formating(num_vertices: int, edges: List[edge]):
    output = ""
    output = f"{num_vertices} {len(edges)}\n"
    for _, v in enumerate(edges):
        output += str(v[0]) + " " + str(v[1]) + " " + str(v[2]) + "\n"
    return output


for i in range(10):
    if i <= 4:
        n = random.randint(5, 15)
        edges = create_graph_intances(n)
        chance = random.randint(10, 20)
        edges = [item for item in edges if (random.randint(1, 100) >= chance)]
    else:
        n = random.randint(20, 100)
        edges = create_graph_intances(n)
        chance = random.randint(10, 30)
        edges = [item for item in edges if (random.randint(1, 100) >= chance)]

    with open(f"instance_{i + 1}.mtx", "w") as f:
        f.write(output_formating(n, edges))

for i in range(10):
    n = random.randint(100, 200)
    edges = create_graph_intances(n)
    chance = random.randint(10, 30)
    edges = [item for item in edges if (random.randint(1, 100) >= chance)]

    with open(f"instance_{i + 1 + 10}.mtx", "w") as f:
        f.write(output_formating(n, edges))
