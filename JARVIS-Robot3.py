import serial
import time
from JARVIS import listen, say

def send_command_to_robot(command):
    try:
        bt = serial.Serial('COM12', 9600)  # Update with the correct COM port for HC-05
        time.sleep(2)  # Allow time for HC-05 to stabilize
        bt.write((command + '\n').encode())
        print("Sent:", command)
        bt.close()
    except Exception as e:
        print("Failed to send command:", e)

text = listen()
if "forward" in text:
    send_command_to_robot("MOTOR_FORWARD")
elif "backward" in text:
    send_command_to_robot("MOTOR_BACKWARD")
elif "left" in text:
    send_command_to_robot("MOTOR_LEFT")
elif "right" in text:
    send_command_to_robot("MOTOR_RIGHT")
elif "stop" in text:
    send_command_to_robot("MOTOR_STOP")
elif "light on" in text:
    send_command_to_robot("LED_ON")
elif "light off" in text:
    send_command_to_robot("LED_OFF")
else:
    say("Command not recognized.")
