import serial
from JARVIS import listen, say
import datetime, os
import wikipedia
from google2 import search
from browser import browseropen

arduino = serial.Serial('COM5', 9600)  

def mfx(fx):
    def ifx():
        say("Welcome Boss")
        fx()
        say("Thank You")
    return ifx()

@mfx
def main():
    print("Search on Internet\n", 
          "Open Browsers\n", 
          "Wikipedia\n", 
          "Open Applications\n", 
          "Music\n", 
          "Time\n",
          "Access Internet",
          "Object Detection")

    task = listen()

    if "browser" in task:
        result = browseropen(task)
        say(result)
    elif "time" in task:
        dt = datetime.datetime.now().strftime("%H Hours and %M Minutes")
        print(dt)
        say(f"Time is {dt}")
    elif "code" in task:
        os.startfile("C:/Users/DELL/Downloads/VSCodeUserSetup-x64-1.91.1 (1).exe")
    elif "open" in task:
        os.startfile("C:/Users/DELL/Downloads/kali-linux-2024.2-virtualbox-amd64.7z")
    elif "music" in task:
        os.startfile("C:/Users/DELL/Downloads/my code/Back-In-Black.mp3")
    elif "wikipedia" in task:
        task = task.replace("wikipedia", " ")
        result = wikipedia.summary(task, sentences=3)
        print(result)
        say(result)
    elif "search" in task:
        task = task.replace("search", " ")
        result = search(task)
        print(result)
        say(result)
    elif "object detection" in task:
        say("Checking for objects")
        arduino.write(b'CHECK_DISTANCE\n')  # Send command to Arduino
        distance = arduino.readline().decode().strip()
        say(f"Object detected at {distance}")
        print(f"Object detected at {distance} cm")
