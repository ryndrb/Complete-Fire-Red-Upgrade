Most here are replacements. (If adding/in free space, must be free after inserting engine.)
Haven't encounter bugs yet, so seems fine... If there is, might inject before DPE.

Small changes just go to bytereplacement.

Sample Python Script:

import binascii

# file1 and file2 should be the same exept for the patch. base should be LEON (in my case)

file1 = 'vanilla.gba' # LEON base
file2 = 'patched.gba'

with open(file1, 'rb') as f1, open(file2, 'rb') as f2, open('offsets.txt', 'w') as offsets:
    offset = 0
    while True:
        byte1 = f1.read(1)
        byte2 = f2.read(1)
        if byte1 != byte2:
            offsets.write(f"08{offset:X} {byte2.hex()}\n".upper())
        offset += 1
        if not byte1 and not byte2:
            break