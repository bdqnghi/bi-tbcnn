import os
import sys
import pickle
import pyarrow

if __name__ == "__main__":
    with open(sys.argv[1], 'rb') as f:
        data = pickle.load(f)
        f.close()
    buf = pyarrow.serialize(data).to_buffer()
    out = pyarrow.OSFile(sys.argv[2], 'wb')
    out.write(buf)
    out.close()
