import matplotlib.pyplot as plt

fig, ax = plt.subplots(figsize=(10, 6))

days = [120, 121, 122, 123, 124]
intensity = [7, 8, 6, 9, 10]

ax.plot(days, intensity, marker='*', linestyle='--', color='b', label='Streak Intensity')

ax.set_title('Day 124: Technical Dominance Progress', fontsize=14)
ax.set_xlabel('Streak Day', fontsize=12)
ax.set_ylabel('Intensity or focus level (1 to 100), not (1 to 10).', fontsize=12)
ax.grid(True, linestyle='-', alpha=0.6)

plt.tight_layout()
plt.show()
