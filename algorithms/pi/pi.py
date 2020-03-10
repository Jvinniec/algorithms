
import random
import numpy as np

# Keep track of how many are inside the circle
total  = 1000000
inside = 0

for i in range(total):
    # Compute random position
    x = random.random()*2.0 - 1
    y = random.random()*2.0 - 1
    r = np.sqrt(x*x+y*y)

    # Check if x,y coordinate is inside
    if r <= 1.0:
        inside += 1

# Print some final information
est  = 4.0*(inside/total)
diff = np.abs(est - np.pi)
print(f'FINAL: Est={est:02.4f} Err={diff:1.3e}')
