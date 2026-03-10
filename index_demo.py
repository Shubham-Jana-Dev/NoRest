import random as rd
import time

raw_data = rd.sample(range(1, 10000000),1000000)

data_list = list(raw_data)
data_set = set(raw_data)

target = raw_data[500000]
def equality_counter(data_structure,name):
    start = time.perf_counter()
    _ = target in data_structure
    data_time = time.perf_counter() - start
    print(f"Equality Search ({name}): {data_time:.8f}s")
equality_counter(data_list,'List')
equality_counter(data_set,'Set')