from conans import ConanFile, CMake, tools
import os, re

class Conan(ConanFile):
    name            = "Logger"
    version         = "1.0"
    license         = "freeware"
    repoUrl         = "https://github.com/ssitkowx"
    url             = repoUrl + '/' + name + '.git'
    downloadsPath   = "C:/Users/sitko/.conan/download"
    description     = "Logs informations"
    settings        = "os", "compiler", "build_type", "arch"
    options         = {"shared": [True, False]}
    default_options = "shared=False"
    generators      = "cmake"
    author          = "sylsit"
    requires        = "gtest/1.8.1@bincrafters/stable"
    build_requires  = ["Utils/1.0@ssitkowx/stable"]

    def createDownload(self):
        if not os.path.isdir(self.downloadsPath):
            os.mkdir(self.downloadsPath)
        os.chdir(self.downloadsPath)
        
    def cloneRepo(self, name):
        if not os.path.isdir(name):
            self.run('git clone ' + self.repoUrl + '/' + name + '.git')
        os.chdir(self.downloadsPath + '/' + name + '/Conan')
    
    def createPackage(self, user, channel):
        self.run('conan create . ' + user + '/' + channel)
    
    def source(self):
        for packages in self.build_requires:
            package = (re.split('[/@]', packages, 3))
            name    = package[0]
            #version = package[1]
            user    = package[2]
            channel = package[3]

            self.createDownload () 
            self.cloneRepo      (name)
            self.createPackage  (user,channel)

    def build(self):
        projectPath = self.downloadsPath + '\\' + self.name
        
        if self.settings.os == 'Windows' and self.settings.compiler == 'Visual Studio':
            cmake = CMake(self)
            cmake.configure(source_dir=projectPath)
            cmake.build()
        else:
            raise Exception('Unsupported platform or compiler')
            
        tools.replace_in_file(projectPath + "\\CMakeLists.txt", "Template", self.name, False)
        
    def package(self):     
        projectPath = self.downloadsPath + '\\' + self.name
    
        self.copy('*.h'     , dst='include', src= projectPath + '\\Project' , keep_path=False)
        self.copy('*.hxx'   , dst='include', src= projectPath + '\\Project' , keep_path=False)
        self.copy('*.lib'   , dst='lib'    , src= projectPath + '\Build\lib', keep_path=False)
        self.copy('*.dll'   , dst='bin'    , src= projectPath + '\Build\bin', keep_path=False)
        self.copy('*.dylib*', dst='lib'    , src= projectPath + '\Build\lib', keep_path=False)
        self.copy('*.so'    , dst='lib'    , src= projectPath + '\Build\lib', keep_path=False)
        self.copy('*.a'     , dst='lib'    , src= projectPath + '\Build\lib', keep_path=False)

    def package_info(self):
        self.cpp_info.libs = [self.name]
