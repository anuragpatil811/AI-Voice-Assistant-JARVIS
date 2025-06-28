import serial
from JARVIS import listen, say
import time
arduino = serial.Serial('COM12', 9600)
time.sleep(2)  
def send_command(command):
    arduino.write((command + "\n").encode())  
    say(f"Sent command: {command}")
def main():
    say("JARVIS is now active. At your service sir")
    
    for i in range(3):  
        say(f"Listening for command {i+1}")
        task = listen()

        if "light on" in task:
            send_command("LED_ON")
        elif "light off" in task:
            send_command("LED_OFF")
        elif "move forward" in task:
            send_command("MOTOR_FORWARD")
        elif "move backward" in task:
            send_command("MOTOR_BACKWARD")
        elif "left" in task:
            send_command("MOTOR_LEFT")
        elif "right" in task:
            send_command("MOTOR_RIGHT")
        elif "stop" in task:
            send_command("MOTOR_STOP")
        else:
            say("Command not recognized, please try again.")
    say("Session complete. Thank You!")
main()
