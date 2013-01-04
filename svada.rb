# 3363. Svada
# 
# Problem code: SVADA
# 
# The local zoo has acquired a large open garden in which animals may freely move as in their natural habitats and entertain visitors with their usual shenanigans.
# 
# The most popular animals are monkeys. With their climbing and jumping and other skills, they delight old and young visitors alike.
# 
# One species of monkey has specialized in climbing tall trees and picking off coconuts. Another species has specialized in breaking them open.
# 
# There are N monkeys of the first type (numbered 1 through N) and M monkeys of the second type (numbered 1 through M).
# 
# Monkey k of the first type takes Ak seconds to find a good spot on the tree, after which it picks off its first coconut. After that the monkey produces a 
#new coconut every Bk seconds.
# 
# Monkey k of the second type takes Ck seconds to find a good tool for opening the coconuts, after which it opens its first coconut. After that the monkey 
#opens another coconut every Dk seconds.
# 
# Unfortunately, the second type of monkey is extremely aggressive so the two types may not be in the garden at the same time. Therefore, zoo keepers will 
#chase away the first type of monkeys as soon as they have picked off all the coconuts. Similarly, if monkeys of the same type stay too long after opening 
#all the coconuts, fights will ensue. Because of that, zoo keepers will send them away as soon as they have opened all the coconuts.
# 
# The zoo keepers first arrive immediately after all coconuts have been picked, and again immediately after the monkeys open them all. The time needed for 
#monkeys to enter or leave the garden is also negligibly small.
# 
# Tomislav especially likes the second type of monkey, but can never guess when to arrive in order to see them. Help him calculate the time when the second
#type arrives if he knows the total time that monkeys spent in the garden, but does not know the number of coconuts in the garden.
# 
# Input
# 
# The first line contains the integer T (1 ≤ T ≤ 1 000 000 000), the total time that monkeys spent in the garden, in seconds.
# 
# The next line contains the integer N (1 ≤ N ≤ 100), the number of monkeys of the first type.
# 
# Each of the following N lines contains two integers Ak and Bk (1 ≤ Ak, Bk ≤ 1 000 000 000), how fast monkey k of the first type is.
# 
# The next line contains the integer M (1 ≤ M ≤ 100), the number of monkeys of the second type.
# 
# Each of the following M lines contains two integers Ck and Dk (1 ≤ Ck, Dk ≤ 1 000 000 000), how fast monkey k of the second type is.
# 
# Output
# 
# Output the number of seconds between the arrival of the first type of monkeys and the arrival of the second type.
# 
# Example
# 
# Input:
# 20
# 2
# 3 2
# 1 3
# 3
# 3 1
# 4 1
# 5 1
# 
# Output:
# 13

#Solving

class MonkeyA
  
  attr_accessor :findSpotTime, :takeCoconutTime
  
  def initialize(findSpotTime,takeCoconutTime)
    self.findSpotTime , self.takeCoconutTime = findSpotTime, takeCoconutTime
  end
  
end

class MonkeyB
  attr_accessor :findToolTime, :openCoconutTime
  
  def initialize(findToolTime, openCoconutTime)
    self.findToolTime, self.openCoconutTime = findToolTime, openCoconutTime
  end
end

#p "Svada problem"
#p "Total time that the monkeys can spent in the garden in seconds"
totalTime = rand(1..60) #testing
# totalTime = rand(10) #testing
# totalTime = gets.chomp #spoj
#p "Number of finding coconuts type of monkey"
# nTypeA = gets.chomp #spoj
# nTypeA = rand(1..10) #testing
nTypeA = rand(10) #testing
monkeysOfTypeA = []
(1..nTypeA).each do 
  # findSpotTime = gets.chomp #spoj
  findSpotTime = rand(1..10) #testing
  # findSpotTime = rand(10) #testing
  # takeCoconutTime = gets.chomp #spoj
  takeCoconutTime = rand(1..10) #testing
  # takeCoconutTime = rand(10) #testing
  monkeysOfTypeA << MonkeyA.new(findSpotTime,takeCoconutTime)
end
#p "Number of open coconuts type of monkeys"
# nTypeB = gets.chomp #spoj
# nTypeB = rand(1..10) #testing
nTypeB = rand(10) #testing
monkeysOfTypeB = []
(1..nTypeB).each do
  # findToolTime = gets.chomp # spoj
  findToolTime = rand(1..10) #testing
  # findToolTime = rand(10) #testing
  # openCoconutTime = gets.chomp #spoj
  openCoconutTime = rand(1..10) #testing
  # openCoconutTime = rand(10) #testing
  monkeysOfTypeB << MonkeyB.new(findToolTime, openCoconutTime)
end

