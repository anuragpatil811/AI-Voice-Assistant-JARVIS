from JARVIS import listen, say
from browser import browseropen
import datetime, os
import wikipedia
from google import search_google  
def mfx(fx):
    def ifx():
        say("Jarvis is now active. At your service, sir")
        fx()
        say("Thank you")
    return ifx()
@mfx
def main():
    print("Search on Internet\n", 
          "Open Browsers\n", 
          "Wikipedia\n", 
          "Open Applications\n", 
          "Music\n", 
          "Time\n",
          "Access Internet")

    task = listen().lower()  # Convert to lowercase for consistent matching

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

    elif "vlc" in task:
        os.startfile("C:/Program Files/VideoLAN/VLC")

    elif "power bi" in task:
        os.startfile("C:/Users/Public/Desktop/Power BI Desktop.lnk")

    elif "microsoft word" in task:
        os.startfile("C:/ProgramData/Microsoft/Windows/Start Menu/Programs/Word.lnk")

    elif "music" in task:
        os.startfile("C:/Users/Admin/Downloads/(24 Bit)ACDC-Back In Black-06-Back In Black.mp3")

    elif "wikipedia" in task:
        task = task.replace("wikipedia", " ")
        result = wikipedia.summary(task, sentences=3)
        print(result)
        say(result)

    elif "search" in task:
        task = task.replace("search", " ")
        result = search_google(task)  # Use updated google.py function
        print(result)
        say(result)
