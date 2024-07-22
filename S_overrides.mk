# Add -g for debugging purposes

TRICK_CFLAGS += -Imodels -g
TRICK_CXXFLAGS += -Imodels -g

# Link zmq and its dependencies
TRICK_LDFLAGS += -lzmq -lpthread -lrt -lpgm -lsodium -lgssapi_krb5 -lnorm