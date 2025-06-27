import speech_recognition as sr
import win32com.client as pywin
#speaker = pywin.Dispatch("SAPI.SpVoice")
#speaker.Speak("Welcome to the future")
def say(str):
    speaker = pywin.Dispatch("SAPI.SpVoice")
    speaker.Speak(str)

def listen():
    try:
        r = sr.Recognizer()
        with sr.Microphone() as mic:
            print("Listening....Sir")
            audio = r.listen(mic)
            text = r.recognize_google(audio)
            print(text)
            return text.lower()
#    except ValueError:
#        print("Please Sir Say Something")
    except Exception:
        print("Sorry Sir ! Please Say Again")
#    r = sr.Recognizer()
#    with sr.Microphone() as mic:
#        print("Listening... Sir")
#        audio = r.listen(mic)
#        text = r.recognize_google(audio)
#        print(text)        
#        return text

#while 1:
#    print(listen())
    
#say("Hello Anil Kumar Sah")   
#r = sr.Recognizer()
#with sr.Microphone() as mic:
#    print("Listening... Sir")
#    audio = r.listen(mic)
#    text = r.recognize_google(audio)
    #print(text)
    #say(text)
