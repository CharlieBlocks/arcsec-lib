<h1 align="center">
Arcsec
</h1>

Arcsec is a SIMD (Single Instruction Multiple Data) focused vector maths library which is intended for use in graphical applications. The library has compatibility for both x86 and Arm through SSE/AVX and Neon extensions. 

Arcsec is targeted at modern systems that have SIMD and larger instruction caches as ite makes heavy use of inlining for all operations.

## Using Arcsec and CMake
Arcsec is developed as a CMake interface library. As such adding to a CMake project is easy. First clone the arcsec repository or download the source code into your libraries folder for your project.
```bash
git clone --depth 1 https://github.com/CharlieBlocks/arcsec-library.git
```
Or add it as a submodule
```bash
git submodule add https://github.com/CharlieBlocks/arcsec-library.git <desired-submodule-path>
```

<br>
With the source code downloaded it can now be added to the desired CMake project. In the root CMake file add the project using

```cmake
add_subdirectory (<module-path>)
```

The project can now be referenced by another project using
```cmake
target_link_libraries(project PRIVATE arcsec)
```

## Configure Arcsec using CMake
Arcsec exposes multiple options which can be used to trigger the desired SIMD support. When the building Host is x86, SSE and AVX will be enabled by default, when the host architecture is Arm, Neon will be enabled by default.

The possible options are:
- `ENABLE_SSE2` - Are SSE2 intrinsics enabled? (x86 only)
- `ENABLE_AVX2` - Are AVX2 intrinsics enabled? (x86 only)
- `ENABLE_AVX512` - Are AVX512 intrinsics enabled? (x86 only)
- `ENABLE_NEON` - Are NEON intrinsics enabled? (Supported Arm architectures only)