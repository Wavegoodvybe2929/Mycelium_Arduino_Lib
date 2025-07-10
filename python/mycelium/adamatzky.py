import numpy as np

def detect_spikes(signal, w=200, delta=0.1):
    spikes = []
    n = len(signal)

    for i in range(w, n - w):
        neighborhood = np.mean(signal[i - w:i + w])
        if abs(signal[i]) - abs(neighborhood) > delta:
            spikes.append(i)

    return np.array(spikes)

def estimate_complexity(words):
    joined = ''.join(['1' * len(w) + '0' for w in words])
    entropy = -sum(joined.count(c) / len(joined) * np.log2(joined.count(c) / len(joined)) for c in set(joined))
    lz = len(set(joined[i:j] for i in range(len(joined)) for j in range(i + 1, len(joined) + 1)))
    return {
        "entropy": entropy,
        "lz_complexity": lz
    }
