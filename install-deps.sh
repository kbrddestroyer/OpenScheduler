if [[ -z "${1}" ]]; then
  echo "Provide build type (Debug|Release)"
fi

conan install . -s build_type="${1}" --build=missing --output-folder=conan/"${1}"
