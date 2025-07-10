import serial
import time
from mycelium import core, language

def real_time_decode(port='/dev/ttyUSB0', baudrate=9600):
    ser = serial.Serial(port, baudrate, timeout=1)
    spike_indices = []
    idx = 0

    try:
        while True:
            line = ser.readline().decode('utf-8').strip()
            if line.startswith("S:"):
                value = float(line[2:])
                if value > 0.05:  # Simple threshold
                    spike_indices.append(idx)
                    print(f"Spike at index {idx} (value: {value})")
                idx += 1

                # Example "word" extraction every 50 samples
                if idx % 50 == 0 and spike_indices:
                    words = language.extract_words(spike_indices, theta=10)
                    transitions = language.analyze_syntax(words)
                    print(f"Transitions: {transitions}")

    except KeyboardInterrupt:
        print("Stopped by user.")
    finally:
        ser.close()

if __name__ == "__main__":
    real_time_decode()
