file(REMOVE_RECURSE
  "libglSH.a"
  "libglSH.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/glSH.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
