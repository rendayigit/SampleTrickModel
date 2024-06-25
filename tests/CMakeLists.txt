cmake_minimum_required(VERSION 3.22)

project(tests LANGUAGES C CXX)

# Enable coverage
if(${ENABLE_COVERAGE})
  message("#################### Coverage Enabled ####################")
  set(GCOV_LINK_FLAGS "--coverage -O0 -g")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCOV_LINK_FLAGS}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCOV_LINK_FLAGS}")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set target directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/)

# Include SourceFiles.cmake to access the SOURCEFILES and INCLUDEDIRS variables
include(${CMAKE_SOURCE_DIR}/SourceFiles.cmake)

# Find the udunits2 library
find_library(UDUNITS2_LIB udunits2)
find_path(UDUNITS2_INCLUDE udunits2.h)

add_executable(tests
    ${SOURCEFILES}
)

target_include_directories(tests PUBLIC
    ${INCLUDEDIRS}
    ${UDUNITS2_INCLUDE}
)

target_link_libraries(tests PRIVATE 
    gtest_main
    gtest
    $ENV{TRICK_HOME}/lib/liber7_utils.a
    $ENV{TRICK_HOME}/lib/libtrick.a
    $ENV{TRICK_HOME}/lib/libtrick_comm.a
    $ENV{TRICK_HOME}/lib/libtrick_connection_handlers.a
    $ENV{TRICK_HOME}/lib/libtrick_math.a
    $ENV{TRICK_HOME}/lib/libtrick_mm.a
    $ENV{TRICK_HOME}/lib/libtrick_pyip.a
    $ENV{TRICK_HOME}/lib/libtrick_units.a
    $ENV{TRICK_HOME}/lib/libtrick_var_binary_parser.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPC.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPM.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPV.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libeqparse.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/liblog.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libtrick_units.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libvar.a
    ${UDUNITS2_LIB}
    # TRICK OBJECT FILES
    $ENV{TRICK_HOME}/trick_source/trick_utils/trick_adt/object_Linux_11.4_x86_64/bubble_sort.o
    $ENV{TRICK_HOME}/trick_source/trick_utils/trick_adt/object_Linux_11.4_x86_64/dllist.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/CheckPointAgent.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/ClassicCheckPointerAgent.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventManager.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventInstrument.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventProcessor.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventManager_c_intf.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/var_server_ext.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServerSession_write_stdio.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_open_additional_servers.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_get_next_freeze_call_time.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_get_next_sync_call_time.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/ChkPtParseContext.o
    # TRICK IO OBJECT FILES
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JobData.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SimObject.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/class_map.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ABM_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_AttributesMap.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_CheckPointAgent.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_CheckPointRestart.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ClientConnection.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Clock.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_CommandLineArguments.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DRAscii.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DRBinary.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DRHDF5.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DataRecordDispatcher.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DataRecordGroup.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_DebugPause.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_EchoJobs.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_EnumAttributesMap.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Environment.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Euler_Cromer_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Euler_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Event.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_EventInstrument.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_EventManager.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_EventProcessor.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Executive.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ExecutiveException.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ExternalApplication.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Flag.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_FrameDataRecordGroup.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_FrameLog.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_GetTimeOfDayClock.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_IPPython.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_IPPythonEvent.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ITimer.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_InputProcessor.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_InstrumentBase.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_IntegLoopManager.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_IntegLoopScheduler.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_IntegLoopSimObject.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JITEvent.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JITInputFile.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JSONVariableServer.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JSONVariableServerThread.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_JobData.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MM4_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MSConnect.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MSSharedMem.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MSSocket.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MTV.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MalfunctionsTrickView.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Master.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MemoryManager.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageCout.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageCustomFile.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageCustomManager.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageFile.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageHSFile.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageLCout.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessagePublisher.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageSubscriber.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageTCDevice.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MessageThreadedCout.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MonteCarlo.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MonteMonitor.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MonteVar.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_MulticastGroup.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_NL2_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_PlaybackFile.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RK2_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RK4_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RKF45_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RKF78_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RKG4_Integrator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RealtimeSync.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RemoteShell.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RtiEvent.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RtiExec.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RtiList.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_RtiStager.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_STLInterface.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ScheduledJobQueue.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Scheduler.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Sie.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SimControlPanel.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SimObject.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SimTime.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Slave.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_StripChart.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SysThread.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_SystemInterface.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_TCPClientListener.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_TCPConnection.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ThreadBase.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ThreadTrigger.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Threads.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Timer.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_TrickView.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_UCFn.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_UDPConnection.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_UdUnits.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Unit.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_UnitTest.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_UnitsMap.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_VariableReference.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_VariableServer.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_VariableServerListenThread.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_VariableServerSession.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_VariableServerSessionThread.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_Zeroconf.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_attributes.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_dllist.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_io_alloc.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_lqueue.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_lstack.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_master.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_python_code.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_file.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_fixed.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_random.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_random_bool.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_random_normal.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_random_string.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_random_uniform.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mc_variable_semi_fixed.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_message_type.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_mm_error.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_ms_sim_mode.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_parameter_types.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_rand_generator.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_reference.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_reference_frame.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_regula_falsi.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_sim_mode.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_tc.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_time_offset.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_trick_error_hndlr.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_tsm.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_units_conv.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_value.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_var.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_variable_server_message_types.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_variable_server_sync_types.o
    # $ENV{TRICK_HOME}/trick_source/sim_services/include/object_Linux_11.4_x86_64/io_wave_form.o
)

include(GoogleTest)
gtest_discover_tests(tests)