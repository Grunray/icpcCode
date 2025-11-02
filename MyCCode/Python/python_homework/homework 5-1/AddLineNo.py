with open (r"G:\MyVSCode\MyCCode\Python\homework 5-1\AddLineNo.py", "rt") as f :
    lines = f.readlines()
#202311071205 付泊源
maxLength = len(max(lines, key = len))

newLines=[line.rstrip().ljust (maxLength) + \
    "#" + str(r + 1)+ "\n" for r, line in enumerate (lines)]

with open(r"G:\MyVSCode\MyCCode\Python\homework 5-1\AddLineNo2.py", "wt") as f :
    f.writelines(newLines)