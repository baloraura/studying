#!/usr/bin/env python3

import asyncio
from bleak import BleakScanner, BleakClient

async def explore_device():
    print("Scanning for devices...")
    devices = await BleakScanner.discover(timeout=5.0)

    if not devices:
        print("No devices found.")
        return

    # Pick the first device found
    for i in range(0, len(devices)):
        print(f"{i}: {devices[i].name}")
    
    choice = int(input("Choose your device"))
    device = devices[choice]
        
    print(f"Connecting to: {device.name} ({device.address})")

    async with BleakClient(device.address) as client:
        connected = await client.is_connected()
        print(f"Connected: {connected}")

        if connected:
            print("Discovering services and characteristics...")
            services = await client.get_services()
            for service in services:
                print(f"[Service] {service.uuid} ({service.description})")
                # if "Battery Service" in str(service):
                #     Battery_UUID = service.uuid
                for char in service.characteristics:
                    print(f"  [Characteristic] {char.uuid} — {char.properties}")

if __name__ == "__main__":
    asyncio.run(explore_device())
