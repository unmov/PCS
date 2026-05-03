import matplotlib.pyplot as plt

sizes = [4, 8, 16, 32, 64, 128, 256, 512]

t_bubble   = [0.00000003, 0.00000013, 0.00000054, 0.00000200, 0.00000727, 0.00002953, 0.00009972, 0.00035406]
t_insert   = [0.00000002, 0.00000006, 0.00000013, 0.00000032, 0.00000076, 0.00000267, 0.00000707, 0.00002137]
t_select   = [0.00000003, 0.00000010, 0.00000030, 0.00000083, 0.00000236, 0.00000849, 0.00001993, 0.00006363]
t_merge    = [0.00000017, 0.00000042, 0.00000099, 0.00000237, 0.00000464, 0.00001252, 0.00001975, 0.00003878]
t_quick    = [0.00000003, 0.00000009, 0.00000023, 0.00000054, 0.00000130, 0.00000329, 0.00000606, 0.00001289]
t_modified = [0.00000002, 0.00000006, 0.00000013, 0.00000034, 0.00000083, 0.00000310, 0.00000565, 0.00001227]
t_std      = [0.00000002, 0.00000009, 0.00000013, 0.00000046, 0.00000105, 0.00000290, 0.00000523, 0.00001132]

plt.figure(figsize=(12, 7))

plt.plot(sizes, t_bubble,   marker='o', label='Bubble Sort', color='red', alpha=0.6)
plt.plot(sizes, t_select,   marker='^', label='Selection Sort', color='green', alpha=0.6)
plt.plot(sizes, t_merge,    marker='d', label='Merge Sort', color='blue', alpha=0.7)
plt.plot(sizes, t_insert,   marker='s', label='Insertion Sort', color='orange', linewidth=2)
plt.plot(sizes, t_quick,    marker='x', label='Quick Sort', color='purple', linewidth=2)
plt.plot(sizes, t_modified, marker='*', label='Modified QuickSort', color='brown', linewidth=3, markersize=12)
plt.plot(sizes, t_std,      marker='v', label='std::sort', color='black', linestyle='--', linewidth=2)

plt.title('Confronto Algoritmi', fontsize=14)
plt.xlabel('Dimensione del vettore (N)', fontsize=12)
plt.ylabel('Tempo medio (secondi)', fontsize=12)
plt.grid(True, which="both", linestyle='--', alpha=0.5)

plt.xscale('log', base=2)
plt.xticks(sizes, sizes) 

plt.legend(loc='upper left')

plt.show()