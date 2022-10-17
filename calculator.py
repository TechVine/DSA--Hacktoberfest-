## Calculator in Python ##

print("CALCULADORA EM PYTHON")

n1 = int(input("Digite o primeiro número: "))
n2 = int(input("Digite o segundo número: "))

print("Soma (S)")
print("Divisão (D)")
print("Multplicação (M)")
print("Subtração (SB)")

operacao = input("Adicione a operação que você deseja realizar: ")

S = (n1 + n2)
D = (n1 / n2)
M = (n1*n2)
SB = (n1 - n2)

if operacao == "S":
  print(S)

if operacao == "D":
  print(D)

if operacao == "SB":
  print(SB)

if operacao == "M":
  print(M)
