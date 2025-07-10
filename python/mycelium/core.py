import mycelium as rust_backend

def bandpass_filter(data, low=0.1, high=2.0):
    return rust_backend.py_bandpass_filter(data, low, high)

def detect_spikes(data, window=200, delta=0.1):
    return rust_backend.py_detect_spikes(data, window, delta)

def shannon_entropy(seq):
    return rust_backend.py_shannon_entropy(seq)

def lz_complexity(seq):
    return rust_backend.py_lz_complexity(seq)
