import matplotlib.pyplot as plt

dimensioni = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192]

tempi_bubble =    [1e-7, 1e-7, 0.000001, 0.000004, 0.000013, 0.000072, 0.000211, 0.000747, 0.003114, 0.012375, 0.051581, 0.243489]
tempi_insertion = [1e-7, 1e-7, 1e-7, 0.000001, 0.000005, 0.000023, 0.000057, 0.000212, 0.001037, 0.004002, 0.016638, 0.064609]
tempi_selection = [1e-7, 1e-7, 0.000001, 0.000002, 0.000010, 0.000029, 0.000110, 0.000409, 0.001595, 0.005662, 0.022804, 0.089649]
tempi_std =       [1e-7, 1e-7, 0.000001, 0.000002, 0.000006, 0.000011, 0.000033, 0.000050, 0.000109, 0.000216, 0.000478, 0.001091]

plt.figure(figsize=(10, 7))

plt.plot(dimensioni, tempi_bubble, label='bubble', color='blue', marker='+', markersize=5, linewidth=1.5)
plt.plot(dimensioni, tempi_insertion, label='insertion', color='orange', marker='+', markersize=5, linewidth=1.5)
plt.plot(dimensioni, tempi_selection, label='selection', color='green', marker='+', markersize=5, linewidth=1.5)
plt.plot(dimensioni, tempi_std, label='std', color='teal', marker='+', markersize=5, linewidth=1.5)

plt.xscale('log')
plt.yscale('log')

plt.xlabel('Dimensione')
plt.ylabel('Tempo (secondi)')

plt.grid(True, which="both", linestyle='--', linewidth=0.5, alpha=0.7)

plt.legend()

plt.savefig('grafico_tempi.png', dpi=300)
plt.show()