import requests
import sys

s = requests.Session()
url = sys.argv[1] if len(sys.argv) > 1 else 'http://localhost:1337'

# don't follow redirect to /end as the flag is in the intermidiate response that redirects to /end
r = s.get(url + "/magic", allow_redirects=False)
print(r.text)
