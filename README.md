
Run the Program:

To run your program, open the integrated terminal in VS Code (using Ctrl+` or from the View menu -> Terminal).
Navigate to the directory containing your compiled program.
Run the program by typing ./your_program_name (replace your_program_name with the name of your compiled executable).

Configure Build and Debug Settings:
To build and run C++ code,you need a tasks.json file to tell VS Code how to build (compile) the program and a launch.json file to configure debugging settings.
If one does not have these files, VS Code will typically prompt you to add them when you first open a C++ file. Select a C++ compiler from the prompt, and VS Code will auto-generate these files for you.
Make sure the tasks.json file is correctly set up to compile your rec3new.cpp. It should reference the C++ compiler (like g++ or clang) and include any necessary compile flags.
