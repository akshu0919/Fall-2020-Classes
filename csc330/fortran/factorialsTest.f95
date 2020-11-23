program recursive_factorial
use iso_fortran_env
implicit none

  integer (kind = int64):: i

  do i = 1, 20
  print *,i , (factorial(i))
  enddo

  contains 

  recursive function factorial(i) result (fac)

    implicit none
    integer (kind = int64), intent(in):: i
    integer (kind = int64):: fac

    if( i <= 1 ) then
      fac = 1
    else
      fac = i * factorial(i - 1)
    end if

  end function

end program recursive_factorial
