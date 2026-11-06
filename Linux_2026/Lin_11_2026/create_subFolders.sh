
#!/bin/bash

# Linux Internals - Directory Structure

#ROOT="/home/exin/Workspace/kernelInternals"
ROOT="/home/exin/Workspace/LinuxInternals/Linux_2026/Lin_11_2026"

# Navigate to root directory
#mkdir -p "$ROOT"
cd "$ROOT" || exit 1

folders=(
    "01_Linux_Architecture"
    "02_Process_Management"
    "03_Memory_Management"
    "04_Linux_IPC"
    "05_Multithreading_Synchronization"
    "06_File_System_Internals"
    "07_Linux_Kernel_Internals"
    "08_Hardware_Embedded_Linux"
    "09_Linux_Networking_Internals"
    "10_Debugging_Performance_Security"
    "11_Linux_Advanced_Internals"
)

for folder in "${folders[@]}"; do
    mkdir -p "$folder"
    echo "[CREATED] $ROOT/$folder"
done

echo ""
echo "Linux Internals directory structure created successfully!"

