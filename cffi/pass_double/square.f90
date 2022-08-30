module fortfuncs

  use iso_c_binding, only: c_double
  implicit none

contains

  function square(x) result(y) bind(c)

    real(c_double), value, intent(in) :: x

    real(c_double) :: y
    
    y = x * x

  end function square

end module fortfuncs
