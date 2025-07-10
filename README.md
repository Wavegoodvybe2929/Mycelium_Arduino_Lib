# Mycelium Arduino Lib

## Overview

This project is a cross-language system for decoding, analyzing, and interacting with fungal electrical spiking activity, inspired by Andrew Adamatzky's research on the "language" of fungi. It integrates Arduino firmware, Rust core libraries, and Python interfaces for end-to-end data acquisition and linguistic analysis.

---

## Architecture

Mycelium_Arduino_Lib/
├── arduino/ # Arduino firmware & mycelium sensor library
├── rust-core/ # Rust libraries for IO, DSP, and language modeling
├── python/ # Python layer for higher-level data analysis and ML models
├── models/ # Pre-trained neural models for decoding
├── data/ # Experimental and calibration data
├── configs/ # Configuration files
├── examples/ # Usage examples
├── docs/ # Documentation and guides


---

## Key Features

- **Fungal Electrical Spike Acquisition**: Collect high-resolution spike data via Arduino sensors using differential electrodes.
- **Rust Core Processing**:
  - `mycelium-io`: Serial and LoRaWAN communication support.
  - `mycelium-dsp`: Signal filtering, spike detection, and preprocessing.
  - `mycelium-lang`: State machines and word/phrase extraction logic inspired by fungal "words" and "sentences".
- **Python Analysis**:
  - Wraps Rust libraries (via PyO3).
  - Supports spike complexity analysis, Adamatzky-style linguistic parsing, and ML-based classification.
- **Neural Decoders**: BitNet-inspired deep learning models for "language" decoding.

---

## Scientific Basis

The fungal spiking analysis is based on:

> Adamatzky, A. (2022). Language of fungi derived from their electrical spiking activity. *Royal Society Open Science*, 9: 211926. https://doi.org/10.1098/rsos.211926

Key methods:

- Spike detection via local neighborhood averaging and thresholding.
- Binary encoding of spike presence per second.
- Word segmentation using inter-spike interval thresholds (θ).
- Algorithmic and Lempel-Ziv complexity measures for decoding.

---

## Getting Started

1. **Firmware**: Deploy Arduino code for sensor nodes and gateway.
2. **Rust Core**: Build the Rust crates (`cargo build`).
3. **Python Bindings**: Install using `pip install .` or `maturin develop`.
4. **Python Scripts**: Use `scripts/data_collection.py` to acquire spikes, and `scripts/real_time_decode.py` for live decoding.

---

## License

This project is licensed under MIT. See [LICENSE](LICENSE) for details.

---

## Contributors

- **You!** (Primary developer and integrator)
- Inspired by the Unconventional Computing Lab (UWE, Bristol)

---

## Acknowledgments

Special thanks to the open science community and fungal researchers contributing to the emerging field of bioelectrical linguistics.

---
