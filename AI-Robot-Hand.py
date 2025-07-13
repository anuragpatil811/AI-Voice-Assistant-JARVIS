from JARVIS import listen, say
import datetime, os, serial, time
from browser import browseropen
import wikipedia
from google2 import search

# Setup serial communication (update COM port if needed)
ser = serial.Serial('COM9', 9600)
time.sleep(2)  # Wait for NodeMCU to be ready

def handle_task(task):
    task = task.lower()

    if "hold the object" in task:
        ser.write(b'H')
        say("Holding the object.")

    elif "release the object" in task:
        ser.write(b'R')
        say("Releasing the object.")

    elif "move up" in task:
        ser.write(b'U')
        say("Moving arm up.")

    elif "move down" in task:
        ser.write(b'D')
        say("Moving arm down.")

    elif "stop" in task:
        ser.write(b'S')
        say("Stopping motors.")

    else:
        say("Sorry, I didn't understand the command.")

def main():
    say("JARVIS is now active. At your service sir")
    while True:
        try:
            say("Listening for your command.")
            task = listen()
            handle_task(task)
        except Exception as e:
            print("Error:", e)
            say("An error occurred. Please try again.")

main()
