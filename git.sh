
git init
git config --global --add safe.directory /home/mnt_drive/leetcode

git config --global user.email ""
git config --global user.name ""



git add .

git submodule add <url> env/setuptools
git submodule add https://github.com/pypa/setuptools.git env/setuptools

git commit -m "first commit"
git branch -M main


git remote add origin https://github.com/shouyanxiang/alg.git
git push -u origin main

# shouyanxiang
