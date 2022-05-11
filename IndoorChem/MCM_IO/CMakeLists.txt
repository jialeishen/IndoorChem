#CMakeLists.txt
PROJECT(helloworld)
ADD_SUBDIRECTORY(src)
FILE(COPY ./src/data1.txt DESTINATION ./src/)