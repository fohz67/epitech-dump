#!/bin/bash
set -e
git add --all
if [$1 == ""]
then
	git commit -m "No commit message"
else
	git commit -m "$1"
fi
git push origin main --force
