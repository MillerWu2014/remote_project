import pandas as pd


df = pd.read_pickle("/tmp/test/train_test_data/train_resampling.partition.03") 
print(df.index)