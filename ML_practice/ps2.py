import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
np.random.seed(1)
uniform_draw = np.random.uniform(0, 1, 50)
normals_smirnov = norm.ppf(uniform_draw)
normals_canned = np.random.normal(0, 1, size = 50)
bins = np.linspace(-3.5, 3.5, 10)

plt.hist(normals_smirnov, alpha = 0.3, bins = bins)
plt.hist(normals_canned, alpha = 0.3, bins = bins)
plt.show()