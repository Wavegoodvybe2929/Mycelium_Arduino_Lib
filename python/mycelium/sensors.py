import numpy as np

def normalize_signal(signal):
    min_val = np.min(signal)
    max_val = np.max(signal)
    if abs(max_val - min_val) < 1e-6:
        return np.zeros_like(signal)
    return (signal - min_val) / (max_val - min_val)

def smooth_signal(signal, window_size=5):
    return np.convolve(signal, np.ones(window_size)/window_size, mode='valid')
