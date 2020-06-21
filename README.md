# Logger
General logger class.

Configuration:
1. Currently used:
- Python 2.7.16,
- cmake version 3.17.0-rc2,
- Visual Studio 2019.

2. GTest and GMock tooked from: 
   https://bintray.com/bincrafters/public-conan/gtest%3Abincrafters/1.8.1%3Astable#

3. You need update your remotes:
   Conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

Builidng:
1. Go to Conan folder,
2. Open git bash console,
3. Type conan source .
4. Type conan install .
5. Type conan build .
6. Got to "Build" folder and open Visual Project.

Tips:
- It is unacceptable if the package calls the package (recursion),
- The first time you start the program python packages can be missing. Please follow the python suggestion to install them,
- The first time you start the program using "conan build ." CMakeLists is updated with current project name and packages names. 
  Remove Build folder and try again with updated CMakeLists.txt,
- To install gtest and gmock packages for specified options and settings type "conan install . --build gtest".