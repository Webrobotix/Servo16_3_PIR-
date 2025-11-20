# Servo16_3_PIR Function Index

**16-Channel RC Servo Controller with PIR Motion Sensor Integration**

*Processing Code Documentation - Webrobotix 2025*
*Line Numbers Verified and Corrected*

---

## Table of Contents

- [Core Setup and Loop Functions](#core-setup-and-loop-functions)
- [PIR Motion Sensor Functions](#pir-motion-sensor-functions)
- [Sequence Control Functions](#sequence-control-functions)
- [Mouse and Keyboard Input Handlers](#mouse-and-keyboard-input-handlers)
- [Sequence Recording Functions](#sequence-recording-functions)
- [Arduino Sketch Export Function](#arduino-sketch-export-function)
- [Serial Communication Functions](#serial-communication-functions)
- [Servo Control Functions](#servo-control-functions)
- [Label Editing Functions](#label-editing-functions)
- [File Management Functions](#file-management-functions)
- [Settings File Functions](#settings-file-functions)
- [Keyframe File Functions](#keyframe-file-functions)
- [UI Creation and Display Functions](#ui-creation-and-display-functions)
- [Custom Classes](#custom-classes)
- [Summary Statistics](#summary-statistics)

---

## Core Setup and Loop Functions

### `setup()` (Lines 242-271)

Initializes the application window, UI elements, servo positions, and serial connection. Loads settings and keyframes from files. Sets all servos to inactive state on startup.

**Coordinates:**
- Window Size: `1440 x 800`

---

### `draw()` (Lines 273-350)

Main rendering loop that updates the display every frame. Handles connection checks, PIR status requests, and UI element rendering. Manages sequence playback and serial communication.

**Text Elements:**
- Title "Servo16 + PIR" at `(740, 15)` - size 24 (Line 202)
- "Webrobotix 2025" at `(1435, 780)` - size 16 (Line 205)
- "Active Servos: X/16" at `(65, 720)` - size 16 (Line 224)
- "PWM Shield: ENABLED/DISABLED" at `(250, 720)` - size 16 (Line 225)

---

## PIR Motion Sensor Functions

### `drawPIRPanel()` (Lines 352-397)

Renders the PIR control panel with status indicator, buttons, and cooldown slider. Shows motion detection state with pulsing visual effect.

**Coordinates:**
- Panel Rectangle: `(880, 600)` size `320 x 140` (Line 257)

**Text Elements:**
- "PIR Motion Sensor" at `(890, 610)` - size 16 (Line 263)
- Motion state at `(indicatorX + 15, indicatorY + 3)` = `(1065, 613)` - size 12 (Line 276)
- "Status: ENABLED/DISABLED" at `(890, 635)` - size 14 (Line 279)
- "Auto-Play: ON/OFF" at `(890, 655)` - size 14 (Line 280)
- "Cooldown (ms):" at `(890, 675)` - size 14 (Line 282)
- Cooldown value at `(1120, 700)` - size 14 black (Line 285)

**Visual Elements:**
- Motion indicator circle at `(1050, 620)` - diameter 20px (pulsing) (Lines 265-274)

**Buttons:**
- PIR Enable at `(890, 700)` size `90 x 30` (Line 290)
- PIR Auto-Play at `(990, 700)` size `90 x 30` (Line 294)

**Sliders:**
- PIR Cooldown at `(990, 670)` size `200 x 20` - range 1000-30000ms (Line 283)

---

### `requestPIRStatus()` (Lines 399-403)

Sends command to Arduino to retrieve current PIR sensor status.

---

### `setPIREnabled(boolean enable)` (Lines 405-413)

Enables or disables the PIR motion sensor. Sends enable/disable command to Arduino via serial.

---

### `setPIRCooldown(int cooldown)` (Lines 415-420)

Sets the cooldown period for PIR motion detection. Updates both local variable and Arduino setting.

---

## Sequence Control Functions

### `drawSequenceControls()` (Lines 422-462)

Renders the sequence recording panel with all controls. Displays keyframe count, recording/playback status, and timing sliders.

**Coordinates:**
- Panel Rectangle: `(50, 600)` size `800 x 140` (Line 323)

**Text Elements:**
- "Sequence Recording Panel" at `(60, 610)` - size 16 (Line 329)
- "Keyframes: X" at `(60, 630)` - size 14 (Line 332)
- "Recording: ON/OFF" at `(150, 630)` - size 14 (Line 333)
- "Playing: ON/OFF" at `(250, 630)` - size 14 (Line 334)
- "Movement Speed (ms):" at `(60, 655)` - size 14 (Line 336)
- Speed value at `(417, 660)` - size 14 (Line 338)
- "Delay After Move (ms):" at `(530, 660)` - size 14 (Line 341)
- Delay value at `(817, 660)` - size 14 (Line 343)
- "Loaded: [filename]" at `(400, 770)` - size 14 black (Line 347)

**Buttons:**
- Record at `(60, 680)` size `80 x 30` (Lines 350-352)
- Add Frame at `(150, 680)` size `80 x 30` (Line 354)
- Play at `(240, 680)` size `80 x 30` (Line 355)
- Clear at `(330, 680)` size `80 x 30` (Line 356)
- Export at `(420, 680)` size `80 x 30` (Line 357)
- Save Keys at `(510, 680)` size `90 x 30` (Line 358)
- Load Keys at `(610, 680)` size `90 x 30` (Line 359)

**Sliders:**
- Speed at `(200, 650)` size `150 x 20` - range 100-5000ms (Line 337)
- Delay at `(600, 650)` size `150 x 20` - range 0-3000ms (Line 342)

---

### `drawSequenceStatus()` (Lines 464-471)

Displays temporary status messages for sequence operations (3-second duration).

**Text Elements:**
- Status message at `(400, 720)` - size 14 - color RGB(200, 0, 100) (Line 369)

---

### `drawSketchNamingDialog()` (Lines 473-497)

Shows modal dialog for entering Arduino sketch export name. Displays target hardware configuration.

**Coordinates:**
- Dialog Box: centered at `(width/2 - 250, height/2 - 120)` = `(470, 280)` size `500 x 240` with rounded corners (radius 10) (Line 377)

**Text Elements:**
- "Export Arduino Sketch" at `(width/2, height/2 - 80)` = `(720, 320)` - size 16 (Line 383)
- "Sketch Name: [name]_" at `(width/2, height/2 - 50)` = `(720, 350)` - size 16 (Line 384)
- "Target Hardware:" at `(width/2, height/2 - 20)` = `(720, 380)` - size 14 (Line 387)
- Hardware type at `(width/2, height/2 + 5)` = `(720, 405)` - size 14 (Line 388)
- Instructions at `(width/2, height/2 + 25)` = `(720, 425)` - size 14 (Line 389)
- "Press ENTER to export, ESC to cancel" at `(width/2, height/2 + 50)` = `(720, 450)` - size 16 (Line 391)
- Validation hint at `(width/2, height/2 + 75)` = `(720, 475)` - size 12 (Line 392)

---

## Mouse and Keyboard Input Handlers

### `mousePressed()` (Lines 499-652)

Handles all mouse click events for buttons, sliders, and UI elements. Manages file selection pagination and dialog interactions.

---

### `mouseReleased()` (Lines 664-667)

Releases all slider locks when mouse button is released. Updates PIR cooldown setting if slider was dragged.

---

### `mouseDragged()` (Lines 668-685)

Updates slider positions and servo values during drag operations. Handles speed, delay, and PIR cooldown slider dragging.

---

### `keyPressed()` (Lines 687-784)

Processes keyboard input for text entry dialogs and shortcuts. Handles ENTER/ESC keys for dialog confirmation/cancellation.

**Keyboard Shortcuts:**
- `R` - Toggle recording (Lines 641-642)
- `K` - Add keyframe (Lines 643-644)
- `P` - Play sequence (Lines 645-646)
- `C` - Clear sequence (Lines 647-648)
- `S` - Toggle PWM Shield (Lines 649-650)

---

## Sequence Recording Functions

### `togglePWMShield()` (Lines 787-791)

Toggles between PWM Shield and Standard Servo mode for export.

---

### `countActiveServos(ServoKeyframe kf)` (Lines 793-799)

Counts how many servos are active in a given keyframe.

---

### `toggleRecording()` (Lines 801-809)

Starts or stops sequence recording mode.

---

### `addKeyframe()` (Lines 811-822)

Creates and adds a new keyframe to the sequence with current servo positions. Captures speed, delay, and active servo states.

---

### `playSequence()` (Lines 824-829)

Starts or stops playback of the recorded sequence.

---

### `clearSequence()` (Lines 843-848)

Clears all keyframes from the current sequence.

---

### `startSketchNaming()` (Lines 850-858)

Initiates the Arduino sketch export dialog.

---

### `updateSequencePlayback()` (Lines 860-928)

Updates servo positions during sequence playback. Implements smooth movement interpolation with easing. Manages timing between keyframes.

---

### `easeInOutCubic(float t)` (Lines 930-937)

Provides cubic easing function for smooth servo movements.

**Formula:**
```
if (t < 0.5): return 4.0 * t * t * t
else: return 1.0 + ((2.0 * t - 2.0)^3) / 2.0
```

---

## Arduino Sketch Export Function

### `exportArduinoSketch(String sketchName)` (Lines 939-1247)

Generates complete Arduino code (.ino file) from recorded sequence. Supports both PWM Shield and Standard Servo implementations. Includes PIR motion sensor integration with cooldown logic.

**Features:**
- PWM Shield support (Adafruit 16-Channel 12-bit PWM Servo Driver)
- Standard Arduino Servo Library support
- PIR motion sensor integration
- Cooldown period management
- Smooth servo movement with easing
- Complete keyframe sequence export

---

## Serial Communication Functions

### `checkForNewSerialPorts()` (Lines 1116-1132)

Monitors for serial port disconnections and attempts reconnection.

---

### `establishConnection()` (Lines 1134-1184)

Scans available serial ports and attempts to connect to Arduino. Sends test command to verify connection.

**Serial Settings:**
- Baud Rate: `115200` (Line 1156)
- Timeout: 5000ms

---

### `readSerialData()` (Lines 1291-1356)

Parses incoming serial data from Arduino. Updates servo positions, limits, and PIR status. Handles motion detection events and triggers auto-play if enabled.

**Serial Protocol:**
- `PO:servoNum:position` - Position update (Lines 1296-1302)
- `MI:servoNum:minLimit` - Min limit update (Lines 1303-1307)
- `MA:servoNum:maxLimit` - Max limit update (Lines 1308-1312)
- `CE:servoNum:centerPos` - Center position update (Lines 1313-1315)
- `AC:servoNum:active` - Active state update (Lines 1316-1318)
- `RE:servoNum` - Reset confirmation (Lines 1319-1326)
- `PIR:MOTION_DETECTED` - Motion detected (Lines 1327-1333)
- `PIR:STATUS:enabled:cooldown:state` - PIR status update (Lines 1334-1341)
- `PIR:ENABLED` / `PIR:DISABLED` - PIR state change (Lines 1342-1346)
- `PIR:COOLDOWN:value` - Cooldown update (Lines 1347-1349)

---

## Servo Control Functions

### `centerServo(int servoNum)` (Lines 1186-1190)

Moves specified servo to its center position.

---

### `setCenterPosition(int servoNum)` (Lines 1192-1197)

Sets the center position for a servo to its current position.

**Command:** `SETCENTER:servoNum:position` (Line 1196)

---

### `setMinLimit(int servoNum)` (Lines 1199-1205)

Sets the minimum angle limit for a servo.

**Command:** `SETMINLIMIT:servoNum:position` (Line 1204)

---

### `setMaxLimit(int servoNum)` (Lines 1207-1213)

Sets the maximum angle limit for a servo.

**Command:** `SETMAXLIMIT:servoNum:position` (Line 1212)

---

### `resetLimits(int servoNum)` (Lines 1215-1223)

Resets servo to default limits (0-180°) and center (90°).

**Command:** `RESET:servoNum` (Line 1222)

---

### `updateServoPosition(int servoNum, int position)` (Lines 1225-1230)

Sends position command to Arduino for specified servo.

**Command:** `S:servoNum:position` (Line 1228)

---

### `toggleServoActive(int servoNum)` (Lines 1360-1365)

Toggles the active/inactive state of a servo.

**Command:** `ACTIVE:servoNum:state` (Line 1363)

---

### `setAllServosActive()` (Lines 1367-1373)

Activates all servos at once.

**Command:** `ALLACTIVE` (Line 1372)

---

### `setAllServosInactive()` (Lines 1375-1381)

Deactivates all servos at once.

**Command:** `ALLINACTIVE` (Line 1380)

---

### `manualReconnect()` (Lines 1383-1396)

Manually triggers serial port reconnection.

---

## Label Editing Functions

### `startLabelEdit(int servoNum)` (Lines 1358-1363)

Initiates label editing dialog for specified servo.

---

### `initializeLabels()` (Lines 1545-1549)

Sets default labels for all servos ("Servo 0" through "Servo 15").

---

## File Management Functions

### `updateSavedFilesList(String operation)` (Lines 1398-1416)

Scans data directory and builds list of saved settings or keyframe files.

**File Patterns:**
- Settings: `*_settings.txt`
- Keyframes: `*_keyframes.txt`

---

### `startFileNaming()` (Lines 1418-1424)

Initiates save dialog (uses existing filename or prompts for new one).

---

### `startFileNamingAs()` (Lines 1426-1429)

Initiates "Save As" dialog with optional pre-filled filename.

---

### `startFileSelection(String operation)` (Lines 1431-1447)

Shows file selection dialog for load/delete operations.

**Operations:** `load`, `delete`, `loadKeyframes`

---

### `isValidFileName(String name)` (Lines 1449-1452)

Validates filename format (alphanumeric, hyphens, underscores only).

**Regex:** `[a-zA-Z0-9\-_]+` (Line 1451)

---

## Settings File Functions

### `saveSettingsToFileWithName(String fileName)` (Lines 1454-1478)

Saves all servo settings (limits, centers, labels, active states) to file.

**File Format:**
```
# Servo Settings: fileName
# Saved: date
# Format: servoNum:minLimit:maxLimit:centerPos:active
servoNum:minLimit:maxLimit:centerPos:active
...
L:servoNum:labelText
```

---

### `loadSettingsFromFileWithName(String fileName)` (Lines 1480-1546)

Loads servo settings from file and applies them to all servos. Sends settings to Arduino if connected.

---

### `deleteSettingsFileWithName(String fileName)` (Lines 1548-1560)

Deletes a settings file from disk.

---

### `loadSettingsFromFile()` (Lines 1634-1641)

Loads the default settings file on startup.

**Default File:** `default_settings.txt`

---

### `sendAllSettingsToArduino()` (Lines 1643-1655)

Transmits all current servo settings to Arduino via serial.

---

## Keyframe File Functions

### `saveKeyframesToFile()` (Lines 1562-1598)

Saves current sequence keyframes to timestamped file. Stores as last loaded file for auto-loading.

**File Format:**
```
# Keyframe Sequence Data
# Saved: date
# Total Keyframes: X
# Format: KF:speed:delay:name:pos0,pos1,...:active0,active1,...
KF:speed:delay:name:positions:activeStates
```

---

### `loadKeyframesFromFileWithName(String fileName)` (Lines 1600-1648)

Loads keyframe sequence from specified file. Parses positions, active states, speed, and delay for each keyframe.

---

### `loadKeyframesFromFile()` (Lines 1650-1665)

Automatically loads the last used keyframe file on startup.

**Reference File:** `last_keyframes.txt`

---

## UI Creation and Display Functions

### `createUI()` (Lines 1551-1587)

Creates all UI elements (sliders, buttons) with proper positioning. Initializes sequence control buttons and PIR controls.

**Servo Controls (16 servos in 4×4 grid):**
- Starting position: `(50, 70)` (Line 1556)
- Layout: 4 columns × 4 rows
- Column spacing: 350px (SLIDER_WIDTH + MARGIN = 300 + 50)
- Row spacing: 140px (ROW_HEIGHT)

**Each servo panel includes:**
- Slider at `(x, y)` size `300 x 30` (Line 1559)
- Center button at `(x, y + 70)` size `60 x 30` (Line 1562)
- Set Ctr button at `(x, y + 35)` size `60 x 30` (Line 1563)
- Set Min button at `(x + 65, y + 35)` size `60 x 30` (Line 1564)
- Set Max button at `(x + 130, y + 35)` size `60 x 30` (Line 1565)
- Reset button at `(x + 195, y + 35)` size `50 x 30` (Line 1566)
- Label button at `(x + 250, y + 35)` size `50 x 30` (Line 1567)
- Active button at `(x + 65, y + 70)` size `60 x 30` (Line 1568)

**Global Control Buttons:**
- All Active at `(215, 750)` size `100 x 40` (Line 1571)
- All Inactive at `(340, 750)` size `100 x 40` (Line 1572)
- Connect at `(165, 5)` size `80 x 30` (Line 1573)

**Settings Buttons:**
- Save at `(720, 750)` size `80 x 40` (Line 1575)
- Save As at `(810, 750)` size `80 x 40` (Line 1576)
- Load at `(900, 750)` size `80 x 40` (Line 1577)
- Delete at `(990, 750)` size `80 x 40` (Line 1578)
- PWM Shield at `(1080, 750)` size `120 x 40` (Line 1580)

**Sequence Control Buttons:**
- Record at `(60, 680)` size `80 x 30` (Line 1582)
- Add Frame at `(150, 680)` size `80 x 30` (Line 1583)
- Play at `(240, 680)` size `80 x 30` (Line 1584)
- Clear at `(330, 680)` size `80 x 30` (Line 1585)
- Export at `(420, 680)` size `80 x 30` (Line 1586)
- Save Keys at `(510, 680)` size `90 x 30` (Line 1587)
- Load Keys at `(610, 680)` size `90 x 30` (Line 1588)

**Sliders:**
- Speed at `(200, 650)` size `150 x 20` - range 100-5000 (Lines 1590-1591)
- Delay at `(600, 650)` size `150 x 20` - range 0-3000 (Lines 1592-1593)

**PIR Controls:**
- PIR Enable button at `(890, 700)` size `90 x 30` (Line 1595)
- PIR Auto-Play button at `(990, 700)` size `90 x 30` (Line 1596)
- PIR Cooldown slider at `(990, 670)` size `200 x 20` - range 1000-30000 (Lines 1597-1598)

---

### `drawServoControl(int servoNum)` (Lines 1599-1632)

Renders individual servo control panel with slider and buttons. Shows servo status, position, and limits.

**Layout calculation:**
```
row = servoNum / 4  (Line 1600)
col = servoNum % 4  (Line 1601)
x = 50 + col × 350  (Line 1602)
y = 70 + row × 140  (Line 1603)
```

**Text Elements:**
- Servo label and position at `(x, y - 10)` - size 14 (Line 1610)
- Limits info at `(x + 135, y + 90)` - size 12 (Lines 1613-1614)
- Format: "Min: X° | Max: X° | Ctr: X°"

---

### `drawSettingsStatus()` (Lines 1634-1646)

Displays temporary status messages for settings operations. Shows currently loaded settings filename.

**Text Elements:**
- Status message at `(880, 700)` - size 14 - color RGB(0, 100, 200) (Line 1638)
- "Current file: [filename]" at `(880, 720)` - size 18 - color RGB(100) (Line 1644)

---

### `drawConnectionStatus()` (Lines 1648-1670)

Displays serial connection indicator and auto-scan countdown. Shows connection status messages.

**Visual Elements:**
- Status indicator circle at `(16, 16)` - diameter 12px (Line 1658)
- Auto-scan countdown at `(108, 27)` - size 12 - color RGB(100) (Lines 1662-1663)
- Connection status at `(90, 12)` - size 14 - color RGB(0, 100, 200) (Line 1667)

---

### `drawLabelEditDialog()` (Lines 1672-1687)

Renders modal dialog for editing servo labels.

**Coordinates:**
- Dialog Box: centered at `(520, 320)` size `400 x 160` with rounded corners (radius 10) (Line 1676)

**Text Elements:**
- "Edit Label for Servo X" at `(720, 360)` - size 16 (Line 1681)
- "Current: [label]" at `(720, 380)` - size 16 (Line 1682)
- "New: [text]_" at `(720, 410)` - size 16 (Line 1683)
- Instructions at `(720, 440)` - size 16 (Line 1684)

---

### `drawFileNamingDialog()` (Lines 1689-1703)

Renders modal dialog for entering new settings filename.

**Coordinates:**
- Dialog Box: centered at `(520, 320)` size `400 x 160` with rounded corners (radius 10) (Line 1693)

**Text Elements:**
- "Enter Settings File Name" at `(720, 360)` - size 16 (Line 1698)
- "Name: [text]_" at `(720, 390)` - size 16 (Line 1699)
- "Press ENTER to save, ESC to cancel" at `(720, 420)` - size 16 (Line 1700)
- Validation hint at `(720, 440)` - size 16 (Line 1701)

---

### `drawFileSelectionDialog()` (Lines 1705-1770)

Renders paginated file selection dialog with navigation buttons. Shows available files for load/delete operations.

**Coordinates:**
- Dialog Box: centered at `(420, 200)` size `600 x 400` with rounded corners (radius 10) (Line 1709)

**Text Elements:**
- Dialog title at `(720, 230)` - size 18 (Line 1716)
- "Page X of Y" at `(720, 260)` - size 14 (Line 1722)
- File list items starting at y = 290, spacing 30px - size 13 (Line 1733)
- Instructions at `(720, 490)` - size 14 (Line 1742)
- Selected file at `(720, 510)` - size 12 - color RGB(0, 100, 200) (Line 1746)

**Buttons:**
- "◄ Prev" at `(450, 220)` size `120 x 30` with rounded corners (radius 5) (Lines 1750-1755)
- "Next ►" at `(870, 220)` size `120 x 30` with rounded corners (radius 5) (Lines 1758-1763)

**File Selection:**
- Selection highlight at `(width/2 - 280, fileY - 12)` size `560 x 24` with rounded corners (radius 5) (Lines 1726-1728)
- 10 files per page (Constant FILES_PER_PAGE = 10, Line 57)

---

## Custom Classes

### ServoKeyframe Class (Lines 143-168)

**Constructors:**
- `ServoKeyframe()` - Default constructor (Lines 148-163)
- `ServoKeyframe(int spd, int dly, String nm)` - Constructor with parameters (Lines 165-168)

**Properties:**
- `int[] positions` - Array of 16 servo positions (0-180°) (Line 144)
- `boolean[] activeServos` - Array of 16 active states (Line 145)
- `int speed` - Movement duration in milliseconds (Line 146)
- `int delay` - Delay after movement in milliseconds (Line 147)
- `String name` - Keyframe name/label (Line 148)

**Purpose:** Stores snapshot of all servo positions and states with timing parameters for sequence playback.

---

### Slider Class (Lines 1772-1818)

**Constructor:** `Slider(float x, float y, float w, float h, float min, float max)` (Lines 1776-1783)

**Properties:**
- `float x, y, w, h` - Position and dimensions (Line 1773)
- `float min, max, value` - Value range and current value (Line 1774)
- `boolean locked` - Drag lock state (Line 1775)

**Methods:**
- `display(boolean active)` (Lines 1785-1787) - Renders slider with value display
- `display(boolean active, boolean showValue)` (Lines 1789-1802) - Renders slider with optional value display
- `display()` (Lines 1804-1806) - Default display method
- `isOver()` (Lines 1808-1811) - Checks if mouse is over slider handle
- `updatePosition(float mx)` (Lines 1813-1815) - Updates slider value based on mouse position
- `setValue(float v)` (Lines 1817-1819) - Sets slider value programmatically
- `getValue()` (Lines 1821-1823) - Returns current slider value

**Features:**
- Rounded slider track
- Circular handle with value display
- Mouse hover detection
- Value constraints (min/max)

---

### Button Class (Lines 1826-1858)

**Constructor:** `Button(float x, float y, float w, float h, String label, color buttonColor)` (Lines 1830-1837)

**Properties:**
- `float x, y, w, h` - Position and dimensions (Line 1827)
- `String label` - Button text (Line 1828)
- `color buttonColor` - Button color (Line 1829)

**Methods:**
- `display()` (Lines 1839-1848) - Renders active button with hover effect
- `displayInactive()` (Lines 1850-1859) - Renders inactive/disabled button
- `isOver()` (Lines 1861-1863) - Checks if mouse is over button

**Features:**
- Hover color transition (lerpColor with 0.2 factor)
- Rounded corners (radius h/4)
- Centered text label
- Inactive state styling

---

## Summary Statistics

### 📊 Code Metrics

- **Total Functions:** 62 main functions + 11 class methods = **73 total**
- **Lines of Code:** 1,863 lines total
- **Window Dimensions:** 1440 x 800 pixels
- **Hardware Support:** Arduino with PWM Shield or Standard Servo Library
- **Total Classes:** 3 (ServoKeyframe, Slider, Button)
- **Total Constants:** 28 color and layout constants

### 🎯 Key Features

1. **16-Channel Servo Control**
   - Individual servo limits (min/max angles)
   - Custom center positions
   - Independent activation/deactivation
   - Real-time position updates

2. **PIR Motion Detection**
   - Auto-play on motion detection
   - Configurable cooldown period (1-30 seconds)
   - Visual motion indicator with pulse effect
   - Enable/disable control

3. **Sequence Recording & Playback**
   - Add keyframes with current servo positions
   - Adjustable movement speed (100-5000ms)
   - Configurable delay between keyframes (0-3000ms)
   - Smooth cubic easing interpolation
   - Real-time playback visualization

4. **Arduino Sketch Export**
   - PWM Shield support (Adafruit 16-Channel)
   - Standard Arduino Servo Library support
   - Complete PIR integration
   - Standalone .ino file generation
   - Cooldown management in exported code

5. **File Management**
   - Save/load servo settings
   - Save/load keyframe sequences
   - Paginated file browser (10 files per page)
   - Auto-load last used files
   - Delete saved files

6. **Serial Communication**
   - Auto-detect and connect (115200 baud)
   - Bi-directional servo control
   - Real-time position feedback
   - PIR status updates
   - Connection monitoring with auto-reconnect

7. **Interactive GUI**
   - 16 servo control panels (4×4 grid)
   - Sliders with visual feedback
   - Color-coded buttons
   - Modal dialogs for input
   - Status messages and indicators
   - Keyboard shortcuts for quick access

### 🔧 Hardware Requirements

- **Arduino Board** (Uno, Mega, etc.)
- **Optional:** Adafruit 16-Channel 12-bit PWM Servo Shield
- **Optional:** PIR Motion Sensor (HC-SR501 or similar, connected to pin 2)
- **16 RC Servos** (standard hobby servos)
- **Power Supply** (adequate for servo load - recommend 5V 10A for 16 servos)

### 📝 File Formats

**Settings Files (`*_settings.txt`):**
```
# Servo Settings: fileName
# Saved: date
# Format: servoNum:minLimit:maxLimit:centerPos:active
0:0:180:90:0
1:0:180:90:0
...
L:0:Servo 0
L:1:Servo 1
...
```

**Keyframe Files (`*_keyframes.txt`):**
```
# Keyframe Sequence Data
# Saved: date
# Total Keyframes: X
# Format: KF:speed:delay:name:pos0,pos1,...:active0,active1,...
KF:1000:500:Keyframe 1:90,90,90,...:1,1,0,...
KF:2000:1000:Keyframe 2:120,60,90,...:1,1,0,...
...
```

### 🎮 Keyboard Shortcuts

| Key | Action | Line Reference |
|-----|--------|----------------|
| `R` | Toggle recording mode | 641-642 |
| `K` | Add keyframe to sequence | 643-644 |
| `P` | Play/pause sequence | 645-646 |
| `C` | Clear sequence | 647-648 |
| `S` | Toggle PWM Shield mode | 649-650 |

### 🔌 Serial Protocol

**Commands (Processing → Arduino):**
- `S:servoNum:position` - Set servo position
- `ACTIVE:servoNum:state` - Set servo active state
- `ALLACTIVE` - Activate all servos
- `ALLINACTIVE` - Deactivate all servos
- `SETCENTER:servoNum:position` - Set center position
- `SETMINLIMIT:servoNum:position` - Set minimum limit
- `SETMAXLIMIT:servoNum:position` - Set maximum limit
- `RESET:servoNum` - Reset servo to defaults
- `GETALL` - Request all servo states
- `PIR:ENABLE` - Enable PIR sensor
- `PIR:DISABLE` - Disable PIR sensor
- `PIR:COOLDOWN:value` - Set PIR cooldown period
- `PIR:STATUS` - Request PIR status

**Responses (Arduino → Processing):**
- `PO:servoNum:position` - Position update (Lines 1296-1302)
- `MI:servoNum:minLimit` - Min limit (Lines 1303-1307)
- `MA:servoNum:maxLimit` - Max limit (Lines 1308-1312)
- `CE:servoNum:centerPos` - Center position (Lines 1313-1315)
- `AC:servoNum:active` - Active state (Lines 1316-1318)
- `RE:servoNum` - Reset confirmation (Lines 1319-1326)
- `PIR:MOTION_DETECTED` - Motion detected (Lines 1327-1333)
- `PIR:STATUS:enabled:cooldown:state` - PIR status (Lines 1334-1341)
- `PIR:ENABLED` / `PIR:DISABLED` - PIR state (Lines 1342-1346)
- `PIR:COOLDOWN:value` - Cooldown value (Lines 1347-1349)

---

## Color Scheme

### UI Colors (Lines 34-58)

| Element | Color (RGB) | Hex | Constant Name |
|---------|-------------|-----|---------------|
| Background | (240, 240, 240) | #F0F0F0 | BG_COLOR |
| Slider | (180, 200, 220) | #B4C8DC | SLIDER_COLOR |
| Button | (144, 213, 255) | #90D5FF | BUTTON_COLOR |
| Button Hover | (80, 140, 180) | #508CB4 | BUTTON_HOVER_COLOR |
| Text | (40, 40, 40) | #282828 | TEXT_COLOR |
| Center Button | (255, 200, 100) | #FFC864 | CENTER_BUTTON_COLOR |
| Set Center Button | (255, 150, 50) | #FF9632 | SET_CENTER_BUTTON_COLOR |
| Min/Max/Reset Button | (241, 241, 241) | #F1F1F1 | MIN/MAX/RESET_BUTTON_COLOR |
| Label Button | (198, 219, 255) | #C6DBFF | LABEL_BUTTON_COLOR |
| Active Button | (100, 255, 100) | #64FF64 | ACTIVE_BUTTON_COLOR |
| Inactive Button | (255, 100, 100) | #FF6464 | INACTIVE_BUTTON_COLOR |
| Record Button | (255, 100, 100) | #FF6464 | RECORD_BUTTON_COLOR |
| Recording Button | (255, 50, 50) | #FF3232 | RECORDING_BUTTON_COLOR |
| Play Button | (100, 255, 100) | #64FF64 | PLAY_BUTTON_COLOR |
| Clear Button | (255, 150, 100) | #FF9664 | CLEAR_BUTTON_COLOR |
| Export Button | (100, 200, 255) | #64C8FF | EXPORT_BUTTON_COLOR |
| Save Settings Button | (100, 200, 100) | #64C864 | SAVE_SETTINGS_BUTTON_COLOR |
| Load Settings Button | (100, 150, 255) | #6496FF | LOAD_SETTINGS_BUTTON_COLOR |
| Delete Settings Button | (255, 100, 100) | #FF6464 | DELETE_SETTINGS_BUTTON_COLOR |
| PWM Shield Button | (255, 255, 255) | #FFFFFF | PWM_SHIELD_BUTTON_COLOR |
| Inactive Slider | (150, 150, 150) | #969696 | INACTIVE_SLIDER_COLOR |
| Inactive Button Gray | (200, 200, 200) | #C8C8C8 | INACTIVE_BUTTON_COLOR_GRAY |
| Inactive Text | (120, 120, 120) | #787878 | INACTIVE_TEXT_COLOR |
| Page Button | (100, 150, 255) | #6496FF | PAGE_BUTTON_COLOR |
| PIR Button | (255, 200, 50) | #FFC832 | PIR_BUTTON_COLOR |
| PIR Motion | (255, 50, 50) | #FF3232 | PIR_MOTION_COLOR |
| PIR Clear | (100, 255, 100) | #64FF64 | PIR_CLEAR_COLOR |

---

## Constants Reference (Lines 30-61)

```processing
NUM_SERVOS = 16                    // Total number of servos
WINDOW_WIDTH = 1280                // (Note: actual window is 1440 from size() call)
WINDOW_HEIGHT = 800
SLIDER_WIDTH = 300
SLIDER_HEIGHT = 30
BUTTON_WIDTH = 120
BUTTON_HEIGHT = 30
MARGIN = 50
ROW_HEIGHT = 140
FILES_PER_PAGE = 10               // Pagination for file browser
CONNECTION_CHECK_INTERVAL = 2000  // Auto-reconnect check (ms)
PIR_STATUS_REQUEST_INTERVAL = 2000 // PIR status polling (ms)
```

---

## Usage Workflow

### Basic Setup
1. Connect Arduino to computer via USB
2. Launch Processing sketch (press Run)
3. Wait for auto-connection (green indicator) or click "Connect" button
4. Click "All Active" to enable servos
5. Adjust servo positions using sliders

### Recording a Sequence
1. Click "Record" button (or press `R`)
2. Move servos to desired positions using sliders
3. Click "Add Frame" (or press `K`) to capture keyframe
4. Adjust speed and delay sliders as needed for next keyframe
5. Repeat steps 2-4 for each keyframe in your sequence
6. Click "Record" again to stop recording (or press `R`)
7. Click "Save Keys" to save sequence to file

### Playing a Sequence
1. Click "Play" button (or press `P`)
2. Watch servos move smoothly through keyframes
3. Click "Play" again to stop playback (or press `P`)

### Exporting to Arduino
1. Create and test your sequence
2. Click "Export" button
3. Enter sketch name (alphanumeric, hyphens, underscores only)
4. Toggle "PWM Shield" button if needed to select hardware type
5. Press ENTER to generate .ino file (saved to /data folder)
6. Open exported file in Arduino IDE
7. Upload to Arduino for standalone operation

### PIR Integration
1. Enable PIR sensor by clicking "PIR: OFF" button (turns green)
2. Adjust cooldown period using slider (1-30 seconds, default 5000ms)
3. Toggle "Auto: OFF" to enable auto-play on motion detection
4. When motion detected, sequence plays automatically (if auto-play enabled)
5. Cooldown prevents repeated triggers during specified period

### Saving/Loading Settings
1. Adjust servo limits, centers, and labels as desired
2. Click "Save" to save to current file (or "Save As" for new file)
3. Click "Load" to browse and load saved settings
4. Click "Delete" to remove unwanted settings files
5. Settings auto-load from "default_settings.txt" on startup

---

## Troubleshooting

### Connection Issues
- **No serial ports found:** Check USB cable and Arduino drivers installed
- **Connection lost:** Check for loose USB connection, auto-reconnect attempts every 2 seconds
- **Auto-reconnect fails:** Click "Connect" button manually
- **Wrong port selected:** Disconnect other serial devices, restart Processing sketch

### Servo Issues
- **Servos not moving:** Check if servo is active (green "Active" button, not red "Inactive")
- **Erratic movement:** Check power supply capacity (16 servos can draw 10+ amps)
- **Limited range:** Check min/max limits aren't too restrictive, click "Reset" to restore 0-180°
- **Servo jitter:** Reduce serial communication speed or check servo power supply

### PIR Issues
- **No motion detection:** Check PIR sensor wiring (VCC to 5V, GND to GND, Signal to pin 2)
- **False triggers:** Adjust PIR sensitivity potentiometer on sensor module
- **Cooldown not working:** Verify cooldown value sent to Arduino (check serial monitor)
- **Auto-play not triggering:** Ensure "Auto: ON" button is green and sequence has keyframes

### File Issues
- **Can't save files:** Check write permissions on sketch /data folder
- **Files not loading:** Verify file format matches expected structure (see File Formats section)
- **Missing keyframes:** Ensure sequence saved before exiting Processing
- **Corrupted files:** Delete and recreate, check for special characters in filenames

### Performance Issues
- **Slow UI:** Reduce number of active servos or close other applications
- **Laggy playback:** Check serial connection quality, reduce keyframe complexity
- **Serial buffer overflow:** Add delays between commands in exported Arduino sketch

---

## License

MIT License - Copyright (c) 2025 Webrobotix

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

**⚠️ WARNING:** This program controls mechanical devices that may move suddenly and with force. Use at your own risk.

---

## Credits

**Developer:** Webrobotix  
**Version:** v2.0 with PIR Integration (formerly v1.7)  
**Year:** 2020-2025  
**Platform:** Processing 3.x+  
**Language:** Java (Processing)  
**File:** Servo16_3_PIR.txt  
**Total Lines:** 1,863  

---

## Changelog

### v2.0 (2025)
- ✨ Added PIR motion sensor integration
- ✨ Motion-triggered sequence playback
- ✨ Configurable cooldown period (1-30 seconds)
- ✨ PIR enable/disable control with visual indicator
- ✨ Visual motion detection indicator with pulse effect
- 🎨 Updated UI with dedicated PIR control panel (320x140px)
- 🔧 Serial protocol extended with PIR commands
- 📝 Enhanced Arduino sketch export with PIR support

### v1.7
- Initial PIR sensor support foundation
- Enhanced sequence recording capabilities
- Improved Arduino sketch export functionality
- Added keyframe save/load features

---

## Additional Resources

- **Processing:** https://processing.org (Download and documentation)
- **Arduino:** https://arduino.cc (IDE and tutorials)
- **Adafruit PWM Shield:** https://www.adafruit.com/product/1411 (16-Channel 12-bit)
- **PIR Sensor Guide:** HC-SR501 documentation and wiring diagrams
- **Webrobotix:** Creator's documentation and support

---

## Technical Notes

### Window Size Discrepancy
- Constant `WINDOW_WIDTH = 1280` (Line 31)
- Actual window: `size(1440, 800)` (Line 171)
- UI elements positioned for 1440px width

### Serial Communication
- Baud rate: 115200 (Line 1156)
- Buffer cleared with `bufferUntil('\n')` (Line 1157)
- Connection timeout: 5000ms (50 iterations × 100ms)

### File Storage
- All files saved to /data subfolder in sketch directory
- Automatic timestamp format: `keyframes_MMDDYYYY_HHmmss`
- Last used files tracked for auto-loading on startup

### Easing Function
- Cubic easing (Lines 804-811)
- Smooth acceleration/deceleration
- Applied to all sequence playback movements

---

*Generated from Servo16_3_PIR.txt - Webrobotix 2020-2025*  
*Complete Documentation for Processing Sketch with PIR Motion Sensor Integration*  
*Line Numbers Verified Against Source Code*  
*Last Updated: November 2025*
