from JARVIS import listen, say
import serial, time
ser = serial.Serial('COM5', 9600)
time.sleep(2)  
def handle_task(task):
    task = task.lower()
    if "fan on" in task:
        ser.write(b'M')
        say("Turning on the fan.")
    elif "fan off" in task:
        ser.write(b'F')
        say("Turning off the fan.")
    elif "terminate" in task:
        say("Terminating the session. Goodbye!")
        return False 
    else:
        say("Sorry, I didn't understand that command.")

    return True  
def main():
    say("JARVIS is now active. At your service sir.")
    while True:
        try:
            task = listen()
            if not handle_task(task):
                break
        except Exception as e:
            print("Error:", e)
            say("An error occurred.")
            break
main()
