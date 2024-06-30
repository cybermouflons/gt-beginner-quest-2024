def getFlag():
    FLAG = open("flag.txt").read()
    print FLAG

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

print("""
{0}||==============================================================================||
||  Warnng: This application is using python2 and is deprecated.                ||
||          Please do not use in production.                                    ||
||          Contains potential security vulnerabilities.                        ||
||==============================================================================||{1}
""".format(bcolors.WARNING, bcolors.ENDC))

banner = """{0}
                                                        _    _ __  __  _____ 
                                                       | |  | |  \/  |/ ____|
                                                       | |__| | \  / | (___  
                                                       |  __  | |\/| |\___ \ 
                                                       | |  | | |  | |____) |
                                                       |_|  |_|_|  |_|_____/ 
  _    _            _               __  __                                                   _      _____           _                 
 | |  | |          | |             |  \/  |                                                 | |    / ____|         | |                
 | |__| | __ _  ___| | _____ _ __  | \  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  
 |  __  |/ _` |/ __| |/ / _ \ '__| | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|  \___ \| | | / __| __/ _ \ '_ ` _ \ 
 | |  | | (_| | (__|   <  __/ |    | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \__ \ ||  __/ | | | | |
 |_|  |_|\__,_|\___|_|\_\___|_|    |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__| |_____/ \__, |___/\__\___|_| |_| |_|
                                                              __/ |                                        __/ |                      
                                                             |___/                                        |___/                       
{1}""".format(bcolors.BOLD+bcolors.HEADER, bcolors.ENDC)
print banner

class Hacker:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return "Hacker '{}' | {} years old".format(self.name, self.age)

class HackerManager:
    def __init__(self):
        self.hackers = []

    def add_user(self, name, age):
        user = Hacker(name, age)
        self.hackers.append(user)
        print "Hacker {} added successfully.".format(name)

    def list_hackers(self):
        if not self.hackers:
            print "No hackers available."
        else:
            print "\nList of hackers:"
            for user in self.hackers:
                print user

    def delete_user(self, name):
        for user in self.hackers:
            if user.name == name:
                self.hackers.remove(user)
                print "Hacker {} deleted successfully.".format(name)
                return
        print "Hacker {} not found.".format(name)

def display_menu():
    print "\nThe HMS"
    print "1. Add Hacker"
    print "2. List Hackers"
    print "3. Delete Hacker"
    print "4. GetFlag"
    print "5. Exit"

manager = HackerManager()

while True:
    display_menu()
    choice = input("Enter your choice: ")

    if choice == 1:
        name = raw_input("Enter user name: ")
        age = raw_input("Enter user age: ")
        try:
            age = int(age)
            manager.add_user(name, age)
        except ValueError:
            print "Invalid age. Please enter a number."
    elif choice == 2:
        manager.list_hackers()
    elif choice == 3:
        name = raw_input("Enter the name of the user to delete: ")
        manager.delete_user(name)
    elif choice == 4:
        print("Option is disabled.")
    elif choice == 5:
        print "Exiting the system. Goodbye!"
        break
    else:
        print "Invalid choice. Please select a valid option."

