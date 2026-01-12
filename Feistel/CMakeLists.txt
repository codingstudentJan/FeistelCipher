# CMakeList.txt: CMake-Projekt für "Feistel". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (Feistel "Main.cpp" "Main.h" "Feistel-Cipher/FeistelCipher.cpp" "Feistel-Cipher/FeistelCipher.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Feistel PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
