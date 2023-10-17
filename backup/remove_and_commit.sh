#!/bin/bash

# Remove the first line of code from all C files with a custom commit message based on the filename
for c_file in *.c; do
    filename="${c_file%.c}"  # Getting the base filename without extension
    commit_message="Updated $filename: removed duplicate main.h inclusion"

    # Remove the first line from the file
    sed -i '1d' "$c_file"

    # Adding the file to Git
    git add "$c_file"

    # Sending the commit message
    git commit -m "$commit_message"
done

# Pushing the changes to GitHub
git push origin main

