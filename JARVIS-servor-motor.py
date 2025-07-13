from JARVIS import listen, say
import datetime, os, serial, time
from browser import browseropen
import wikipedia
from google2 import search

# Setup serial communication (replace with your actual COM port)
ser = serial.Serial('COM9', 9600)
time.sleep(2)  # Wait for NodeMCU to reset

def handle_task(task):
    if "browser" in task:
        result = browseropen(task)
        say(result)    
    elif "rotate forward" in task:
        ser.write(b'F')
        say("Rotating servo forward")

    elif "rotate backward" in task:
        ser.write(b'B')
        say("Rotating servo backward")

    else:
        say("Sorry, I didn't understand the command.")

def main():
    say("Welcome Boss. JARVIS is now active.")
    while True:
        try:
            say("Listening for your command.")
            task = listen()
            handle_task(task.lower())
        except Exception as e:
            print("Error:", e)
            say("An error occurred. Please try again.")

main()
