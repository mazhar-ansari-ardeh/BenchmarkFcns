import re

with open("src/C++/main.cpp", "r") as f:
    content = f.read()

# Find all m.def blocks
blocks = re.findall(r'm\.def\("([^"]+)"(.*?)\)pbdoc";', content, re.DOTALL)

for name, body in blocks:
    # Lowercase everything for simpler matching
    body_lower = body.lower()

    # Extract the name without 'n' suffix or numbers (e.g. 'ackleyn2' -> 'ackley')
    base_name = re.match(r"([a-zA-Z]+)", name).group(1)

    # Check if some other common names appear in the text
    common_names = [
        "ackley",
        "sphere",
        "rosenbrock",
        "rastrigin",
        "schwefel",
        "griewank",
        "beale",
        "booth",
        "branin",
        "bukin",
    ]
    for common in common_names:
        if common != base_name and common in body_lower:
            print(f"Function '{name}' mentions '{common}' in its docstring.")
