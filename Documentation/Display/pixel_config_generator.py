

with open("coordinates.txt", "r") as infile:

    data = infile.read()

    infile.close()
    
data_stripped = []

current_data = ""

for char in data:
    
    if char in ["0","1","2","3","4","5","6","7","8","9"]:
        current_data += char;
        
    if ((char == " ") & (current_data != "") & (len(data_stripped) <= 799)):
        data_stripped.append(int(current_data))
        current_data = ""


datapoints = []
for i in range(0,len(data_stripped),4):
    datapoints.append([data_stripped[i],data_stripped[i+1],data_stripped[i+2],data_stripped[i+3]])

# print([i[0] for i in datapoints])
print(datapoints[-1])

datapoints.sort(key=lambda x: x[0])

with open("display_pixel_config.csv", "w") as outfile:
    for i in datapoints:
        i = [str(a) for a in i]
        outfile.write(",".join(i)+"\n")
    outfile.close()








# f = open("display_pixel_config.csv", "r")
# print(f.read()) 
