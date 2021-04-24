#!/bin/bash
git add .
IFS= read -r -p "Commit description: " desc
git commit -m "$desc"
eval $(ssh-agent -s)
ssh-add ~/.ssh/github_rsa
git push
read -p "Press enter to continue"