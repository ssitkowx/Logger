# Logger
# I. Description:
General logger class.

# II. Assumption:
- The code should be dependent only on C/C++ language libraries,
- The code should work in various environments such as Linux, Windows, Embedded and be independent of them.

# III. Structure:
The solution project has been divided into three parts:
- Project with header and source files,
- Project library,
- Tests which uses the project library and the gtest and/or gmock libraries.

# IV. Configuration:
- Python 2.7.16,
- CMake version 3.17.0-rc2,
- Visual Studio 2019,
- GTest and GMock tooked from https://bintray.com/bincrafters/public-conan/gtest%3Abincrafters/1.8.1%3Astable#
- You should update yours remote with 'conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan'
- You should update yours conanfile.py according to the example below:
  - name     = "Template"                                          -> Display
  - Packages = ["packageName/version@owner/channel", next package] -> ["Logger/1.0@ssitkowx/stable", "Utils/2.3@ssitkowx/testing"] 

# V. Builidng:
- Go to 'Conan' folder and open git bash console,
- Type 'conan install .',
- Type 'conan source .',
- Type 'conan build .',
- Got to 'Build' folder and open Visual Studio Project.

# VI. Tips:
- It is unacceptable if the package calls the package (recursion),
- The first time you start the program after entering 'conan install .' python packages can be missing,
  Please follow the python suggestion to install them,
- The first time you start the program after entering 'conan build .' CMakeLists is updated with current project name and packages names.
  Remove Build folder and try again with updated CMakeLists.txt,
- To install gtest and gmock packages for specified options and settings type 'conan install . --build gtest'.