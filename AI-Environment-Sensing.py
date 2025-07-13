from JARVIS import listen, say
from browser import browseropen
import datetime, os
import wikipedia
from google2 import search
import serial
import time

# Setup Serial Communication with NodeMCU
try:
    node_serial = serial.Serial('COM9', 9600, timeout=1)  # Change COM4 as per your PC
    time.sleep(2)  # wait for the serial connection to initialize
except:
    node_serial = None
    print("NodeMCU not connected")

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
          "Access Internet\n",
          "Temperature and Humidity")
    
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
        os.startfile("C:/Users/Public/Desktop/VMware Workstation Pro.lnk")
        
    elif "cisco packet tracer" in task:
        os.startfile("C:/Users/DELL/Desktop/Cisco Packet Tracer.lnk")
        
    elif "power bi" in task:
        os.startfile("C:/Users/Public/Desktop/Power BI Desktop.lnk")
        
    elif "Microsoft Word" in task:
        os.startfile("C:/ProgramData/Microsoft/Windows/Start Menu/Programs/Word 2016.lnk")
        
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
    elif "temperature" in task or "humidity" in task or "temperature and humidity" in task:
     if node_serial:
        time.sleep(1)
        if node_serial.in_waiting:
            data = node_serial.readline().decode(errors='ignore').strip()
            if "Error" not in data and "," in data:
                temp, hum = data.split(",")
                say(f"The current temperature is {temp} degrees Celsius and the humidity is {hum} percent.")
                print(f"Temperature: {temp} °C, Humidity: {hum} %")
            else:
                say("Failed to read from sensor")
        else:
            say("No data from NodeMCU")
    else:
        say("NodeMCU is not connected")


