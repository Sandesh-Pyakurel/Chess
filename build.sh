# Useful variables

files_to_compile="src/*.cpp"
includes="-I include"
output_filename="bin/main"
compiler_flags="-w"
SFML_library="-lsfml-graphics -lsfml-window -lsfml-system"

# print the commmand to files with SFML
echo "g++ $files_to_compile $includes $compiler_flags $SFML_library -o $output_filename"

# Compiling commmand
g++ $files_to_compile $includes $compiler_flags $SFML_library -o $output_filename
