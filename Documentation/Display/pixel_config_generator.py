

with open("coordinates.txt", "r") as infile:

    data = infile.read()

    infile.close()
    
data_stripped = []

current_data = ""

for char in data:
    
    if char in ["0","1","2","3","4","5","6","7","8","9"]:
        current_data += char;
        
    if (((char == " ") | (char == "\n")) & (current_data != "")):#& (len(data_stripped) <= 1659)):
        data_stripped.append(int(current_data))
        current_data = ""

if (current_data != ""):
    data_stripped.append(int(current_data))
    
datapoints = []
for i in range(0,len(data_stripped),4):
    datapoints.append([data_stripped[i],data_stripped[i+1],data_stripped[i+2],data_stripped[i+3]])

datapoints.sort(key=lambda x: x[0])

for i in range(0, len(datapoints)):
    if (((int(datapoints[i][2]) - int(datapoints[i][1])) != (int(datapoints[i][3])-1)) | (datapoints[i][0] != i)):
        print("Error in line " + str(datapoints[i][0]))

with open("display_pixel_config.csv", "w") as outfile:
    for i in datapoints:
        i = [str(a) for a in i]
        outfile.write(i[1] + "," + i[2] + "\n")
    outfile.close()








# f = open("display_pixel_config.csv", "r")
# print(f.read()) 
