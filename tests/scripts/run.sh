# Initialization
cd `dirname $0`
SCRIPTDIR=`pwd`
cd -

# Run unit tests
cd $SCRIPTDIR/../bin/
./tests --gtest_output="xml:../reports/reports.xml"