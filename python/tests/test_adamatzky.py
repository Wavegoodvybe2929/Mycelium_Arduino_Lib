from mycelium import adamatzky
import numpy as np

def test_detect_spikes():
    signal = np.concatenate([np.zeros(100), np.ones(5), np.zeros(100)])
    spikes = adamatzky.detect_spikes(signal, w=5, delta=0.5)
    assert isinstance(spikes, np.ndarray)
    assert spikes.size > 0

def test_estimate_complexity():
    words = ["111", "11", "1"]
    result = adamatzky.estimate_complexity(words)
    assert "entropy" in result
    assert "lz_complexity" in result
