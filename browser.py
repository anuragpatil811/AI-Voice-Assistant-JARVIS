import webbrowser
import json
link = open("links.json",  "r")
obj = json.load(link)
def browseropen(task):
#    link = open("links.json",  "r")
#    obj = json.load(link)
    for i in obj["links"]:
        print(i)
        if i in task:
            print(i)
            webbrowser.open(obj["links"][i])
            return  f"Opening {i}"
        
#    print(type(obj))


#    print(task)
