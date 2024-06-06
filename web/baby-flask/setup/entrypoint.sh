#!/bin/bash

python /app/app.py 2>&1 | tee /app/logs.txt
