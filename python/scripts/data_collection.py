import serial
import time

def collect_data(port='/dev/ttyUSB0', baudrate=9600, duration=60):
    ser = serial.Serial(port, baudrate, timeout=1)
    start_time = time.time()
    data = []

    try:
        while (time.time() - start_time) < duration:
            line = ser.readline().decode('utf-8').strip()
            if line.startswith("S:"):
                value = float(line[2:])
                data.append(value)
                print(f"Spike reading: {value}")
    except KeyboardInterrupt:
        print("Interrupted by user.")
    finally:
        ser.close()

    return data

if __name__ == "__main__":
    data = collect_data()
    print(f"Collected {len(data)} samples.")
