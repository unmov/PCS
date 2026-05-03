import matplotlib.pyplot as plt

sizes = [4, 8, 16, 32, 64, 128, 256, 512]

t_insert   = [0.00000002, 0.00000006, 0.00000013, 0.00000032, 0.00000076, 0.00000267, 0.00000707, 0.00002137]
t_quick    = [0.00000003, 0.00000009, 0.00000023, 0.00000054, 0.00000130, 0.00000329, 0.00000606, 0.00001289]
t_modified = [0.00000002, 0.00000006, 0.00000013, 0.00000034, 0.00000083, 0.00000310, 0.00000565, 0.00001227]

plt.figure(figsize=(10, 6))

plt.plot(sizes, t_insert,   marker='s', label='Insertion Sort', color='orange', linewidth=2)
plt.plot(sizes, t_quick,    marker='x', label='Quick Sort', color='purple', linewidth=2)
plt.plot(sizes, t_modified, marker='*', label='Modified QuickSort', color='brown', linewidth=2, markersize=10)

plt.title('Punto di Cut-off', fontsize=14)
plt.xlabel('Dimensione del vettore (N)', fontsize=12)
plt.ylabel('Tempo medio (secondi)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.xscale('log', base=2)
plt.xticks(sizes, sizes) 

plt.show()