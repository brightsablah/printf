#!/bin/bash

# Adding a line of code to the top of all C files with a custom message based on the filename
for c_file in *.c; do
    filename="${c_file%.c}"  # Getting the base filename without extension
    commit_message="Updated $filename: included main header file"

    # Adding the line to the file
    sed -i '1i #include "main.h"' "$c_file"

    # Adding the file to Git
    git add "$c_file"

    # Sending the commit message
    git commit -m "$commit_message"
done

# Pushing the changes to GitHub
git push origin main

