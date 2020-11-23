program fact1
use iso_fortran_env
implicit none

integer (kind = int64) :: val, i
integer (kind = int64):: fact
external fact

do i = 1, 15
  print *, i, fact(i)
enddo

end program fact1


recursive integer function fact( i ) result (val)
use iso_fortran_env

integer(kind = int64) :: i

if ( i /= 1 ) then
  val = i * fact(i-1)
else
  val = 1
  return
endif

end function fact
