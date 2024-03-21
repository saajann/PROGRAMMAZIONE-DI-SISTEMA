#!/bin/bash

for file in *; do
  grep "#!/bin/bash" "$file" 1>/dev/null && echo "$file"
done

exit 0
