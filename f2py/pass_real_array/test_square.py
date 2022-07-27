from square import fortfuncs
import numpy as np

y=fortfuncs.square([2,3,4])
assert np.all(y==np.array([4,9,16]))
