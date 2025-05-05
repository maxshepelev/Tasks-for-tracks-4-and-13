import matplotlib.pyplot as plt
import random as rd

#initilizing tensor as 400x400 matrix
a = [[rd.randint(0, 255) for i in range(400)] for i in range(400)]


#adding a bit of interface
plt.figure(figsize=(10, 10))
plt.imshow(a, vmin=0, vmax=255)
plt.colorbar(label='correlation between integer value and corresponding pixel brightness')
plt.title("4D tensor visualization via 2D projections")

#creating a grid for visualizing projections
plt.grid(True, color='black', linewidth=1)
plt.xticks(range(0, 401, 20))
plt.yticks(range(0, 401, 20))