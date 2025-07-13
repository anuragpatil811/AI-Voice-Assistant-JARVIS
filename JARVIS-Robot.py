import requests
from JARVIS import listen, say

ESP8266_IP = "http://192.168.1.103"
 

def send_command(command):
    url = f"{ESP8266_IP}/{command}"
    response = requests.get(url)
    say(f"Sent command: {command}")
    print(f"Response: {response.text}")

def main():
    say("Welcome Boss, WiFi control activated.")
    
    while True:
        say("Listening for command...")
        task = listen().lower()

        if "light on" in task:
            send_command("LED_ON")
        elif "light off" in task:
            send_command("LED_OFF")
        elif "move forward" in task:
            send_command("FORWARD")
        elif "move backward" in task:
            send_command("BACKWARD")
        elif "turn left" in task:
            send_command("LEFT")
        elif "turn right" in task:
            send_command("RIGHT")
        elif "stop" in task:
            send_command("STOP")
        elif "exit" in task:
            say("Shutting down JARVIS control.")
            break
        else:
            say("Command not recognized, please try again.")

    say("Session complete. Thank You!")

main()
