#!/bin/bash

error() {
  echo "si è verificato un errore"
  exit 1
}

[ "$#" -eq 1 ] || error
touch "$1"
echo "#!/bin/bash" > "$1"
chmod 755 "$1"
echo "echo Hello World!" >> "$1"
echo "exit 0" >> "$1"

exit 0
