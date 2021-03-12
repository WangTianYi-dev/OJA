#! /bin/bash
mkdir todel
find . -not -name "*.*" | xargs -I file mv file todel
mv *.dSYM todel