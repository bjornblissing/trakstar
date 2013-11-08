# Target name
SET(TARGET_LIBRARYNAME TrakStar)
SET(TARGET_TARGETNAME TrakStarExample)

# Target source files
SET(TARGET_LIB_SRC
	trakstar.cpp
)

# Target headerfiles
SET(TARGET_LIB_H
	trakstar.h
)

#####################################################################
# Create library
#####################################################################

ADD_LIBRARY(${TARGET_LIBRARYNAME} ${TARGET_LIB_SRC} ${TARGET_LIB_H})

#####################################################################
# Create example executable
#####################################################################

ADD_EXECUTABLE(${TARGET_TARGETNAME} main.cpp)
TARGET_LINK_LIBRARIES(${TARGET_TARGETNAME} ${TARGET_LIBRARYNAME})


#####################################################################
# Linker options
#####################################################################


# Link to trakstar libs
TARGET_LINK_LIBRARIES(${TARGET_TARGETNAME}  ${TRAKSTAR_SDK_LIBRARIES} )

####################################################################
# Create user file for correct environment string
#####################################################################
IF(WIN32)
    IF(MSVC)
		IF (OPENSCENEGRAPH_FOUND)
			# Build path
			SET(USERFILE_ENVIRONMENT_DEBUG "PATH=")
			SET(USERFILE_ENVIRONMENT_RELEASE "PATH=")

			# Add location of needed dll files to path
			SET(USERFILE_ENVIRONMENT_DEBUG "${USERFILE_ENVIRONMENT_DEBUG}${TRAKSTAR_SDK_BIN_DIRS}")
			SET(USERFILE_ENVIRONMENT_RELEASE "${USERFILE_ENVIRONMENT_RELEASE}${TRAKSTAR_SDK_BIN_DIRS}")

			# For visual studio 10
			IF(MSVC10)
				CONFIGURE_FILE(trakstar.vcxproj.template ${TARGET_TARGETNAME}.vcxproj.user @ONLY)
			ENDIF(MSVC10)

		ENDIF (OPENSCENEGRAPH_FOUND)
    ENDIF(MSVC)
ENDIF(WIN32)
