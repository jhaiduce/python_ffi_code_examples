module fortfuncs

  implicit none

contains

  subroutine square(x,y,n)

    real, intent(in) :: x(n)

    real, intent(out) :: y(n)

    integer, intent(in) :: n
    
    y = x * x

  end subroutine square

end module fortfuncs
