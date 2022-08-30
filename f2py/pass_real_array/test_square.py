from square import fortfuncs
import numpy as np

a = np.array([1,2,3,4])
b=fortfuncs.square(a)
assert np.all(b == a**2)
print("Success: b={}".format(b))
