#!/usr/bin/env python3
import serial


with serial.Serial('/dev/ttyACM0', 9600) as port:
    while port.is_open:
        x = port.readline().decode('utf-8')
        print(x)


