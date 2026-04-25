import math

def calculate_area(a, b, c):
    # Calculate the semi-perimeter
    p = (a + b + c) / 2
    # Heron's formula for area
    # Note: We can compare p*(p-a)*(p-b)*(p-c) directly without the sqrt 
    # to save computation, since areas are guaranteed to be different.
    return p * (p - a) * (p - b) * (p - c)

n = int(input())
triangles = []

for _ in range(n):
    # Read sides a, b, c
    sides = list(map(int, input().split()))
    area = calculate_area(*sides)
    # Store sides and area together
    triangles.append((sides, area))

# Sort triangles based on the area (the second element in the tuple)
triangles.sort(key=lambda x: x[1])

# Print the sides of the sorted triangles
for t in triangles:
    print(*t[0])

