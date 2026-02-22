# data-structures-and-oop
All code exercises shall be found here.

## For VisualStudioCode build/run

Here we need to build and run each project by itself if you want to have all the projects opend inside the same instace of VSCode.

### Build

Press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> to build the selected project. A dropdown will appear asking which project to compile.

### Run

#### Run task shortcut
To set up the run shortcut, first open the keyboard shortcuts JSON file:

1. Press <kbd>Ctrl</kbd>+<kbd>K</kbd> then <kbd>Ctrl</kbd>+<kbd>S</kbd> to open Keyboard Shortcuts
2. Click the **"Open Keyboard Shortcuts (JSON)"** icon in the top right corner (or use the shortcut <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>K</kbd>)
3. Add the following entry:
```json
{
    "key": "ctrl+shift+r ctrl+shift+r",
    "command": "workbench.action.tasks.runTask",
    "args": "run"
}
```
4. Now use <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>R</kbd> <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>R</kbd> to run the project.

#### Run from the Terminal

1. Press <kbd>Ctrl</kbd>+<kbd>`</kbd> to toggle the terminal.
2. Run the _output_ file from the project (created by the build), for example _./linked-lists/output_

### Important

The file ___tasks.json___ should not be changed because that will break the way to build and run the projects in _VSCode_, changes to that process should be documented here if the need arise. 
