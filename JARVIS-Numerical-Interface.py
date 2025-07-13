from JARVIS import listen, say
import serial, time

ser = serial.Serial('COM9', 9600)
time.sleep(2)

def handle_task(task):
    task = task.lower()

    digits = {
        "zero": '0', "one": '1', "two": '2', "three": '3', "four": '4',
        "five": '5', "six": '6', "seven": '7', "eight": '8', "nine": '9'
    }

    for word, num in digits.items():
        if f"display {word}" in task:
            ser.write(num.encode())
            say(f"Displaying {word}")
            return

    say("Sorry, I didn't understand the number to display.")

def main():
    say("Jarvis is now active. At your sevice sir")
    while True:
        try:
            say("Say a number to display.")
            task = listen()
            handle_task(task)
        except Exception as e:
            print("Error:", e)
            say("Error occurred.")

main()
