#Enter the scale and temperature value and this value will be converted to other scales.#

escala = str(input())
valortemp = float(input())

celsioskelvin = valortemp + 273.15

kelvincelsios = valortemp - 273.15

celsiosfahren = (valortemp*1.8) + 32

fahrencelsios = (valortemp-32)/1.8

kelvinfahren = 1.8*(valortemp - 273.15) + 32

fahrenkelvin = (valortemp + 459.67)*(5/9)

if escala == "C" and valortemp >= -273.15:
    print("%.2f" % celsiosfahren, "F")
    print("%.2f" % celsioskelvin, "K")
elif escala =="K" and valortemp >= 0.0:
    print("%.2f" % kelvincelsios, "C")
    print("%.2f" % kelvinfahren, "F")
elif escala == "F" and valortemp >= -459.67:
    print("%.2f" % fahrencelsios, "C")
    print("%.2f" % fahrenkelvin, "K")
else:
    print("Valor de temperatura abaixo do minimo")
