# Add include paths
FLAGS += -Imodels										# Add simulation models include path

# Add compile flags
FLAGS += -pthread										# Enable multi threading
FLAGS += -g 											# Needed for debugging simulation

# Add defines, includes and other compile flags to C and CXX flags
TRICK_CFLAGS += $(FLAGS)
TRICK_CXXFLAGS += $(FLAGS)