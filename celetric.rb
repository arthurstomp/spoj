# 8483. Conta de eletricidade
# 
# Problema: CELETRIC
# 
# É o ano de 2100. Eletricidade se tornou muito cara. Recentemente, sua companhia de eletricidade aumentou as taxas de energia novamente. 
#A tabela abaixo mostra as novas taxas (consumo é sempre um inteiro positivo):
# 
# Intervalo
# (Watt-hora) Custo   |   (Reais)
# 1 ~ 100             |     2
# 101 ~ 10000         |     3
# 10001 ~ 1000000     |     5
# > 1000000           |     7
#
# Isto significa que, ao calcular a quantia a pagar, os primeiros Wh custam 2 Reais cada; os próximos 9900 Wh (entre 101 e 10000) custam 
#3 Reais cada e assim por diante.
# 
# Por exemplo, se você consumir 10123 Wh deverá pagar 2 x 100 + 3 x 9900 + 5 x 123 = 30515 Reais.
# 
# Os matemáticos da companhia encontraram um modo de ganhar ainda mais dinheiro. Ao invés de lhe dizer quanta energia você consumiu e quanto 
#você deve pagar, eles mostrarão a você dois números relacionados a você e a um vizinho aleatório:
# 
# o total a pagar se seus consumos fossem somados; 
# e a valor absoluto da diferença entre os custos de suas contas.
#
# Se não conseguir descobrir quanto deve pagar, você deve pagar outros 100 Reais para tal "serviço". Você é muito econômico, e portanto você 
#tem certeza que não consome mais que nenhum de seus vizinhos. Então, esperto como é, você sabe que consegue computar quanto tem que pagar. 
#Por exemplo, suponha que a companhia informou a você os dois seguintes números: A = 1100 e B = 300. Então o seu consumo e o de seu vizinho 
#devem ser 150 Wh e 250 Wh, respectivamente. O consumo total é 400 Wh e A é então 2 x 100 + 3 x 300 = 1100. Você deve pagar 2 x 100 + 3 x 50 = 350 Reais, 
#enquanto seu vizinho deve pagar 2 x 100 + 3 x 150 = 650 Reais, portanto B é |350 - 650| = 300.
# 
# Decidido a não pagar a taxa adicional, você decidiu escrever um programa de computador para descobrir quanto você deve pagar.
# 
# Entrada
# 
# A entrada contém vários casos de teste. Cada caso de teste é composto de uma única linha contendo dois inteiros A e B, separados por um espaço em branco, 
#representando os valores apresentados a você (1 ≤ A,B ≤ 10**9). Você pode assumir que sempre haverá uma soluçao única, ou seja, existe apenas um par de consumos 
#que produz esses valores.
# 
# O último caso de teste é seguido de uma linha contendo dois zeros separados por um espaço em branco.
# 
# Saída
# 
# Para cada caso de teste da entrada, seu programa deve imprimir uma linha contendo um inteiro representando o total que você deve pagar.
# 
# Exemplo
# 
# Entrada:
# 1100 300
# 35515 27615
# 0 0
# 
# Saída:
# 350
# 2900

def bill(wh)
  if wh <= 100
    return 2 * wh
  elsif wh > 100 and wh <= 10000
    return 2 * 100 + 3 * (wh - 100)
  elsif wh > 10000 and wh <= 1000000
    return 2 * 100 + 3 * 9900 + 5 * (wh - 10000)
  else 
    return 2 * 100 + 3 * 9900 + 5 * 990000 + 7 * (wh - 1000000)
  end
end

def consumption(bill)
  if bill <= 200
    return bill/2
  elsif bill > 200 and bill <= 29900
    return (bill + 100)/3
  elsif bill > 29900 and bill <= 4979900
    return (bill + 20100)/5
  else
    return (bill + 2020100)/7
  end
end

def binarySearch(lower, upper, wantedDiference, sumOfConsumption)
   return -1 if lower > upper
   myConsumption = (lower+upper)/2
   diference = (bill(myConsumption) - bill(sumOfConsumption - myConsumption )).abs
   if ( diference == wantedDiference)
     myConsumption
   elsif (diference < wantedDiference)
     binarySearch(lower, myConsumption-1, wantedDiference, sumOfConsumption)
   else
     binarySearch(myConsumption+1, upper, wantedDiference, sumOfConsumption)
   end
end

# #Testing
# consumptionX = rand(1..1000)
# consumptionY = rand(1..1000)
# lowerConsumption = consumptionX < consumptionY ? consumptionX : consumptionY
# 
# a = bill(consumptionX + consumptionY) #bill for the sum of the consumption #Testing
# b = (bill(consumptionX) - bill(consumptionY)).abs #diference between the bills. #Testing
# 
# sumOfConsumption = consumption(a)
# 
# #Binary way
# foundBill = bill(binarySearch(0,sumOfConsumption,b,sumOfConsumption))
# p "Bill found with binary search algoritm = #{foundBill}"
# 
# #Linear way
# result = 0
# (0..sumOfConsumption).each do |myConsumption|
#   if (bill(myConsumption) - bill(sumOfConsumption - myConsumption)).abs == b
#     result = myConsumption
#     break
#   end
# end
# p "Bill found with linear search algoritm = #{bill(result)}"
# 
# p "Sucess" if foundBill == bill(lowerConsumption) and bill(result) == foundBill

#spoj
inputs = gets.chomp.split(" ")
a = inputs[0].to_i #spoj
b = inputs[1].to_i.to_i #spoj
while a != 0 and b != 0 do
  sumOfConsumption = consumption(a)
  #Binary way
  p bill(binarySearch(0,sumOfConsumption,b,sumOfConsumption))
  inputs = gets.chomp.split(" ")
  a = inputs[0].to_i #spoj
  b = inputs[1].to_i.to_i #spoj
end






