# CMake generated Testfile for 
# Source directory: C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests
# Build directory: C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestMoves "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/build/tests/test_moves.exe")
set_tests_properties(TestMoves PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;7;add_test;C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;0;")
add_test(SkakspilRuns "powershell" "-NoProfile" "-ExecutionPolicy" "Bypass" "-Command" "echo 'exit' | & 'C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/build/skakspil.exe'")
set_tests_properties(SkakspilRuns PROPERTIES  WORKING_DIRECTORY "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/build" _BACKTRACE_TRIPLES "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;9;add_test;C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;0;")
add_test(PerftTest "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/build/tests/test_perft.exe")
set_tests_properties(PerftTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;23;add_test;C:/Users/madss/OneDrive - Aarhus universitet/Dokumenter/Synced VSC folder/projects/skakspil/tests/CMakeLists.txt;0;")
