module fortfuncs

  use iso_c_binding, only: c_double, c_int
  implicit none

contains

  subroutine square(x,y,n) bind(c)

    real(c_double), intent(in) :: x(n)

    real(c_double), intent(out) :: y(n)
    
    integer(c_int), intent(in), value :: n
    
    y = x * x

  end subroutine square

end module fortfuncs
