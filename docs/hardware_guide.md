# Hardware Guide

## Electrode Setup

- **Type**: Iridium-coated stainless steel sub-dermal needle electrodes (e.g., Spes Medica S.r.l.)
- **Placement**:
  - Inserted into the substrate colonized by mycelium or directly into fruit bodies.
  - Recommended distance: **1–2 cm** between electrode pairs.
- **Connection**: Use twisted pair cables to minimize noise.

---

## Data Acquisition Module

- **Recommended ADC**: Pico Technology ADC-24 or similar high-resolution differential logger.
- **Sample rate**: 1 sample per second (software averaged from ~600 instantaneous samples per second).
- **Voltage range**: ±78 mV.

---

## Arduino Node Circuit

- Sensor board integrates differential input and optional amplification.
- Connect to Arduino analog inputs (e.g., A0, A1).
- Decouple power rails carefully to avoid microvolt-level noise.

---

## PCB & Electrode Schematics

Schematics are included:

arduino/schematics/
├── electrode_circuit.pdf
└── sensor_node_pcb.pdf


---

## Mycelium Sensor Node

- Handles local spike detection, buffering, and communication (LoRa/serial).
- Periodically transmits data to the gateway or directly to a computer.

---

## Gateway Node

- Receives signals from sensor nodes.
- Can forward data to PC or cloud endpoint over USB or Wi-Fi.

---

## Environment

- Temperature: ~21 °C
- Humidity: ~80%
- Light: Recommended to operate in darkness during sensitive experiments.

---

## References

Based on methods from:

> Adamatzky, A. (2022). Language of fungi derived from their electrical spiking activity. *R. Soc. Open Sci.*, 9: 211926.

---

**Next step:** Check `docs/api_reference.md` for available software APIs.
