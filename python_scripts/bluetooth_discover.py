#!/usr/bin/env python3 
import asyncio
from bleak import BleakScanner


async def scan_ble_devices():
    """
    Scans for bluetooth devices

    device.rssi works for now (2025) but will be deprecated in the future
    """

    print("Scanning for devices...")

    devices = await BleakScanner.discover()

    if not devices:
        print("No devices found")
    else:
        
        for device in devices:
            print(f"Name: {device.name or 'Unknown'} | Address: {device.address} | RSSI: {device.rssi} dBm")


if __name__=="__main__":
    asyncio.run(scan_ble_devices())