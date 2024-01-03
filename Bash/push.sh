#!/usr/bin/bash

GIT_USERNAME="krahul2024"
GIT_PAT="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"

echo "Enter the message (Press Enter to use the default message): "
read -r message


echo "Adding files..."
sleep 1
git add .
echo "Committing the changes to GitHub..."
sleep 1
git commit -m "$message"
echo "Pushing the changes..."

git config credential.helper 'store --file ~/.git-credentials'

GIT_URL="https://${GIT_USERNAME}:${GIT_PAT}@github.com/krahul2024/bash-stuff.git"


git push "$GIT_URL" master
