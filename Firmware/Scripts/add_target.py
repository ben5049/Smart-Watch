import os
import sys
import shutil

newFileContents = ""
fileName = "..\\Middlewares\\Third_Party\\Infineon_Wireless_Connectivity\\pal\\targets\\TARGET_STM32\\Inc\\stm32_cyhal_common.h"

try:
    file = open(fileName, "r")

    targetFound = False
    
    for line in file:
        if "STM32U5G9xx" in line:
            targetFound = True

    file.close()
    
    if not targetFound:

        file = open(fileName, "r")
        
        for line in file:
            if "STM32U5A9xx" in line:
                newFileContents += line[:-1] + "   || \\\n    defined (STM32U5G9xx)\n"
            else:
                newFileContents += line
                
        file.close()

        file = open(fileName, "w")
        file.write(newFileContents)
        file.close()
        
except FileNotFoundError:
    print(f"'{fileName}' not found")



newFileContents = ""
fileName = "..\\Middlewares\\Third_Party\\Infineon_Wireless_Connectivity\\pal\\hal\\include\\cyhal.h"

try:
    file = open(fileName, "r")

    targetFound = False
    
    for line in file:
        if "#define CY_USING_HAL" in line:
            targetFound = True
            break

    file.close()
    
    if not targetFound:

        file = open(fileName, "r")
        
        newFileContents = "#define CY_USING_HAL\n" + file.read()
                
        file.close()

        file = open(fileName, "w")
        file.write(newFileContents)
        file.close()
        
except FileNotFoundError:
    print(f"'{fileName}' not found")





newFileContents = ""
fileName = "..\\Middlewares\\Third_Party\\Infineon_Wireless_Connectivity\\pal\\abstraction-rtos\\source\\cy_worker_thread.c"

try:
    file = open(fileName, "r")

    targetFound = False
    
    for line in file:
        if "#define CY_USING_HAL" in line:
            targetFound = True
            break

    file.close()
    
    if not targetFound:

        file = open(fileName, "r")
        
        newFileContents = "#define CY_USING_HAL\n" + file.read()
                
        file.close()

        file = open(fileName, "w")
        file.write(newFileContents)
        file.close()
        
except FileNotFoundError:
    print(f"'{fileName}' not found")




newFileContents = ""
fileName = "..\\Middlewares\\Third_Party\\Infineon_Wireless_Connectivity\\netxduo-network-interface-integration/source/cy_netxduo.c"

try:
    file = open(fileName, "r")

    targetFound = False
    
    for line in file:
        if "#define CY_DHCP_SERVER_DISABLE" in line:
            targetFound = True
            break

    file.close()
    
    if not targetFound:

        file = open(fileName, "r")
        
        newFileContents = "#define CY_DHCP_SERVER_DISABLE\n" + file.read()
                
        file.close()

        file = open(fileName, "w")
        file.write(newFileContents)
        file.close()
        
except FileNotFoundError:
    print(f"'{fileName}' not found")



folderName = "..\\Middlewares\\Third_Party\\Infineon_Wireless_Connectivity\\ARM"

try:
    shutil.rmtree(folderName)
except OSError as e:
##    print("Error: %s - %s." % (e.filename, e.strerror))
    pass






