import serial
from JARVIS import listen, say
from browser import browseropen
import datetime, os, wikipedia

# Set up serial communication (change COM port as per your setup)
arduino = serial.Serial('COM3', 9600)

def send_command(command):
    arduino.write(command.encode())  # Send command to Arduino
    say(f"Sent command: {command}")

def main():
    say("Welcome Boss")
    task = listen()

    if "light on" in task:
        send_command("LIGHT_ON")
    elif "light off" in task:
        send_command("LIGHT_OFF")
    elif "fan on" in task:
        send_command("FAN_ON")
    elif "fan off" in task:
        send_command("FAN_OFF")
    elif "browser" in task:
        result = browseropen(task)
        say(result)
    elif "time" in task:
        dt = datetime.datetime.now().strftime("%H Hours and %M Minutes")
        say(f"Time is {dt}")

    say("Thank You")

main()
