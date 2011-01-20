
#if defined (_STLP_MSVC) || defined (__ICL)

#  pragma warning (push)
#  include <stl/config/_warnings_off.h>
/* We are forcing the alignment to guaranty that libraries are use
 * with the same alignment as the one use to build them.
 */
#  if !defined (_WIN64)
#    pragma pack(push, 8)
#  else
#    pragma pack(push, 16)
#  endif

#elif defined (__BORLANDC__)

#  pragma option push
#  pragma option -Vx- -Ve- -a8 -b -pc
#  include <stl/config/_warnings_off.h>

#elif defined (__IBMCPP__)
/* supress EDC3130: A constant is being used as a conditional expression */
#  pragma info(nocnd)
#elif defined (__WATCOMCPLUSPLUS__)
#  pragma warning 604 10 /* must lookahead to determine... */
#  pragma warning 594 10 /* resolved as declaration/type */
#  pragma warning 595 10 /* resolved as an expression */
#endif
