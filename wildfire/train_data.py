import os
from six import moves

root_dir = "/data/dl_datasets/wildfire_train_data"
for file in os.listdir(root_dir):
    pickle_file_path = os.path.join(root_dir, file)
    with open(pickle_file_path, "rb") as f:
        data = moves.cPickle.load(f)
    print(data.shape)
    print(data.columns)
    exit(0)
