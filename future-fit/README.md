# BLE Heart Rate Monitor

A single-screen Expo app that scans for Bluetooth Low-Energy heart rate sensors,
connects to them, and displays live heart rate data.

---

## Prerequisites

- Node.js 18+
- Expo CLI: `npm install -g expo-cli`
- A **physical device** (iOS or Android) — BLE does not work in simulators/emulators
- A BLE heart rate sensor (Polar H10, Garmin HRM, Apple Watch acting as peripheral, etc.)

---

## Setup & Run

```bash
# 1. Install dependencies
npm install

# 2. Prebuild native code (required for react-native-ble-plx)
npx expo prebuild

# 3a. Run on iOS (requires Xcode + Apple Developer account)
npx expo run:ios

# 3b. Run on Android (requires Android Studio + a connected device)
npx expo run:android
```

> **Why `expo prebuild`?**  
> `react-native-ble-plx` uses native Bluetooth APIs and cannot run in Expo Go.
> `prebuild` generates the `ios/` and `android/` native folders so you can build a
> development client directly.

---

## Permissions

### iOS
`app.json` already declares the required `NSBluetooth*UsageDescription` keys.
The OS will prompt the user automatically on first scan.

### Android
- **API ≥ 31 (Android 12+):** `BLUETOOTH_SCAN`, `BLUETOOTH_CONNECT`, `ACCESS_FINE_LOCATION`
- **API < 31:** `ACCESS_FINE_LOCATION`

The app requests these at runtime before scanning.

---

## How it works

| Step | Detail |
|------|--------|
| **Scan** | `BleManager.startDeviceScan` filtered to the standard Heart Rate Service UUID `0x180D` |
| **Connect** | `connectToDevice` → `discoverAllServicesAndCharacteristics` |
| **Subscribe** | `monitorCharacteristicForService` on characteristic `0x2A37` |
| **Parse** | Bit-flag parsing per Bluetooth SIG Heart Rate Measurement spec (supports 8-bit & 16-bit HR, RR intervals) |

---

## Key Files

```
App.js          ← Entire app (single screen)
app.json        ← Expo + BLE plugin config
package.json    ← Dependencies
babel.config.js ← Babel preset
```

---

## Dependencies

| Package | Purpose |
|---------|---------|
| `react-native-ble-plx` | BLE scanning, connecting, characteristic monitoring |
| `react-native-quick-base64` | Fast base64 decode for characteristic values |
