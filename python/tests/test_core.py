from mycelium import core

def test_bandpass_filter():
    data = [0.0, 0.1, 0.2, 0.3]
    filtered = core.bandpass_filter(data, 0.1, 2.0)
    assert len(filtered) == len(data)

def test_detect_spikes():
    data = [0.0]*100 + [1.0] + [0.0]*100
    spikes = core.detect_spikes(data, window=10, delta=0.5)
    assert isinstance(spikes, list)

def test_entropy_lz():
    seq = "11110000"
    entropy = core.shannon_entropy(seq)
    lz = core.lz_complexity(seq)
    assert entropy >= 0
    assert lz > 0
