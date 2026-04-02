# esp32-emulator-

ESP32 emulator playground / experiments.

## What this is
This repository aims to emulate (or partially emulate) ESP32 behavior so you can:
- run and debug ESP32-style code on a desktop machine,
- test logic without flashing hardware,
- prototype peripherals and timing behavior.

> Status: early/WIP. APIs and behavior may change.

## Features (planned / in progress)
- Basic SDK-style stubs (GPIO, delay/timers, logging)
- Event loop / task scheduling (FreeRTOS-like) stubs
- Peripheral simulation hooks (UART/I2C/SPI)
- Deterministic time for repeatable tests
- Optional unit-test integration

## Repository structure
(Adjust these as you add files)
- `src/` – emulator core and stubs
- `examples/` – example sketches/programs
- `tests/` – unit/integration tests
- `docs/` – additional documentation

## Getting started
### Prerequisites
- A C/C++ toolchain (or whatever language this repo uses)
- `git`

### Build / run
Because this project is still being set up, there may not be a build script yet.

Once you add a build system, document it here, for example:
```sh
# configure
cmake -S . -B build

# build
cmake --build build

# run (example)
./build/esp32_emulator
```

## Usage
- Put your ESP32-style application code under `examples/` (or `src/`).
- Use the provided stubs to replace hardware calls.
- Add tests under `tests/` to validate behavior.

## Roadmap
- [ ] Define minimal API surface compatible with common Arduino-ESP32 / ESP-IDF patterns
- [ ] Add a simple scheduler / timing model
- [ ] Add GPIO + UART simulation
- [ ] Add CI (build + tests)

## Contributing
PRs welcome. If you’re adding a new subsystem, please include:
- a small example,
- basic tests (if possible),
- notes in `docs/`.

