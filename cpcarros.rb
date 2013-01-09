# 2923. Competição de placas de carros
# 
# Problema: CPCARROS
# 
# Martin e Isa são bem competitivos. A mais nova competição que eles criaram é sobre olhar as placas dos carros. Cada vez que um deles vê uma placa de carro na 
#rua, ele ou ela manda para o outro uma mensagem SMS com o conteúdo da placa; aquele que tiver visto a placa mais recente fica na liderança. Como um escritório 
#da Gerência de Veículos Automotores (ACM) coloca as placas seqüencialmente em ordem crescente, eles podem comparar elas e descobrir que é o vencedor.
# 
# Martin tem um olhar atento e ficou várias semanas na liderança. Talvez ele fique olhando para a rua ao invés de trabalhar, ou talvez ele fique o dia inteiro 
#em frente a lojas de carros esperando novos carros saírem com novas placas. Isa, cansada de ficar para trás, escreveu um programa que gera uma placa aleatória, 
#para que a próxima vez que Martin lhe mande uma mensagem, ela responda com a placa gerada. Desse jeito, ela espera dificultar as coisas para Martin.
# 
# Entretanto, Martin começou a desconfiar, e quer determinar se Isa realmente viu um carro com a placa que ela mandou ou não. Desse jeito, ele saberá se a Isa 
#está na liderança do jogo.
# 
# Ele sabe alguns fatos sobre as placas feitas pela ACM:
# 
# Cada placa é uma combinação de 7 caracteres, que podem ser letras maiúsculas (A-Z) ou dígitos (0-9).
# Existem dois tipos de esquema de placas: o velho, usado por vários ano, e o novo, que está em uso há alguns meses, quando as combinações do velho foram extigüidas.
# No esquema velho, os três primeiros caracteres eram letras, e os últimos quatro eram dígitos, portanto as placas vão de AAA0000 a ZZZ9999.
# No esquema novo, os primeiros cinco caracteres são letras, e os ultimos dois são dígitos. Infelizmente o chefe da ACM bagunçou o sistema de impressão enquanto 
#ele estava tentando criar um poster para sua próxima campanha para prefeito, e a impressora não consegue imprimir as letras A, C, M, I e P. Portanto, no novo 
#esquema, a primeira placa é BBBBB00, ao invés de AAAAA00.
# As placas são criadas em seqüência. Como caso particular, a última placa do esquema velho é seguida pela primeira placa do novo esquema. Como Isa não sabe de tudo 
#isso, ela só garantiu que o gerador aleatório dela criasse uma combinação consistindo de sete caracteres, onde os três primeiros sempre são letras maiúsculas, os 
#dois últimos são sempre dígitos, e o quarto e o quinto podem ser tanto uma letra maiúscula quanto um dígito (possivelmente gerando uma combinação ilegal, mas ela 
#não tem muito tempo para se preocupar com isso).
# Obviamente, Martin não considerará Isa a vencedora se ele receber uma combinação ilegal, ou se ele receber uma placa legal, mas igual ou mais velha do que a dele. 
#Mas isso não é tudo. Como ele sabe que as placa novas não são geradas muito rápido, ele não acreditará que a Isa viu um carro com uma placa mais nova que a dele, 
#mas sequencialmente muito distante. Por exemplo, se Martin mandar DDDDD45, e receber ZZZZZ45, ele não acreditará que Isa viu um carro com aquela placa, porque ele 
#sabe que a ACM não conseguiria imprimir placas suficientes para chegar a ZZZZZ45 no momento que ele recebeu a resposta.
# 
# Então, Martin decidiu considerar Isa a vencedora somente se ele receber uma placa legal, mais nova que a dele, e mais velha que a C-ésima placa consecutiva depois 
#da que ele mandou. Ele chama de C seu número de confidência. Por exemplo, se Martin mandar ABC1234, e seu número de confidência é 6, ele considerará que Isa é a 
#vencedora somente se ele receber uma placa mais nova que ABC1234, mas mais velha ou igual a ABC1240.
# 
# Entrada
# 
# A entrada contém vários casos de teste. Cada caso de teste é descrito em uma única linha que contém duas strings SM e SI, e um inteiro C, separados por um único
#espaço cada. SM é a string de 7 caracteres enviada por Martin, que é sempre válida. SI é a string de 7 caracteres respondida por Isa, que foi gerada usando seu 
#gerador aleatório. C é o número de confidência de Martin (1 <= C <= 10^9).
# 
# O final da entrada é dado por SM = SI = “*” e C = 0.
# 
# Saída
# 
# Para cada caso de teste, imprima uma única linha com o caractere maiúsculo “Y” se, de acordo com Martin, Isa é a vencedora, e com a letra maiúscula “N” caso contrário.
# 
# Exemplo
# 
# Entrada
# ABC1234 ABC1240 6
# ABC1234 ABC1234 6
# ACM5932 ADM5933 260000
# BBBBB23 BBBBC23 100
# BBBBB23 BBBBD00 77
# ZZZ9997 ZZZ9999 1
# ZZZ9998 BBBBB01 3
# ZZZZZ95 ZZZZZ99 10
# BBBBB23 BBBBB22 5
# * * 0
# 
# Saída
# Y
# N
# N
# N
# Y
# N
# Y
# Y
# N

class Plate
  def initialize plateString
    
    if Plate.validatePlate(plateString)
      @plateString = plateString.to_s.upcase
      @valid = true
    else
      @plateString = nil
      @valid = false
    end
  end
  
  def self.validatePlate(plate)
    plate.upcase!
    if plate.length == 7 and plate.scan(/[A-Z]/).count == 3 and plate.scan(/[0-9]/).count == 4 #old licence plate
      return true
    elsif plate.length == 7 and plate.scan(/[A-Z]/).count == 5 and plate.scan(/[0-9]/).count == 2 and plate.scan(/A|C|M|I|P/).empty? #new licence plate
      return true
    else
      return false
    end
  end
  
  def valid?
    return @valid
  end
  
  def to_s
    @plateString
  end
  
  def <=>(otherPlate)
    return 0 if @plateString.eql? otherPlate.to_s.upcase
    return 1 if @plateString > otherPlate.to_s.upcase
    return -1 if @plateString < otherPlate.to_s.upcase
  end
  
  def >(otherPlate)
    if (self <=> otherPlate) == 1
      return true
    else
      return false
    end
  end
  
  def <(otherPlate)
    if (self <=> otherPlate) == -1
      return true
    else
      return false
    end
  end
  
  def ==(otherPlate)
    if (self <=> otherPlate) == 0
      return true
    else
      return false
    end
  end
  
  def +(i)
    numericPart = @plateString.scan(/\d+/).join('')
    if numericPart.length == 4 
      alphaPart = @plateString[0..2]
      alphaPartAsNum = Plate.alphaPartToNum(alphaPart) * 10000
      plateAsNum = alphaPartAsNum + numericPart.to_i
      resultNum = plateAsNum + i
      resultAlphaPart = Plate.numToAlphaPart (resultNum.to_s[0..resultNum.to_s.length - 5].to_i)
      (1..3-resultAlphaPart.length).each do 
        resultAlphaPart.prepend("A")
      end
      resultPlate = "#{resultAlphaPart}#{sprintf('%04d',resultNum.to_s[resultNum.to_s.length - 4..resultNum.to_s.length].to_i)}"
      @plateString = resultPlate
    elsif numericPart.length == 2
      alphaPart = @plateString[0..4]
      alphaPartAsNum = Plate.alphaPartToNum(alphaPart) * 100
      plateAsNum = alphaPartAsNum + numericPart.to_i
      resultNum = plateAsNum + i
      resultAlphaPart = Plate.numToAlphaPart (resultNum.to_s[0..resultNum.to_s.length - 3].to_i)
      resultAlphaPart.slice!(0..2)
      (1..5-resultAlphaPart.length).each do 
        resultAlphaPart.prepend("A")
      end
      # resultAlphaPart[0..resultAlphaPart.length - 4] = ""
      resultPlate = "#{resultAlphaPart}#{sprintf '%02d',(resultNum.to_s[resultNum.to_s.length - 2..resultNum.to_s.length].to_i)}"
      @plateString = resultPlate
    end
    return @plateString
  end
  
  # private
  
  @alpha = %w{A B C D E F G H I J K L M N O P Q R S T U V W X Y Z} # user A como Zero
  
  def self.numToAlphaPart(num)
    result = []
    begin 
      result << @alpha[(num % 26)]
      num = num / 26
    end until num == 0
    return result.join('').reverse
  end
  
  def self.alphaPartToNum(alphaPart)
    arrayAlphaPart = alphaPart.reverse.split(//)
    result = 0
    arrayAlphaPart.each_index do |i|
      result += @alpha.index(arrayAlphaPart[i])*(26**i)
    end
    return result
  end
  
end

x = Plate.new("ABC0004")
y = Plate.new("BBBBD00")

# p Plate.numToAlphaPart 26

# p Plate.alphaPartToNum("BA")

# p x.to_s[0..x.to_s.length-5]
p x + 1
p y + 1



