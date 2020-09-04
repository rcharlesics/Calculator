TEMPLATE = subdirs

GreenHouse.subdir = GreenHouse
GreenHouse.target = GreenHouse-tests
SUBDIRS += GreenHouse

exists(CalculatorInterfaces) {
  CalculatorInterfaces.subdir = CalculatorInterfaces
  CalculatorInterfaces.target = CalculatorInterfaces-tests

  SUBDIRS += \
      CalculatorInterfaces
}
