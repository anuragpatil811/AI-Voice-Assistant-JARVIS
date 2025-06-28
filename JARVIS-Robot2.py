import requests
from JARVIS import listen, say
import time
# Replace with your ESP8266 NodeMCU's IP Address
NODEMCU_IP = "http://192.168.1.119"
  
def send_command(command):
    try:
        url = f"{NODEMCU_IP}/{command}"
        response = requests.get(url)
        if response.status_code == 200:
            say(f"Sent command: {command}")
        else:
            say("Failed to send command")
    except Exception as e:
        say(f"Error: {e}")

def main():
    say("Welcome Boss")

    for i in range(3):  
        say(f"Listening for command {i+1}")
        task = listen().lower()

        if "light on" in task:
            send_command("lighton")
        elif "light off" in task:
            send_command("lightoff")
        elif "move forward" in task:
            send_command("forward")
        elif "move backward" in task:
            send_command("backward")
        elif "left" in task:
            send_command("left")
        elif "right" in task:
            send_command("right")
        elif "stop" in task:
            send_command("stop")
        else:
            say("Command not recognized, please try again.")

    say("Session complete. Thank You!")

main()
