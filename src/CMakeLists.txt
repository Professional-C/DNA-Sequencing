# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	SrcMain.h
    Fasta.hpp
    AminoAcidCount.hpp
)

set(SOURCE_FILES
	SrcMain.cpp
    Fasta.cpp
    AminoAcidCount.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})
