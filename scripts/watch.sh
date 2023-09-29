#!/usr/bin/env bash

find . \( -type d -name build -o -name .git -o -name scripts \) -prune -o -type f -print | entr -c -p cmake --build build
