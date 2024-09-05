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

    #else // defined(__MSC_VER)

    inline constexpr bool evaluate() noexcept {
        return __builtin_is_constant_evaluated();
    }

    #endif
}


#if defined(__MSC_VER)
#define OOL_STATIC static
#else
#define OOL_STATIC
#endif

namespace arc::detail {

    template<typename T, T __v>
    struct integral_constant {
        static constexpr T value = __v;
        using value_type = T;
        using type = integral_constant<T, __v>;
        constexpr operator value_type() const noexcept { return value; }
    };
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;



    template<typename _T, typename _F>
    struct type_eq : false_type {};
    template<typename _T>
    struct type_eq<_T, _T> : true_type {};

    template<typename _T, typename _F>
    struct type_neq : true_type {};
    template<typename _T>
    struct type_neq<_T, _T> : false_type {};
}

#endif // _ARC_UTILS_H
