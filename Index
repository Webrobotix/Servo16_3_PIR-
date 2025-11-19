# Servo16_3_PIR Function Index

**16-Channel RC Servo Controller with PIR Motion Sensor Integration**

*Processing Code Documentation - Webrobotix 2025*

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

### `setup()` (Lines 173-196)

Initializes the application window, UI elements, servo positions, and serial connection. Loads settings and keyframes from files. Sets all servos to inactive state on startup.

**Coordinates:**
- Window Size: `1440 x 800`

---

### `draw()` (Lines 198-254)

Main rendering loop that updates the display every frame. Handles connection checks, PIR status requests, and UI element rendering. Manages sequence playback and serial communication.

**Text Elements:**
- Title "Servo16 + PIR" at `(740, 15)` - size 24
- "Webrobotix 2025" at `(1435, 780)` - size 16
- "Active Servos: X/16" at `(65, 720)` - size 16
- "PWM Shield: ENABLED/DISABLED" at `(250, 720)` - size 16

---

## PIR Motion Sensor Functions

### `drawPIRPanel()` (Lines 256-298)

Renders the PIR control panel with status indicator, buttons, and cooldown slider. Shows motion detection state with pulsing visual effect. Displays current PIR settings (enabled/disabled, auto-play, cooldown period).

**Coordinates:**
- Panel Rectangle: `(880, 600)` size `320 x 140`

**Text Elements:**
- "PIR Motion Sensor" at `(890, 610)` - size 16
- Motion state at `(1065, 613)` - size 12
- "Status: ENABLED/DISABLED" at `(890, 635)` - size 14
- "Auto-Play: ON/OFF" at `(890, 655)` - size 14
- "Cooldown (ms):" at `(890, 675)` - size 14
- Cooldown value at `(1120, 700)` - size 14 (black)

**Visual Elements:**
- Motion indicator circle at `(1050, 620)` - diameter 20px (pulsing)

**Buttons:**
- PIR Enable at `(890, 700)` size `90 x 30`
- PIR Auto-Play at `(990, 700)` size `90 x 30`

**Sliders:**
- PIR Cooldown at `(990, 670)` size `200 x 20` - range 1000-30000ms

---

### `requestPIRStatus()` (Lines 300-304)

Sends command to Arduino to retrieve current PIR sensor status.

---

### `setPIREnabled(boolean enable)` (Lines 306-314)

Enables or disables the PIR motion sensor. Sends enable/disable command to Arduino via serial.

---

### `setPIRCooldown(int cooldown)` (Lines 316-321)

Sets the cooldown period for PIR motion detection. Updates both local variable and Arduino setting.

---

## Sequence Control Functions

### `drawSequenceControls()` (Lines 323-365)

Renders the sequence recording panel with all controls. Displays keyframe count, recording/playback status, and timing sliders. Shows last loaded keyframe file name.

**Coordinates:**
- Panel Rectangle: `(50, 600)` size `800 x 140`

**Text Elements:**
- "Sequence Recording Panel" at `(60, 610)` - size 16
- "Keyframes: X" at `(60, 630)` - size 14
- "Recording: ON/OFF" at `(150, 630)` - size 14
- "Playing: ON/OFF" at `(250, 630)` - size 14
- "Movement Speed (ms):" at `(60, 655)` - size 14
- Speed value at `(417, 660)` - size 14
- "Delay After Move (ms):" at `(530, 660)` - size 14
- Delay value at `(817, 660)` - size 14
- "Loaded: [filename]" at `(400, 770)` - size 14 (black)

**Buttons:**
- Record at `(60, 680)` size `80 x 30`
- Add Frame at `(150, 680)` size `80 x 30`
- Play at `(240, 680)` size `80 x 30`
- Clear at `(330, 680)` size `80 x 30`
- Export at `(420, 680)` size `80 x 30`
- Save Keys at `(510, 680)` size `90 x 30`
- Load Keys at `(610, 680)` size `90 x 30`

**Sliders:**
- Speed at `(200, 650)` size `150 x 20` - range 100-5000ms
- Delay at `(600, 650)` size `150 x 20` - range 0-3000ms

---

### `drawSequenceStatus()` (Lines 367-373)

Displays temporary status messages for sequence operations (3-second duration).

**Text Elements:**
- Status message at `(400, 720)` - size 14 - color RGB(200, 0, 100)

---

### `drawSketchNamingDialog()` (Lines 375-394)

Shows modal dialog for entering Arduino sketch export name. Displays target hardware configuration (PWM Shield vs Standard Servo).

**Coordinates:**
- Dialog Box: centered at `(520, 320)` size `500 x 240` with rounded corners (radius 10)

**Text Elements:**
- "Export Arduino Sketch" at `(720, 320)` - size 16
- "Sketch Name: [name]_" at `(720, 350)` - size 16
- "Target Hardware:" at `(720, 380)` - size 14
- Hardware type at `(720, 405)` - size 14
- Instructions at `(720, 425)` - size 14
- "Press ENTER to export, ESC to cancel" at `(720, 450)` - size 16
- Validation hint at `(720, 475)` - size 12

---

## Mouse and Keyboard Input Handlers

### `mousePressed()` (Lines 396-558)

Handles all mouse click events for buttons, sliders, and UI elements. Manages file selection pagination and dialog interactions. Routes clicks to appropriate handler functions.

---

### `mouseReleased()` (Lines 560-571)

Releases all slider locks when mouse button is released. Updates PIR cooldown setting if slider was dragged.

---

### `mouseDragged()` (Lines 573-587)

Updates slider positions and servo values during drag operations. Handles speed, delay, and PIR cooldown slider dragging.

---

### `keyPressed()` (Lines 589-663)

Processes keyboard input for text entry dialogs and shortcuts. Handles ENTER/ESC keys for dialog confirmation/cancellation.

**Keyboard Shortcuts:**
- `R` - Toggle recording
- `K` - Add keyframe
- `P` - Play sequence
- `C` - Clear sequence
- `S` - Toggle PWM Shield

---

## Sequence Recording Functions

### `togglePWMShield()` (Lines 666-670)

Toggles between PWM Shield and Standard Servo mode for export.

---

### `countActiveServos(ServoKeyframe kf)` (Lines 672-678)

Counts how many servos are active in a given keyframe.

---

### `toggleRecording()` (Lines 680-688)

Starts or stops sequence recording mode.

---

### `addKeyframe()` (Lines 690-701)

Creates and adds a new keyframe to the sequence with current servo positions. Captures speed, delay, and active servo states.

---

### `playSequence()` (Lines 703-720)

Starts or stops playback of the recorded sequence.

---

### `clearSequence()` (Lines 722-727)

Clears all keyframes from the current sequence.

---

### `startSketchNaming()` (Lines 729-737)

Initiates the Arduino sketch export dialog.

---

### `updateSequencePlayback()` (Lines 739-804)

Updates servo positions during sequence playback. Implements smooth movement interpolation with easing. Manages timing between keyframes.

---

### `easeInOutCubic(float t)` (Lines 806-813)

Provides cubic easing function for smooth servo movements.

**Formula:**
```
if (t < 0.5): return 4.0 * t * t * t
else: return 1.0 + ((2.0 * t - 2.0)^3) / 2.0
```

---

## Arduino Sketch Export Function

### `exportArduinoSketch(String sketchName)` (Lines 815-1116)

Generates complete Arduino code (.ino file) from recorded sequence. Supports both PWM Shield and Standard Servo implementations. Includes PIR motion sensor integration with cooldown logic. Creates standalone animatronic controller sketch.

**Features:**
- PWM Shield support (Adafruit 16-Channel 12-bit PWM Servo Driver)
- Standard Arduino Servo Library support
- PIR motion sensor integration
- Cooldown period management
- Smooth servo movement with easing
- Complete keyframe sequence export

---

## Serial Communication Functions

### `checkForNewSerialPorts()` (Lines 1118-1134)

Monitors for serial port disconnections and attempts reconnection.

---

### `establishConnection()` (Lines 1136-1186)

Scans available serial ports and attempts to connect to Arduino. Sends test command to verify connection.

**Serial Settings:**
- Baud Rate: `115200`
- Timeout: 5000ms

---

### `readSerialData()` (Lines 1293-1358)

Parses incoming serial data from Arduino. Updates servo positions, limits, and PIR status. Handles motion detection events and triggers auto-play if enabled.

**Serial Protocol:**
- `PO:servoNum:position` - Position update
- `MI:servoNum:minLimit` - Min limit update
- `MA:servoNum:maxLimit` - Max limit update
- `CE:servoNum:centerPos` - Center position update
- `AC:servoNum:active` - Active state update
- `RE:servoNum` - Reset confirmation
- `PIR:MOTION_DETECTED` - Motion detected
- `PIR:STATUS:enabled:cooldown:state` - PIR status update
- `PIR:ENABLED` / `PIR:DISABLED` - PIR state change
- `PIR:COOLDOWN:value` - Cooldown update

---

## Servo Control Functions

### `centerServo(int servoNum)` (Lines 1188-1192)

Moves specified servo to its center position.

---

### `setCenterPosition(int servoNum)` (Lines 1194-1199)

Sets the center position for a servo to its current position.

**Command:** `SETCENTER:servoNum:position`

---

### `setMinLimit(int servoNum)` (Lines 1201-1207)

Sets the minimum angle limit for a servo.

**Command:** `SETMINLIMIT:servoNum:position`

---

### `setMaxLimit(int servoNum)` (Lines 1209-1215)

Sets the maximum angle limit for a servo.

**Command:** `SETMAXLIMIT:servoNum:position`

---

### `resetLimits(int servoNum)` (Lines 1217-1225)

Resets servo to default limits (0-180°) and center (90°).

**Command:** `RESET:servoNum`

---

### `updateServoPosition(int servoNum, int position)` (Lines 1227-1232)

Sends position command to Arduino for specified servo.

**Command:** `S:servoNum:position`

---

### `toggleServoActive(int servoNum)` (Lines 1362-1367)

Toggles the active/inactive state of a servo.

**Command:** `ACTIVE:servoNum:state`

---

### `setAllServosActive()` (Lines 1369-1375)

Activates all servos at once.

**Command:** `ALLACTIVE`

---

### `setAllServosInactive()` (Lines 1377-1383)

Deactivates all servos at once.

**Command:** `ALLINACTIVE`

---

### `manualReconnect()` (Lines 1385-1398)

Manually triggers serial port reconnection.

---

## Label Editing Functions

### `startLabelEdit(int servoNum)` (Lines 1360-1365)

Initiates label editing dialog for specified servo.

---

### `initializeLabels()` (Lines 1547-1551)

Sets default labels for all servos ("Servo 0" through "Servo 15").

---

## File Management Functions

### `updateSavedFilesList(String operation)` (Lines 1400-1418)

Scans data directory and builds list of saved settings or keyframe files.

**File Patterns:**
- Settings: `*_settings.txt`
- Keyframes: `*_keyframes.txt`

---

### `startFileNaming()` (Lines 1420-1426)

Initiates save dialog (uses existing filename or prompts for new one).

---

### `startFileNamingAs()` (Lines 1428-1431)

Initiates "Save As" dialog with optional pre-filled filename.

---

### `startFileSelection(String operation)` (Lines 1433-1449)

Shows file selection dialog for load/delete operations.

**Operations:** `load`, `delete`, `loadKeyframes`

---

### `isValidFileName(String name)` (Lines 1451-1454)

Validates filename format (alphanumeric, hyphens, underscores only).

**Regex:** `[a-zA-Z0-9\-_]+`

---

## Settings File Functions

### `saveSettingsToFileWithName(String fileName)` (Lines 1456-1480)

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

### `loadSettingsFromFileWithName(String fileName)` (Lines 1482-1548)

Loads servo settings from file and applies them to all servos. Sends settings to Arduino if connected.

---

### `deleteSettingsFileWithName(String fileName)` (Lines 1550-1562)

Deletes a settings file from disk.

---

### `loadSettingsFromFile()` (Lines 1636-1643)

Loads the default settings file on startup.

**Default File:** `default_settings.txt`

---

### `sendAllSettingsToArduino()` (Lines 1645-1657)

Transmits all current servo settings to Arduino via serial.

---

## Keyframe File Functions

### `saveKeyframesToFile()` (Lines 1564-1600)

Saves current sequence keyframes to timestamped file. Stores as last loaded file for auto-loading.

**File Format:**
```
# Keyframe Sequence Data
# Total Keyframes: X
# Format: KF:speed:delay:name:pos0,pos1,...:active0,active1,...
KF:speed:delay:name:positions:activeStates
```

---

### `loadKeyframesFromFileWithName(String fileName)` (Lines 1602-1650)

Loads keyframe sequence from specified file. Parses positions, active states, speed, and delay for each keyframe.

---

### `loadKeyframesFromFile()` (Lines 1652-1667)

Automatically loads the last used keyframe file on startup.

**Reference File:** `last_keyframes.txt`

---

## UI Creation and Display Functions

### `createUI()` (Lines 1553-1589)

Creates all UI elements (sliders, buttons) with proper positioning. Initializes sequence control buttons and PIR controls.

**Servo Controls (16 servos in 4×4 grid):**
- Starting position: `(50, 70)`
- Layout: 4 columns × 4 rows
- Column spacing: 350px
- Row spacing: 140px

**Each servo panel includes:**
- Slider at `(x, y)` size `300 x 30`
- Center button at `(x, y + 70)` size `60 x 30`
- Set Ctr button at `(x, y + 35)` size `60 x 30`
- Set Min button at `(x + 65, y + 35)` size `60 x 30`
- Set Max button at `(x + 130, y + 35)` size `60 x 30`
- Reset button at `(x + 195, y + 35)` size `50 x 30`
- Label button at `(x + 250, y + 35)` size `50 x 30`
- Active button at `(x + 65, y + 70)` size `60 x 30`

**Global Control Buttons:**
- All Active at `(215, 750)` size `100 x 40`
- All Inactive at `(340, 750)` size `100 x 40`
- Connect at `(165, 5)` size `80 x 30`

**Settings Buttons:**
- Save at `(720, 750)` size `80 x 40`
- Save As at `(810, 750)` size `80 x 40`
- Load at `(900, 750)` size `80 x 40`
- Delete at `(990, 750)` size `80 x 40`
- PWM Shield at `(1080, 750)` size `120 x 40`

---

### `drawServoControl(int servoNum)` (Lines 1591-1624)

Renders individual servo control panel with slider and buttons. Shows servo status, position, and limits.

**Layout calculation:**
```
row = servoNum / 4
col = servoNum % 4
x = 50 + col × 350
y = 70 + row × 140
```

**Text Elements:**
- Servo label and position at `(x, y - 10)` - size 14
- Limits info at `(x + 135, y + 90)` - size 12
- Format: "Min: X° | Max: X° | Ctr: X°"

---

### `drawSettingsStatus()` (Lines 1626-1638)

Displays temporary status messages for settings operations. Shows currently loaded settings filename.

**Text Elements:**
- Status message at `(880, 700)` - size 14 - color RGB(0, 100, 200)
- "Current file: [filename]" at `(880, 720)` - size 18 - color RGB(100)

---

### `drawConnectionStatus()` (Lines 1640-1662)

Displays serial connection indicator and auto-scan countdown. Shows connection status messages.

**Visual Elements:**
- Status indicator circle at `(16, 16)` - diameter 12px
- Auto-scan countdown at `(108, 27)` - size 12 - color RGB(100)
- Connection status at `(90, 12)` - size 14 - color RGB(0, 100, 200)

---

### `drawLabelEditDialog()` (Lines 1664-1679)

Renders modal dialog for editing servo labels.

**Coordinates:**
- Dialog Box: centered at `(520, 320)` size `400 x 160` with rounded corners (radius 10)

**Text Elements:**
- "Edit Label for Servo X" at `(720, 360)` - size 16
- "Current: [label]" at `(720, 380)` - size 16
- "New: [text]_" at `(720, 410)` - size 16
- Instructions at `(720, 440)` - size 16

---

### `drawFileNamingDialog()` (Lines 1681-1695)

Renders modal dialog for entering new settings filename.

**Coordinates:**
- Dialog Box: centered at `(520, 320)` size `400 x 160` with rounded corners (radius 10)

**Text Elements:**
- "Enter Settings File Name" at `(720, 360)` - size 16
- "Name: [text]_" at `(720, 390)` - size 16
- "Press ENTER to save, ESC to cancel" at `(720, 420)` - size 16
- Validation hint at `(720, 440)` - size 16

---

### `drawFileSelectionDialog()` (Lines 1697-1762)

Renders paginated file selection dialog with navigation buttons. Shows available files for load/delete operations.

**Coordinates:**
- Dialog Box: centered at `(420, 200)` size `600 x 400` with rounded corners (radius 10)

**Text Elements:**
- Dialog title at `(720, 230)` - size 18
- "Page X of Y" at `(720, 260)` - size 14
- File list items starting at y = 290, spacing 30px - size 13
- Instructions at `(720, 490)` - size 14
- Selected file at `(720, 510)` - size 12 - color RGB(0, 100, 200)

**Buttons:**
- "◄ Prev" at `(450, 220)` size `120 x 30` with rounded corners (radius 5)
- "Next ►" at `(870, 220)` size `120 x 30` with rounded corners (radius 5)

**File Selection:**
- Selection highlight at `(width/2 - 280, fileY - 12)` size `560 x 24` with rounded corners (radius 5)
- 10 files per page

---

## Custom Classes

### Slider Class (Lines 1764-1810)

**Constructor:** `Slider(float x, float y, float w, float h, float min, float max)`

**Methods:**
- `display(boolean active)` - Renders slider with value display
- `display(boolean active, boolean showValue)` - Renders slider with optional value display
- `isOver()` - Checks if mouse is over slider handle
- `updatePosition(float mx)` - Updates slider value based on mouse position
- `setValue(float v)` - Sets slider value programmatically
- `getValue()` - Returns current slider value

**Features:**
- Rounded slider track
- Circular handle with value display
- Mouse hover detection
- Value constraints (min/max)

---

### Button Class (Lines 1812-1844)

**Constructor:** `Button(float x, float y, float w, float h, String label, color buttonColor)`

**Methods:**
- `display()` - Renders active button with hover effect
- `displayInactive()` - Renders inactive/disabled button
- `isOver()` - Checks if mouse is over button

**Features:**
- Hover color transition
- Rounded corners
- Centered text label

---

### ServoKeyframe Class (Lines 143-168)

**Constructors:**
- `ServoKeyframe()` - Default constructor
- `ServoKeyframe(int spd, int dly, String nm)` - Constructor with parameters

**Properties:**
- `int[] positions` - Array of 16 servo positions (0-180°)
- `boolean[] activeServos` - Array of 16 active states
- `int speed` - Movement duration in milliseconds
- `int delay` - Delay after movement in milliseconds
- `String name` - Keyframe name/label

**Purpose:** Stores snapshot of all servo positions and states with timing parameters for sequence playback.

---

## Summary Statistics

### 📊 Code Metrics

- **Total Functions:** 62 main functions + 11 class methods = **73 total**
- **Lines of Code:** ~1,844 lines
- **Window Dimensions:** 1440 x 800 pixels
- **Hardware Support:** Arduino with PWM Shield or Standard Servo Library

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
- **Optional:** PIR Motion Sensor (HC-SR501 or similar)
- **16 RC Servos** (standard hobby servos)
- **Power Supply** (adequate for servo load)

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

| Key | Action |
|-----|--------|
| `R` | Toggle recording mode |
| `K` | Add keyframe to sequence |
| `P` | Play/pause sequence |
| `C` | Clear sequence |
| `S` | Toggle PWM Shield mode |

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
- `PO:servoNum:position` - Position update
- `MI:servoNum:minLimit` - Min limit
- `MA:servoNum:maxLimit` - Max limit
- `CE:servoNum:centerPos` - Center position
- `AC:servoNum:active` - Active state
- `RE:servoNum` - Reset confirmation
- `PIR:MOTION_DETECTED` - Motion detected
- `PIR:STATUS:enabled:cooldown:state` - PIR status
- `PIR:ENABLED` / `PIR:DISABLED` - PIR state
- `PIR:COOLDOWN:value` - Cooldown value

---

## Color Scheme

### UI Colors

| Element | Color (RGB) | Hex |
|---------|-------------|-----|
| Background | (240, 240, 240) | #F0F0F0 |
| Slider | (180, 200, 220) | #B4C8DC |
| Button | (144, 213, 255) | #90D5FF |
| Button Hover | (80, 140, 180) | #508CB4 |
| Text | (40, 40, 40) | #282828 |
| Center Button | (255, 200, 100) | #FFC864 |
| Set Center Button | (255, 150, 50) | #FF9632 |
| Active Button | (100, 255, 100) | #64FF64 |
| Inactive Button | (255, 100, 100) | #FF6464 |
| Record Button | (255, 100, 100) | #FF6464 |
| Recording Button | (255, 50, 50) | #FF3232 |
| Play Button | (100, 255, 100) | #64FF64 |
| PIR Motion | (255, 50, 50) | #FF3232 |
| PIR Clear | (100, 255, 100) | #64FF64 |

---

## Constants Reference

```processing
NUM_SERVOS = 16
WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 800
SLIDER_WIDTH = 300
SLIDER_HEIGHT = 30
BUTTON_WIDTH = 120
BUTTON_HEIGHT = 30
MARGIN = 50
ROW_HEIGHT = 140
FILES_PER_PAGE = 10
CONNECTION_CHECK_INTERVAL = 2000 (ms)
PIR_STATUS_REQUEST_INTERVAL = 2000 (ms)
```

---

## Usage Workflow

### Basic Setup
1. Connect Arduino to computer via USB
2. Launch Processing sketch
3. Wait for auto-connection (or click "Connect" button)
4. Click "All Active" to enable servos
5. Adjust servo positions using sliders

### Recording a Sequence
1. Click "Record" button (or press `R`)
2. Move servos to desired positions
3. Click "Add Frame" (or press `K`) to capture keyframe
4. Adjust speed and delay sliders as needed
5. Repeat steps 2-4 for each keyframe
6. Click "Record" again to stop recording (or press `R`)
7. Click "Save Keys" to save sequence

### Playing a Sequence
1. Click "Play" button (or press `P`)
2. Watch servos move through keyframes
3. Click "Play" again to stop (or press `P`)

### Exporting to Arduino
1. Create and test your sequence
2. Click "Export" button
3. Enter sketch name
4. Toggle PWM Shield if needed
5. Press ENTER to generate .ino file
6. Open exported file in Arduino IDE
7. Upload to Arduino for standalone operation

### PIR Integration
1. Enable PIR sensor by clicking "PIR: OFF" button
2. Adjust cooldown period using slider (1-30 seconds)
3. Enable/disable auto-play feature
4. When motion detected, sequence plays automatically
5. Cooldown prevents repeated triggers

---

## Troubleshooting

### Connection Issues
- **No serial ports found:** Check USB cable and Arduino drivers
- **Connection lost:** Check for loose USB connection
- **Auto-reconnect fails:** Click "Connect" button manually
- **Wrong port selected:** Disconnect other serial devices

### Servo Issues
- **Servos not moving:** Check if servo is active (green button)
- **Erratic movement:** Check power supply capacity
- **Limited range:** Check min/max limits aren't too restrictive
- **Servo jitter:** Reduce serial communication delays

### PIR Issues
- **No motion detection:** Check PIR sensor wiring (VCC, GND, Signal to pin 2)
- **False triggers:** Adjust PIR sensitivity potentiometer
- **Cooldown not working:** Verify cooldown value sent to Arduino

### File Issues
- **Can't save files:** Check write permissions on /data folder
- **Files not loading:** Verify file format and extension
- **Missing keyframes:** Ensure sequence saved before exiting

---

## License

MIT License - Copyright (c) 2025 Webrobotix

---

## Credits

**Developer:** Webrobotix  
**Version:** 2.0 with PIR Integration (v1.7)  
**Year:** 2020-2025  
**Platform:** Processing 3.x+  
**Language:** Java (Processing)  

---

## Changelog

### v2.0 (2025)
- ✨ Added PIR motion sensor integration
- ✨ Motion-triggered sequence playback
- ✨ Configurable cooldown period
- ✨ PIR enable/disable control
- ✨ Visual motion detection indicator
- 🎨 Updated UI with PIR control panel

### v1.7
- Initial PIR sensor support
- Enhanced sequence recording
- Improved Arduino sketch export

---

## Additional Resources

- **Processing:** https://processing.org
- **Arduino:** https://arduino.cc
- **Adafruit PWM Shield:** https://www.adafruit.com/product/1411
- **PIR Sensor Guide:** HC-SR501 documentation

---

*Generated from Servo16_3_PIR.txt - Webrobotix 2020-2025*  
*Documentation for Processing sketch with PIR Motion Sensor Integration*  
*Last Updated: 2025*
