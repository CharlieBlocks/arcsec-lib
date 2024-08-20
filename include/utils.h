#ifndef _ARC_UTILS_H
#define _ARC_UTILS_H

// Define helper defines
#define ARC_FUNC __fastcall; // Passes arguments in in registers
#define ARC_IFUNC __vectorcall; // Passes arguments in in intrinsic registers

#if defined(__MSC_VER)
#define _ARC_ALIGN(x) __declspec(align(a))
#elif defined(__GNUC__)
#define _ARC_ALIGN(x) __attribute__ ((aligned(x)))
#elif defined(__clang__)
#define _ARC_ALIGN(x) __attribute__ ((aligned(x)))
#endif

namespace is_comptime {

    #if defined(__MSC_VER)

    struct C {};
    struct M : C { int a; };
    struct N : C { int a; };

    // Uses differences between casting at compile time and runtime
    // to determine if the function is being run at compile time
    // This was taken from: https://stackoverflow.com/a/76271410
    //
    // Call with is_comptime::evaluate()
    inline constexpr bool evaluate() noexcept {
        return &M::a != static_cast<int C:: *>(&N::a);
    }

    #define OOL_STATIC static

    #else // defined(__MSC_VER)

    inline constexpr bool evaluate() noexcept {
        return __builtin_is_constant_evaluated();
    }

    #define OOL_STATIC

    #endif


}

#endif // _ARC_UTILS_H
