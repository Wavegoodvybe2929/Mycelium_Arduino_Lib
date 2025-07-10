# API Reference

## Python API

### `mycelium.core`

- `collect_spikes(serial_port: str, duration: int) -> np.ndarray`
  - Collect raw spike data from Arduino gateway via serial.

- `decode_sequence(spikes: np.ndarray) -> str`
  - Run linguistic decoding pipeline on spikes (word grouping, state analysis).

- `apply_filters(spikes: np.ndarray, method: str = "bandpass") -> np.ndarray`
  - Preprocessing filters from Rust DSP core.

---

### `mycelium.adamatzky`

- `detect_spikes(signal: np.ndarray, params: dict) -> np.ndarray`
  - Detect spikes using local thresholding as per Adamatzky.

- `estimate_complexity(words: list[str]) -> dict`
  - Estimate algorithmic, Lempel-Ziv, and entropy-based complexities.

---

### `mycelium.language`

- `extract_words(spike_train: np.ndarray, theta: float) -> list[str]`
  - Segment spike sequences into "words" using inter-spike interval threshold θ.

- `analyze_syntax(words: list[str]) -> dict`
  - Basic grammar and state transition analysis.

---

## Rust Core API

### `mycelium-io`

- Serial and LoRaWAN input modules
- Functions:
  - `fn read_serial(port: &str) -> Vec<f32>`
  - `fn read_lorawan() -> Vec<f32>`

---

### `mycelium-dsp`

- Filtering and preprocessing modules
- Functions:
  - `fn bandpass_filter(data: &[f32]) -> Vec<f32>`
  - `fn detect_spikes(data: &[f32], params: &DetectionParams) -> Vec<usize>`

---

### `mycelium-lang`

- Word grouping and finite state machine analysis
- Functions:
  - `fn extract_words(spike_train: &[usize], theta: f32) -> Vec<String>`
  - `fn analyze_state_transitions(words: &[String]) -> TransitionGraph`

---

## Example

```python
from mycelium import core, adamatzky

spikes = core.collect_spikes("/dev/ttyUSB0", duration=300)
words = adamatzky.detect_spikes(spikes, params={"w": 200, "δ": 0.1, "d": 300})
decoded = core.decode_sequence(words)
print(decoded)
