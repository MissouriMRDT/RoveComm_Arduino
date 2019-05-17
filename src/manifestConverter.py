import os

with open("RoveCommManifest.h") as f:
	lines = f.readlines()
	
output = open("RoveCommManifest.py", "w+")

lines = lines[2:]
lines = lines[:-1]
	
for line in lines:
	line = line.replace("	", " ")
	if "#define" in line:
		line = line.replace("#define ", "", 1).replace(" ", "=", 1)
		if "DATATYPE" in line:
			line = "#" + line
			
	
	line = line.replace(" 01", " 1")
	line = line.replace(" 02", " 2")
	line = line.replace(" 03", " 3")
	line = line.replace(" 04", " 4")
	line = line.replace(" 05", " 5")
	line = line.replace(" 06", " 6")
	line = line.replace(" 07", " 7")
	line = line.replace(" 08", " 8")
	line = line.replace(" 09", " 9")

	line = line.replace("//", "#", 1).replace("/*", "'''").replace("*/", "'''")
	output.write(line)