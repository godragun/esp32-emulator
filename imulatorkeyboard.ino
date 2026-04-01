// ESP32-S3 USB HID Keyboard (wired) — auto-runs on plug-in.
//
// On boot (USB plug-in / reset) it opens CMD and types a message.
// No buttons required.

#include <Arduino.h>

#include "USB.h"
#include "USBHIDKeyboard.h"

static constexpr uint32_t STARTUP_DELAY_MS = 2000; // increase if the PC is slow to enumerate USB
static constexpr uint32_t PS_FOCUS_DELAY_MS = 1100;  // increase if PowerShell opens but doesn't receive text
static constexpr uint32_t BETWEEN_COMMANDS_MS = 350; // increase if commands get skipped

USBHIDKeyboard Keyboard;

static bool sentOnce = false;

static void sendWinKey()
{
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.releaseAll();
}

static void typeText(const char *text)
{
  Keyboard.print(text);
}

void setup()
{
  Serial.begin(115200);
  delay(200);

  USB.begin();
  Keyboard.begin();

  Serial.println("USB HID keyboard ready.");
}

void loop()
{
  if (!sentOnce)
  {
    delay(STARTUP_DELAY_MS); // give host time to enumerate USB

    // Win+R (Run)
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(50);
    Keyboard.releaseAll();
    delay(250);

    // Start PowerShell
    typeText("powershell");
    Keyboard.write(KEY_RETURN);
    delay(PS_FOCUS_DELAY_MS); // wait for PowerShell window to appear/focus

    // Run commands
    typeText("ipconfig");
    Keyboard.write(KEY_RETURN);
    delay(BETWEEN_COMMANDS_MS);

    typeText("Write-Host \"you are a good boy\"");
    Keyboard.write(KEY_RETURN);

    sentOnce = true;
  }

  delay(10);
}