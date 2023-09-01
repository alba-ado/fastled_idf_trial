idf_component_register( SRC_DIRS            "."
                                           	"lib/FastLED/src"
                                            "lib/FastLED/src/platforms/esp/32"
                                            
                        INCLUDE_DIRS        "."
                                            "lib/FastLED/src"
                                            "lib/FastLED/src/platforms/esp/32"
)

#Delete the redundant options when warnings are fixed
component_compile_options(-Wno-unknown-pragmas -Wno-missing-field-initializers -std=gnu++2b)
