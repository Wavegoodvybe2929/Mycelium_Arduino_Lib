# Setup Guide

## Prerequisites

- Python ≥ 3.8
- Rust toolchain (install via [rustup](https://rustup.rs/))
- Arduino IDE or PlatformIO
- Maturin (for Rust-Python bindings)

---

## Arduino Setup

1. **Install Arduino IDE** and required board drivers.
2. Connect electrodes and your custom mycelium sensor shield (see `arduino/schematics/`).
3. Upload:
   - `arduino/firmware/node_firmware/node_firmware.ino` for sensor nodes.
   - `arduino/firmware/gateway_firmware/gateway_firmware.ino` for central collector or gateway.

---

## Rust Core

```bash
cd rust-core
cargo build --release
