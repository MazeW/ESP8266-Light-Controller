#!/bin/bash
# this script takes html from src/index.html minifies it and copies to include/index.h file
html=$(cat ../src/index.html | tr -d "\t\n\r")
#length=$(echo -n "$html" | wc -c)
echo "static String indexHtml = \"${html}\";" >| ../include/index.h
echo "index.html minified and copied to index.h";
