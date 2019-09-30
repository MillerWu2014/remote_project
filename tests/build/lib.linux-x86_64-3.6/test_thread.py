#!/opt/anaconda3/envs/FireWar/bin/python
import cy_thread
from concurrent.futures import ThreadPoolExecutor, as_completed

all_task = []
with ThreadPoolExecutor(max_workers=12) as executor:
    for i in range(12):
        all_task.append(executor.submit(cy_thread.thread))

i = 1
for future in as_completed(all_task):
    r = future.result()
    print(r)