#!/usr/bin/env python3
import serial

def main():
    """Monitor the serial port (which should connect to the Arduino)."""
    with serial.Serial('/dev/ttyACM0', 9600) as port:
        while port.is_open:
            x = port.readline().decode('utf-8')
            print(x)

if __name__ == '__main__':
    main()


