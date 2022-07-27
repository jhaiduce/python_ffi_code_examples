from square import square
import numpy as np

a = np.array([1,2,3,4])
b=square(a)
assert np.all(b == a**2)
